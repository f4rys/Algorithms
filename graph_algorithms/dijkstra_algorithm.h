#include <iostream>
#include <limits>
#include <queue>

#include "weighted_graph.h"

using namespace std;

vector<int> ShortestPath(const WeightedGraph& graph, int source) 
{
    int num_vertices = graph.GetNumVertices();
    const vector<vector<pair<int, int>>>& adj_lists = graph.GetAdjLists();

    vector<int> distance(num_vertices, numeric_limits<int>::max());
    distance[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : adj_lists[u]) 
        {
            int v = edge.first;
            int weight = edge.second;

            if (distance[u] + weight < distance[v]) 
            {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    return distance;
}

void DijkstraAlgorithm(WeightedGraph& graph){

    int source = 0;
    vector<int> shortest_distances = ShortestPath(graph, source);

    cout << "Shortest distances from vertex " << source << ":" << endl;

    for (int i = 0; i < graph.GetNumVertices(); i++) 
    {
        cout << "Vertex " << i << ": " << shortest_distances[i] << endl;
    }

}