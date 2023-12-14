//
// Created by co034504 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_NAZLI_OZBEK_GRAPH_H
#define GRAPH_PUZZLE_GAME_NAZLI_OZBEK_GRAPH_H

namespace array{
    class Graph : public AbstractGraph{
    private:
        int** edges;
    public:
        explicit Graph(int vertexCount);
        ~Graph();
        void addEdge(int from, int to);
        void addEdge(int from, int to, int weight);

};


#endif //GRAPH_PUZZLE_GAME_NAZLI_OZBEK_GRAPH_H
