//
// Created by co034504 on 12/21/2023.
//

#include "DictionaryReader.h"
#include "DictionaryReader.h"
#include <string>
#include <vector>
#include "Graph.h"
#include <fstream>


DictionaryReader :: DictionaryReader(const std::string filename) : dictionaryFileName(filename){}

int DictionaryReader::countLetters(const std::string word){
    int count = 0;
    for(char letter:word){
        if(letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z'){
            count ++;
        } else if(letter >= -128 && letter <= -97){
            count++;
        }
    }
    return count;
}

void DictionaryReader :: readDictionaryToGraph(){
    std::ifstream file(dictionaryFileName);
    if(file.is_open()){
        std:: string word;
        int letter3count = 0;
        int letter4count = 0;
        int letter5count = 0;
        while(file >> word) {
            if (countLetters(word) == 3) {
                letter3count++;
                g3WordList.push_back(word);
            }
            if (countLetters(word) == 4) {
                letter4count++;
                g4WordList.push_back(word);
            }
            if (countLetters(word) == 5) {
                letter5count++;
                g5WordList.push_back(word);
            }
        }
        file.close();
        array::Graph g3(letter3count);
        array::Graph g4(letter4count);
        array::Graph g5(letter5count);

        for(std::string word3 : g3WordList){
            g3.addWord(word3);
        }
        for(std::string word4 : g4WordList){
            g4.addWord(word4);
        }
        for(std::string word5 : g5WordList){
            g5.addWord(word5);
        }
    } else{

    }
}