#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

bool is_unique_hash(string str){
    if(str.size() ==0){
        return true;
    }
    unordered_map<char,int> count_map;
    for(char c: str){
        if(count_map.find(c) == count_map.end() ){
            count_map[c] = 1;
        }
        else{
            count_map[c] += 1;
        }
    }
    for(auto elem: count_map){
        if(elem.second >1)
            return false;
    }
    return true;

}

bool is_unique_sort(string str){
    if(str.size() ==0){
        return true;
    }
    sort(str.begin(), str.end());
    for(int i=0; i<str.size()-1; i++){
        if(str[i] == str[i+1]){
            return false;
        }

    }

    return true;

}


int main(){
    string s1("vamsee");
    cout<< is_unique_hash(s1)<<" "<< is_unique_sort(s1)<<endl;
    s1="dhar";
    cout<< is_unique_hash(s1)<<" "<< is_unique_sort("")<<endl;
    return 0
}
