//
// Created by co034504 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_NAZLI_OZBEK_DICTIONARYREADER_H
#define GRAPH_PUZZLE_GAME_NAZLI_OZBEK_DICTIONARYREADER_H
#include "Graph.h"
#include <string>

class DictionaryReader {
public:
    DictionaryReader :: DictionaryReader(const std::string filename);
    void DictionaryReader :: readDictionaryToGraph(Graph& graph):
private:
    std::string dictionaryFileName;
};


#endif //GRAPH_PUZZLE_GAME_NAZLI_OZBEK_DICTIONARYREADER_H
