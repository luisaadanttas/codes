#include<bits/stdc++.h>
using namespace std;

long long p[27];
long long dp[2005][2005];

void f(int *s1, int *s2, int n, int m){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + p[s1[i-1]];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}


int main(){
    int n,m;
    int s1[2005],s2[2005];

    cin >> n >> m;

    for(int i = 0; i < 26; i++){
        cin >> p[i];
    }
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        s1[i] = (((int)c)-97);
    }
    for(int i = 0; i < m; i++){
        char c;
        cin >> c;
        s2[i] = (((int)c)-97);
    }

    f(s1,s2,n,m);

    cout << dp[n][m] << endl;

    return 0;
}