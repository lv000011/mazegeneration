#ifndef KRU_H
#define KRU_H
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

namespace mgen {

class kru {
private:
    vector<vector<int>> graph, returnGraph;
    vector<pair<int, int>> edges;
public:
    vector<vector<int>> generate(int seed = 0);
    kru(vector<vector<int>> graph);
};

}

#endif
