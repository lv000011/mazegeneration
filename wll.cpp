#include "wll.h"

namespace mgen {

vector<vector<int> > wll::generate(int startPos, int seed) {
    int n = graph.size();
    returnGraph = vector<vector<int>>(n, vector<int>(0, 0));
    visited = vector<bool>(n, false);
    d = vector<int>(n, 0);
    unVisited = n-1;
    visited[startPos] = true;
    while (unVisited > 0) {
        mt19937 gen(seed);
        int seed1 = seed, v, w, x;
        uniform_int_distribution<int> get_rand_int(0, n-1);
        v = w = x = get_rand_int(gen);
        seed++;
        if (visited[v]) {
            continue;
        }
        while (!visited[x]) {
            mt19937 gen1(seed1);
            uniform_int_distribution<int> get_rand_next(0, graph[v].size()-1);
            x = graph[v][get_rand_next(gen1)];
            seed1++;
            d[v] = x;
            v = x;
        }
        v = x = w;
        while (!visited[v]) {
            visited[v] = true;
            x = d[v];
            returnGraph[v].push_back(x);
            returnGraph[x].push_back(v);
            v = x;
            unVisited--;
        }
    }
    return returnGraph;
}

wll::wll(vector<vector<int> > graph) {
    this->graph = graph;
}

}