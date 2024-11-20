#include "prm.h"
#include <iostream>

namespace mgen {

vector<vector<int>> prm::generate(int statPos, int seed) {
    T = vector<int>(0);
    int n = graph.size();
    used = vector<bool>(n, false);
    returnGraph = vector<vector<int>>(n, vector<int>(0));
    T.push_back(statPos);
    used[statPos] = true;
    int notInT = n-1;
    while (notInT > 0) {
        mt19937 rng(seed);
        uniform_int_distribution<int> dist(0, T.size()-1);
        int pos = T[dist(rng)];
        vector<int> order(graph[pos].size(), 0);
        iota(order.begin(), order.end(), 0);
        for (int i = 0; i < graph[pos].size(); i++) {
            int next = graph[pos][order[i]];
            if (!used[next]) {
                used[next] = true;
                notInT--;
                T.push_back(next);
                returnGraph[pos].push_back(next);
                returnGraph[next].push_back(pos);
                break;
            }
        }
        seed++;
    }
    return returnGraph;
}

prm::prm(vector<vector<int> > graph) {
    this->graph = graph;
}

}