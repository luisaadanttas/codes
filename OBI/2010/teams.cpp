#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, t;
  cin >> n >> t;

  priority_queue <int, vector <pair<int, string>>>pq;
  vector <string> a[1000];

  string name;
  int skill;
  for (int i = 0; i < n; i++){
    cin >> name >> skill;
    pq.push(make_pair(skill,name));
  }

  int team = 0, limit = t-1;

  while (!pq.empty()){

    string top = pq.top().second;
    a[team].push_back(top);
    pq.pop();
    team++;
    if (team > limit){
      team = 0;
    }
  }

  for (int i = 0; i < t; i++){
  	sort(a[i].begin(),a[i].end());
  	cout << "Time "<< i+1 << endl;
    for (int j = 0; j < a[i].size(); j++){
      cout << a[i][j] << endl;
    }
    cout << endl;
  }
  
}
