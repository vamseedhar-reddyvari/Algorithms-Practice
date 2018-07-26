#include<iostream>
#include<memory>

using namespace std;

struct LLNode{
    int value;
    unique_ptr<LLNode> next_ptr;
};

class LinkedListUniquePtr{

    private:
        unique_ptr<LLNode> head_ptr;
    public:
    //constructor
    LinkedListUniquePtr() {
        head_ptr = NULL;
    }

    void push_back(int elem){
        // create a new elem 
        unique_ptr<LLNode> newNode (new LLNode());
        newNode->value = elem;
        newNode->next_ptr = NULL;
        //traverse to the end
        unique_ptr<LLNode> *tmp_ptr = &head_ptr;
        while( (*tmp_ptr)!= NULL){
            tmp_ptr = &(*tmp_ptr)->next_ptr;
        }
        //move ownership
        (*tmp_ptr).reset();
        (*tmp_ptr) = move(newNode);
        
    }

    void push_front(int elem){
        unique_ptr<LLNode> newNode(new LLNode());
        newNode->value = elem;
        newNode->next_ptr = move(head_ptr);
        head_ptr = move(newNode);
    }

    void print(){
        print(head_ptr);
        cout<<endl;
    }

    void print(unique_ptr<LLNode> &curr_ptr){
        if(curr_ptr == NULL){
            return;
        } else{
            cout<<curr_ptr->value<<", ";
            print(curr_ptr->next_ptr);
        }
    }

    void print_trusted(){
        unique_ptr<LLNode> *curr_ptr = &head_ptr;
        while( (*curr_ptr) != NULL){
            cout<<(*curr_ptr)->value<<", ";
            curr_ptr = &(*curr_ptr)->next_ptr;
        }
        cout<<endl;
    }
    void print_trusted2(){
        LLNode *curr_ptr = head_ptr.get();
        while(curr_ptr != NULL){
            cout<<curr_ptr->value<<", ";
            curr_ptr = curr_ptr->next_ptr.get();
        }
        cout<<endl;
    }

};

int main(){

    unique_ptr<LinkedListUniquePtr> list (new LinkedListUniquePtr());
    list->push_front(2);
    list->push_front(8);
    list->push_front(12);
    list->push_front(15);
    list->print_trusted();
    list->push_back(27);
    list->push_back(9);
    list->print_trusted();
    return 0;

}
