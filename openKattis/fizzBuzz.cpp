#include <iostream>

using namespace std;

int main() {
    int x, y, n;
    cin >> x >> y >> n;

    for(int i=1; i<=n; i++) {
        bool printFizz = (i % x == 0);
        bool printBuzz = (i % y == 0);

        if(printFizz and printBuzz)
            cout << "FizzBuzz" << endl;
        else if(printFizz)
            cout << "Fizz" << endl;
        else if(printBuzz)
            cout << "Buzz" << endl;
        else
            cout << i << endl;
    }

    return 0;
}
