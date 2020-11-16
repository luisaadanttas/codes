#include <bits/stdc++.h>

using namespace std; 
  
int josephus(int n, int k) 
{ 
    if (n == 1) 
        return 1; 
    else{
      return (josephus(n - 1, k) + k-1) % n + 1;
    } 
} 


int main(){

  int t,n,k;

  cin >> t;

  for (int i = 1; i <= t; i++){
    
    cin >> n >> k;
    cout << "Case " << i << ": " << josephus(n, k) << endl; 
  }
}
