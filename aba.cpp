#include "aba.h"

namespace mgen {

vector<vector<int>> aba::generate(int startPos, int seed) {
    unVisited = graph.size()-1;
    visited = vector<bool>(graph.size(), false);
    visited[startPos] = true;
    returnGraph = vector<vector<int>>(graph.size(), vector<int>(0));
    int pos = startPos;
    while (unVisited > 0) {
        mt19937 gen(seed);
        seed += pos;
        uniform_int_distribution<int> get_rand_int(0, graph[pos].size()-1);
        int next = graph[pos][get_rand_int(gen)];
        if (!visited[next]) {
            visited[next] = true;
            returnGraph[pos].push_back(next);
            returnGraph[next].push_back(pos);
            unVisited--;
        }
        pos = next;
    }
    return returnGraph;
}

aba::aba(vector<vector<int>> graph) {
    this->graph = graph;
}

}