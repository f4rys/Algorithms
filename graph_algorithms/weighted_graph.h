#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

class WeightedGraph {
    int num_vertices;
    vector<vector<pair<int, int>>> adj_lists;

public:
    WeightedGraph(int vertices) 
    {
        num_vertices = vertices;
        adj_lists.resize(vertices);
    }

    void AddEdge(int src, int dest, int weight) 
    {
        adj_lists[src].push_back(make_pair(dest, weight));
        adj_lists[dest].push_back(make_pair(src, weight));
    }

    void PrintGraph() {
        for (int i = 0; i < num_vertices; i++) 
        {
            cout << "Vertex " << i << ": ";

            for (const auto& edge : adj_lists[i]) 
            {
                cout << "(" << edge.first << ", " << edge.second << ") ";
            }

            cout << endl;
        }
    }

    int GetNumVertices() const 
    {
        return num_vertices;
    }

    const vector<vector<pair<int, int>>>& GetAdjLists() const 
    {
        return adj_lists;
    }
};

#endif