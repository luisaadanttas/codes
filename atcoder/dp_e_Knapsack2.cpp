#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e12; 
int peso[105], valor[105];

int main(){
    int n,w; //n = num de itens e w = capacidade da mochila
    cin >> n >> w;
    long long sum_val = 0;
    for(int i = 1; i <= n; i++){
        cin >> peso[i] >> valor[i];
        sum_val += valor[i];
    }
    long long dp[n+2][sum_val+2];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum_val; j++){
            if(j == 0) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum_val; j++){
            if(j >= valor[i]){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-valor[i]]+peso[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i = sum_val; i >= 0; i--){
        if(dp[n][i] <= w){
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}