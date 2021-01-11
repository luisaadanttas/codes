#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
typedef long long ll;

struct node{
    ll max1,max2;
};

ll a[MAX];
node tree[4*MAX];

node merge(node esq, node dir){
    node aux;
    aux.max1 = max(esq.max1,dir.max1);
    if(aux.max1 == esq.max1) aux.max2 = max(dir.max1,esq.max2);
    else aux.max2 = max(esq.max1,dir.max2);

    return aux;
}


void build(ll no, ll l, ll r){
    if(l == r){
        tree[no].max1 = a[l];
        tree[no].max2 = 0;
        return;
    }
    ll mid = l + (r-l)/2;
    build(2*no+1,l,mid);
    build(2*no+2,mid+1,r);
    
    tree[no] = merge(tree[2*no+1],tree[2*no+2]);
}


node query(ll no, ll l, ll r, ll ql, ll qr){
    if(qr < l || ql > r){
        node aux;
        aux.max1=0,aux.max2=0;
        return aux;
    }
    if(ql <= l && qr >= r) return tree[no];

    ll mid = l + (r-l)/2;
    return merge(query(2*no+1,l,mid,ql,qr), query(2*no+2,mid+1,r,ql,qr));
}


void update(ll no, ll l, ll r, ll idx, ll x){
    if(l == r){
        tree[no].max1 = x;
        tree[no].max2 = 0;
        a[l] = x;
        return;
    }
    ll mid = l + (r-l)/2;
    if(l <= idx && idx <= mid) update(2*no+1,l,mid,idx,x);
    else update(2*no+2,mid+1,r,idx,x);
    tree[no] = merge(tree[2*no+1],tree[2*no+2]);
}


int main(){
    ll n,nop;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    build(0,0,n-1);

    cin >> nop;
    while(nop--){
        char op;
        cin >> op;
        if(op == 'U'){
            ll i,x;
            cin >> i >> x;
            i--;
            update(0,0,n-1,i,x);
        }
        else{
            ll x,y;
            cin >> x >> y;
            x--,y--;
            node aux = query(0,0,n-1,x,y);
            ll ans = aux.max1 + aux.max2;
            cout << ans << endl;
        }
    }

    return 0;
}