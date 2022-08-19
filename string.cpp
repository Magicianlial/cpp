#include <iostream>
#include <string.h>

class mystring {
public:
    mystring();
    mystring(const char *str);
    mystring(const mystring &rhs);
    mystring& operator=(const mystring&rhs);
    ~mystring();

    char operator[](int n) const;
    int size() const;
    char *c_str() const;

private:
    char *m_pData;
};

mystring::mystring():m_pData(new char[1]) {
    *m_pData = '\0';
}

mystring::mystring(const char *str){
    if(!str) {
        m_pData = new char[1];
        *m_pData = '\0';
    } else {
        int nLen = strlen(str);
        m_pData = new char[nLen + 1];
        strcpy(m_pData, str); 
    }
}

mystring::mystring(const mystring &rhs) {
    
}