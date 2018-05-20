#include<iostream>
#include<vector>
#include<string>
using namespace std;
class MyQueue{
    public:
        bool enqueue(int val);
        int dequeue();
        void print();
        int size();
    private:
        vector<int> list_elems;
    friend ostream& operator<<(ostream &os, const MyQueue& q);
};
