#include "Subscription.h"
#include <string>
#include <iostream>

using namespace std;

Subscription::Subscription()
: name{new string("Unknown")}, price{new int(0)}, longing{new int(0)}, features{new string("None")}{}
Subscription::Subscription(std::string &&new_name, int &&new_price, int &&new_longing, std::string &&new_features)
: name{new string(new_name)}, price{new int(new_price)}, longing{new int(new_longing)}, features{new string(new_features)}{
    //cout << "Subscription consructor was called" << endl;
}
Subscription::~Subscription(){
    //cout << "Subscription destructor was called" << endl;
}

void Subscription::New_name(std::string &&new_name) {
    *name = new_name;
}
void Subscription::New_price(int &&new_price) {
    *price = new_price;
}

void Subscription::New_longing(int &&new_longing) {
    *longing = new_longing;
}
void Subscription::New_features(std::string &&new_features) {
    *features = new_features;
}

void Subscription::Print() {
    cout << "Name: " << *name << endl
         << "Price: " << *price << " $" << endl
         << "Longing: " << *longing << " days" << endl
         << "Features: " << *features << endl;
}

Subscription::Subscription(const Subscription &other) {
    name = make_shared<string>(*other.name);
    *name = *other.name;
    price = make_shared<int>(*other.price);
    *price = *other.price;
    longing = make_shared<int>(*other.longing);
    *longing = *other.longing;
    features = make_shared<string>(*other.features);
    *features = *other.features;
    //cout << "Deep copy constryctor Subscription was called" << endl;
}
Subscription::Subscription(Subscription &&other) noexcept
: name{other.name}, price{other.price}, longing{other.longing}, features{other.features}{
    other.name = nullptr;
    other.price = nullptr;
    other.longing = nullptr;
    other.features = nullptr;
    //cout << "Subscription move constructor was called" << endl;
}

istream &operator >>(istream &is, Subscription &obj)
{
    is >> *obj.name >> *obj.price >> *obj.longing >> *obj.features;
    return is;
}
ostream &operator <<(ostream &os, Subscription &obj)
{
    os << *obj.name << " " << *obj.price << " " << *obj.longing << " " << *obj.features << endl;
    return os;
}

istream &operator >(istream &is, Subscription &obj)
{
    cout << "Enter name: ";
    is >> *obj.name;
    cout << "Enter price: ";
    is >> *obj.price;
    cout << "Enter longing: ";
    is >> *obj.longing;
    cout << "Enter features: ";
    is >> *obj.features;
    return is;
}

Subscription Subscription::operator=(Subscription &obj) {
    if(this != &obj)
    {
        name = obj.name;
        price = obj.price;
        longing = obj.longing;
        features = obj.features;
    }
    return *this;
}