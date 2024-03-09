#include <iostream>
#include "Music.h"
#include "Subscription.h"
#include "User.h"
#include <vector>

int main() {


    PremiumUser preamUser("Vlad", "I_am_I", "uzerok88@gmail.com", 9, 3, 2024, "VIP", 1000, 30, "All features available", 1);
    preamUser.Print();
    User *user = new PremiumUser();
    user->Print();



    return 0;
}
