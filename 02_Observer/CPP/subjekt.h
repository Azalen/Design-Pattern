#include "beobachter.h"

class Subjekt {
    private:
        list<Beobachter*> beobachterList; 

    protected:
        Subjekt(){};

    public: 
        ~Subjekt(){};

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
                // sende Information, dass sich Daten geändert haben
                (*it)->aktualisieren(this);
            }
        }
    
    
};

// konkretes Subjekt - hier eine Nachricht (string)
class konkretesSubjekt : public Subjekt {
    private:
        string subjektZustand = "initial state";
        
    public:
        konkretesSubjekt() : Subjekt() {}
        virtual ~konkretesSubjekt(){}

        virtual const string & gibZustand(){
            return subjektZustand;
        }
        virtual void setzeZustand(const string & neuerZustand){
            subjektZustand = neuerZustand;
            this->benachrichtige();
        }



    
};