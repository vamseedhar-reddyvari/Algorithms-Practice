#include<iostream>
#include<memory>
using namespace std;
struct Node{

    int key;
    Node* right_ptr;
    Node* left_ptr;

};

class BinarySearchTree{

    private:
        Node* root_ptr = NULL;
        void print_inorder(Node* root_ptr){
            if(root_ptr == NULL){
                return;
            }

            print_inorder(root_ptr->left_ptr);
                cout<<root_ptr->key<< ", ";
            print_inorder(root_ptr->right_ptr);
        }

        void print_postorder(Node* root_ptr){
            if(root_ptr == NULL){
                return;
            }

            print_postorder(root_ptr->right_ptr);
                cout<<root_ptr->key<< ", ";
            print_postorder(root_ptr->left_ptr);
        }

        void insert_recursive(Node* root_ptr, int value){
            if(value <= root_ptr->key){

                if(root_ptr->left_ptr == NULL){
                    Node* new_node = new Node();
                    new_node->key = value;
                    new_node->left_ptr = NULL;
                    new_node->right_ptr = NULL;
                    root_ptr->left_ptr = new_node;
                    return;
                } 
                else{
                    insert_recursive(root_ptr->left_ptr, value);
                }
            }
            else if(value > root_ptr->key){
                if(root_ptr->right_ptr == NULL){
                    Node* new_node = new Node();
                    new_node->key = value;
                    new_node->left_ptr = NULL;
                    new_node->right_ptr = NULL;
                    root_ptr->right_ptr = new_node;
                    return;
                } 
                else{
                    insert_recursive(root_ptr->right_ptr, value);
                }

            }


        }

    public:
        BinarySearchTree(int value){
            Node* newNode = new Node();
            newNode->key = value;
            newNode->left_ptr = NULL;
            newNode->right_ptr = NULL;
            root_ptr = newNode;
        }

        void insert(int value){
            insert_recursive(root_ptr, value);
        }


        void print(){
            print_inorder(root_ptr);
            cout<<endl;
        }

        void print_post(){
            print_postorder(root_ptr);
            cout<<endl;
        }

};


int main(){
    BinarySearchTree* mytree = new BinarySearchTree(10);
    mytree->print();
    mytree->insert(20);
    mytree->insert(1);
    mytree->insert(7);
    mytree->print();
    mytree->insert(40);
    mytree->print();
    mytree->print_post();


    return 0;
}
