#include <iostream>

using namespace std;

// Virtuelle Basisklasse == Interface
// <<interface>> Komponente
class IButton {
  public:
    virtual ~IButton(){}
    virtual void render() = 0;
};

// Konkrete Komponente
class Button : public IButton {
    public:
        ~Button(){ cout << "Button destructed"; }
        void render() {
            cout << "<" 
                 << "\033[1;31m" << "button " 
                 << "\033[1;32m" << "type" 
                 << "\033[0m" << "=" 
                 << "\033[1;33m" << "'submit' " 
                 << "\033[1;32m" <<  "class" 
                 << "\033[0m" << "=" 
                 << "\033[1;33m" << "'btn ";
        }
};

// Dekorierer
class Decorator : public IButton {
    private: 
        IButton * component;

    protected:
        /**     Hier kommt wie schon beim Observer-Pattern Polymorphie von Zeigern zum Einsatz
         *      Der Konstruktor erwartet einen Zeiger von Typ IButton* doch erhält in der Realität
         *      immer Zeiger von Typ Button*
         *      
         *      Polymorphie von Zeigern in C++ ermöglicht nun, dass die Zuweisung
         *      IButton * = Button * erfolgreich ist 
         * 
         *      Das heißt der Zeiger zeigt letztendlich doch auf ein Objekt vom Typ Button* und 
         *      nutzt dann auch die korrekte render()-Methode !
         * */
        Decorator(IButton * component){
            this->component = component;
        }
        ~Decorator() {
            delete component;
        }
        void render() {
            component->render();
        }
};

// Konkreter Dekorierer A
class ButtonPrimary : public Decorator {
    public:
        ButtonPrimary(IButton * component) : Decorator(component) {}
        ~ButtonPrimary(){ cout << "ButtonPrimary destructed"; }

        void render() {
            Decorator::render();
            cout << "btn-primary ";
        }
};

// Konkreter Dekorierer B
class ButtonSecondary : public Decorator {
    public:
        ButtonSecondary(IButton * component) : Decorator(component) {}
        ~ButtonSecondary(){ cout << "ButtonSecondary destructed"; }

        void render() {
            Decorator::render();
            cout << "btn-secondary ";
        }
};

// Konkreter Dekorierer C
class ButtonSmall : public Decorator {
    public:
        ButtonSmall(IButton * component) : Decorator(component) {}
        ~ButtonSmall(){ cout << "ButtonSmall destructed"; }

        void render() {
            Decorator::render();
            cout << "btn-sm ";
        }
};

// Konkreter Dekorierer D
class ButtonLarge : public Decorator {
    public:
        ButtonLarge(IButton * component) : Decorator(component) {}
        ~ButtonLarge(){ cout << "ButtonLarge destructed"; }

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
    IButton * bp = new ButtonPrimary(new Button);
    bp->render(); 
    cout << "\033[0m" << "'></" 
         << "\033[1;31m" << "button" 
         << "\033[0m" << ">" << endl << endl;

    // BUTTON PRIMARY LARGE
    IButton * bpl = new ButtonLarge(bp);
    bpl->render();
    cout << "\033[0m" << "'></" 
         << "\033[1;31m" << "button" 
         << "\033[0m" << ">" << endl << endl;

    // BUTTON SECONDARY SMALL
    IButton * bss = new ButtonSmall(new ButtonSecondary(new Button));
    bss->render();
    cout << "\033[0m" << "'></" 
         << "\033[1;31m" << "button" 
         << "\033[0m" << ">" << endl << endl;
    

    return 0;
}