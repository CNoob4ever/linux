#ifndef __MMAP_TEST1_H__
#define __MMAP_TEST1_H__

#include "rf_test.hpp"
#include "mmap.hpp"

class MmapTest1:public RfTest
{
public:
    MmapTest1();
    virtual ~MmapTest1();

    virtual void run_test();

    static void maptest(Mmap* mem);

    static void advisetest(Mmap* mem);
};

#endif
