#ifndef DATABASE_MUSIC_PLAYER_SUBSCRIPTION_H
#define DATABASE_MUSIC_PLAYER_SUBSCRIPTION_H
#include <string>
#include <memory>

using namespace std;

class Subscription {
public:
    shared_ptr<string> name = make_shared<string>();
    shared_ptr<int> price = make_shared<int>();
    shared_ptr<int> longing = make_shared<int>();
    shared_ptr<string> features = make_shared<string>();
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
    friend istream &operator >>(istream &is, Subscription &obj);
    friend ostream &operator <<(ostream &os, Subscription &obj);
    friend istream &operator >(istream &is, Subscription &obj);
    Subscription operator =(Subscription &obj);
};


#endif //DATABASE_MUSIC_PLAYER_SUBSCRIPTION_H
