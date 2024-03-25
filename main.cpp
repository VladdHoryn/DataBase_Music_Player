#include <iostream>
#include "Music.h"
#include "Subscription.h"
#include "User.h"
#include <vector>

int main() {
    Music_Pop mus("Hello", "Andrue", 10, "Pop");
    mus.Print();
    Music_Pop music(mus);
    music.Print();
    mus.New_author("Vlad");
    music.Print();
    mus.Print();

    return 0;
}
