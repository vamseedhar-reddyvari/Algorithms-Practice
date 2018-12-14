#include<iostream>
#include<memory>
#include<vector>
#include<queue>
#include<cmath>
#include<list>
using namespace std;


class Graph{
    public:
    Graph(int V){
        no_vertices = V;
        list<int> empy_list;
        adj_list_vec.resize(V, empy_list);
    }
    void add_edge(int s, int d){
        adj_list_vec[s].push_back(d);
    }
    void print(){
        for(int i=0; i< no_vertices; i++){
            cout<<i<<": ";
            list<int> a = adj_list_vec[i];
            for(auto it = a.begin(); it != a.end(); it++){
                cout<<(*it)<<",";
            }
            cout<<endl;
        }

    }
    private:
    vector<list<int>> adj_list_vec;
    int no_vertices;

};

int main(){
    Graph* G = new Graph(4);
    G->add_edge(1,3);
    G->add_edge(0,1);
    G->add_edge(0,2);
    G->add_edge(3,2);
    G->print();
}
