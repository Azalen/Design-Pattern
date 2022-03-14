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
    protected:
        Button * component;
        Decorator(){
            this->component = nullptr;
        }
        virtual ~Decorator() {
            delete component;
        }

        virtual void render() {
            component->render();
        }
};

// Konkreter Dekorierer A
class ButtonPrimary : public Decorator {
    public:
        ButtonPrimary(Button * component) : Decorator() {
            Decorator::component = component;
        }

        void render() {
            Decorator::render();
            cout << "btn-primary ";
        }
};

int main() {

    system("clear");
    cout << endl;

    Button * bp = new ButtonPrimary(new KonkreterButton);
    bp->render();
    cout << ">" << endl << endl;

    return 0;
}