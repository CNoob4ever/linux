#include "mmaptest.hpp"
#include "mmaptest1.hpp"

#include <cstring>
#include <iostream>

void
rf_test(RfTest* test)
{
    test->run_test();
}

int
main(int argc,char** argv)
{
    RfTest* test;

    if(argc != 2)
	std::cout << "invalid paramaters" << std::endl;
	
    if(std::strncmp(argv[1],"0",1) == 0)
	test =new MmapTest();
    else if(std::strncmp(argv[1],"1",1) == 0)
	test =new MmapTest1();
    else if(std::strncmp(argv[1],"3",1) == 0)
    {
	std::cout << "malloc " << std::endl;
	(char*)malloc(sizeof(char)*9*1024*1024*1024);
	std::cout << "malloc ~" << std::endl;
	for(;;);
    }
    else
    {
	std::cout << "unknown paramaters" << std::endl;
	return 0;
    }
		
    rf_test(test);

    for(;;);
    
    return 0;
}
