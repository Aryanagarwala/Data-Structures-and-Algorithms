#include <iostream>
#include <vector>
using namespace std;
//This algorithm finds minimum distance to all nodes from a particular source vertex in a graph, working on negative weights as well.
//It also finds whether a negative weight cycle exists in the graph.
const int N = 1e3; //maximum number of nodes the graph can have
vector<pair<pair<int, int>, long long>> edges;
int V, E;//number of vertices and edges in the Graph
long long ShortestPath[N];
void NegativeWeightCycle(){
    for(int i = 0;i<E;i++){
        if(ShortestPath[edges[i].first.first] + edges[i].second<ShortestPath[edges[i].first.second]){
            cout<<"NEGATIVE WEIGHT CYCLE FOUND"<<endl;
            return;
        }
    }
    cout<<"NO NEGATIVE WEIGHT CYCLE"<<endl;
}
void BellmanFord(int StartingNode){
    for(int i = 0;i<V;i++) ShortestPath[i] = LONG_MAX; //initialising all distances to infinite
    ShortestPath[StartingNode] = 0;
    for(int count = 1;count<V;count++){
        for(int i = 0;i<E;i++){
            if(ShortestPath[edges[i].first.first] + edges[i].second<ShortestPath[edges[i].first.second]){
                ShortestPath[edges[i].first.second] = ShortestPath[edges[i].first.first] + edges[i].second;
            }
        }
    }
    NegativeWeightCycle();
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); //FAST IO
    cin>>V>>E;
    for(int i = 0;i<E;i++){
        int start, end, weight;
        cin>>start>>end>>weight;
        edges.push_back(make_pair(make_pair(start, end), weight));
    }
}