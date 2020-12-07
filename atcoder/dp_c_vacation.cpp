#include<bits/stdc++.h>
#define MAX 100005
using namespace std;

int dp[MAX][3];
int a[MAX], b[MAX], c[MAX];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[0][0] = a[0], dp[0][1] = b[0], dp[0][2] = c[0];
    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][1]+a[i], dp[i-1][2]+a[i]);
        dp[i][1] = max(dp[i-1][0]+b[i], dp[i-1][2]+b[i]);
        dp[i][2] = max(dp[i-1][0]+c[i], dp[i-1][1]+c[i]);
    }
    cout << max(max(dp[n-1][0],dp[n-1][1]), dp[n-1][2]) << endl;
    return 0;
}