//
// Created by co034504 on 1/4/2024.
//

#ifndef DATASTRUCTURES_CPP_EDGE_H
#define DATASTRUCTURES_CPP_EDGE_H


class Edge {
private:
    int from;
    int to;
    int weight;
    Edge* next;
public:
    Edge();
    Edge(int from, int to, int weight);
    void setNext(Edge* _next);
    Edge* getNext() const;
    int getFrom() const;
    int getTo() const;
    int getWeight() const;
};


#endif //DATASTRUCTURES_CPP_EDGE_H
