#include <iostream>
#include <pthread.h>

class Singleton {
private:
    static Singleton *instance;
    Singleton(){};

    class CG {
    public:
        ~CG(){
            if(Singleton::instance != nullptr) {
                delete Singleton::instance;
                Singleton::instance = nullptr;
            }
        }
    };
    static CG cleanCarbage;

public:
    static Singleton* getIntance(){};
};

Singleton* Singleton::instance = nullptr;
Singleton* Singleton::getIntance() {
    if(Singleton::instance == nullptr) {
        Singleton::instance = new Singleton();
    }
    return Singleton::instance;
}

int main() {

    return 0;
}