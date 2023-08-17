#include <iostream>
#include <vector>
#include <limits>

#include "weighted_graph.h"

using namespace std;

const int INF = numeric_limits<int>::max();

void FloydWarshallAlgorithm(const WeightedGraph& graph) 
{
    int num_vertices = graph.GetNumVertices();
    vector<vector<pair<int, int>>> adjLists = graph.GetAdjLists();

    vector<vector<int>> dist(num_vertices, vector<int>(num_vertices, INF));

    for (int i = 0; i < num_vertices; i++) 
    {
        dist[i][i] = 0;

        for (const auto& edge : adjLists[i]) 
        {
            dist[i][edge.first] = edge.second;
        }
    }

    for (int k = 0; k < num_vertices; k++) 
    {
        for (int i = 0; i < num_vertices; i++) 
        {
            for (int j = 0; j < num_vertices; j++) 
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) 
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < num_vertices; i++) 
    {
        for (int j = 0; j < num_vertices; j++) 
        {
            if (dist[i][j] == INF) 
            {
                cout << "INF ";
            } 
            
            else 
            {
                cout << dist[i][j] << " ";
            }
        }
        
        cout << endl;
    }
}