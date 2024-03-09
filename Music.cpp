#include "Music.h"
#include <string>

using namespace std;

Music::Music() :
    name{new std::string("Unknown")}, autor{new std::string("Unknown")}, longing{new int(0)} {};
Music::Music(std::string &&new_name, std::string &&new_author, int &&new_longing) :
    name{new string(new_name)}, autor{new string(new_author)}, longing{new int(new_longing)} {};
void Music::New_name(std::string &&new_name) {
    *name = new_name;
}
void Music::New_author(std::string &&new_author) {
    *autor = new_author;
}

void Music::New_longing(int &&new_longing) {
    *longing = new_longing;
}

Music::Music(const Music &other) {
    name = new string;
    *name = *other.name;
    autor = new string;
    *autor = *other.autor;
    longing = new int;
    *longing = *other.longing;
    cout << "Deep copy constryctor Music was called" << endl;
}

Music::Music(Music &&other) noexcept : name{other.name}, autor{other.autor}, longing{other.longing}{
    other.name = nullptr;
    other.autor = nullptr;
    other.longing = nullptr;
    cout << "Music move constructor was called" << endl;
}
//-------------------------------------

Music_Pop::Music_Pop()
: Music(), genre{new string("Unknown")} {cout << "Music_Pop constructor was called" << endl;}
Music_Pop::Music_Pop(std::string &&new_name, std::string &&new_author, int &&new_longing, string &&new_genre)
: Music(forward<string>(new_name), forward<string>(new_author), forward<int>(new_longing)), genre{new string(new_genre)} {cout << "Music_Pop constructor was called" << endl;}

void Music_Pop::Play_Music() {
    cout << "Easy, calm pop music is played" << endl;
}
void Music_Pop::Print() {
    cout << "Name: " << *name << endl
    << "Author: " << *autor << endl
    << "Longing: " << *longing << endl
    << "Genre: " << *genre << endl;
}

void Music_Pop::New_genre(std::string &&new_genre) {
    *genre = new_genre;
}

Music_Pop::Music_Pop(const Music_Pop &other) : Music(other){
    genre = new string;
    *genre = *other.genre;
    /*name = new string;
    *name = *other.name;
    autor = new string;
    *autor = *other.autor;
    longing = new int;
    *longing = *other.longing;*/
    cout << "Deep copy constryctor Music_Pop was called" << endl;
}
Music_Pop::Music_Pop(Music_Pop &&other) noexcept
: Music(other), genre{other.genre}{
    other.genre = nullptr;
    cout << "Music_Pop move constructor was called" << endl;

}
