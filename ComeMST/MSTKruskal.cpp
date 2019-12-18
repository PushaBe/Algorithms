//
// Created by xiaomi on 17.12.2019.
//

#include "MSTKruskal.h"
#include "DSU.h"
#include <algorithm>
#include <iostream>
#include <vector>
typedef std::pair<double, double> Point;
typedef std::pair<std::pair<int, int>, double> Edge;
//typedef std::pair<std::vector<std::vector<std::pair<int, double>>>, double> mstWithWeight;
typedef std::vector<std::vector<double>> Graph;

Graph mstKruskal(std::vector<Edge> graph_edges, int n_vertex) {
    double mst_weight = 0;
    Graph mst_graph(n_vertex, std::vector<double>(n_vertex, -1));
    sort(graph_edges.begin(), graph_edges.end());
    DSU dsu(n_vertex);
    for (auto x: graph_edges) {
        int u = x.first.first;
        int v = x.first.second;

        int set_u = dsu.find(u);
        int set_v = dsu.find(v);

        if (set_u != set_v) {
            mst_weight += x.second;
//            std::cout << u << " - " << v << std::endl;
            mst_graph[u][v] = x.second;
            mst_graph[v][u] = x.second;
            dsu.merge(set_u, set_v);
        }
    }
    return mst_graph;
}
