#include<iostream>
#include<vector>
#include<string>
using namespace std;
class MyStack{
    public:
        bool push(int val);
        int pop();
        int peek();
        void print();
        int size();
    private:
        vector<int> elem_array;
};
