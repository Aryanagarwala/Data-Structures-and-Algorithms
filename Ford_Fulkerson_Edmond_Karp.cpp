#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//This algorithm uses BFS to find the Maximum Flow in a graph.
//It works by running BFS and finding the shortest Augumented Path (A path in which every edge has some residual flow)
//It then runs the maximum possible flow through this path and adds reverse direction residual flow to the edges
//Keep running this BFS until there is no augumented path remaining

int main(){
    int V, E;
    cin>>V>>E;
    int ResidualFlow[V][V];
    for(int i = 0;i<V;i++){
        for(int j = 0;j<V;j++){
            ResidualFlow[i][j] = 0;
        }
    }
    vector<int> AdjacencyList[V];
    for(int i = 0;i<E;i++){
        int start, end, flow;
        cin>>start>>end>>flow;
        AdjacencyList[start].push_back(end);
        ResidualFlow[start][end] = flow;
    }
    int source, sink;
    cin>>source>>sink;
    int MaxFlow = 0;
    bool AugumentedPathExists = true;
    while(AugumentedPathExists){
        AugumentedPathExists = false;
        bool NodeVisited[V];
        int Parent[V];
        for(int i = 0;i<V;i++){
            NodeVisited[i] = false;
            Parent[i] = -1;
        }
        queue<int> NextNode;
        NextNode.push(source);
        NodeVisited[source] = true;
        while(!NextNode.empty() && !AugumentedPathExists){
            int CurrentNode = NextNode.front(); NextNode.pop();
            for(int Neighbour: AdjacencyList[CurrentNode]){
                if(!NodeVisited[Neighbour] && ResidualFlow[CurrentNode][Neighbour]){
                    NodeVisited[Neighbour] = true;
                    Parent[Neighbour] = CurrentNode;
                    NextNode.push(Neighbour);
                }
            }
            if(CurrentNode == sink){
                AugumentedPathExists = true;
                int GeneratedFlow = 1e8;
                while(Parent[CurrentNode]!=(-1)){
                    GeneratedFlow = min(GeneratedFlow, ResidualFlow[Parent[CurrentNode]][CurrentNode]);
                    CurrentNode = Parent[CurrentNode];
                }
                CurrentNode = sink;
                while(Parent[CurrentNode]!=(-1)){
                    ResidualFlow[Parent[CurrentNode]][CurrentNode] -= GeneratedFlow;
                    ResidualFlow[CurrentNode][Parent[CurrentNode]] += GeneratedFlow;
                    CurrentNode = Parent[CurrentNode];
                }
                MaxFlow += GeneratedFlow;
            }
        }
    }
    cout<<MaxFlow<<endl;
}