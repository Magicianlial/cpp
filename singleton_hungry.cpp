#include <iostream>

class Singleton {
private:
    static Singleton *instance;
    Singleton(){};
    
    class CG {
        ~CG() {
            if(Singleton::instance != nullptr) {
                delete Singleton::instance;
                Singleton::instance = nullptr;
            }
        }
    };
    static CG cleanCarbarge;

public:
    static Singleton* getInstance() {
        return instance;
    }
    
};

Singleton* Singleton::instance = new Singleton();

int main() {
    Singleton *p = Singleton::getInstance();
    if(p != nullptr) printf("succeed\n");
    return 0;
}