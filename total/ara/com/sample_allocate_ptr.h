#ifndef SAMPLE_ALLOCATE_PTR_H
#define SAMPLE_ALLOCATE_PTR_H

#include <memory>
#include <cstddef>

namespace ara 
{
    namespace com 
    {
        template <typename T>
        using SampleAllocateePtr = std::unique_ptr<T>;
    }
}

#endif