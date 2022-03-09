#include "konkreterBeobachter.h"

int main(){

    cout << endl;
    cout << "   ======================" << endl;
    cout << "   || OBSERVER PATTERN ||" << endl;
    cout << "   ======================" << endl;
    cout << endl;

    // BEOBACHTBARES SUBJEKT ERSTELLEN
    konkretesSubjekt * s = new konkretesSubjekt();
    cout << "Konkretes Subjekt erstellt in : " << s->gibZustand() << endl << endl;


    cout << "Subscription-Log" << endl;
    cout << "----------------" << endl;
    // SUBSCRIPTION
    konkreterBeobachter * b = new konkreterBeobachter(s);
    
    s->setzeZustand("next state");
    s->setzeZustand("another state");


    // Speicherplatz freigeben
    delete b;
    delete s;

    return 0;
}