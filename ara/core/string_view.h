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
            StringView(const std::string& str) : m_str(str) {}

            operator std::string() const {
                return m_str;
            }

        private:
            std::string m_str;
        };
        
    }
}
#endif