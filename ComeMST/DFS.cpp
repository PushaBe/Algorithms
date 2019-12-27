#include <vector>
typedef std::vector<std::vector<double>> Graph;
void DFS_(int u, Graph g, std::vector<bool>& visited, std::vector<int>& visited_seq) {
    visited[u] = true;
    visited_seq.push_back(u);
    for (int i = 0; i < g[u].size(); i++) {
        if (g[u][i] == -1) continue;
        if (!visited[i]) {
            DFS_(i, g, visited, visited_seq);
        }
    }
}

std::vector<int> DFS(const Graph& g, int V) {
    std::vector<int> visited_seq;
    std::vector<bool> visited(V, false);
    for (int u = 0; u < V; u++) {
        if (!visited[u])
            DFS_(u, g, visited, visited_seq);
    }
    visited_seq.push_back(0);
    return visited_seq;
}
