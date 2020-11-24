#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

void mult(long long m[2][2], long long m2[2][2]){
  long long res[2][2];
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      res[i][j] = 0;
      for(int k = 0; k < 2; k++){
        res[i][j] += ((m[i][k]%MOD)*(m2[k][j]%MOD))%MOD;
      }
    }
  }

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      m[i][j] = res[i][j];
    }
  }
}


long long power(long long m[2][2], long long n){
  long long m2[2][2] = {{1,0}, {0,1}};
  while(n > 0){
    if(n % 2 == 1){
      mult(m2,m);
    }
    mult(m,m);
    n /= 2;
  }
  return m2[0][0]%MOD;
}


int main(){
  long long n;

  cin >> n;
  long long m[2][2] = {{19,7},{6,20}};
  cout << power(m,n) << endl;

  return 0;
}