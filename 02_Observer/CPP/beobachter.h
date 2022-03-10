#ifndef BEOBACHTER_H
#define BEOBACHTER_H

class Subjekt;

class Beobachter{
    private:
    protected:
        Beobachter(){};
    public:
        virtual ~Beobachter(){};

        // rein virtuelle Methode (pure virtual function) 
        // -> von dieser Klasse kann kein Objekt instanziiert werden (technisch wie ein Interface)
        virtual void aktualisieren() = 0;
};

#endif