//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#include "Graph.h"
#include "Queue.h"
#include "Heap.h"
#include "MinHeap.h"
#include <string>
#include <vector>



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

    Path *Graph::dijkstra(int source) {
        Path *shortestPaths = initializePaths(source);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++) {
            heap.insert(HeapNode(shortestPaths[i].getDistance(), i));
        }
        while (!heap.isEmpty()) {
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                if (newDistance < shortestPaths[toNode].getDistance()) {
                    int position = heap.search(toNode);
                    heap.update(position, newDistance);
                    shortestPaths[toNode].setDistance(newDistance);
                    shortestPaths[toNode].setPrevious(fromNode);
                }
            }
        }
        return shortestPaths;
    }
}


