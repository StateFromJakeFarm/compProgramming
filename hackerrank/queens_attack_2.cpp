#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>

using namespace std;

bool on_diagonal(int p1_r, int p1_c, int p2_r, int p2_c) {
    return abs(p1_r - p2_r) == abs(p1_c - p2_c);
}

int main() {
    int n, k, q_r, q_c;
    cin >> n >> k >> q_r >> q_c;


    // Distance from queen along each direction, starting with West, then
    // moving clockwise
    vector<int> distance(8);
    distance[0] = q_c - 1; // W
    distance[2] = n - q_r; // N
    distance[4] = n - q_c; // E
    distance[6] = q_r - 1; // S
    distance[1] = min(distance[2], distance[0]); // NW
    distance[3] = min(distance[2], distance[4]); // NE
    distance[5] = min(distance[6], distance[4]); // SE
    distance[7] = min(distance[6], distance[0]); // SW

    // Determine which obstacles are the distance along each of the 8 directions
    int o_r, o_c, o_dist;
    while (k--) {
        cin >> o_r >> o_c;

        if (o_r == q_r) {
            // Horizontal
            o_dist = abs(o_c - q_c) - 1;
            if (o_c < q_c) {
                // W
                distance[0] = min(distance[0], o_dist);
            } else {
                // E
                distance[4] = min(distance[4], o_dist);
            }
        } else if (o_c == q_c) {
            // Vertical
            o_dist = abs(o_r - q_r) - 1;
            if (o_r > q_r) {
                // N
                distance[2] = min(distance[2], o_dist);
            } else {
                // S
                distance[6] = min(distance[6], o_dist);
            }
        } else if (on_diagonal(o_r, o_c, q_r, q_c) && o_r > q_r && o_c < q_c) {
            // NW
            o_dist = abs(o_c - q_c) - 1;
            distance[1] = min(distance[1], o_dist);
        } else if (on_diagonal(o_r, o_c, q_r, q_c) && o_r < q_r && o_c > q_c) {
            // SE
            o_dist = abs(o_c - q_c) - 1;
            distance[5] = min(distance[5], o_dist);
        } else if (on_diagonal(o_r, o_c, q_r, q_c) && o_r > q_r && o_c > q_c) {
            // NE
            o_dist = abs(o_c - q_c) - 1;
            distance[3] = min(distance[3], o_dist);
        } else if (on_diagonal(o_r, o_c, q_r, q_c) && o_r < q_r && o_c < q_c) {
            // SW
            o_dist = abs(o_c - q_c) - 1;
            distance[7] = min(distance[7], o_dist);
        }
    }

    // Sum reachable squares in all directions
    long total = 0;
    for (long d : distance) {
        total += d;
    }

    cout << total << endl;

    return 0;
}
