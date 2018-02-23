#include <iostream>
#include <bitset>
#include <vector>

#define MAX_EVES 50

using namespace std;

int main() {
   int N, E, K, v;

   cin >> N >> E;

   vector< bitset<MAX_EVES> > villagers(N);
   bitset<MAX_EVES> bard;

   for (int e=0; e<E; e++) {
      villagers[0].reset();

      cin >> K;
      vector<int> villagers_this_evening(K);
      for (int k=0; k<K; k++) {
         cin >> v; v -= 1; // 0-indexing

         // Keep track of which villagers were out this evening
         villagers_this_evening[k] = v;

         // If the bard shows up, he definitely knows the song
         if (v == 0)
            villagers[v][e] = bard[e] = 1;
      }

      int cur, next;
      if (!villagers[0][e]) {
         for (int k=0; k<K-1; k++) {
            cur = villagers_this_evening[k];
            next = villagers_this_evening[k+1];

            villagers[next] |= villagers[cur];
         }
         for (int k=K-1; k>=1; k--) {
            cur = villagers_this_evening[k];
            next = villagers_this_evening[k-1];

            villagers[next] |= villagers[cur];
         }
      } else {
         for (int k=0; k<K; k++) {
            cur = villagers_this_evening[k];
            villagers[cur] |= villagers[0];
         }
      }
   }

   // See which villagers know all of the songs
   cout << 1 << endl;
   for (int n=1; n<N; n++) {
      if (villagers[n] == bard)
         cout << n+1 << endl;
   }

   return 0;
}
