//
// Created by co034504 on 12/14/2023.
//

#include "DictionaryReader.h"
#include <string>
#include "Graph.h"
#include "fstream"


DictionaryReader :: DictionaryReader(const std::string filename) : dictionaryFileName(filename){}

int countLetters(std::string s){
    int Letters = 0;
    int i = 0;
    while(s[i] != nullptr){
            Letters++;
            i++;
        }
    }
    return Letters;
}

void DictionaryReader :: readDictionaryToGraph(Graph& graph){
    std:: ifstream file(dictionaryFileName)
    if(file.is_open()){
        std:: string word;
        while(file >> word){
            int letter3count = 0;
            int letter4count = 0;
            int letter5count = 0;
            if(countLetters(word) == 3){
                letter3count++;
            }
            if(countLetters(word) == 4){
                letter4count++;
            }
            if(countLetters(word) == 5){
                letter5count++;
            }
            Graph g3 = new Graph(letter3count);
            Graph g4 = new Graph(letter4count);
            Graph g5 = new Graph(letter5count);
        }
        file.close();
    } else{

    }
}
