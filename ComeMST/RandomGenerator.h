//
// Created by xiaomi on 17.12.2019.
//

#ifndef COMEMST_RANDOMGENERATOR_H
#define COMEMST_RANDOMGENERATOR_H
typedef std::pair<double, double> Point;
typedef std::pair<std::pair<int, int>, double> Edge;

class RandomGraphGenerator {
public:
    Point GeneratePoint();
    std::vector<Point> GeneratePoints();
    static Edge GenerateEdge(Point point1, Point point2, int i, int j);
    std::vector<Edge> GenerateGraph();
    int n_points;
    explicit RandomGraphGenerator(double s, double e, int n_points);

private:
    double s, e;

};

#endif //COMEMST_RANDOMGENERATOR_H
