#ifndef WLL_H
#define WLL_H
#include <vector>
#include <random>
using namespace std;

namespace mgen {

class wll {
private:
    vector<vector<int>> graph, returnGraph;
    vector<bool> visited;
    vector<int> d;
    int unVisited;
public:
    vector<vector<int>> generate(int startPos, int seed);
    wll(vector<vector<int>> graph);
};

}

#endif
