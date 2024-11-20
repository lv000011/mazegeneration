#ifndef UNIONFIND_H
#define UNIONFIND_H

class UnionFind {
public:
    int par[100009], size[100009];
    void init(int n);
    int root(int x);
    void unite(int u, int v);
    bool same(int u, int v);
};

#endif