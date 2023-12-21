//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef DATASTRUCTURES_CPP_GRAPH_H
#define DATASTRUCTURES_CPP_GRAPH_H


#include "AbstractGraph.h"
#include <string>
#include <vector>

namespace array{
    class Graph : public AbstractGraph{
    private:
        int** edges;
        std::vector<std::string> words;
    public:
        explicit Graph(int vertexCount);
        ~Graph();
        void addWord(const std::string& word);
        void addEdge(int from, int to);
        void addEdge(int from, int to, int weight);
        Path* dijkstra(int source);

    protected:
        void breadthFirstSearch(bool* visited, int startNode) override;

    };

}


#endif //DATASTRUCTURES_CPP_GRAPH_H
