#include <vector>
#include <iostream>
typedef std::vector<std::vector<double>> Graph;
void DFSUtil(int u, Graph adj, std::vector<bool>& visited, std::vector<int>& visited_seq) {
    visited[u] = true;
    visited_seq.push_back(u);
//    std::cout << u << " ";
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == -1) continue;
        if (!visited[i]) {
            DFSUtil(i, adj, visited, visited_seq);
        }
    }
}

std::vector<int> DFS(const Graph& adj, int V) {
    std::vector<int> visited_seq;
//    visited_seq.push_back(0);
    std::vector<bool> visited(V, false);
    for (int u = 0; u < V; u++) {
//        std::cout << std::endl;
        if (!visited[u])
            DFSUtil(u, adj, visited, visited_seq);
    }
    visited_seq.push_back(0);
    return visited_seq;
}
