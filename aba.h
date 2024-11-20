#ifndef ABA_H
#define ABA_H
#include <vector>
#include <random>
using namespace std;

namespace mgen {

class aba {
private:
    vector<bool> visited;
    vector<vector<int>> graph, returnGraph;
    int unVisited;
public:
    vector<vector<int>> generate(int startPos, int seed = 0);
    aba(vector<vector<int>> graph);
};

}

#endif
