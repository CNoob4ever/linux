#include "mmap.hpp"
#include "exception.hpp"

#include <cerrno>
#include <cstring>

Mmap::Mmap(void* addr,size_t length,int prot,int flags,int fd,off_t offset)
    :addr_(addr),length_(length),prot_(prot),flags_(flags),fd_(fd),offset_(offset)
{
}

Mmap::~Mmap()
{
}

void
Mmap::map()
{
    starting_addr_ = mmap(addr_,length_,prot_,flags_,fd_,offset_);
    if(starting_addr_ == MAP_FAILED)
	throw MmapError("map",errno,std::strerror(errno));
}

void
Mmap::unmap()
{
    if( munmap(starting_addr_,length_) == -1)
	throw MmapError("unmap",errno,std::strerror(errno));
}

void
Mmap::advise(void* addr,size_t length,int advise)
{
    if(madvise(addr,length,advise) == -1)
	throw MmapError("advise",errno,std::strerror(errno));
}
