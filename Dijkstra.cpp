#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
//This algorithm finds the minimum distance to all nodes in a weighted graph from a particular source vertex.
//It does not work on graphs with negative weights, refer to Bellman Ford for such an algorithm.
const int N = 1e3; //maximum number of nodes the graph can have
int EdgeWeight[N][N];//store weight of edges
vector<int> AdjacencyList[N];//Adjacency List to store the Graph
int nodes, edges;//number of nodes and edges in the Graph
long long ShortestPath[N];
void Dijkstra(int StartingNode){
    for(int i = 0;i<nodes;i++) ShortestPath[i] = LONG_MAX; //initialising all distances to infinite
    ShortestPath[StartingNode] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Queue; //priority queue for storing weights
    Queue.push({0, StartingNode}); //inserting starting node with 0 weight
    while(!Queue.empty()){
        pair<long long, int> CurrentNode = Queue.top();
        Queue.pop();
        for(int neighbour:AdjacencyList[CurrentNode.second]){
            if(CurrentNode.first + EdgeWeight[CurrentNode.second][neighbour]<ShortestPath[neighbour]){
                ShortestPath[neighbour] = CurrentNode.first + EdgeWeight[CurrentNode.second][neighbour];
                Queue.push(make_pair(ShortestPath[neighbour], neighbour));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); //FAST IO
    cin>>nodes;
    cin>>edges;
    //creating adjacency list
    for(int i = 0;i<edges;i++){
        int start, end, weight;
        cin>>start>>end>>weight;
        AdjacencyList[start].push_back(end);
        EdgeWeight[start][end] = weight;
    }
}

