#include <bits/stdc++.h>

using namespace std;


bool compare(char a, char b){
  
  char n = toupper(a);
  char t = toupper(b);

  if (n == t) return true;
  return false;

}


int main(){
  
  string word;

  while(getline(cin,word)){
    if (word == "*"){
      break;
    }
    else{


  bool isTauto = true;
  char ini = word[0];

  for (int i = 1; word[i]; i++){

    if (word[i-1] == ' '){
      if (!compare(word[i], ini)){
        isTauto = false;
        cout << "N" << endl;
        break;
      }
    }
  }

  if (isTauto){
    cout << "Y" << endl;
  }
    }
  }
}
