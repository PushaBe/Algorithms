#include <vector>
typedef std::vector<std::vector<double>> Graph;

std::vector<bool> visited;
std::vector<int> visited_seq;
void dfs(const int u, const Graph& g) {
    visited[u] = true;
    for (int v = 0; v < static_cast<int>(g.size()); ++v) {
        if (!visited[v]) {
            visited_seq.push_back(v);
            dfs(v, g);
        }
    }
}

std::vector<int> Maindfs(const Graph& g) {
    visited_seq.clear();
    visited.assign(g.size(), false);
    visited_seq.push_back(0);
    for (int i = 0; i < static_cast<int>(g.size()); i++) {
        if (!visited[i]) {
            dfs(i, g);
        }
    }
    visited_seq.push_back(0);
//    std::cout << "visited_seq:";
//    for (int i = 0; i < static_cast<int>(visited_seq.size()); ++i) {
//        std::cout << visited_seq[i] << "-";
//    }
//    std::cout << std::endl;
    return visited_seq;
}