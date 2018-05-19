/*****************************************
 * This program serves as an example for how to
 * use unordered_map api.
 * *************************************/
#include<iostream>
#include<unordered_map>

using namespace std;

int main(){

    unordered_map<string, int> my_map;
    pair<string, int> pair_elem = {"v",1};
    pair<string, int> pair_elem2 = {"a",2};
    my_map.insert(pair_elem);
    my_map.insert(pair_elem2);
    my_map.insert(make_pair("m",3));
    my_map.insert(make_pair("s",4));
    my_map["ee"] = 6;

    // Iterate keys and values
    for(auto iter = my_map.begin(); iter != my_map.end(); ++iter){
        cout<< iter->first << ":"<< iter->second << endl;
    }
    // update a key carefully/ gracefully
    string key ="a";
    auto key_iter = my_map.find(key);
    if(key_iter != my_map.end()){
        key_iter->second = 0;
    }

    // erase
    my_map.erase( next(key_iter));
    my_map.erase( "ee");

    cout<<endl;
    for(auto elem :my_map){
        cout<< elem.first << ":"<< elem.second << endl;
    }
    return 0;
}
