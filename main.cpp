#include "mmaptest.hpp"
#include "mmaptest1.hpp"

#include <cstring>

int
main(int argc,char** argv)
{
    
    if(std::strncmp(argv[1],"0",1) == 0)
    {
	MmapTest test = MmapTest();
	test.run_test();
    }else
    {
	MmapTest1 test1 = MmapTest1();
	test1.run_test();
    }
    return 0;
}
