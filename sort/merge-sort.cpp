/******************************************************
 *
 * Takes an array and reorders such that all 
 * elements in even position are at the beginning
 *
 * ******************************************************/
#include<iostream>
using namespace std;


void merge_sort(int* array, int start, int end){

    if(start >= end){
        return;
    }
    int mid = start+ (end-start)/2;
    merge_sort(array, start, mid);
    merge_sort(array, mid+1, end);

    //combine
    int len = end-start+1;
    int new_array[len];

    int left_idx = start;
    int right_idx = mid+1;
    for(int i = 0; i <len; i++){

        if(left_idx > mid){
            new_array[i] = array[right_idx];
            right_idx++;
        }
        else if(right_idx > end){
            new_array[i] = array[left_idx];
            left_idx++;
        }
        else if(array[left_idx] < array[right_idx]){
            new_array[i] = array[left_idx];
            left_idx++;
        }
        else if(array[left_idx] >= array[right_idx]){
            new_array[i] = array[right_idx];
            right_idx++;
        }
    }
    // copy back
    for(int i = 0; i <len; i++){
        array[start+i] = new_array[i];
    }
    return;

}


int main(){

    int a[] = {6,2,3,9,23,69,12,10};
    merge_sort(a, 0, 7);

    for(int i =0;i< 8; i++){
        cout<<a[i]<<", ";
    }
    cout<<endl;
}
