#include "c_string.h"

c_string::c_string(const char* new_str) 
{
    uint32_t len = 0;
    while (new_str[len] != '\0') 
    {
        len++;
    }
    
    s = new char[len + 1];
    
    if (s != NULL) 
    {
        for (uint32_t i = 0; i < len; i++)
        {
            s[i] = new_str[i];
        }
        s[len] = '\0';
    }
}

c_string::~c_string()
{
    delete[] s;
}

int32_t c_string::find(char c)
{
    for (uint32_t i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)
        {
            return i;
        }
    }
    return -1;
}

int32_t c_string::find(c_string& str)
{
    int32_t str_len = str.length();

    for (uint32_t i = 0; s[i] != '\0'; i++) 
    {
        uint32_t j = 0;
        while (s[i + j] == str.s[j] && str.s[j] != '\0')
        {
            j++;
        }
        if (j == str_len)
        {
            return i;
        }
    }
    return -1;
}


uint32_t c_string::length(void) const
{
    uint32_t len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

c_string c_string::operator+(const c_string& str)
{
    uint32_t len1 = length();
    uint32_t len2 = str.length();

    char* new_str = new char[len1 + len2 + 1];
    if (new_str != NULL)
    {
        for (uint32_t i = 0; i < len1; i++)
        {
            new_str[i] = s[i];
        }
        for (uint32_t i = 0; i < len2; i++)
        {
            new_str[len1 + i] = str.s[i];
        }
        new_str[len1 + len2] = '\0';
    }
    c_string res = c_string(new_str);
    delete [] new_str;

    return res;
}

c_string& c_string::operator=(const c_string& str)
{
    uint32_t len;

    if (this == &str)
    {
        return *this;
    }

    delete[] s;
    len = str.length();
    s = new char[len + 1];
    if (s != NULL)
    {
        for (uint32_t i = 0; i < len; ++i)
        {
            s[i] = str.s[i];
        }
        s[len] = '\0';
    }

    return *this;
}

bool c_string::operator== (const c_string& str) const
{
    if (length() != str.length())
        return false;
    
    for (uint32_t i = 0; i < length(); ++i) 
    {
        if (s[i] != str.s[i])
            return false;
    }
    
    return true;
}

bool c_string::operator!= (const c_string& str) const
{
    return !(*this == str);
}

std::ostream& operator<<(std::ostream& os, const c_string& str)
{
    for (uint32_t i = 0; i < str.length(); ++i)
    {
        os << str.s[i];
    }
    return os;
}