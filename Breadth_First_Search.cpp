#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
//This is a graph traversal method that finds shortest path in an unweighted graph
//It traverses the graph in level order
void BreadthFirstSearch(int Source, vector<int> AdjacencyList[], int Nodes, int ShortestPath[Nodes]){
    bool NodeVisited[Nodes];
    for(int i = 0;i<Nodes;i++) NodeVisited[i] = false;
    queue<pair<int, int>> Queue; //first element contains the node, second element contains shortest distance to the node
    Queue.push(make_pair(Source, 0));
    NodeVisited[Source] = true;
    while(!Queue.empty()){
        pair<int, int> CurrentNode = Queue.front(); Queue.pop();
        ShortestPath[CurrentNode.first] = CurrentNode.second;
        for(int Neighbour: AdjacencyList[CurrentNode.first]){
            if(!NodeVisited[Neighbour]){
                Queue.push(make_pair(Neighbour, CurrentNode.second + 1));
                NodeVisited[Neighbour] = true;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); //FAST IO
    int Nodes, Edges, Source;
    cin>>Nodes>>Edges>>Source;
    vector<int> AdjacencyList[Nodes];//Adjacency List to store the Graph
    int ShortestPath[Nodes];
    //creating adjacency list
    for(int i = 0;i<Edges;i++) {
        int start, end;
        cin >> start >> end;
        AdjacencyList[start].push_back(end);
    }
    BreadthFirstSearch(Source, AdjacencyList, Nodes, ShortestPath);
}