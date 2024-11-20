#include "hka.h"
#include <iostream>

namespace mgen {

    vector<vector<int>> hka::generate(int startPos, int seed) {
        int pos = startPos, n = graph.size();
        int next = pos;
        returnGraph = vector<vector<int>>(n, vector<int>(0));
        visited = vector<bool>(n, false);
        while (true) {
            while (!isDead(next)) {
                pos = next;
                vector<int> order(graph[pos].size());
                iota(order.begin(), order.end(), 0);
                mt19937 rng(seed);
                shuffle(order.begin(), order.end(), rng);
                seed++;
                for (int i = 0; i < order.size(); i++) {
                    if (!visited[graph[pos][order[i]]]) {
                        next = graph[pos][order[i]];
                        visited[next] = true;
                        break;
                    }
                }
                returnGraph[pos].push_back(next);
                returnGraph[next].push_back(pos);
            }
            bool b = true;
            for (int i = 0; i < n; i++) {
                if (visited[i] && !isDead(i)) {
                    b = false;
                    pos = next = i;
                    break;
                }
            }
            if (b) {
                return returnGraph;
            }
        }
    }

    hka::hka(vector<vector<int> > g) {
        graph = g;
    }

    bool hka::isDead(int pos) {
        for (int i = 0; i < graph[pos].size(); i++) {
            if (!visited[graph[pos][i]]) {
                return false;
            }
        }
        return true;
    }


}