#include <iostream>

using namespace std;

int main(){
  char letters[16] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
  char first[8];
  char second[4];
  char third[2];

  int x,y;
  int j = 0;
  for (int i = 0; i < 8; i++){
    cin >> x >> y;
    if (x > y){
      first[i] = letters[j]; 
    }
    else{
      first[i] = letters[j+1];
    }
    j+=2;
  }
  int k = 0;
  for (int i = 0; i < 4; i++){
    cin >> x >> y;
    if (x > y){
      second[i] = first[k]; 
    }
    else{
      second[i] = first[k+1];
    }
    k+=2;
  }

  int l = 0;
  for (int i = 0; i < 2; i++){
    cin >> x >> y;
    if (x > y){
      third[i] = second[l]; 
    }
    else{
      third[i] = second[l+1];
    }
    l+=2;
  }
  cin >> x >> y;
  if (x > y){
    cout << third[0] << endl;
  }
  else{
    cout << third[1] << endl;
  }
}
