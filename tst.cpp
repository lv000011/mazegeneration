#include "tst.h"
#include <random>

namespace mgen {

    void tst::test() {
    rbt RBT = rbt(graph);
    aba ABA = aba(graph);
    wll WLL = wll(graph);
    hka HKA = hka(graph);
    kru KRU = kru(graph);
    prm PRM = prm(graph);
    int total_rbt = 0, total_aba = 0, total_wll = 0, total_hka = 0, total_kru = 0, total_prm = 0;
    for (int i = 0; i < epoch; i++) {
        mt19937 rng(i+6);
        uniform_int_distribution<int> dist(0, 10009);
        int seed = dist(rng);
        gotGraph = RBT.generate(0, seed);
        total_rbt += minimum_distance();
        gotGraph = ABA.generate(0, seed);
        total_aba += minimum_distance();
        gotGraph = WLL.generate(0, seed);
        total_wll += minimum_distance();
        gotGraph = HKA.generate(0, seed);
        total_hka += minimum_distance();
        gotGraph = KRU.generate(seed);
        total_kru += minimum_distance();
        gotGraph = PRM.generate(0, seed);
        total_prm += minimum_distance();
    }
    cout << "RBT:" << total_rbt/(float)epoch << endl;
    cout << "ABA:" << total_aba/(float)epoch << endl;
    cout << "WIL:" << total_wll/(float)epoch << endl;
    cout << "HKA:" << total_hka/(float)epoch << endl;
    cout << "KRU:" << total_kru/(float)epoch << endl;
    cout << "PRM:" << total_prm/(float)epoch << endl;
}

int tst::minimum_distance() {
    queue<int>().swap(Q);
    int n = gotGraph.size();
    for (int i = 0; i < n; i++) {
        dist[i] = -1;
    }
    Q.push(0);
    dist[0] = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < gotGraph[u].size(); i++) {
            int v = gotGraph[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    return dist[n-1];
}

tst::tst(int epoch, int size) {
    this->epoch = epoch;
    graph = sqr::squareGraph(size, size);
}

}
