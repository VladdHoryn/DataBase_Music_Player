#include <iostream>
#include "Music.h"
#include "Subscription.h"
#include "User.h"
#include "Music.cpp"
#include "Subscription.cpp"
#include "User.cpp"
#include <vector>
#include <fstream>
#include <memory>

template <typename T>
vector<T> Read(vector<T> array, string name_of_file) {
    ifstream file(name_of_file);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
    }
    array.clear();

    if(name_of_file == "Music_Pop.txt") {
        string name, author, genre;
        double longing;
        while (file >> name >> author >> longing >> genre) {
            array.push_back(Music_Pop(forward<string>(name), forward<string>(author), forward<int>(longing),
                                      forward<string>(genre)));
        }
    }
    
    file.close();
    return array;
}

template <typename T>
void Write(vector<T> array, string name_of_file) {
    ofstream file(name_of_file);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
    }

    for (auto &i: array) {
        i.Print();
    }

    file.close();
}

int main() {
    vector<Music_Pop> array;
    string name_of_file = "Music_Pop.txt";
    array = Read(array, name_of_file);
    Write(array, name_of_file);

    return 0;
}
