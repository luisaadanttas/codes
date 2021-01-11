#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define MAX 1005

char grid[MAX][MAX];
long long dp[MAX][MAX];

int main(){
    int h,w;
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> grid[i][j];
        }
    }
    dp[0][0] = 1;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == '.' && i > 0 && j > 0) dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
            else if(grid[i][j] == '.' && i > 0) dp[i][j] =  (dp[i][j]+dp[i-1][j])%mod;
            else if(grid[i][j] == '.' && j > 0) dp[i][j] =  (dp[i][j]+dp[i][j-1])%mod;
        }
    }
    
    cout << dp[h-1][w-1]%mod << endl;

    return 0;
}