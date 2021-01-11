#include<bits/stdc++.h>
#define MAX 105
using namespace std;

int peso[MAX], valor[MAX];
long long dp[MAX][100005];

int main(){
    int n,w;
    cin >> n >> w;
    for(int i = 1; i <= n; i++){
        cin >> peso[i] >> valor[i];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            if(j-peso[i] >= 0 ){
                dp[i][j] = max(valor[i]+dp[i-1][j-peso[i]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}