#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#include <queue>
#include <stack>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class UndirectedGraph {
  private:
    std::unordered_map<int, std::unordered_set<int>> adjList;

  public:
    void addVertex(int vertex);
    void addEdge(int vertex1, int vertex2);
    void removeEdge(int vertex1, int vertex2);
    bool hasEdge(int vertex1, int vertex2) const;
    std::vector<int> getNeighbors(int vertex) const;
    void removeVertex(int vertex);
    int vertexCount() const;
    int edgeCount() const;

    // Breadth-First Search starting from a given vertex
    std::vector<int> bfs(int startVertex) const;

    // Depth-First Search starting from a given vertex
    std::vector<int> dfs(int startVertex) const;

    // Detect if there’s a cycle in the graph
    bool hasCycle() const;
};

#endif // UNDIRECTED_GRAPH_H
