#ifndef STRING_H
#define STRING_H

#include <cstdint>
#include <iostream>

class c_string
{
    private:
        char* s;
    public:
        c_string(const char* new_str);
        ~c_string();

        int32_t find(char c);
        int32_t find(c_string& str);
        uint32_t length(void) const;

        c_string operator+ (const c_string& str);
        c_string& operator= (const c_string& str);
        bool operator== (const c_string& str) const;
        bool operator!= (const c_string& str) const;

        friend std::ostream& operator<<(std::ostream& os, const c_string& str);
};

#endif
