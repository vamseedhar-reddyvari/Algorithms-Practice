/******************************************************
 * This program implements StringBuffer class.
 * A StringBuffer provides a method called append which 
 * concatenates string to the existing string. There will not
 * be any copying penalty.
 *
 * ************************* *************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class MyStringBuffer{
    public:
        MyStringBuffer(){};

        bool append(string s){
            for(auto c:s){
                char_array.push_back(c);
            }
            return true;

        }
        string toString(){
            string s(char_array.begin(),char_array.end());
            return s;
        }
    private:
        vector<char> char_array;
};

int main(){

    MyStringBuffer sb;
    sb.append("v");
    cout<<sb.toString()<<endl;
    sb.append("amse");
    cout<<sb.toString()<<endl;
    sb.append("e dhar Reddy");
    cout<<sb.toString()<<endl;
    return 0;

}
