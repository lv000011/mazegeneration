#include "kru.h"
#include "UnionFind.h"
#include <iostream>

namespace mgen {

vector<vector<int>> kru::generate(int seed) {
    UnionFind UF;
    int n = graph.size();
    edges = vector<pair<int, int>>(0);
    returnGraph = vector<vector<int>>(n, vector<int>(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (i < graph[i][j]) {
                edges.push_back(make_pair(i, graph[i][j]));
            }
        }
    }
    int m = edges.size();
    UF.init(n);
    mt19937 rng(seed);
    shuffle(edges.begin(), edges.end(), rng);
    for (int i = 0; i < m; i++) {
        if(!UF.same(edges[i].first, edges[i].second)) {
            UF.unite(edges[i].first, edges[i].second);
            returnGraph[edges[i].first].push_back(edges[i].second);
            returnGraph[edges[i].second].push_back(edges[i].first);
        }
    }
    return returnGraph;
}

kru::kru(vector<vector<int>> graph) {
    this->graph = graph;
}


}