#include<bits/stdc++.h>
#define MAX 100005
using namespace std;

int h[MAX];
int dp[MAX];

int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    dp[0] = 0, dp[1] = abs(h[1]-h[0]);
    for(int i = 2; i < n; i++){
        int min_cost = dp[i-1]+abs(h[i]-h[i-1]);
        for(int j = 1; j <= k; j++){
            if(i-j >= 0){
                dp[i] = min(min_cost, dp[i-j]+abs(h[i]-h[i-j]));
                min_cost = dp[i];
            }
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}