#ifndef SUBJEKT_H
#define SUBJEKT_H

#include "beobachter.h"

#include <list>

// ! BAD PRACTICE ! BETTER USE STD:: ! ONLY FOR CONVENIENCE !
using namespace std;

class Subjekt {
    private:
        list<Beobachter*> beobachterList; 

    protected:
        Subjekt(){};

    public: 
        virtual ~Subjekt(){};

        // late binding via virtual keyword -> ermöglicht Überladung in Unterklassen
        virtual void meldeAn(Beobachter * beobachter){
            beobachterList.push_back(beobachter);
        }
        virtual void meldeAb(Beobachter * beobachter){
            beobachterList.remove(beobachter);
        }
        virtual void benachrichtige(){
            list<Beobachter*>::iterator it;
            for(it = beobachterList.begin(); it != beobachterList.end(); ++it){
                // sende Information an alle Beobachter, dass sich Daten geändert haben
                (*it)->aktualisieren();
            }
        }
};

#endif