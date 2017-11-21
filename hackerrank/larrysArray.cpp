#include <iostream>
#include <string>

using namespace std;

int N;

bool intCmp(const void *i1, const void *i2) {
    return *(int*)i1 - *(int*)i2;
}

void rotate(int a[], int bot) {
    int temp = a[bot];
    int a[bot] = a[bot+1];
    int a[bot+1] = a[bot+2];
    int a[bot+2] = temp;
}

string canSort(int a[], int aSorted[]) {
    qsort(aSorted, N, sizeof(int), intCmp);

    for(int i=0; i<N-2; i++) {
        if(a[i] != aSorted[i]) {
            int next = aSorted[i];
            int nextIndex;
            for(int j=i; j<N; j++) {
                if(a[j] == next) {
                    nextIndex = j;
                    break;
                }
            }

            int bot = nextIndex - 2;
            if(bot <= i) {
                return "NO";
            }


        }
    }

    return "YES";
}

int main() {
    int T;
    cin >> T;

    for(int i=0; i<2*T; i++) {
        cin >> N;
        int a[N];
        int aSorted[N];

        int num;
        for(int j=0; j<N; j++) {
            cin >> num;
            a[j] = num;
            aSorted[j] = num;
        }

        cout << canSort(a, aSorted) << endl;
    }

    return 0;
}
