#include <iostream>
#include <string.h>
using namespace std;

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
    friend ostream& operator<<(ostream& out, mystring &s);
    friend istream& operator>>(istream& in, mystring &s);
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
    int nLen = strlen(rhs.m_pData);
    m_pData = new char[nLen + 1];
    strcpy(m_pData, rhs.m_pData);
}

mystring& mystring::operator=(const mystring &rhs) {
    if(this != &rhs) {
        if(m_pData) {
            delete[] m_pData;
        }
        int nLen = strlen(rhs.m_pData);
        m_pData = new char[nLen + 1];
        strcpy(m_pData, rhs.m_pData);
    }
    return *this;
}

mystring::~mystring() {
    if(m_pData) {
        delete[] m_pData;
        m_pData = nullptr;
    }
}

char mystring::operator[](int i) const {
    int nLen = strlen(m_pData);
    if(i >= nLen) return '\0';
    else return m_pData[i];
}

int mystring::size() const {
    return strlen(m_pData);
}

char* mystring::c_str() const{
    return m_pData;
}

ostream& operator<<(ostream &out, mystring &s) {
    out << s.m_pData;
    return out;
}

istream& operator>>(istream &in, mystring &s) {
    char data[1024];
    in.getline(data, 1024);
    s = data;
    return in;
}