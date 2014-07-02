#include "common/base/log.h"
#include "common/sys/memory/static_allocator.h"

namespace ps_common_sys {

namespace memory {

StaticAllocator::StaticAllocator() {
  __ENTER_FUNCTION
    buffer_ = NULL;
    size_ = 0;
    offset_ = 0;
  __LEAVE_FUNCTION
}

StaticAllocator::~StaticAllocator() {
  //do nothing
}

void StaticAllocator::init(char* buffer, size_t size) {
  __ENTER_FUNCTION
    buffer_ = buffer;
    size_ = size;
  __LEAVE_FUNCTION
}

void* StaticAllocator::malloc(size_t size) {
  __ENTER_FUNCTION
    using namespace ps_common_base;
    if (offset_ + size > size_) {
      SLOW_ERRORLOG("error",
                    "StaticAllocator::malloc: out of memory allocating %d bytes",
                    size);
      Assert(false);
      return NULL;
    }
    char* pointer = &buffer_[offset_]; 
    offset_ += size;
    return reinterpret_cast<void*>(pointer);
  __LEAVE_FUNCTION
    return NULL;
}

void* StaticAllocator::calloc(size_t count, size_t size) {
  __ENTER_FUNCTION
    void* pointer = malloc(count * size);
    memset(pointer, 0, count * size);
    return reinterpret_cast<void*>(pointer);
  __LEAVE_FUNCTION
    return NULL;
}

void* StaticAllocator::realloc(void* data, size_t newsize) {
  __ENTER_FUNCTION
    Assert(data >= buffer_ && data < buffer_ + size_);
    size_t size_ofdata = 
      offset_ - static_cast<size_t>(reinterpret_cast<char*>(data) - buffer_);
    size_t size = newsize - size_ofdata;
    if (offset_ + size > size_) {
      SLOW_ERRORLOG("error",
                    "StaticAllocator::malloc: out of memory allocating %d bytes",
                    size);
      Assert(false);
      return NULL;
    }
    else {
      offset_ += size;
      return data;
    }
  __LEAVE_FUNCTION
    return NULL;
}

void StaticAllocator::free(void* data) {
  __ENTER_FUNCTION
    USE_PARAM(data);
    Assert(data >= buffer_ && data < buffer_ + size_);
  __LEAVE_FUNCTION
}

}; //namespace memory

}; //namespace ps_common_sys
