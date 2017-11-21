#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

struct obst {
    int x;
    int y;
};

int pythagDist(int x1, int y1, int x2, int y2) {
    return int(floor(sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)) / sqrt(2)));
}

int diagWallDist(int qx, int qy, int n, int slope, int forward) {
    // Get y intercept
    int b = qy - slope*qx;

    // What is closest wall
    if(forward) {
        if(slope == 1) {
            int t_x = n - b;
            int t_dist = pythagDist(t_x, n, qx, qy);

            int r_y = qx + b;
            int r_dist = pythagDist(n, r_y, qx, qy);

            return min(t_dist, r_dist);
        } else {
            int b_x = b;
            int b_dist = pythagDist(b_x, 0, qx, qy);

            int r_y = -qx + b;
            int r_dist = pythagDist(n, r_y, qx, qy);

            return min(b_dist, r_dist);
        }
    } else {
        if(slope == 1) {
            int b_x = -b;
            int b_dist = pythagDist(b_x, 0, qx, qy); 

            int l_y = b;
            int l_dist = pythagDist(0, l_y, qx, qy);

            return min(b_x, l_y);
        } else {
            int t_x = 
        }
    }
}

int getDist(int qx, int qy, int ox, int oy, int n, int slope, bool forward) {
    if(ox == -1) {
        // Looking for wall
        switch(slope) {
            case INT_MAX:
                if(forward)
                    // Above
                    return n - qy - 1;
                else
                    // Below
                    return qy - 1;
                break;

            case 0:
                if(forward)
                    // Ahead
                    return n - qx - 1;
                else
                    // Behind
                    return qx - 1;
                break;

            case -1:
                if(forward) {
                    // Upper left
                } else {
                    // Bottom right
                }
                break;
            case 1:
                break;
        }
    } else {
        // Looking for obstacle
    }
}

int main() {
    int n, num_obs;
    cin >> n >> num_obs;

    int qx, qy;
    cin >> qx >> qy;

    int B[n][n] = {0};
    for(int i=0; i<num_obs; i++) {
        int ox, oy;
        cin >> ox >> oy;

        B[ox][oy] = 1;
    }

    // Keep track of closest obstacles in all 8 directions
    obst closest[8];

    // Start with walls (cc-wise from 0 degrees)
    for(int i=0; i<8; i++) {
        switch(i) {
            case 0:
                // 0 -> slope = 0
                
                break;
        }
    }

    return 0;
}










