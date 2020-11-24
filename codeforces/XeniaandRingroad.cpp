#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main(){
  int n, m;
  int a[MAX];

  cin >> n >> m;
  
  for(int i = 1; i <= m; i++){
    cin >> a[i];
  }

  long long ans = 0;
  int pos = 1;

  for(int i = 1; i <= m; i++){
    if(pos <= a[i]){
      ans += abs(pos-a[i]);
    }
    else{
      ans += abs(n-(pos-a[i]));
    }
    pos = a[i];
  }

  cout << ans << endl;

  return 0;
}