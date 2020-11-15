#include <bits/stdc++.h>
 
using namespace std;
 
int countDigit(int n)
{
    int count = 0;
    while (n != 0) 
    {
        n = n / 10;
        ++count;
    }
    return count;
}
 
 
int main(){
 
  int n,x;
  cin >> n;
 
  int sums[4] = {1,3,6,10};
 
  for ( int i = 0; i < n; i++){
    
    cin >> x;
 
 
    int qtd = countDigit(x);
    int digit = x%10;
 
   
    cout << 10*(digit-1)+sums[qtd-1] << endl;
  }
}
