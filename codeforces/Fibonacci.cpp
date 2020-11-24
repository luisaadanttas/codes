#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

void mult(long long m[2][2], long long m2[2][2]){
  int res[2][2];
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


void power(long long m[2][2], long long n){
  if(n == 0 or n == 1) return;
  long long m2[2][2] = {{1,1}, {1,0}};
  power(m,n/2);
  mult(m,m);
  if(n % 2 != 0) mult(m,m2);
}


long long fib(long long n){
  long long m[2][2] = {{1, 1},{1, 0}}; 
  if(n == 0) return 0;
  if(n == 1 or n == 2) return 1;
  power(m,n-1);
  return m[0][0];
}


int main(){
  long long n;
  cin >> n;
  cout << (fib(n))%MOD << endl;
  return 0;
}