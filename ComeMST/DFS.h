#ifndef COMEMST_DFS_H
#define COMEMST_DFS_H
#include <vector>

typedef std::vector<std::vector<double>> Graph;

void DFSUtil(int u, Graph adj, std::vector<bool>& visited, std::vector<int>& visited_seq);
std::vector<int> DFS(const Graph& adj, int V);

#endif //COMEMST_DFS_H
