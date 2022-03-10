#include "subjekt.h"

// konkretes Subjekt - hier eine Nachricht (string)
class konkreterBeobachter : public Beobachter {
    private:
        konkretesSubjekt * subjekt;
        string beobachteterZustand = "";

    public:
        konkreterBeobachter(konkretesSubjekt * subjekt){
            konkreterBeobachter::subjekt = subjekt;
            subjekt->meldeAn(this);
            beobachteterZustand = konkreterBeobachter::beobachteterZustand = subjekt->gibZustand();
            cout << "Das Subjekt wird nun beobachtet." << endl;
            cout << "aktueller Zustand : " << beobachteterZustand << endl << endl;
        }
        virtual ~konkreterBeobachter(){};

        void aktualisieren(Subjekt * veraendertesSubjekt){
            konkreterBeobachter::beobachteterZustand = subjekt->gibZustand();
            cout << "Der Zustand des Subjekts hat sich geändert. Der konkrete Beobachter wurde aktualisiert." << endl;
            cout << "aktueller Zustand : " << beobachteterZustand << endl << endl;
        }

    
};