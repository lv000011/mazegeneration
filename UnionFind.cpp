#include "UnionFind.h"

void UnionFind::init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = -1;
        size[i] = 1;
    }
}

int UnionFind::root(int x) {
    while (true) {
        if (par[x] == -1) {
            break;
        }
        x = par[x];
    }
    return x;
}

void UnionFind::unite(int u, int v) {
    int RootU = root(u);
    int RootV = root(v);
    if (RootU == RootV) {
        return;
    }
    if (size[RootU] < size[RootV]) {
        par[RootU] = RootV;
        size[RootV] += size[RootU];
    } else {
        par[RootV] = RootU;
        size[RootU] += size[RootV];
    }
}

bool UnionFind::same(int u, int v) {
    if (root(u) == root(v)) {
        return true;
    }
    return false;
}