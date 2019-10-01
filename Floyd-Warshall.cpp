#include <iostream>
#include <vector>
using namespace std;
//This algorithm finds the shortest path between all pairs of nodes in a graph
//This is an intuitive algorithm which keeps on checking whether the path between two nodes through an intermediary node is shorter than the
//direct path.
int INF = 1e8;
int main(){
    int V, E;
    cin>>V>>E;
    int ShortestPath[V][V];
    for(int i = 0;i<V;i++) for(int j = 0;j<V;j++) ShortestPath[i][j] = INF;
    for(int i = 0;i<V;i++) ShortestPath[i][i] = 0;
    for(int i = 0;i<E;i++){
        int start, end, weight;
        cin>>start>>end>>weight;
        ShortestPath[start-1][end-1] = weight;
    }
    for(int k = 0;k<V;k++)
        for(int i = 0;(i+k)<V;i++)
            for(int j = 0;j<V;j++)
                ShortestPath[i][j] = min(ShortestPath[i][i+k] + ShortestPath[i+k][j], ShortestPath[i][j]);
}