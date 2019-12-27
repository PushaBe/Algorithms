#ifndef COMEMST_DSU_H
#define COMEMST_DSU_H

#include <vector>

class DSU {
public:
    explicit DSU(size_t size);
    int find(int element);
    void merge(int left, int right);
    void print() const;

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

#endif //COMEMST_DSU_H
