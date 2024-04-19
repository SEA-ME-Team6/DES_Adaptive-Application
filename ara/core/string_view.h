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
            StringView(const std::string& str) : mstr(str) {}

            StringView(const char* str) : mstr(str) {}

            std::string mstr;

        private:
        };
        
    }
}
#endif
