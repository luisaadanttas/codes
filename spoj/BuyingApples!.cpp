#include<bits/stdc++.h>
using namespace std;
#define MAX 105
 
int c,n,k;
int p[MAX];
long long dp[MAX][MAX];
const int INF = 1e+9;
 
long long f(int idx, int peso){
    if(peso < 0 or idx > peso) return INF;
    if(idx == peso) return p[idx] == -1? INF:p[idx];
 
    long long &ans = dp[idx][peso];
    if(ans != -1) return ans;
 
    if(p[idx] == -1){
      dp[idx][peso] = f(idx+1,peso);
    }
    else{
      dp[idx][peso] = min(f(idx,peso-idx)+p[idx],min(f(idx+1,peso-idx)+p[idx],f(idx+1,peso)));
    }
 
    return dp[idx][peso];
}
 
 
int main(){
    cin >> c;
    while(c--){
        cin >> n >> k;
        for(int i = 1; i <= k; i++){
            cin >> p[i];
        }
        memset(dp, -1, sizeof(dp));
        long long resp = f(1,k);
        if(resp == INF) cout << -1 << endl;
        else cout << resp << endl;
    }
    return 0;
}  