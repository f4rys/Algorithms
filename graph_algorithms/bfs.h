#include <iostream>
#include <vector>
#include <queue>

#include "undirected_graph.h"

using namespace std;

void BFS(const UndirectedGraph& graph) 
{
    int num_vertices = graph.GetNumVertices();
    vector<bool> visited(num_vertices, false);

    for (int start_vertex = 0; start_vertex < num_vertices; start_vertex++) 
    {
        if (!visited[start_vertex]) 
        {
            queue<int> q;
            q.push(start_vertex);
            visited[start_vertex] = true;

            while (!q.empty()) 
            {
                int current_vertex = q.front();
                q.pop();
                cout << current_vertex << " ";

                for (int neighbor : graph.GetAdjacentVertices(current_vertex)) 
                {
                    if (!visited[neighbor]) 
                    {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
    }

    cout << endl;
}