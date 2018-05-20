/******************************************************
 *
 * Takes an array and reorders such that all 
 * elements in even position are at the beginning
 *
 * ******************************************************/
#include<iostream>
using namespace std;


void even_reorder(int *given_array, int length){
    int* new_array = new int(length);
    int odd_index_begin = 0;
    if(length%2 == 0)
        odd_index_begin = length/2;
    else
        odd_index_begin  = (length+1)/2;

    int even_ptr = 0;
    int odd_ptr = odd_index_begin;

    for(int i=0; i< length; i++){
        if(i %2 == 0){
            new_array[even_ptr] = given_array[i];
            even_ptr++;
        }else{
            new_array[odd_ptr] = given_array[i];
            odd_ptr++;
        }
    }
    for(int i=0; i< length; i++){
            given_array[i] = new_array[i];
    }
}

void myswap(int * a , int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void even_reorder_inplace(int *given_array, int length){
    int current_idx = 1;
    for(int i=1; i < length; i++){
        if(i%2 == 0){
            swap(given_array[current_idx] , given_array[i]);
            current_idx =current_idx+1;
        }
    }

}

int main(){
    int a[] = {0,1,2,3,4,5,6};
    even_reorder_inplace(a, 7);
    for(int i=0; i<7; i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
