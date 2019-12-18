#ifndef COMEMST_DFS_H
#define COMEMST_DFS_H
#include <vector>

typedef std::vector<std::vector<double>> Graph;

void dfs(int u, const Graph& g);
std::vector<int> Maindfs(const Graph& g);


#endif //COMEMST_DFS_H
