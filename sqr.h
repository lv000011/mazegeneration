#ifndef SQR_H
#define SQR_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

namespace mgen {

class sqr {
public:
    static vector<vector<int>> squareGraph(int width = 5, int height = 5);
    static void show(vector<vector<int>> graph, int width = 5, int height = 5);
    static void generateSquareMaze();
};

}

#endif
