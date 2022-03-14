#include "singleton.h"
Singleton* Singleton::uniqueInstance = nullptr; 

Singleton::Singleton(){
    
}

Singleton* Singleton::Instance () {
    if (uniqueInstance == nullptr) {      // Check ob bereits konstruiert
        uniqueInstance = new Singleton;     // Konstruktion
    }
    return uniqueInstance;                // Rückgabe des Objekts
} 