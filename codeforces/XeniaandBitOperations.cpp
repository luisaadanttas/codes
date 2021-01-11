#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int a[MAX];
int tree[4*MAX];

void build(int no, int l, int r, int op){ // op = 1 or e op = 0 xor
    if(l == r){
        tree[no] = a[l];
        return;
    }
    int mid = l + (r-l) / 2; //(r+l)/2 pode causar overflow
    build(2*no+1,l,mid,!op);
    build(2*no+2,mid+1,r,!op);

    if(op == 1) tree[no] = tree[2*no+1] | tree[2*no+2];
    else tree[no] = tree[2*no+1] ^ tree[2*no+2];
}

void update(int no, int l, int r, int idx, int x, int op){
    if(l == r){
        tree[no] = x;
        a[no] = x;
        return;
    }
    int mid = l + (r-l) / 2;
    if(idx >= l && idx <= mid) update(no*2+1, l, mid, idx, x, !op);
    else if(idx > mid && idx <= r) update(no*2+2, mid+1, r, idx, x, !op);

    if(op == 1) tree[no] = tree[2*no+1] | tree[2*no+2];
    else tree[no] = tree[2*no+1] ^ tree[2*no+2];
}


int main(){
    int n,m,op;
    cin >> n >> m;

    int num = (int)pow(2,n);

    for(int i = 0; i < num; i++){
        cin >> a[i];
    }

    int alt = (int)(ceil(log2(num))); //altura da segtree
    
    if(alt%2 == 0) op = 0; // xor root
    else op = 1; // or root

    build(0,0,num-1,op);
    
    while(m--){
        int idx, value;
        cin >> idx >> value;
        idx--;
        update(0,0,num-1,idx,value,op);
        cout << tree[0] << endl;
    }

    return 0;
}