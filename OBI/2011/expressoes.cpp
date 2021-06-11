#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
  int n;
  cin >> n;
  string s;
  stack <char> q;
 
  for (int i = 0; i < n; i++){
    cin >> s;
    bool ok = true;
    int t = s.size();
 
    for (int i = 0; i < t; i++){
      if (s[i] == '(' or s[i] =='{' or s[i] =='['){
        q.push(s[i]);
      }
      else{
        if (q.empty()){
          ok = false;
          break;
        }
        else{
        	char tp = q.top();
          if (s[i] == ')'){
            if (tp == '(')q.pop();
            else{
              ok = false;
              break;
            }
            
          }
          else if (s[i] == ']'){
            if (tp == '[')q.pop();
            else{
              ok = false;
              break;
            }
          }
          else{
            if (tp == '{')q.pop();
            else{
              ok = false;
              break;
            }
          }
        }
      }
    }
