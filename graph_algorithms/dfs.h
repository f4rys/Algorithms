#include <iostream>
#include <vector>

#include "undirected_graph.h"

using namespace std;

void DFSUtil(const UndirectedGraph& graph, int start_vertex, vector<bool>& visited) 
{
    visited[start_vertex] = true;
    cout << start_vertex << " ";

    for (int neighbor : graph.GetAdjacentVertices(start_vertex)) 
    {
        if (!visited[neighbor]) 
        {
            DFSUtil(graph, neighbor, visited);
        }
    }
}

void DFS(const UndirectedGraph& graph) 
{
    vector<bool> visited(graph.GetNumVertices(), false);

    for (int i = 0; i < graph.GetNumVertices(); i++) 
    {
        if (!visited[i]) 
        {
            DFSUtil(graph, i, visited);
        }
    }
    
    cout << endl;
}