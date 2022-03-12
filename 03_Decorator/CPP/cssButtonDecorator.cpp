#include <iostream>

using namespace std;

// Virtuelle Basisklasse == Interface
// <<interface>> Komponente
class Button {
  public:
    virtual ~Button(){}
    virtual void render() = 0;
};

// Konkrete Komponente
class KonkreterButton : public Button {
    public:
        ~KonkreterButton(){ cout << "Button destructed" << endl; }
        void render() {
            cout << "<" 
                 << "\033[1;31m" << "button " 
                 << "\033[1;32m" << "type" 
                 << "\033[0m"    << "=" 
                 << "\033[1;33m" << "'submit' " 
                 << "\033[1;32m" << "class" 
                 << "\033[0m"    << "=" 
                 << "\033[1;33m" << "'btn ";
        }
};

// Dekorierer
class Decorator : public Button {
    private: 
        Button * component;

    protected:
        /**     Hier kommt wie schon beim Observer-Pattern Polymorphie von Zeigern zum Einsatz
         *      Der Konstruktor erwartet einen Zeiger von Typ Button* doch erhält in der Realität
         *      immer Zeiger von Typ KonkreterButton*
         *      
         *      Polymorphie von Zeigern in C++ ermöglicht nun, dass die Zuweisung
         *      Button * = KonkreterButton * erfolgreich ist 
         * 
         *      Das heißt der Zeiger zeigt letztendlich doch auf ein Objekt vom Typ KonkreterButton* und 
         *      nutzt dann auch die korrekte render()-Methode !
         * */
        Decorator(Button * component){
            this->component = component;
        }
        ~Decorator() {
            delete component;
        }
        virtual void render() {
            component->render();
        }

};

// Konkreter Dekorierer A
class ButtonPrimary : public Decorator {
    public:
        ButtonPrimary(Button * component) : Decorator(component) {}
        ~ButtonPrimary(){ cout << "ButtonPrimary destructed "; }

        void render() {
            Decorator::render();
            cout << "btn-primary ";
        }
};

// Konkreter Dekorierer B
class ButtonSecondary : public Decorator {
    public:
        ButtonSecondary(Button * component) : Decorator(component) {}
        ~ButtonSecondary(){ cout << "ButtonSecondary destructed "; }

        void render() {
            Decorator::render();
            cout << "btn-secondary ";
        }
};

// Konkreter Dekorierer C
class ButtonSmall : public Decorator {
    public:
        ButtonSmall(Button * component) : Decorator(component) {}
        ~ButtonSmall(){ cout << "ButtonSmall destructed "; }

        void render() {
            Decorator::render();
            cout << "btn-sm ";
        }
};

// Konkreter Dekorierer D
class ButtonLarge : public Decorator {
    public:
        ButtonLarge(Button * component) : Decorator(component) {}
        ~ButtonLarge(){ cout << "ButtonLarge destructed "; }

        void render() {
            Decorator::render();
            cout << "btn-lg ";
        }
};

/**     ANZAHL NÖTIGER KLASSEN FÜR ALLE KOMBINATIONEN 
 *      -> Beliebige Kombination im Aufruf möglich
 *      -> Etwas Overhead durch Klassen Decorator und IButton
 *      -> Reihenfolge spielt keine Rolle
 *      
 *          => n-viele konkreterDecorator-Klassen
 * */

int main() {

    system("clear");
    cout << endl;

    // BUTTON PRIMARY
    Button * bp = new ButtonPrimary(new KonkreterButton);
    bp->render(); 
    cout << "\033[0m"    << "'></" 
         << "\033[1;31m" << "button" 
         << "\033[0m"    << ">" << endl << endl;

    // BUTTON PRIMARY LARGE
    Button * bpl = new ButtonLarge(new ButtonPrimary(new KonkreterButton));
    bpl->render();
    cout << "\033[0m"    << "'></" 
         << "\033[1;31m" << "button" 
         << "\033[0m"    << ">" << endl << endl;

    // BUTTON SECONDARY SMALL
    Button * bss = new ButtonSmall(new ButtonSecondary(new KonkreterButton));
    bss->render();
    cout << "\033[0m"    << "'></" 
         << "\033[1;31m" << "button" 
         << "\033[0m"    << ">" << endl << endl;
    

    delete bp;
    delete bpl;
    delete bss;

    return 0;
}