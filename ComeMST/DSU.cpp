//
// Created by xiaomi on 17.12.2019.
//

#include "DSU.h"
#include <assert.h>
#include <iostream>

DSU::DSU(size_t size) :
        parent(size + 1, -1),
        rank(size + 1, 0) {}

int DSU::find(int element) {
    if (parent[element] == -1) {
        return element;
    }
    return parent[element] = find(parent[element]);
}

void DSU::merge(int left, int right) {
    const int deputat_left = find(left);
    const int deputat_right = find(right);
    assert(deputat_left != deputat_right);
    if (rank[deputat_left] == rank[deputat_right]) {
        parent[deputat_right] = deputat_left;
        ++rank[deputat_right];
    } else if(rank[deputat_left] > rank[deputat_right]) {
        parent[deputat_left] = deputat_right;
    } else {
        parent[deputat_right] = deputat_left;
    }
}

void DSU::print() const {
    for (const auto parent_element : parent) {
        std::cout << parent_element << " ";
    }
    std::cout << std::endl;
}