
#include<iostream>
#include<memory>
#include<vector>
#include<queue>
#include<cmath>
#include<list>
#include<stack>
using namespace std;



class Graph{
    public:
    vector<list<int>> adj_list_vec;
    int no_vertices;
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

};
bool exec_bfs(int start_idx, vector<list<int>> adj_list_vec, vector<int> & color_nodes, vector<bool>  & is_visited){
    queue<int> nodes_q;
    nodes_q.push(start_idx);
    int curr_color = 1;
    int next_color = 2;
    color_nodes[start_idx] = curr_color;
    while(nodes_q.size() > 0){
        int curr = nodes_q.front();
        if(is_visited[curr]) continue;
        is_visited[curr] = true;

        curr_color = color_nodes[curr];
        if(curr_color == 1) next_color = 2;
        else next_color = 1;

        cout<<" curr node: "<<curr;
        nodes_q.pop();
        
        for(auto each_child: adj_list_vec[curr]){
            cout<<" child node: "<< each_child;
            if(color_nodes[each_child] == curr_color) return false;
            else if(!is_visited[each_child]) {
                nodes_q.push(each_child);
                color_nodes[each_child] = next_color;
            }
        }
        cout<<endl;
        for(auto elem : color_nodes){
            cout<< elem<<",";
        }
        cout<<endl;
    }
    return true;
}

bool is_bipartite(vector<list<int>> adj_list_vec){

    /*
     * 0 - denotes not visited
     * 1 - color red or group 1
     * 2 - color blue or group 2
     */
    vector<int> color_nodes(adj_list_vec.size(), 0);
    vector<bool> is_visited(adj_list_vec.size(), false);

    // Lets do BFS and make sure there no edges between same colors
    int V = adj_list_vec.size();
    for(int i=0 ; i< V; i++){
        if(!is_visited[i])
            if(!exec_bfs(i, adj_list_vec, color_nodes, is_visited))  return false;
    }
    return true;
}
int main(){
    Graph* G = new Graph(7);
    G->add_edge(1,3);
    G->add_edge(0,2);
    G->add_edge(0,6);
    G->add_edge(4,2);
    G->add_edge(5,6);
    G->add_edge(4,3);
    G->add_edge(4,0);
    G->print();

    cout<<"Is Bipartitie: " ;
    if(is_bipartite(G->adj_list_vec))  cout<< " True"<<endl;
    else cout<<" False"<<endl;

}
