#ifndef RBT_H
#define RBT_H
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

namespace mgen {

class rbt {
private:
    vector<bool> visited;
    vector<vector<int>> graph, returnGraph;
    int seed;
    void backtrack(int pos);
public:
    vector<vector<int>> generate(int startPos = 0, int seed = 0);
    rbt(vector<vector<int>> g);
};

}

#endif
