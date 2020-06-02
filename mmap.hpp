#ifndef __MMAP_H__
#define __MMAP_H__

#define _BSD_SOURCE

#include <sys/mman.h>

class Mmap
{
public:
    Mmap(void* addr,size_t length,int prot,int flags,int fd,off_t offset);
    ~Mmap();

    void* map();
    
    void unmap();

    void advise(void* addr,size_t length,int advise);

    void* get_starting_add();
private:
    void* starting_addr_;
    void* addr_;
    size_t length_;
    int prot_;
    int flags_;
    int fd_;
    off_t offset_;
};

#endif
