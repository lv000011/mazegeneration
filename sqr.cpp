#include "sqr.h"
#include "rbt.h"
#include "wll.h"
#include "aba.h"
#include "hka.h"
#include "kru.h"
#include "prm.h"

namespace mgen {

    vector<vector<int>> sqr::squareGraph(int width, int height) {
        vector<vector<int>> graph(width*height, vector<int>(0, 0));
        for (int i = 0; i < width*height; i++) {
            if (i >= width) {
                graph[i].push_back(i-width);
            }
            if (i < width*(height-1)) {
                graph[i].push_back(i+width);
            }
            if (i%width != 0) {
                graph[i].push_back(i-1);
            }
            if (i%width != width-1) {
                graph[i].push_back(i+1);
            }
        }
        return graph;
    }

    void sqr::show(vector<vector<int> > graph, int width, int height) {
        char fll = 'X', emp = ' ';
        for (int i = 0; i < width*2+1; i++) {
            cout << fll;
        }
        cout << '\n';
        for (int i = 0; i < height; i++) {
            cout << fll;
            for (int j = 0; j < width; j++) {
                cout << emp;
                if (j < width-1 && find(graph[i*width+j].begin(), graph[i*width+j].end(), i*width+j+1) != graph[i*width+j].end()) {
                    cout << emp;
                } else {
                    cout << fll;
                }
            }
            cout << '\n' << fll;
            for (int j = 0; j < width; j++) {
                if (i < height-1 && find(graph[i*width+j].begin(), graph[i*width+j].end(), (i+1)*width+j) != graph[i*width+j].end()) {
                    cout << emp;
                } else {
                    cout << fll;
                }
                cout << fll;
            }
            cout << '\n';
        }
    }

    void sqr::generateSquareMaze() {
        string line = "---------------------------------------------";
        cout << "Enter width and height of the square maze:\n";
        int width, height, seed;
        cin >> width >> height;
        cout << "Enter seed value:\n(if you enter 0, seed value will be randomly generated)\n";
        cin >> seed;
        if (seed == 0) {
            random_device rd;
            mt19937 gen(rd());
            seed = gen();
        }
        vector<vector<int>> graph = squareGraph(width, height);
        cout << "Enter type of generation:\n(0:recursive backtracker)\n(1:Aldous-Broder Algorithm)\n(2:Wilson's Algorithm)\n(3:Hunt and Kill Algorithm)\n(4:Kruskal's Algorithm)\n(5:Prim's Algorithm)\n";
        int type;
        cin >> type;
        switch (type) {
            case 0: {
                cout << "Enter start position:\n";
                int startPos;
                cin >> startPos;
                cout << line << '\n';
                cout << "width:" << width << '\n';
                cout << "height:" << height << '\n';
                cout << "seed:" << seed << '\n';
                cout << "type:" << "recursive backtracker"   << '\n';
                cout << "start position:" << startPos << '\n';
                cout << line << endl;
                rbt a(graph);
                graph = a.generate(startPos, seed);
                break;
            }
            case 1: {
                cout << "Enter start position:\n";
                int startPos;
                cin >> startPos;
                cout << line << '\n';
                cout << "width:" << width << '\n';
                cout << "height:" << height << '\n';
                cout << "seed:" << seed << '\n';
                cout << "type:" << "Aldous-Broder Algorithm" << '\n';
                cout << "start position:" << startPos << '\n';
                cout << line << endl;
                aba a(graph);
                graph = a.generate(startPos, seed);
                break;
            }
            case 2: {
                cout << "Enter start position:\n";
                int startPos;
                cin >> startPos;
                cout << line << '\n';
                cout << "width:" << width << '\n';
                cout << "height:" << height << '\n';
                cout << "seed:" << seed << '\n';
                cout << "type:" << "Wilson's Algorithm" << '\n';
                cout << "start position:" << startPos << '\n';
                cout << line << endl;
                wll a(graph);
                graph = a.generate(startPos, seed);
                break;
            }
            case 3: {
                cout << "Enter start position:\n";
                int startPos;
                cin >> startPos;
                cout << line << '\n';
                cout << "width:" << width << '\n';
                cout << "height:" << height << '\n';
                cout << "seed:" << seed << '\n';
                cout << "type:" << "Hunt and Kill Algorithm" << '\n';
                cout << "start position:" << startPos << '\n';
                cout << line << endl;
                hka a(graph);
                graph = a.generate(startPos, seed);
                break;
            }
            case 4: {
                cout << line << '\n';
                cout << "width:" << width << '\n';
                cout << "height:" << height << '\n';
                cout << "seed:" << seed << '\n';
                cout << "type:" << "Kruskal's Algorithm" << '\n';
                cout << line << endl;
                kru a(graph);
                graph = a.generate(seed);
                break;
            }
            case 5: {
                cout << "Enter start position:\n";
                int startPos;
                cin >> startPos;
                cout << line << '\n';
                cout << "width:" << width << '\n';
                cout << "height:" << height << '\n';
                cout << "seed:" << seed << '\n';
                cout << "type:" << "Prim's Algorithm" << '\n';
                cout << "start position:" << startPos << '\n';
                cout << line << endl;
                prm a(graph);
                graph = a.generate(startPos, seed);
                break;
            }
            default:
                break;
        }
        show(graph, width, height);
    }


}
