//
// Created by co034504 on 12/21/2023.
//
// Your First C++ Program

#include <iostream>
#include "DictionaryReader.h"

int main() {
    std::string filename = "C:\\Users\\TEMP\\Desktop\\turkish_dictionary.txt";
    DictionaryReader reader(filename);
    std::string start,end;
    std::cout << "Enter starting word: ";
    std::getline(std::cin,start);
    std::cout << "Enter destination word: ";
    std::getline(std::cin,end);
    reader.readDictionaryToGraph(start,end);
    return 0;
}