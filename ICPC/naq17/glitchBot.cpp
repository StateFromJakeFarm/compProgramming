#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
   int dx, dy;
   cin >> dx >> dy;

   int n;
   cin >> n;

   char direction = 'n';
   int x, y;
   x = y = 0;

   vector<int> X(1);
   vector<int> Y(1);
   vector<char> d;

   string curInstr;
   for(int i=0; i<=n; i++) {
      getline(cin, curInstr);
      cout << curInstr << endl;

      d.push_back(direction);

      if(curInstr == "Forward") {
         if(direction == 'e') {
            X.push_back( X[X.size()-1] + 1 );
            Y.push_back( Y[Y.size()-1] );
         } else if(direction == 'w') {
            X.push_back( X[X.size()-1] - 1 );
            Y.push_back( Y[Y.size()-1] );
         } else if(direction == 'n') {
            Y.push_back( Y[Y.size()-1] + 1 );
            X.push_back( X[X.size()-1] );
         } else {
            Y.push_back( Y[Y.size()-1] - 1 );
            X.push_back( X[X.size()-1] );
         }
      } else if(curInstr == "Right") {
         if(direction == 'n')
            direction = 'e';
         else if(direction = 's')
            direction = 'w';
         else if(direction = 'e')
            direction = 's';
         else
            direction = 'n';
      } else {
        if(direction == 'n')
            direction = 'w';
         else if(direction = 's')
            direction = 'e';
         else if(direction = 'e')
            direction = 'n';
         else
            direction = 's';
      }
   }

   int fx = X[X.size()-1];
   int fy = Y[Y.size()-1];
   for(int i=0; i<n; i++) {
      int curx = X[i];
      int cury = Y[i];
      for(int i=0; i<3; i++) {
         if(i == 0) {
            if(direction == 'n') {
               if(fx == dx && fy + 1 == dy) {
                  cout << "Forward" << i+1 << endl;
                  return 0;
               }
            } else if(direction = 's') {
               if(fx == dx && fy - 1 == dy) {
                  cout << "Forward" << i+1 << endl;
                  return 0;
               }
            } else if(direction = 'e') {
               if(fx + 1 == dx && fy == dy) {
                  cout << "Forward" << i+1 << endl;
                  return 0;
               }
            } else {
               if(fx - 1 == dx && fy == dy) {
                  cout << "Forward" << i+1 << endl;
                  return 0;
               }
            }
         } else if(i == 1) {
            int diffx = X[i] - fx;
            int diffy = Y[i] - fy;

            if(curx + diffy == dx && cury - diffx == dy) {
               cout << i+1 << "Right" << endl;
               return 0;
            }
         } else {
            int diffx = fx - X[i];
            int diffy = fy - Y[i];

            if(curx - diffy == dy && cury + diffx == dy) {
               cout << i+1 << "Left" << endl;
               return 0;
            }
         }
      }
   }

   return 0;
}

















