#include <iostream>

using namespace std;

// Virtuelle Basisklasse == Interface
// <<interface>> Komponente
class Apfel {
    public:
        Apfel(){}
        virtual ~Apfel(){}
        virtual void ausgabe() = 0;
        double gewicht;
};

// Konkrete Komponente
class KonkreterApfel : public Apfel {
    public:
        KonkreterApfel(double gewicht) : Apfel() {
            this->gewicht = gewicht;
        }
        ~KonkreterApfel(){ cout << "KonkreterApfel destructed" << endl; }

        void ausgabe(){ cout << gewicht << endl; } 
};

// Dekorierer
class Decorator : public Apfel {
    protected:
        Apfel * component;

        Decorator(double gewicht) : Apfel() {
            this->component = nullptr;
            this->gewicht = gewicht;
        }
        virtual ~Decorator() {
            delete component;
        }

        virtual void ausgabe() {
            component->ausgabe();
        }
};

// Konkreter Dekorierer A
class FarbigerApfel : public Decorator {
    public:
        FarbigerApfel(Apfel * component, const string & farbe) : Decorator(component->gewicht) {
            Decorator::component = component;
            this->farbe = farbe;
        }

        void ausgabe() {
            Decorator::ausgabe();
            cout << farbe << endl;
        }

        const string & getFarbe() const { return farbe; }

    private:
        string farbe;
};

int main() {

    system("clear");
    cout << endl;

    Apfel * a = new FarbigerApfel(new KonkreterApfel(10), "blau");

    // statischer Typ Apfel* -> kennt nur Attribute/Methoden des Interface Apfel
    a->ausgabe();

    // dynamischer Typ FarbigerApfel* -> braucht expliziten type cast
    cout << ( (FarbigerApfel *) a)->getFarbe() << endl;


    return 0;
}
