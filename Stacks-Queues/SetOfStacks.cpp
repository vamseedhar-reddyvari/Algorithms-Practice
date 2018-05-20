#include"Mystack.h"
using namespace std;
class SetOfStacks{
    public:
        void push(int val);
        int pop();
        void popAt(int index){}
        void print();

    private:
        int capacity = 3;
        vector<MyStack *> stack_array;

};

void SetOfStacks::print(){
    for(auto each_stack: stack_array){
        each_stack->print();
        cout<<" | ";
    }
    cout<<endl;

}
int SetOfStacks::pop(){
    int number_stacks = stack_array.size();
    MyStack* last_stack = stack_array[number_stacks-1];
    int temp = last_stack->pop();
    if (last_stack->size() == 0){
        stack_array.erase(--stack_array.end());
    }
    return temp;
}

void SetOfStacks::push(int val){
    int number_stacks = stack_array.size();
    if (number_stacks ==0){
        MyStack* new_stack = new MyStack;
        new_stack->push(val);
        stack_array.push_back(new_stack);
    } else {
        auto last_stack = stack_array[number_stacks-1]; //Should be better way
        if( last_stack->size() < capacity){
            last_stack->push(val);
        }
        else {
            MyStack *new_stack = new MyStack();
            new_stack->push(val);
            stack_array.push_back(new_stack);
        }

    }

}


int main(){
    SetOfStacks st;
    st.push(2);
    st.push(5);
    st.push(4);
    st.push(11);
    st.push(4);
    st.push(9);
    st.push(41);
    st.print();
    st.push(5);
    st.push(67);
    st.print();
    st.pop();
    st.pop();
    st.pop();
    st.print();
    st.pop();
    st.print();
    SetOfStacks& st2 = st;
    st2.print();
    st2.pop();
    st2.print();
    st.print();
    st2.pop();
    st2.print();
    st.print();
}

