#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

bool vis[MAX];
int dp[MAX];
vector <int> adj[MAX];

void dfs(int v){
    vis[v] = true;
    for(int i = 0; i < (int)adj[v].size(); i++){
        if(!vis[adj[v][i]]) dfs(adj[v][i]);
        dp[v] = max(dp[v], dp[adj[v][i]]+1);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        x--,y--;
        adj[x].push_back(y);
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]) dfs(i);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans,dp[i]);
    }

    cout << ans << endl;

    return 0;
}