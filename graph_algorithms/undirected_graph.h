#include <iostream>
#include <vector>

using namespace std;

#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

class UndirectedGraph
{
    int num_vertices;
    vector<vector<int>> adj_lists;

public:
    UndirectedGraph(int vertices) : num_vertices(vertices), adj_lists(vertices) {}

    void AddEdge(const int& src, const int& dest) 
    {
        adj_lists[src].push_back(dest);
        adj_lists[dest].push_back(src);
    }

    void PrintGraph() const
    {
        for (const auto& adj_list : adj_lists)
        {
            cout << "Vertex " << (&adj_list - &adj_lists[0]) << ": ";

            for (const int& vertex : adj_list)
            {
                cout << vertex << " ";
            }
            
            cout << endl;
        }
    }

    int GetNumVertices() const 
    {
        return num_vertices;
    }

    const vector<int>& GetAdjacentVertices(int vertex) const 
    {
        return adj_lists[vertex];
    }
};

#endif