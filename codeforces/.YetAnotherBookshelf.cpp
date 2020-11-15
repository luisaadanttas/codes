#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
  int t;
  cin >> t;
  int n,v[55],zeros[55];
 
  for (int i = 0; i < t; i++){
 
    int countZeros = 0;
    cin >> n;
 
    bool ini = false;
 
    for (int i = 0; i < n; i++){
      
      cin >> v[i];
      
      if (v[i] == 1 and ini == false){
        ini = true;
      }
 
      if (ini == true){
        
        if (v[i] == 0){
          countZeros++;
        }
        zeros[i] = countZeros;
      }
    
    }
 
    int last;
 
    for (int i = n-1; i >= 0; i--){
      if (v[i] == 1){
        last = i;
        break;
      }
    }
 
    cout << zeros[last] << endl;
  }
}
