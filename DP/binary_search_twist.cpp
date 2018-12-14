#include<iostream>
#include<string>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int target, int start_idx, int end_idx){
    //cout<<"target: "<< target << " start_idx: "<<start_idx<<" end_idx: "<<end_idx<<endl;
    int len = end_idx - start_idx ;
    if(len == 0){
        return -1;
    }
    if(len == 1){
        if (nums[start_idx] == target) return start_idx;
        else return -1;
    }
    else{
        int middle = start_idx + (len)/2;
        if (nums[middle] == target) return middle;
        else if(nums[middle] > target ){
            return binarySearch(nums, target, start_idx, middle);
        }
        else if(nums[middle] < target ){
            return binarySearch(nums, target, middle+1, end_idx);
        }
    }

}

vector<int> searchRange(vector<int>& nums, int target) {
    int found_idx = binarySearch(nums, target, 0, nums.size());

    // Found idx now scan around the index to get srat and end
    int start_idx = -1;
    int ending_idx = -1;
    if(found_idx != -1){
        int idx = 0;
        //cout<<"found_idx "<<found_idx<<endl;
        for(idx = found_idx; idx >= 0; idx--){
            if(nums[idx] != target){
                break;
            }
        }
        start_idx = idx+1;
        for(idx = found_idx; idx < nums.size(); idx++){
            if(nums[idx] != target){
                break;
            }
        }
        ending_idx = idx-1;

    }

    vector<int> result;
    result.push_back(start_idx);
    result.push_back(ending_idx);
    
    return result;
}
int main(){
    vector<int> nums = {2,4,6,6,7,8,11,12,12,12};
    auto a = searchRange( nums, 6);
    cout<<a[0]<<", "<<a[1]<<endl;
    auto b = searchRange( nums, 9);
    cout<<b[0]<<", "<<b[1]<<endl;
    auto c = searchRange( nums, 12);

    cout<<c[0]<<", "<<c[1]<<endl;

}
