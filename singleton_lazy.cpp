#include <iostream>
#include <pthread.h>
#include <mutex>
using std::mutex;

mutex m;

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
        m.lock();
        if(Singleton::instance == nullptr) Singleton::instance = new Singleton();
        m.unlock();
    }
    return Singleton::instance;
}

int main() {

    return 0;
}