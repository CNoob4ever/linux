#include "mmaptest.hpp"
#include "mmap.hpp"
#include "exception.hpp"

#include <thread>
#include <cstring>
#include <iostream>

#include <unistd.h>

MmapTest::MmapTest()
{}

MmapTest::~MmapTest()
{}

void
MmapTest::run_test()
{
    std::thread threads[1000];

    for(int i = 0; i < 1000; ++i)
	threads[i] = std::thread(MmapTest::maptest);

    for(auto& t : threads)
	t.join();
}

void
MmapTest::maptest()
{
    try
    {
	for(;;)
	{
	    long length = sysconf(_SC_PAGESIZE);

	    Mmap mem = Mmap(NULL,length,PROT_READ | PROT_WRITE,MAP_PRIVATE | MAP_ANONYMOUS,-1,0);

	    char* starting_addr = (char*)mem.map();

	    std::strncpy(starting_addr,"0",1);

	    mem.advise(starting_addr,length,MADV_DONTNEED);

	    mem.unmap();
	}
    }catch(MmapError& e)
    {
	std::cout << e.toString() << std::endl;
    }
}
