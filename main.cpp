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
vector<T> loadMenuFromFile(vector<T> array, string name_of_file) {
    ifstream file(name_of_file);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
    }
    array.clear();

    if(name_of_file == "text.txt") {
        string name, author, genre;
        double longing;
        while (file >> name >> author >> longing >> genre) {
            array.push_back(Music_Pop(forward<string>(name), forward<string>(author), forward<int>(longing),
                                      forward<string>(genre)));
        }
    }

    return array;
}

int main() {
    vector<Music_Pop> array;
    string name_of_file = "text.txt";
    array = loadMenuFromFile(array, name_of_file);
    for (auto &i: array) {
        i.Print();
    }
    array[0].Print();
    return 0;
}
