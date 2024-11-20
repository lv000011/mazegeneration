#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "sqr.h"
#include "tst.h"

using namespace mgen;

int main() {
    cout << "Enter 0 to test or other number to generate maze:" << endl;
    int n;
    cin >> n;
    if (n == 0) {
        cout << "Enter how many times you want to test:" << endl;
        int epoch;
        cin >> epoch;
        cout << "Enter maze size:" << endl;
        int size;
        cin >> size;
        tst TST(epoch, size);
        TST.test();
    } else {
        sqr::generateSquareMaze();
    }
}
