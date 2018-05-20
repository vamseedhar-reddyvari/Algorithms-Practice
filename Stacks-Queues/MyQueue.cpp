#include"MyQueue.h"
using namespace std;

bool MyQueue::enqueue(int val){
    list_elems.push_back(val);
    return true;
}
int MyQueue::dequeue(){
    int temp = list_elems[0];
    list_elems.erase(list_elems.begin());
    return temp;
}
void MyQueue::print(){
    for(auto elem: list_elems){
        cout<<elem << ",";
    }
    cout<<endl;
}
int MyQueue::size(){
    return list_elems.size();
}
ostream& operator<<(ostream &os, const MyQueue& q){
    for(auto elem : q.list_elems){
        os<< elem<<"," ;
    }
    return os;
}

void driver_queueu(){
    MyQueue q1;
    q1.enqueue(10);
    q1.enqueue(2);
    q1.enqueue(5);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(3);
    q1.print();
    cout<<q1<<endl;
    q1.dequeue();
    q1.print();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    cout<<q1<<endl;
}

int main(){
    driver_queueu();
    return 0;
}
