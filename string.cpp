#include <iostream>

class string {
public:
    string();
    string(const char *str);
    string(const string &rhs);
    string& operator=(const string&rhs);
    ~string();

    char operator[](int n) const;
    int size() const;
    char *c_str() const;

private:
    char *m_str;
};