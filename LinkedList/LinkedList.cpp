#include<iostream>

using namespace std;


struct LLNode{
    int value;
    LLNode* next_ptr;
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
        LLNode *tmp_ptr = prev_ptr->next_ptr->next_ptr;
        prev_ptr = tmp_ptr;
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
    return 0;

}
