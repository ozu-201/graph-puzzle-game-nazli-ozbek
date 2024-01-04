//
// Created by co034504 on 12/21/2023.
//

#ifndef DATASTRUCTURES_CPP_DICTIONARYREADER_H
#define DATASTRUCTURES_CPP_DICTIONARYREADER_H

#include "Graph.h"
#include <string>
#include <vector>
#include "fstream"

class DictionaryReader {
public:
    DictionaryReader(const std::string filename);
    void readDictionaryToGraph(const std::string &startWord,const std::string &endWord);
private:
    std::string dictionaryFileName;
    int countLetters(const std::string word);
    std::vector<std::string> g3WordList;
    std::vector<std::string> g4WordList;
    std::vector<std::string> g5WordList;
};


#endif //DATASTRUCTURES_CPP_DICTIONARYREADER_H
