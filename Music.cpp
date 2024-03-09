#include "Music.h"
#include <string>

using namespace std;

Music::Music() :
    name{new std::string("Unknown")}, autor{new std::string("Unknown")}, longin{0} {};
Music::Music(std::string *new_name, std::string *new_author, int *new_longing) :
    name{new_name}, autor{new_author}, longin{new_longing} {};
void Music::New_name(std::string &&new_name) {
    *name = new_name;
}
void Music::New_author(std::string &&new_author) {
    *autor = new_author;
}

void Music::New_longing(int &new_longing) {
    *longin = new_longing;
}
//-------------------------------------
Music_Pop::Music_Pop()
: Music(){cout << "Music_Pop constructor was called" << endl;}
Music_Pop::Music_Pop(std::string *new_name, std::string *new_author, int *new_longing)
: Music(new_name, new_author, new_longing){cout << "Music_Pop constructor was called" << endl;}
void Music_Pop::Play_Music() {
    cout << "Easy, calm pop music is played" << endl;
}
