#include <gtest/gtest.h>
#include "../src/Graph.h"

// Test adding vertices and checking vertex count
TEST(UndirectedGraphTest, AddVertex) {
    UndirectedGraph graph;
    graph.addVertex(1);
    graph.addVertex(2);

    EXPECT_EQ(graph.vertexCount(), 2);
}

// Test adding edges and checking edge count
TEST(UndirectedGraphTest, AddEdge) {
    UndirectedGraph graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(1, 2);

    EXPECT_TRUE(graph.hasEdge(1, 2));
    EXPECT_TRUE(graph.hasEdge(2, 1));
    EXPECT_EQ(graph.edgeCount(), 1);
}

// Test removing edges
TEST(UndirectedGraphTest, RemoveEdge) {
    UndirectedGraph graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(1, 2);
    graph.removeEdge(1, 2);

    EXPECT_FALSE(graph.hasEdge(1, 2));
    EXPECT_FALSE(graph.hasEdge(2, 1));
    EXPECT_EQ(graph.edgeCount(), 0);
}

// Test Breadth-First Search
TEST(UndirectedGraphTest, BFS) {
    UndirectedGraph graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    std::vector<int> bfsOrder = graph.bfs(1);
    std::vector<int> expectedOrder = {1, 2, 3, 4};
    EXPECT_EQ(bfsOrder, expectedOrder);
}

// Test Depth-First Search
TEST(UndirectedGraphTest, DFS) {
    UndirectedGraph graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    std::vector<int> dfsOrder = graph.dfs(1);
    std::vector<int> expectedOrder = {1, 2, 4, 3};
    EXPECT_EQ(dfsOrder, expectedOrder);
}

// Test cycle detection in a cyclic graph
TEST(UndirectedGraphTest, DetectCycleInCyclicGraph) {
    UndirectedGraph graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    EXPECT_TRUE(graph.hasCycle());
}

// Test cycle detection in an acyclic graph
TEST(UndirectedGraphTest, DetectCycleInAcyclicGraph) {
    UndirectedGraph graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    EXPECT_FALSE(graph.hasCycle());
}

// Edge cases: Test adding an edge with a non-existent vertex
TEST(UndirectedGraphTest, AddEdgeWithNonExistentVertex) {
    UndirectedGraph graph;
    graph.addVertex(1);
    EXPECT_THROW(graph.addEdge(1, 2), std::out_of_range);
}

// Edge cases: Test removing an edge with a non-existent vertex
TEST(UndirectedGraphTest, RemoveEdgeWithNonExistentVertex) {
    UndirectedGraph graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(1, 2);

    EXPECT_NO_THROW(graph.removeEdge(1, 3));
    EXPECT_NO_THROW(graph.removeEdge(3, 4));
}

// Edge cases: Test checking for an edge with non-existent vertices
TEST(UndirectedGraphTest, HasEdgeWithNonExistentVertex) {
    UndirectedGraph graph;
    graph.addVertex(1);
    EXPECT_FALSE(graph.hasEdge(1, 2));
    EXPECT_FALSE(graph.hasEdge(2, 3));
}

// Edge cases: Test getting neighbors for a non-existent vertex
TEST(UndirectedGraphTest, GetNeighborsForNonExistentVertex) {
    UndirectedGraph graph;
    graph.addVertex(1);
    EXPECT_THROW(graph.getNeighbors(2), std::out_of_range);
}

// Edge cases: Test removing a non-existent vertex
TEST(UndirectedGraphTest, RemoveNonExistentVertex) {
    UndirectedGraph graph;
    graph.addVertex(1);
    EXPECT_NO_THROW(graph.removeVertex(2));
    EXPECT_EQ(graph.vertexCount(), 1);
}

// Edge cases: Test edge count with non-existent vertices
TEST(UndirectedGraphTest, EdgeCountWithNonExistentVertices) {
    UndirectedGraph graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(1, 2);

    EXPECT_EQ(graph.edgeCount(), 1);
    graph.removeEdge(1, 3);
    graph.removeEdge(3, 4);
    EXPECT_EQ(graph.edgeCount(), 1);
}
