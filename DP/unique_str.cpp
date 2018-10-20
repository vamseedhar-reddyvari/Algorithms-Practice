#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

bool unique_str(string s){
    unordered_set<char> smap;
    for(auto c :s){
        if (smap.find(c) == smap.end()){
            smap.insert(c);
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    string s = "";
    cout<<unique_str(s)<<endl;
}
