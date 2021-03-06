#include <iostream>

using namespace std;

class KonkreterButton {
    public:
        virtual void render() {
            cout << "<button type='submit' class='btn ";
        }
};

class ButtonPrimary : public KonkreterButton {
    public:
        void render() {
            KonkreterButton::render();
            renderPrimary();
        }
    protected:
        void renderPrimary() {
            cout << "btn-primary ";
        }
};

class ButtonSecondary : public KonkreterButton {
    public:
        void render() {
            KonkreterButton::render();
            renderSecondary();
        }
    protected:
        void renderSecondary() {
            cout << "btn-secondary ";
        }
};

class ButtonLarge : public KonkreterButton {
    public:
        void render() {
            KonkreterButton::render();
            renderLarge();
        }
    protected:
        void renderLarge() {
            cout << "btn-lg ";
        }
};

class ButtonSmall : public KonkreterButton {
    public:
        void render() {
            KonkreterButton::render();
            renderSmall();
        }
    protected:
        void renderSmall() {
            cout << "btn-sm ";
        }
};

class ButtonPrimaryLarge : public ButtonPrimary, public ButtonLarge {
    public:
        void render() {
            ButtonPrimary::render();
            ButtonLarge::renderLarge();
        }
};

/**     ANZAHL NÖTIGER KLASSEN FÜR ALLE KOMBINATIONEN 
 *      -> Ziehen ohne zurücklegen ohne Reihenfolge
 * 
 *      n = 1   0 + A                                                           =  2
 *      n = 2   0 + A B + AB                                                    =  4
 *      n = 3   0 + A B C + AB AC BC + ABC                                      =  8
 *      n = 4   0 + A B C D + AB AC AD + BC BD CD + ABC ABD ACD BCD + ABCD      = 16
 *  
 *          => 2^n viele Klassen um alle Kombinationen abzudecken
 *             (und noch mehr, falls Reihenfolge entscheidend wäre)
 * */

int main(){
    ButtonPrimaryLarge bpl;
    cout << endl;
    bpl.render(); 
    cout << "'></button>" << endl << endl;
}
