#ifndef PRM_H
#define PRM_H
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

namespace mgen {

class prm {
private:
    vector<vector<int>> graph, returnGraph;
    vector<int> T;
    vector<bool> used;
public:
    vector<vector<int>> generate(int startPos, int seed);
    prm(vector<vector<int>> graph);
};

}

#endif
