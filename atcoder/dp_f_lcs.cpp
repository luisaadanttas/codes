#include<bits/stdc++.h>
using namespace std;

int dp[3005][3005];

int main(){
    string s,t;
    cin >> s;
    cin >> t;

    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= t.size(); j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int tam = dp[s.size()][t.size()];
    char lcs[tam+1];
    lcs[tam] = '\0';

    int i = s.size(), j = t.size();
    while(i > 0 and j > 0){
        if(s[i-1] == t[j-1]){
            lcs[tam-1] = s[i-1];
            i--,j--,tam--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else j--;
        }
    }

    cout << lcs << endl;

    return 0;
}