#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "weighted_graph.h"

using namespace std;

struct Edge 
{
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

bool CompareEdges(const Edge& a, const Edge& b) 
{
    return a.weight < b.weight;
}

vector<Edge> KruskalAlgoritmUtil(const WeightedGraph& graph) 
{
    int num_vertices = graph.GetNumVertices();
    const auto& adj_lists = graph.GetAdjLists();
    vector<Edge> edges;

    for (int src = 0; src < num_vertices; src++) 
    {
        for (const auto& edge : adj_lists[src]) 
        {
            int dest = edge.first;
            int weight = edge.second;

            edges.push_back(Edge(src, dest, weight));
        }
    }

    sort(edges.begin(), edges.end(), CompareEdges);

    vector<Edge> mst;
    vector<int> parent(num_vertices);

    for (int i = 0; i < num_vertices; i++) 
    {
        parent[i] = i;
    }

    for (const Edge& edge : edges) 
    {
        int src_root = parent[edge.src];
        int dest_root = parent[edge.dest];

        if (src_root != dest_root) 
        {
            mst.push_back(edge);

            for (int i = 0; i < num_vertices; i++) 
            {
                if (parent[i] == dest_root) 
                {
                    parent[i] = src_root;
                }
            }
        }
    }

    return mst;
}

void KruskalAlgorithm(const WeightedGraph& graph)
{
    vector<Edge> mst = KruskalAlgoritmUtil(graph);

    cout << "Minimum Spanning Tree:\n";

    for (const Edge& edge : mst) 
    {
        cout << "(" << edge.src << " - " << edge.dest << "), Weight: " << edge.weight << endl;
    }
}