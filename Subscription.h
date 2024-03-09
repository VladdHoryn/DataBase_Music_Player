#ifndef DATABASE_MUSIC_PLAYER_SUBSCRIPTION_H
#define DATABASE_MUSIC_PLAYER_SUBSCRIPTION_H
#include <string>

using namespace std;

class Subscription {
protected:
    string *name;
    int *price;
    int *longing;
    string *features;
public:
    Subscription();
    Subscription(string &&new_name, int &&new_price, int &&new_longing, string &&new_features);
    ~Subscription();
    void New_name(string &&new_name);
    void New_price(int &&new_price);
    void New_longing(int &&new_longing);
    void New_features(string &&new_features);
    void Print();
    Subscription(const Subscription &other);
    Subscription(Subscription &&other) noexcept;
};


#endif //DATABASE_MUSIC_PLAYER_SUBSCRIPTION_H
