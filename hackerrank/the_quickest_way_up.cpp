#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum {
    w = 0,
    g = 1,
    b = 2
};

// Return distance to square 100, or -1 if impossible
int shortestPathDFS(const vector<int> & board, const vector<int> & outPoints) {
    vector<int> colors(100);
    vector<int> rolls(100);
    queue<int> Q;
    int numBlack = 0;

    colors[0] = g;
    Q.push(0);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        // Did we finish?
        if (u == 99)
            return rolls[u];

        // We have a 6-sided die
        for (int i=1; i<=6; i++) {
            int v = u+i;
            // Don't go over the edge of board
            if (v <= 99 && colors[v] == w) {
                colors[v] = g;
                rolls[v] = rolls[u] + 1;

                // Check if v is the start of a ladder or snake
                if (outPoints[v] != 0) {
                    int o = outPoints[v];
                    colors[o] = g;
                    rolls[o] = rolls[u] + 1;
                    Q.push(o);
                } else {
                    Q.push(v);
                }
            }
        }

        colors[u] = b;
    }

    // All squares have been visited but there is no path
    return -1;
}

int main() {
    // Our gameboard
    vector<int> board(100);

    // Get number of testcases
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        // Where we end up after going up a ladder
        // or coming out of a snake
        vector<int> outPoints(100);

        // Get ladders
        int N;
        cin >> N;
        int start, end;
        for (int n=0; n<N; n++) {
            cin >> start >> end;
            outPoints[start-1] = end-1;
        }

        // Get snakes
        int M;
        cin >> M;
        for (int m=0; m<M; m++) {
            cin >> start >> end;
            outPoints[start-1] = end-1;
        }

        // Run DFS
        cout << shortestPathDFS(board, outPoints) << endl;
    }

    return 0;
}
