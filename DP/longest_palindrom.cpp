#include<iostream>
#include<vector>
#include<string>

using namespace std;

string longestPalindrum(string s){
  int n = s.size();
  int max_value = 0;
  int max_value_center = 0;
  for(int center_idx = 1; center_idx < 2*n -1 ; center_idx++){
    // Build palindrum from the center
    int left_idx = (center_idx-1)/2 ;
    int right_idx = (center_idx+1)/2 +1 ;
    int pal_size = 0;
    if(center_idx%2 == 0) pal_size = 1;
    while(1){
      if (left_idx < 0) break;
      if (right_idx > n-1) break;
      if(s[left_idx] == s[right_idx]) {
        pal_size = pal_size + 2;
        left_idx = left_idx -1;
        right_idx = right_idx +1;
      }
      else break;
    }
    if ( max_value < pal_size){
      max_value = pal_size;
      max_value_center = center_idx;
    }


  }
  cout<< "max val: "<< max_value << " max_value center: "<< max_value_center<<endl;
  int begin_idx = max_value_center/2 - max_value/2 -1;
  return s.substr(begin_idx, max_value);

}

string find_long_pali(string s){
  int L = s.size();
  cout <<L <<endl;

  vector< vector<int> > pal_mat;
  for(int i=0 ; i<L; i++){
    vector<int> t;
    for(int j=0 ; j<L; j++){
      if(i==j) t.push_back(1);
      else t.push_back(0);
    }
    pal_mat.push_back(t);
  }
  int max_pal[2] = {0,0};

  for (int len = 2; len <= L; len++){
  // Hanlde all palindrums of size len
    for(int i = 0; i <L; i++){
      int j = i + len -1 ;
      if  (j > L-1){
        break;
      }
      if(len == 2){
        if(s[i] == s[j]){
          pal_mat[i][j] = 1; // if [i][j-1] = 1;
          max_pal[0] = i;
          max_pal[1] = j;
        }
        else
          pal_mat[i][j] = 0; // if [i][j-1] = 1;
      }
      else{
        // len > 1
        if( (s[i] == s[j]) && (pal_mat[i+1][j-1] == 1) ){
          pal_mat[i][j] = 1; // if [i][j-1] = 1;
          max_pal[0] = i;
          max_pal[1] = j;
        }
        else
          pal_mat[i][j] = 0; // if [i][j-1] = 1;

      }
    }

  }


  for(int i=0 ; i<L; i++){
    for(int j=0 ; j<L; j++){
      cout<< pal_mat[i][j]<<", ";
    }
      cout<<endl;
  }
  cout<< max_pal[0] << max_pal[1] <<endl;
  return s.substr(max_pal[0], max_pal[1]- max_pal[0] + 1) ;
}

int main(){
  string pal = find_long_pali("bb");
  cout<<"Longest Palindrom "<< pal<<endl;
  string pal2 = longestPalindrum("bb");
  cout<<"Longest Palindrom2  "<< pal<<endl;



}
