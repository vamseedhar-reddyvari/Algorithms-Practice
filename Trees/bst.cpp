#include<iostream>
#include<memory>
#include<vector>
#include<cmath>
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
            cout << "Height: "<<height()<<" Contents: ";
            print_inorder(root_ptr);
            cout<<endl;
        }

        void print_post(){
            print_postorder(root_ptr);

            cout<<endl;
        }

        int height(){

            return height_recursive(root_ptr);
        }

        int height_recursive(Node *temp_ptr){
            if (temp_ptr == NULL) return 0;
            if(temp_ptr->right_ptr == NULL && temp_ptr->left_ptr == NULL){
                return 1;
            } else {
                return 1+max(height_recursive(temp_ptr->left_ptr), height_recursive(temp_ptr->right_ptr) );

            }

        }

        void print_row(vector<vector<string>> &vstring, Node*  root_ptr,  int row_idx, int column_idx, int h){

            int offset = pow(2,h-2);
            vstring[row_idx][column_idx] = to_string(root_ptr->key);
            if(root_ptr->left_ptr !=NULL){
                print_row(vstring, root_ptr->left_ptr,  row_idx+1, column_idx-offset, h-1);
            }
            if(root_ptr->right_ptr !=NULL){
                print_row(vstring, root_ptr->right_ptr,  row_idx+1, column_idx+offset, h-1);
            }

        }


        vector<vector<string>> print_string_fmt(){
            vector<vector<string>> vstring;
            //fill vstrings mxn dimension with _
            int h = height();
            for(int m = 1; m<= h; m++){
                vector<string> v;
                for(int n = 1; n<= pow(2,h)-1; n++){
                    v.push_back("_");
                }
                vstring.push_back(v);
            }
            // update each column
            print_row(vstring, root_ptr, 0, (pow(2,h) -2)/2, h);
            return vstring;


        }


        void tree_print(){
            vector<vector<string>> vstring = print_string_fmt();
            for(int i = 0; i <vstring.size(); i++){
                for(int j=0; j< vstring[i].size(); j++){
                    cout<<vstring[i][j]<<", ";
                }
                cout<<endl;

            }
            cout<<"###########################"<<endl;
        }
};


int main(){
    BinarySearchTree* mytree = new BinarySearchTree(10);
    mytree->print();
    mytree->insert(20);
    mytree->insert(5);
    mytree->tree_print();
    mytree->insert(7);
    mytree->tree_print();
    mytree->insert(4);
    mytree->insert(8);
    mytree->insert(3);
    mytree->tree_print();
    mytree->insert(4);
    mytree->insert(5);
    mytree->insert(5);
    mytree->insert(6);
    mytree->insert(2);
    mytree->print();
    mytree->tree_print();
    mytree->insert(40);
    mytree->tree_print();
    mytree->insert(50);
    mytree->tree_print();
    mytree->insert(30);
    mytree->tree_print();


    return 0;
}
