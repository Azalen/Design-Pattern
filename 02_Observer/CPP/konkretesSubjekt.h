#ifndef KONKRETES_SUBJEKT_H
#define KONKRETES_SUBJEKT_H

#include "subjekt.h"

#include <string>

class konkretesSubjekt : public Subjekt {
    private:
        string subjektZustand = "initial state";
        
    public:
        konkretesSubjekt() : Subjekt() {}
        virtual ~konkretesSubjekt(){}

        const string & gibZustand() const {
            return subjektZustand;
        }
        void setzeZustand(const string & neuerZustand){
            subjektZustand = neuerZustand;
            this->benachrichtige();
        }


};

#endif