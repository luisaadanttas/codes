#include<bits/stdc++.h>
using namespace std;

long long dp[5005];

long long f(string s, int ini, int fim){
    if(s[ini] == '0') return 0;
    if(ini == fim) return 1;

    long long &ans = dp[ini];
    if(ans != -1) return ans;

    ans = f(s, ini+1, fim);
    if(ini+2 <= fim){
        if(s[ini] == '1' or (s[ini] == '2' and s[ini+1] < '7')) ans += f(s, ini+2, fim);
    }

    return ans ;
}


int main(){
    string s;
    while(cin >> s){
        if(s == "0") break;
        memset(dp,-1,sizeof(dp));
        cout << f(s,0,(int)s.size()) << endl;
    }
    return 0;
}