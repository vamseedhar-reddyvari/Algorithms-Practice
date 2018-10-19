#include<iostream>
#include<string>
#include<vector>


using namespace std;


string longest_common_substr(string s1, string s2){
    int p = s1.size();
    int q = s2.size();
    // Construct Longest common Suffix Matrix
    vector<int> zero(q,0);
    vector< vector<int> > suffix_mtx(p,zero);

    // Fill suffix mtx for base case
    if(s1[0] == s2[0]) suffix_mtx[0][0] = 1;
    else {suffix_mtx[0][0] = 0;}

    for(int i=1; i< p; i++){
        suffix_mtx[i][0] = (s1[i] == s2[0]);
        suffix_mtx[0][i] = (s2[i] == s1[0]);
    }

    // Recursively construct
    int p1 = 0;
    int max_value = 0;
    for(int i=1; i <p ; i++){
        for(int j =1; j<q; j++){
            if(s1[i] != s2[j]) suffix_mtx[i][j]  = 0;
            else {
              suffix_mtx[i][j]  = suffix_mtx[i-1][j-1]  +1;
              if (suffix_mtx[i][j] >=  max_value){
                  max_value = suffix_mtx[i][j];
                  p1 = i;
            }
          }
        }
    }
    // print suffix mtx
    for(int i=0; i <p ; i++){
        for(int j =0; j<q; j++){
            cout<< suffix_mtx[i][j]<<", ";
        }
        cout<<endl;
    }
    cout<< "p1: "<< p1<<  " max_value: "<<max_value <<endl;
    string longest_substring = s1.substr(p1-max_value+1, max_value);
    return longest_substring;
}


int main(){
    string s1 = "kavya";
    string s2 = "yaya";
    cout<< longest_common_substr(s1,s2)<<endl;;

}
