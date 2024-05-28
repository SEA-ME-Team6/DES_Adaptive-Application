#ifndef SAMPLEPTR_H
#define SAMPLEPTR_H

#include <memory>
#include <cstddef>

namespace ara 
{
    namespace com 
    {
        template<typename T>
        class SamplePtr {
        private:
            const T* ptr_;

        public:
            constexpr SamplePtr() noexcept : ptr_(nullptr) {}

            constexpr SamplePtr(std::nullptr_t) noexcept : ptr_(nullptr) {}

            SamplePtr(const SamplePtr&) = delete;

            SamplePtr(SamplePtr&& other) noexcept : ptr_(other.ptr_) {
                other.ptr_ = nullptr;
            }

            ~SamplePtr() {
                // delete ptr_;
            }

            SamplePtr& operator=(const SamplePtr&) = delete;

            SamplePtr& operator=(std::nullptr_t) noexcept {
                delete ptr_;
                ptr_ = nullptr;
                return *this;
            }

            SamplePtr& operator=(SamplePtr& other) noexcept {
                if (this != &other) {
                    delete ptr_;
                    ptr_ = other.ptr_;
                    other.ptr_ = nullptr;
                }
                return *this;
            }

            const T& operator*() const noexcept { return *ptr_; }

            const T* operator->() const noexcept { return ptr_; }

            explicit operator bool() const noexcept { return ptr_ != nullptr; }

            void Swap(SamplePtr& other) noexcept {
                std::swap(ptr_, other.ptr_);
            }

            void Reset(std::nullptr_t = nullptr) noexcept {
                delete ptr_;
                ptr_ = nullptr;
            }

            // Non Standard
            void Set(const T* ptr) noexcept {
                ptr_ = ptr;
            }

            const T* Get() const noexcept { return ptr_; }
        };

    }
}

#endif // SAMPLEPTR_H
