#ifndef __MMAP_TEST_H__
#define __MMAP_TEST_H__

#include "rf_test.hpp"

class MmapTest:public RfTest
{
public:
    MmapTest();
    virtual ~MmapTest();

    virtual void run_test();
};

#endif
