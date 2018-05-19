#include"Mystack.h"

using namespace std;

bool MyStack::push(int val){
    elem_array.push_back(val);
    return true;
}
int MyStack::pop(){
    int temp = elem_array[elem_array.size()-1];
    elem_array.erase(elem_array.end()-1);
    return temp;
}
void MyStack::print(){
    for(auto elem: elem_array){
        cout<<elem << ",";
    }
    cout<<endl;
}
int MyStack::size(){
    return elem_array.size();
}

class ArrayStack{
    public:
        ArrayStack(){
            elem_array = new int(20);
            len = 0;
        }
        void push(int val){
            elem_array[len] = val;
            len++;
        }
        int pop(){
            int temp = elem_array[len-1];
            elem_array[len-1] = 0;
            len--;
            return temp;
        }
        void print(){
            for(int i=0; i<len; i++){
                cout<<elem_array[i]<<",";
            }
            cout<<endl;
        }
        int size(){
            return len;
        }
    private:
        int * elem_array;
        int len ;
};

int main(){
    MyStack st;
    st.push(2);
    st.push(5);
    st.push(4);
    st.push(11);
    st.push(4);
    st.push(9);
    MyStack st2;
    st2 = st;
    st2.pop();
    st.print();
    st2.print();

    ArrayStack st3;
    st3.push(2);
    st3.push(5);
    st3.push(4);
    st3.push(11);
    st3.push(4);
    st3.push(9);
    ArrayStack st4;
    st4 = st3;
    st4.pop();
    st4.pop();
    st4.pop();
    st3.print();
    st4.print();
}



