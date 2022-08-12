#include <iostream>

class Singleton {
private:
    static Singleton *instance;
    Singleton(){}

public:
    static Singleton* getInstance() {
        printf("instance got\n");
        return instance;
    }
    class CG {
        ~CG() {
            if(Singleton::instance != nullptr) {
                delete Singleton::instance;
                Singleton::instance = nullptr;
            }
        }
    };
    static CG cleanCarbarge;
};

Singleton* Singleton::instance = new Singleton();

int main() {
    Singleton *p = Singleton::getInstance();
    if(p != nullptr) printf("succeed\n");
    return 0;
}