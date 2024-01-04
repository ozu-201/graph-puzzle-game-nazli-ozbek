//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#include "Graph.h"
#include "Queue.h"
#include "Heap.h"
#include "MinHeap.h"
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>



namespace array {

    Graph::Graph(int vertexCount) : AbstractGraph(vertexCount) {
        edges = new int *[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            edges[i] = new int[vertexCount];
        }
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                edges[i][j] = 0;
            }
        }
    }

    Graph::~Graph() {
        for (int i = 0; i < vertexCount; i++) {
            delete[] edges[i];
        }
        delete[] edges;
    }

    //this method is used to get the index of a given word
    int Graph::getIndex(const std::string &word){
        auto it = std::find(words.begin(),words.end(),word);
        if(it != words.end()){
            return std::distance(words.begin(),it);
        }
        return -1;
    }

    //this method is used to add a word to the graph,
    //it also adds an edge with the words which has one letter difference
    void Graph::addWord(const std::string &word) {
        words.push_back(word);
        int newWordIndex = words.size() - 1;
        for (int i = 0; i < newWordIndex; i++) {
            const std::string currentWord = words[i];
            if (word.size() != currentWord.size()) {
                continue;
            }
            int diffCount = 0;
            for (int j = 0; j < word.size(); j++) {
                if (word[j] != currentWord[j]) {
                    diffCount++;
                }
            }
            if (diffCount == 1) {
                addEdge(i, newWordIndex);
                addEdge(newWordIndex, i);
            }
        }

    }


    void Graph::addEdge(int from, int to) {
        edges[from][to] = 1;
    }

    void Graph::addEdge(int from, int to, int weight) {
        edges[from][to] = weight;
    }


    void Graph::breadthFirstSearch(bool *visited, int startNode) {
        int fromNode;
        Queue queue = Queue(100);
        queue.enqueue(Element(startNode));
        while (!queue.isEmpty()) {
            fromNode = queue.dequeue().getData();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                if (edges[fromNode][toNode] > 0) {
                    if (!visited[toNode]) {
                        visited[toNode] = true;
                        queue.enqueue(Element(toNode));
                    }
                }
            }
        }
    }
    void Graph::depthFirstSearch(bool *visited, int fromNode) {
        for (int toNode = 0; toNode < vertexCount; toNode++){
            if (edges[fromNode][toNode] > 0){
                if (!visited[toNode]){
                    visited[toNode] = true;
                    depthFirstSearch(visited, toNode);
                }
            }
        }
    }

    Edge *Graph::edgeList(int &edgeCount) {
        Edge* list;
        edgeCount = 0;
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                if (edges[i][j] > 0){
                    edgeCount++;
                }
            }
        }
        list = new Edge[edgeCount];
        int index = 0;
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                if (edges[i][j] > 0){
                    list[index] = Edge(i, j, edges[i][j]);
                    index++;
                }
            }
        }
        return list;
    }


    //this method is used to get the shortest path-using dijkstra's algorithm- and print that path between two words
    std::vector<std::string> Graph:: shortestPath(const std::string &startWord,const std::string &endWord){
        int source = getIndex(startWord);
        int destination = getIndex(endWord);
        if(source == -1 && destination == -1){
            std::cout << "Words not found in the graph!" <<std::endl;
            return { };
        }

        Path *shortestPaths = initializePaths(source);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++) {
            heap.insert(HeapNode(shortestPaths[i].getDistance(), i));
        }
        while (!heap.isEmpty()) {
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                if(edges[fromNode][toNode] > 0) {
                    int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                    if (newDistance < shortestPaths[toNode].getDistance()) {
                        int position = heap.search(toNode);
                        heap.update(position, newDistance);
                        shortestPaths[toNode].setDistance(newDistance);
                        shortestPaths[toNode].setPrevious(fromNode);
                    }
                }
            }
        }
        std::vector<std::string> pathWords;
        int currentVertex = destination;
        while(currentVertex != source){
            pathWords.push_back(words[currentVertex]);
            currentVertex = shortestPaths[currentVertex].getPrevious();
        }
        pathWords.push_back(words[source]);
        std::reverse(pathWords.begin(),pathWords.end());
        std::cout << "The path from " << startWord << " to " << endWord << " is:" << std::endl;
        for(const std::string &word : pathWords){
            std::cout << word << " ";
        }
        std::cout << std::endl;
        delete[] shortestPaths;
        return pathWords;
    }
}


