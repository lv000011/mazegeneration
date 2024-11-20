#include "rbt.h"

namespace mgen {

vector<vector<int>> rbt::generate(int startPos, int seed) {
    this->seed = seed;
    returnGraph = vector<vector<int>>(graph.size(), vector<int>(0));
    visited = vector<bool>(graph.size(), false);
    backtrack(startPos);
    return returnGraph;
}

void rbt::backtrack(int pos) {
    visited[pos] = true;
    vector<int> order(graph[pos].size());
    iota(order.begin(), order.end(), 0);
    seed += seed > 0 ? -pos : pos;
    mt19937 rng(seed);
    shuffle(order.begin(), order.end(), rng);
    for (int i = 0; i < order.size(); i++) {
        int next = graph[pos][order[i]];
        if (!visited[next]) {
            returnGraph[pos].push_back(next);
            returnGraph[next].push_back(pos);
            backtrack(next);
        }
    }
}

rbt::rbt(vector<vector<int>> g) {
    graph = g;
}

}