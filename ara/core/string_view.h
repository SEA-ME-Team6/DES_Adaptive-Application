#ifndef STRING_VIEW_H
#define STRING_VIEW_H

#include <string>

namespace ara
{
    namespace core
    {
        class StringView final
        {
        public:
            StringView() noexcept {}
            
            static std::string CreateString(const char* str) 
            {
                return std::string(str);
            }

        };
    }
}
#endif