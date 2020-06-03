#include "mmaptest.hpp"
#include "mmap.hpp"
#include "exception.hpp"

#include <thread>
#include <cstring>
#include <iostream>
#include <system_error>

#include <unistd.h>

MmapTest::MmapTest()
{}

MmapTest::~MmapTest()
{}

void
MmapTest::run_test()
{
    try
    {
	std::thread* threads[1000] = { NULL };
	
	for(int i = 0; i < 1000; ++i)
	    threads[i] = new std::thread(MmapTest::maptest);

//	for(int i = 0; i < 1000;++i)
//	{
//	    if(threads[i] != NULL)
//		threads[i]->detach();
//	}
    
    }catch(std::system_error& e)
    {
	std::cout<< "system error: " << e.code() << std::endl
		 << e.code().message() << std::endl
	         << e.what() << std::endl;
    }
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
