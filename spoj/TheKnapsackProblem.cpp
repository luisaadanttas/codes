#include<bits/stdc++.h>
#define MAX 2005
using namespace std;

int memo[MAX][MAX];
int size[MAX], value[MAX];
int s,n;

const int INF = 1e+9;

int ks(int idx, int tam){
    
    if(tam < 0) return -INF;
    if(idx == n) return 0;

    int &ans = memo[idx][tam];
    if(ans != -1) return ans;

    return ans = max( ks(idx+1, tam-size[idx])+value[idx], ks(idx+1, tam) );
    
}


int main(){
    memset(memo, -1, sizeof(memo));

    cin >> s >> n;

    for(int i = 0; i < n; i++){
        cin >> size[i] >> value[i];
    }

    cout << ks(0,s) << endl;

    return 0;
}