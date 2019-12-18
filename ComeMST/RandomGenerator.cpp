//
// Created by xiaomi on 17.12.2019.
//

#include <vector>
#include "RandomGenerator.h"
#include <random>
#include <math.h>
typedef std::pair<double, double> Point;
typedef std::pair<std::pair<int, int>, double> Edge;

RandomGraphGenerator::RandomGraphGenerator(double s, double e, int n_points):
        s(s),
        e(e),
        n_points(n_points) {}

Point RandomGraphGenerator::GeneratePoint() {
    Point point;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(s, e);
    double box_muller_s = 0;
    while (true) {
        point.first = dis(gen);
        point.second = dis(gen);
        box_muller_s = pow(point.first, 2) + pow(point.second, 2);
        if (box_muller_s <= 1) {
            point.first = point.first * std::sqrt(-2 * std::log(box_muller_s) / box_muller_s);
            point.second = point.second * std::sqrt(-2 * std::log(box_muller_s) / box_muller_s);
            return point;
        }
    }
}

std::vector<Point> RandomGraphGenerator::GeneratePoints() {
    std::vector<Point> points;
    for (int i = 0; i < n_points; ++i) {
        points.push_back(GeneratePoint());
    }
    return points;
}

Edge RandomGraphGenerator::GenerateEdge(Point point1, Point point2, int i, int j) {
    Edge edge;
    edge.first = {i, j};
    edge.second = std::sqrt(
            pow(point1.first - point2.first, 2) + pow(point1.second - point2.second, 2)
            );
    return edge;
}

std::vector<Edge> RandomGraphGenerator::GenerateGraph() {
    std::vector<Edge> g;
    Edge edge;
    std::vector<Point> points = GeneratePoints();
    for (int i = 0; i < n_points; ++i) {
        for (int j = 0; j < n_points - 1; ++j) {
            if (i != j) {
                edge = GenerateEdge(points[i], points[j], i, j);
                g.push_back(edge);
            }
        }
    }
    return g;
}