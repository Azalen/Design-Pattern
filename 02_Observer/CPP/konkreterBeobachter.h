#ifndef KONKRETER_BEOBACHTER_H
#define KONKRETER_BEOBACHTER_H

#include "konkretesSubjekt.h"

#include <iostream>

// konkretes Subjekt - hier eine Nachricht (string)
class konkreterBeobachter : public Beobachter {
    private:
        konkretesSubjekt * konkSubjekt = nullptr;
        string beobachteterZustand = "";

    public:
        konkreterBeobachter(konkretesSubjekt * subjekt) {
            konkSubjekt = subjekt;
            subjekt->meldeAn(this);
            beobachteterZustand = subjekt->gibZustand();
            cout << "Das Subjekt wird nun beobachtet." << endl;
            cout << "aktueller Zustand : " << beobachteterZustand << endl << endl;
        }
        virtual ~konkreterBeobachter(){};

        void aktualisieren(){
            beobachteterZustand = konkSubjekt->gibZustand();
            cout << "Der Zustand des Subjekts hat sich geändert. Der konkrete Beobachter wurde aktualisiert." << endl;
            cout << "aktueller Zustand : " << beobachteterZustand << endl << endl;
        }
};

#endif