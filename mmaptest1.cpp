#include "mmaptest1.hpp"
#include "exception.hpp"

#include <thread>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include <unistd.h>

MmapTest1::MmapTest1()
{}

MmapTest1::~MmapTest1()
{}

void
MmapTest1::run_test()
{
    long length = sysconf(_SC_PAGESIZE);
    
    Mmap* mem[95] = {NULL};
    for(auto& i : mem)
	i = new Mmap(NULL,length,PROT_READ | PROT_WRITE,MAP_PRIVATE | MAP_ANONYMOUS,-1,0);
    
    std::thread threads[100];
    for(int i = 0; i < 95; ++i)
	threads[i] = std::thread(MmapTest1::maptest,mem[i]);

    for(int i = 95; i < 100; ++i)
	threads[i] = std::thread(MmapTest1::advisetest,mem[0]);

    for(auto& i : mem)
	delete i;
}

void
MmapTest1::maptest(Mmap* mem)
{
    try{
	char* starting_addr = (char *)mem->map();

	unsigned seed;
	seed = time(0);
	srand(seed);
	
	for(;;)
	{
	    std::strncpy(starting_addr,"0",1);

	    sleep(rand() % 6 + 1);
	}
    }catch(MmapError& e)
    {
	std::cout << e.toString() << std::endl;
    }
}

void
MmapTest1::advisetest(Mmap* mem)
{
    long length = sysconf(_SC_PAGESIZE);

    unsigned seed;
    seed = time(0);
    srand(seed);

    for(int i = 0; i < 95; ++i)
    {
	mem->advise(mem->get_starting_add(),length,MADV_DONTNEED);

	sleep(rand() % 3 + 1);
    }
}
