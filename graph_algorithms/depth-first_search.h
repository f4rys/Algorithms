#include <iostream>
#include <vector>

#include "undirected_graph.h"

using namespace std;

void DepthFirstSearchUtil(const UndirectedGraph& graph, int start_vertex, vector<bool>& visited) 
{
    visited[start_vertex] = true;
    cout << start_vertex << " ";

    for (int neighbor : graph.GetAdjacentVertices(start_vertex)) 
    {
        if (!visited[neighbor]) 
        {
            DepthFirstSearchUtil(graph, neighbor, visited);
        }
    }
}

void DepthFirstSearch(const UndirectedGraph& graph) 
{
    vector<bool> visited(graph.GetNumVertices(), false);

    for (int i = 0; i < graph.GetNumVertices(); i++) 
    {
        if (!visited[i]) 
        {
            DepthFirstSearchUtil(graph, i, visited);
        }
    }
    
    cout << endl;
}