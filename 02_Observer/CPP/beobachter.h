#include <list>
#include <string>
#include <iostream>

using namespace std;

class Subjekt;

class Beobachter{
    private:
    protected:
        Beobachter(){};
    public:
        virtual ~Beobachter(){};

        // rein virtuelle Methode (pure virtual function) 
        // -> von dieser Klasse kann kein Objekt instanziiert werden (technisch wie ein Interface)
        virtual void aktualisieren(Subjekt * veraendertesSubjekt) = 0;

};