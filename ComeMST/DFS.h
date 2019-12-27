#ifndef COMEMST_DFS_H
#define COMEMST_DFS_H
#include <vector>

typedef std::vector<std::vector<double>> Graph;

void DFS_(int u, Graph g, std::vector<bool>& visited, std::vector<int>& visited_seq);
std::vector<int> DFS(const Graph& g, int V);

#endif //COMEMST_DFS_H
