#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
#define MAX 105
int n;

void mult(long long m[MAX][MAX], long long m2[MAX][MAX]){
  long long res[n][n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      res[i][j] = 0;
      for(int k = 0; k < n; k++){
        res[i][j] += ((m[i][k]%MOD)*(m2[k][j]%MOD))%MOD;
      }
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      m[i][j] = res[i][j];
    }
  }
}


long long power(long long m[MAX][MAX], long long k){
  long long m2[MAX][MAX];
  for(int i = 0; i < n; i++){
    m2[i][i] = 1;
  }

  while(k > 0){
    if(k % 2 == 1){
      mult(m2,m);
    }
    mult(m,m);
    k /= 2;
  }

  long long ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      ans = (ans + m2[i][j]) % MOD;
    }
  }
  return ans;
}


int main(){
  int m;
  long long k;
  long long g[MAX][MAX];

  cin >> n >> m >> k;

  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    a--,b--;
    g[a][b] = 1;
  }

  cout << power(g,k)%MOD << endl;

  return 0;
}