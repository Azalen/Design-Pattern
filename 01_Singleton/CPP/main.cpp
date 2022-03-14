#include "singleton.h"
#include <iostream>

using namespace std;

int main(){

    Singleton * s = Singleton::Instance();
    Singleton * t = Singleton::Instance();

    cout << s << " | " << t << endl;
    cout << boolalpha << (s == t) << endl;

    return 0;
}
