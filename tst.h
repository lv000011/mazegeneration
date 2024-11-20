#ifndef TST_H
#define TST_H
#include "sqr.h"
#include "rbt.h"
#include "wll.h"
#include "aba.h"
#include "hka.h"
#include "kru.h"
#include "prm.h"
#include <vector>
#include <queue>
using namespace std;

namespace mgen {

class tst {
private:
    int epoch;
    vector<vector<int>> graph, gotGraph;
    int minimum_distance();
    queue<int> Q;
    int dist[100009];
public:
    void test();
    tst(int epoch, int size);
};

}

#endif
