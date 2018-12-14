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

void exec_bfs(vector<list<int>> adj_list_vec, int start_idx, vector<bool> &is_visited){
    queue<int> nodes_q;
    nodes_q.push(start_idx);
    while(nodes_q.size() >0 ){
        int curr_node = nodes_q.front();
        if(is_visited[curr_node]) {
            nodes_q.pop();
            continue;
        }
        cout<<nodes_q.front()<<", ";
        // traverse
        auto neigh_list = adj_list_vec[curr_node];
        for(int each_node: neigh_list){
            nodes_q.push(each_node);
        }
        is_visited[curr_node] = true;
        nodes_q.pop();
    }
    cout<<" -- ";
}
void breadth_first_traversal(vector<list<int>> adj_list_vec){
    int V = adj_list_vec.size();
    vector<bool> is_visited(V, false);
    cout<< "BFS Travel: "<<endl;
    for(int i= 0; i< V; i++){
        if (!is_visited[i]) 
            exec_bfs(adj_list_vec, i, is_visited);
    }
    cout<<endl;
    return;
}

void depth_first_traversal(vector<list<int>> adj_list_vec){
    int V = adj_list_vec.size();
    vector<bool> is_visited(V, false);
    stack<int> nodes_stack;
    nodes_stack.push(0);
    cout<<"DFS Traversal:";
    while(nodes_stack.size() > 0){
        int curr_node = nodes_stack.top();
        nodes_stack.pop();
        if(is_visited[curr_node]) continue;
        cout<<curr_node<<", ";
        for(auto each_child : adj_list_vec[curr_node]){
            nodes_stack.push(each_child);
        }
        is_visited[curr_node] = true;
    }
    cout<<endl;
}

void exec_depth_recursive(int idx, const vector<list<int>> &adj_list_vec, vector<int>& is_visited){
    if(is_visited[idx]) return;
    cout<< idx <<", ";
    is_visited[idx] = true;
    for(auto each_child: adj_list_vec[idx]){
        exec_depth_recursive(each_child, adj_list_vec, is_visited);
    }
    return;
}

void depth_recursive(const vector<list<int>> &adj_list_vec){
    cout<<"Depth Recursive: ";
    vector<int> is_visited(adj_list_vec.size(), false);
    for(int i = 0; i < adj_list_vec.size(); i++){
        if (!is_visited[i]) {
            exec_depth_recursive(i , adj_list_vec, is_visited);
            cout<<" -- ";
        }
    }
    cout<<endl;

}


int main(){
    Graph* G = new Graph(13);
    G->add_edge(1,3);
    G->add_edge(0,2);
    G->add_edge(0,1);
    G->add_edge(3,2);
    G->add_edge(3,4);
    G->add_edge(2,5);
    G->add_edge(4,6);
    G->add_edge(7,8);
    G->add_edge(8,2);
    G->add_edge(8,9);
    G->add_edge(10,12);
    G->add_edge(11,9);
    G->print();

    breadth_first_traversal(G->adj_list_vec);
    depth_first_traversal(G->adj_list_vec);


    depth_recursive(G->adj_list_vec);
}
