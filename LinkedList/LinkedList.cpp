#include<iostream>
#include <gsl/gsl>

using namespace std;


struct LLNode{
    int value;
    LLNode* next_ptr;
    ~LLNode(){
        cout<<"Calling LLNode destructor"<<endl;
    }
};


class MyLinkedList{

    private:
        LLNode* llist;
    public:
    //constructor
    MyLinkedList(int v) {
        llist = new LLNode();
        llist->next_ptr = NULL;
        llist->value = v;
    }
    MyLinkedList() {
        llist = NULL;
    }

    LLNode* push_front(int elem){
        LLNode * newNode = new LLNode;
        newNode->value = elem;
        newNode->next_ptr = llist;
        llist = newNode;
        return llist;

    }

    void delete_node(LLNode* prev_ptr){
        LLNode *dangle = prev_ptr->next_ptr;
        LLNode *tmp_ptr = prev_ptr->next_ptr->next_ptr;
        prev_ptr->next_ptr = tmp_ptr;
        delete dangle;
    }


    void print(){
        LLNode* iter_ptr = llist;
        while(iter_ptr !=NULL){
            cout<<iter_ptr->value<<" ";
            iter_ptr = iter_ptr->next_ptr;
        }
        cout<<endl;

    }

    LLNode* head(){
        return llist;
    }

    ~MyLinkedList(){
      LLNode* iter_ptr = llist;
      while(iter_ptr != NULL){
        LLNode* tmp_ptr = iter_ptr->next_ptr ;
        delete iter_ptr;
        iter_ptr = tmp_ptr;
      }

    }

};


int main(){

    MyLinkedList *list = new MyLinkedList();
    list->push_front(2);
    list->push_front(23);
    list->push_front(4);
    list->push_front(6);
    list->push_front(47);
    list->push_front(48);
    list->print();
    list->delete_node(list->head()->next_ptr);
    list->print();
    delete list;
    return 0;

}
