#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;


string sub_str_no_repitions(string s){

    int p = s.size();
    unordered_map<char, int> smap;
    /*for(int i=0; i<p; i++){
        smap[s[i]] = i ;
        cout<<s[i]<<":"<<i<<" ";
    }
    cout<<endl;
    */


    vector<int> Long_suffix_unique_str(p,0);
    smap[s[0]] = 0 ;
    Long_suffix_unique_str[s[0]] = 0;
    for(int i = 0; i< p-1; i++){
        //cout<<"i: "<< i << " ::s[i+1]: "<<s[i+1]<<" smap[s[i+1] "<< smap[s[i+1]]<<endl; 
        if(smap.find(s[i+1]) == smap.end() ){
            Long_suffix_unique_str[i+1] = Long_suffix_unique_str[i];
        }
        else{
            int j = smap[s[i+1]];
            if( j < Long_suffix_unique_str[i] ){
                Long_suffix_unique_str[i+1] = Long_suffix_unique_str[i];
            }
            else{
                Long_suffix_unique_str[i+1] = smap[s[i+1]]+1;
            }

        }
        cout<< ":: "<<i+1<<" "<< Long_suffix_unique_str[i+1]<<endl; 
        smap[s[i+1]] = i+1;
    }

    for(int i=0; i<p; i++){
        cout<< smap[s[i]]<< ", ";
    }
    cout<<endl;
    int max_value = 0;
    int idx = 0;
    for (int i =0 ; i< p; i++){
        int t = i+1-Long_suffix_unique_str[i];
        if(t >= max_value){
            max_value = t;
            idx = i;
        }
    }

    string longstr = s.substr(idx-max_value+1,max_value);

    return longstr;

}





string length_longest_unique_substring(string s){
    int p = s.size();
    int max_value = 0;
    int max_idx = 0;

    int j = 0;
    int i = 0;
    unordered_set<char> sset;
    while(i< p){
        while(j< p){
            if(sset.find(s[j]) == sset.end()){
                // char doesn't exist before
                sset.insert(s[j]);
                if(max_value < sset.size()){
                    max_value = sset.size();
                    max_idx = i;
                }
            }
            else{
                sset.erase(s[i]);
                break;
            }
            j = j+1;
        }
        i = i+1;
    }
    return s.substr(max_idx,max_value);

}


int main(){

    string s = "dvdf";
    
    cout<< sub_str_no_repitions(s)<<endl;
    cout<< length_longest_unique_substring(s)<<endl;


}
