#ifndef COMEMST_MSTKRUSKAL_H
#define COMEMST_MSTKRUSKAL_H

#include <vector>
typedef std::pair<double, double> Point;
typedef std::pair<std::pair<int, int>, double> Edge;
typedef std::vector<std::vector<double>> Graph;

Graph mstKruskal(std::vector<Edge> graph_edges, int n_vertex);

#endif //COMEMST_MSTKRUSKAL_H
