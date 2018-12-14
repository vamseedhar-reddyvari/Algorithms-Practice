#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>

using namespace std;

bool is_valid_str(string s){
    stack<char> br_stack;
    for(char ch: s){

        unordered_map<char,char> bkt_map = { {')','('}, {'}','{'}, {']','['} };
        if (br_stack.empty()){
            br_stack.push(ch);
        }
        else{
            if(ch == ']' || ch ==')' || ch =='}'){
                if (br_stack.top() == bkt_map[ch] ){
                    br_stack.pop();
                }
                else{
                    return false;
                }
            }
            else{
                br_stack.push(ch);
            }
        }
    }
    if(br_stack.empty()){
        return true;
    }else return false;
}

int main(){
    cout<< is_valid_str("{()[]}")<<endl;
    cout<< is_valid_str("{}()[]}")<<endl;

}
