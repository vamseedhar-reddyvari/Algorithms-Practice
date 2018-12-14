#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;


bool is_valid(string s){
    int i =0;
    for(char ch: s){
            if(ch =='(') i++;
            else if(ch ==')'){
                i = i-1;
                if(i <0) return false;
            }
    }
    if( i != 0) return false;
    else return true;
}

bool filter(vector<char> &bkt_holder, int pos){
    int open_bkts = 0;
    int closed_bkts = 0;
    for(int i = 0; i< pos; i++){
        if(bkt_holder[i] == '('){
            open_bkts++;
        }
        else closed_bkts++;
    }
    if(open_bkts > bkt_holder.size()/2) return false; 
    else if(closed_bkts > open_bkts) return false;
    return true;
}

void optimal_recur_bkt_gen(vector<string> &bkt_array, vector<char> &bkt_holder, int pos){
    if(pos ==  bkt_holder.size()){
        string s(bkt_holder.begin(), bkt_holder.end());
        if(is_valid(s)){
            bkt_array.push_back(s);
        }
        return;
    }

    // Check no of open bkts are less than n/2 and no of closed bkts are less than open
    bkt_holder[pos] = '(';
    if(filter(bkt_holder, pos)){
        optimal_recur_bkt_gen(bkt_array, bkt_holder, pos+1);
    }
    bkt_holder[pos] = ')';
    if(filter(bkt_holder, pos)){
        optimal_recur_bkt_gen(bkt_array, bkt_holder, pos+1);
    }
}


vector<string> generateParenthesis(int n){
    vector<string> bkt_array;
    vector<char> bkt_holder(2*n,' ');
    optimal_recur_bkt_gen(bkt_array, bkt_holder, 0);
    return  bkt_array;
}


vector<string> recur_bkt_gen(int n, int K){
    vector<string> all_strings;
    if(n == 1){
        all_strings.push_back("(");
        all_strings.push_back(")");
    }
    else{
        for(const string s : recur_bkt_gen(n-1, K) ){
                all_strings.push_back(s + "(");
                all_strings.push_back(s + ")");
        }
    }
    int len = all_strings[0].size();
    if(len > 30*K){
        for(int i=0; i < all_strings.size(); i++){
            // If number of ( are more than n then remove it
            int no_fwd_bkts = 0;
            for(char c: all_strings[i]){
                if(c == '(') no_fwd_bkts = no_fwd_bkts +1;
            }
            if(no_fwd_bkts > n){
                all_strings.erase(all_strings.begin() +i);
                i = i-1;
            }
        }
    }
    return all_strings;
}

vector<string> generateParenthesis2(int n){
    auto all_strings = recur_bkt_gen(2*n, n);
    for(int i = 0; i< all_strings.size(); i++){
        if(!is_valid(all_strings[i])){
            all_strings.erase(all_strings.begin()+ i);
            i = i-1;
        }

    }
    return  all_strings;
}


void display(vector<string> ss){
    for(auto s: ss){
        cout<<s << ", ";
    }
    cout<<endl;
}

int main(){

   // /*
   display(generateParenthesis(1));
   display(generateParenthesis(2));
   display(generateParenthesis(3));
   display(generateParenthesis(4));
//   display(generateParenthesis(7));
 //  display(generateParenthesis(9));
   //*/

    
   display(generateParenthesis2(1));
   display(generateParenthesis2(2));
   display(generateParenthesis2(3));
   display(generateParenthesis2(4));
   
}
