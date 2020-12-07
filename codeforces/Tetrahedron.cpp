#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

void mult(long long m[4][4], long long m2[4][4]){
    long long resp[4][4] = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                resp[i][j] += ((m[i][k]%MOD)*(m2[k][j]%MOD))%MOD;
            }
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            m[i][j] = resp[i][j];
        }
    }

}


long long pow(long long m[4][4], int n){
    long long aux[4][4] = {{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}};
    while(n > 0){
        if(n % 2 != 0){
            mult(aux,m);
        }
        mult(m,m);
        n /= 2;
    }

    return aux[3][3]%MOD;
}


int main(){
    int n;
    cin >> n;
    long long m[4][4] = {{0,1,1,1}, {1,0,1,1}, {1,1,0,1}, {1,1,1,0}};

    cout << pow(m,n)%MOD << endl;

    return 0;
}