#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005

struct no{
    int a,f,c;
};
int m;
string s;
no tree[4*MAX];

no join(no e, no d){
    no aux;
    int n = min(e.a, d.f); //novos
    aux.a = e.a + d.a - n;
    aux.f = e.f + d.f - n;
    aux.c = e.c + d.c + n;
    return aux;
}

void build(int node, int l, int r){
    if(l==r){
        if(s[l] == '(') tree[node].a = 1;
        else tree[node].f = 1;
        return;
    }
    int mid = l + (r-l)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);
    
    tree[node] = join(tree[2*node+1],tree[2*node+2]);
}

no query(int node, int l, int r, int ql, int qr){
    if(qr < l || ql > r){
        no x;
        x.a = 0, x.f = 0, x.c = 0;
        return x;
    }
    if(ql <= l && qr >= r) return tree[node];
    int mid = l + (r-l)/2;
    return join(query(2*node+1,l,mid,ql,qr), query(2*node+2,mid+1,r,ql,qr));
}

int main(){
    cin >> s;
    int tam = (int)s.size()-1;
    build(0,0,tam);
    cin >> m;
    while(m--){
        int l,r;
        cin >> l >> r;
        l--,r--;
        no res = query(0,0,tam,l,r);
        cout << (res.c)*2 << endl;
    }
    return 0;
}