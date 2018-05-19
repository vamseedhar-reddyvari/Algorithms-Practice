#include<iostream>

using namespace std;

void reverse(char * input_str){
    //Takes a null terminated string as input and returns a string in-place
    int fwd_idx,  bkwd_idx;
    // point bwd_ptr to last elem
    fwd_idx = 0;
    for(int i=0; ;i++){
        if(input_str[i] == '\0'){
            bkwd_idx = i-1;
            break;
        }
    }
    while(bkwd_idx > fwd_idx){
        // swap
        char tmp = input_str[fwd_idx];
        input_str[fwd_idx] = input_str[bkwd_idx];
        input_str[bkwd_idx] = tmp;
        // update
        bkwd_idx--;
        fwd_idx++;
    }

}

int main(){

    char str1[] = {'v','a','m','s','\0'};
    char str2[] = {'k', 'a', 'v', 'y','a','\0'};
    cout<<str1<<endl;
    cout<<str2<<endl;
    reverse(str1);
    reverse(str2);
    cout<<str1<<endl;
    cout<<str2<<endl;

    return 0;

}
