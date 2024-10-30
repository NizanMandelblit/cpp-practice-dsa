#include "Graph.h"
#include <algorithm>
#include <functional>
#include <stack>
#include <unordered_set>
#include <vector>

void
UndirectedGraph::addVertex(int vertex) {
    adjList[vertex] = std::unordered_set<int>(); // Initialize an empty set for the new vertex
}

void
UndirectedGraph::addEdge(int vertex1, int vertex2) {
    if (adjList.find(vertex1) == adjList.end() || adjList.find(vertex2) == adjList.end())
        throw std::out_of_range("");

    adjList[vertex1].insert(vertex2);
    adjList[vertex2].insert(vertex1);
}

void
UndirectedGraph::removeEdge(int vertex1, int vertex2) {
    if (adjList[vertex1].find(vertex2) != adjList[vertex1].end()) {
        adjList[vertex1].erase(vertex2);
        adjList[vertex2].erase(vertex1);
    }
}

bool
UndirectedGraph::hasEdge(int vertex1, int vertex2) const {
    // Due to function's `const` we can't use [] operator
    auto it = adjList.find(vertex1);
    return (it != adjList.end() && it->second.find(vertex2) != it->second.end());
}

std::vector<int>
UndirectedGraph::getNeighbors(int vertex) const {
    std::vector<int> neighbors;

    // Check if the vertex exists in the graph
    auto it = adjList.find(vertex);
    if (it != adjList.end()) {
        // Copy all neighbors from the unordered_set to the vector
        neighbors.assign(it->second.begin(), it->second.end());
    } else {
        throw std::out_of_range("vertex not exist");
    }

    return neighbors; // Return the vector of neighbors
}

void
UndirectedGraph::removeVertex(int vertex) {
    // First, remove the vertex from all adjacency lists of its neighbors
    for (auto &[key, neighbors] : adjList)
        neighbors.erase(vertex); // Remove `vertex` from each neighbor's adjacency list, if present

    // Now remove the vertex itself from the graph
    adjList.erase(vertex);
}

int
UndirectedGraph::vertexCount() const {
    return adjList.size();
}

struct hash_pair {
    template<class T1, class T2> std::size_t operator()(const std::pair<T1, T2> &p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1); // Combine the two hashes
    }
};

int
UndirectedGraph::edgeCount() const {
    // edges are stored as <u,v>
    std::unordered_set<std::pair<int, int>, hash_pair> edges;

    for (const auto &vertexKey : adjList) {
        int vertex = vertexKey.first;
        for (const auto &neighbor : vertexKey.second) {
            // Only add the edge if vertex < neighbor to avoid duplicates <v,u>
            if (vertex < neighbor)
                edges.emplace(vertex, neighbor);
        }
    }

    return edges.size();
}

// BFS method with sorted neighbors to ensure consistent order
std::vector<int>
UndirectedGraph::bfs(int startVertex) const {
    std::vector<int> result;         // To store the order of visited vertices
    std::unordered_set<int> visited; // To keep track of visited vertices
    std::queue<int> queue;           // Queue for BFS

    queue.push(startVertex);
    visited.insert(startVertex); // Mark the start vertex as visited

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        result.push_back(vertex); // Add the vertex to the result

        // Get the neighbors and sort them to enforce a consistent visit order
        auto it = adjList.find(vertex);
        if (it != adjList.end()) {
            std::vector<int> neighbors(it->second.begin(), it->second.end());
            std::sort(neighbors.begin(), neighbors.end()); // Sort neighbors in ascending order

            for (const auto &neighbor : neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.push(neighbor);
                    visited.insert(neighbor); // Mark neighbor as visited
                }
            }
        }
    }

    return result;
}

// Depth-First Search starting from a given vertex
std::vector<int>
UndirectedGraph::dfs(int startVertex) const {
    std::vector<int> result;         // To store the order of visited vertices
    std::unordered_set<int> visited; // To keep track of visited vertices
    std::stack<int> stack;           // Stack for DFS

    // Start DFS from the given start vertex
    stack.push(startVertex);

    while (!stack.empty()) {
        int vertex = stack.top();
        stack.pop();

        // If the vertex has not been visited yet
        if (visited.find(vertex) == visited.end()) {
            visited.insert(vertex);   // Mark the vertex as visited
            result.push_back(vertex); // Add it to the result

            // Add all unvisited neighbors to the stack
            auto it = adjList.find(vertex);
            if (it != adjList.end()) {
                for (const auto &neighbor : it->second) {
                    // if not visited - push to the stack
                    if (visited.find(neighbor) == visited.end())
                        stack.push(neighbor);
                }
            }
        }
    }
    return result;
}

// Detect if there’s a cycle in the UndirectedGraph
bool
UndirectedGraph::hasCycle() const {
    std::unordered_set<int> visited;

    // Helper function to perform DFS and detect cycles
    std::function<bool(int, int)> dfs = [&](int vertex, int parent) -> bool {
        visited.insert(vertex);

        // Iterate through all neighbors of the current vertex
        auto it = adjList.find(vertex);
        if (it != adjList.end()) {
            for (const auto &neighbor : it->second) {
                if (visited.find(neighbor) == visited.end()) {
                    // If neighbor hasn't been visited, recursively call dfs
                    if (dfs(neighbor, vertex))
                        return true;
                } else if (neighbor != parent) {
                    // If neighbor is visited and not the parent, a cycle is found
                    return true;
                }
            }
        }
        return false;
    };

    // Check all components of the graph
    for (const auto &pair : adjList) {
        int vertex = pair.first;
        if (visited.find(vertex) == visited.end()) {
            // Start DFS from each unvisited vertex
            if (dfs(vertex, -1))
                return true;
        }
    }

    return false;
}
