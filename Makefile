
#################################
#purpose: C++ Thread Project, This
#is a template that I compiled project.
#author: Haluk
#date: 12/7/2019
#################################


#detail:
#
#LOCAL_PATH					project path
#LOCAL_CC					compiler
#LOCAL_CFLAGS				
#								-c			Compile or assemble the source files, but do not link.
#								-std=c++1y	The next revision of the ISO C++ standard, tentatively planned
#											for 2014. Support is highly experimental, and will almost certainly
#											change in incompatible ways in future releases.

#									 c++1z
#									 c++11
#								-Wall		This enables all the warnings about constructions that some users consider
#											questionable, and that are easy to avoid (or modify to prevent the warning),
#											even in conjunction with macros.
#								-pedantic	Issue all the warnings demanded by strict ISO C and ISO C++
#								-g			Produce debugging information in the operating system’s native format
#								-O2			Optimize even more
#LOCAL_CPP_FEATURES			
#LOCAL_LDLIB				
#LOCAL_SRC_FILES			source files
#LOCAL_C_INCLUDES			header files
#LOCAL_STATIC_LIBRARIES		
#LOCAL_SHARED_LIBRARIES		
#
#

LOCAL_PATH = .

LOCAL_CC = gcc
LOCAL_CFLAGS += -std=c++1z -Wall -pedantic -g -O2 -static
LOCAL_CPP_FEATURES += 
					  
#which would need explicit linking with -lstdc++ when using gcc; g++ links the standard library by default.					  
LOCAL_LDLIB += -lstdc++ -lpthread -lz -ldl
LOCAL_SRC_FILES += $(wildcard *.cpp)
LOCAL_C_INCLUDES += 
LOCAL_C_LIBS +=
LOCAL_STATIC_LIBRARIES +=  
LOCAL_SHARED_LIBRARIES +=

LOCAL_OBJ=$(patsubst %cpp,%o,$(LOCAL_SRC_FILES))
LOCAL_TARGET=$(notdir $(CURDIR))

.PHONY: clean all test

all: $(LOCAL_TARGET)

$(LOCAL_TARGET): $(LOCAL_OBJ)
	$(LOCAL_CC) $(LOCAL_CFLAGS) -o $@ $^ $(LOCAL_C_LIBS) $(LOCAL_LDLIB) $(LOCAL_STATIC_LIBRARIES) $(LOCAL_SHARED_LIBRARIES)
	
%.o:%.cpp
	$(LOCAL_CC) $(LOCAL_CFLAGS) $(LOCAL_C_INCLUDES) -c $<
	
clean:
	rm -f $(LOCAL_OBJ)
