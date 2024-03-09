#include <iostream>
#include "Music.h"
#include "Subscription.h"
#include <vector>

int main() {

    /*vector <Music_Pop> a;
    a.push_back(Music_Pop());
    a[0].Print();*/

    Subscription sub("VIP", 1000, 30, "All features available");
    sub.Print();


    return 0;
}
