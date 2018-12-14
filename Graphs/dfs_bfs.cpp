#include<iostream>
#include<memory>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

struct GraphNode{
    int value;
    vector<GraphNode*> list_neighbours;
    bool visited = false;
    GraphNode(int x){ value = x; }

};


void print_dfs( GraphNode* root){
    cout<< root->value <<", ";
    root->visited = true;
    for(auto & each_sub_graph : root->list_neighbours){
        if(! (each_sub_graph -> visited) ){
            print_dfs(each_sub_graph);
        }
    }
}

void print_bfs( GraphNode* root){
    queue<GraphNode*> nodes_queue;
    nodes_queue.push(root);
    while(1){
        auto top = nodes_queue.front();
        cout<< top->value <<", ";
        top->visited = true;
        nodes_queue.pop();
        for(auto & each_neighbour: top->list_neighbours){
            if(! (each_neighbour -> visited) ){
                nodes_queue.push(each_neighbour);
            }
        }
        if(nodes_queue.size() == 0) return;
    }
    
}




int main(){
/*   ------->n5( 10)--------------------------------- 
    |                                                |
   r(5) ----> n1(2)------------------->               |
        |                             |              |
        -----> n2(3) ---> n3(-1) ----> n4(-7) ----------|
  */
    auto root = new GraphNode(5);

    auto node1 = new GraphNode(2);
    auto node2 = new GraphNode(3);

    root->list_neighbours.push_back(node1);
    root->list_neighbours.push_back(node2);

    auto node3 = new GraphNode(-1);
    auto node4 = new GraphNode(-7);
    node2->list_neighbours.push_back(node3);
    node3->list_neighbours.push_back(node4);
    node1->list_neighbours.push_back(node4);

    auto node5 = new GraphNode(10);
    root->list_neighbours.push_back(node5);
    node4->list_neighbours.push_back(node5);

    //print_dfs(root);
    cout<<endl<< "BFS: ";

    print_bfs(root);
    cout<<endl;

}

