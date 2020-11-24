#include <bits/stdc++.h>
using namespace std;

const int INF = 1e+9;
int n,a,b,c;
int dp[4005];
int tam[4];


int main(){
  for(int i = 0; i < 4000; i++){
    dp[i] = -INF;
  }

  cin >> n >> a >> b >> c;

  tam[1] = a, tam[2] = b, tam[3] = c;

  dp[0] = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= 3; j++){
      if(i-tam[j] >= 0){
        dp[i] = max(dp[i], dp[i-tam[j]] + 1);
      }
    }
  }
  
  cout << dp[n] << endl;

  return 0;
}