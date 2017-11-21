#include <cmath>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int negSlope, posSlope = 0;
    
    for(int r = 0;r < n;r++){
       for(int c = 0;c < n;c++){
          int num;
          cin >> num;
           
          if(c == r)
              negSlope += num;
          if(c == (n - 1) - r)
              posSlope += num;
       }
    }
    
    int diff = abs(negSlope - posSlope);
    
    cout << diff << endl;
    
    return 0;
}
