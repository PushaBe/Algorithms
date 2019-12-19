//«Приближенное решение метрической неориентированной задачи коммивояжера».
// Найдите приближенное решение метрической неориентированной задачи коммивояжера
// в полном графе (на плоскости) с помощью минимального остовного дерева.
//Оцените качество приближения на случайном наборе точек, нормально распределенном на плоскости с дисперсией 1.
// Нормально распределенный набор точек получайте с помощью преобразования Бокса-Мюллера.
//При фиксированном N, количестве вершин графа, несколько раз запустите оценку качества приближения.
// Вычислите среднее значение и среднеквадратичное отклонение качества приближения для данного N.
//Запустите данный эксперимент для всех N в некотором диапазоне, например, [2, 10].
//Автоматизируйте запуск экспериментов.
//В решении требуется разумно разделить код на файлы. Каждому классу - свой заголовочный файл и файл с реализацией.



#include <iostream>
#include <vector>
#include "MSTKruskal.h"
#include "RandomGenerator.h"
#include "DFS.h"
#include <climits>
#include <algorithm>
#include <cmath>
typedef std::pair<double, double> Point;
typedef std::pair<std::pair<int, int>, double> Edge;
typedef std::pair<std::vector<std::vector<std::pair<int, double>>>, double> mstWithWeight;
typedef std::vector<std::vector<double>> Graph;


Graph reshapeGraph(const std::vector<Edge>& graph, const int n_vertex) {
    Graph new_graph(n_vertex, std::vector<double>(n_vertex, -1));
    for (auto x: graph) {
        int u = x.first.first;
        int v = x.first.second;
        double weight = x.second;
        new_graph[u][u] = 0;
        new_graph[v][v] = 0;
        new_graph[u][v] = weight;
        new_graph[v][u] = weight;
    }
    return new_graph;
}

void printGraph(Graph g, bool mst = false) {
    for (int i = 0; i < static_cast<int>(g.size()); ++i) {
        for (int j = 0; j < static_cast<int>(g[i].size()); ++j) {
            if (mst) {
                if (g[i][j] != -1) std::cout << i << "-" << j << " ";
            } else {
                std::cout << i << "-" << j << " ";
            }
        }
        std::cout << std::endl;
    }
}

void printGraphWeights(Graph g) {
    for (int i = 0; i < static_cast<int>(g.size()); ++i) {
        for (int j = 0; (j < static_cast<int>(g.size())); ++j) {
            std::cout << g[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double calcWeightTsp(const Graph& g, const Graph& mst) {
    std::vector<int> visited_seq = Maindfs(mst);
    double weightTSP = 0;
    for (int i = 0; i < static_cast<int>(visited_seq.size()) - 1; ++i) {
        weightTSP = weightTSP + g[visited_seq[i]][visited_seq[i+1]];
    }
    weightTSP += g[visited_seq[-1]][visited_seq[0]];
//    std::cout << weightTSP << std::endl;
    return weightTSP;
}

double calcWeightBest(const Graph& g, const int s) {
    std::vector<int> vertex;
    for (int i = 0; i < static_cast<int>(g.size()); i++)
        if (i != s)
            vertex.push_back(i);
    auto min_path = static_cast<double>(INT_MAX);
    do {
        double current_pathweight = 0;
        int k = s;
        for (int i : vertex) {
            current_pathweight += g[k][i];
            k = i;
        }
        current_pathweight += g[k][s];
        min_path = std::min(min_path, current_pathweight);
    } while (std::next_permutation(vertex.begin(), vertex.end()));
//    std::cout << min_path << std::endl;
//    std::cout << s << "-";
//    for (auto i: vertex){
//        std::cout << i << "-";
//    }
//    std::cout << s << "-";
//    std::cout << std::endl;
    return min_path;
}

double calcQualityMetric(const int n_points) {
    RandomGraphGenerator g(0., 1., n_points);
    std::vector<Edge> graph = g.GenerateGraph();
    Graph initialGraph = reshapeGraph(graph, g.n_points);
    Graph mst = mstKruskal(graph, n_points);
//    printGraph(initialGraph);
//    printGraphWeights(initialGraph);
//    printGraph(mst, true);
    double weightTSP = calcWeightTsp(initialGraph, mst);
    double weightBest = calcWeightBest(initialGraph, 0);
    double quality = weightTSP / weightBest;
    std::cout << "Quality:" << quality << std::endl;
    return quality;
}


std::pair<double, double> calcAvgStdQualityMetric(int n_points){
    std::vector<double> Qualities;
    double current_quality;
    double avgQuality = 0;
    double stdQuality = 0;

    for (int i = 0; i < 20 + 1; i++) {
        current_quality = calcQualityMetric(n_points);
        Qualities.push_back(current_quality);
        avgQuality += current_quality;
    }

    avgQuality = avgQuality / 21.;
    for (int i = 0; i < 20; ++i) {
        stdQuality += pow(Qualities[i] - avgQuality, 2);
    }
    stdQuality = std::sqrt(stdQuality / 21.);
//    std::cout << "Average Quality:" << avgQuality << std::endl;
//    std::cout << "Standard Deviation of Quality:" << stdQuality << std::endl;
    return {avgQuality, stdQuality};
}

int main() {
    std::vector<double> AvgQualities;
    std::vector<double> StdQualities;
    std::pair<double, double> results;
    for (int i = 2; i < 11; i++) {
        results = calcAvgStdQualityMetric(i);
        std::cout << "N:" << i << " Avg:" << results.first << " Std:" << results.second << std::endl;
    }
    return 0;
}