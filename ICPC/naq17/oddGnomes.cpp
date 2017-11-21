#include <iostream>

using namespace std;

int main() {
   int n;
   cin >> n;

   bool done = false;
   for(int i=0; i<n; i++) {
      bool done = false;

      int g;
      cin >> g;

      int cur, prev;
      for(int j=0; j<g; j++) {
         cin >> cur;
         if(j == 0) {
            prev = cur;
            continue;
         }

         if(!done && cur-1 != prev) {
            done = true;
            cout << j+1 << endl;
         }

         prev = cur;
      }
   }

   return 0;
}
