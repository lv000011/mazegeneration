#ifndef HKA_H
#define HKA_H
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

namespace mgen {

class hka {
private:
    vector<bool> visited;
    vector<vector<int>> graph, returnGraph;
    bool isDead(int pos);
public:
    vector<vector<int>> generate(int startPos = 0, int seed = 0);
    hka(vector<vector<int>> g);
};

}

#endif