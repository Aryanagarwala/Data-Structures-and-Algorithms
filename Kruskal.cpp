#include <iostream>
#include <vector>
using namespace std;
//Kruskal's Algorithm is a greedy algorithm to find the minimum spanning tree in a graph.
//The algorithm works by sorting edges according to their weight and adding them if their endpoints are not already in the same component
const int N = 1e5;
int root[N];
int RANK[N];
int FindRoot(int i){
    if(root[i] == i) return i;
    return root[i] = FindRoot(root[i]);
}
bool UNION(int i, int j){
    int RootOfI = FindRoot(i);
    int RootOfJ = FindRoot(j);
    if(RootOfI==RootOfJ) return false;
    if(RANK[RootOfJ]<RANK[RootOfI]){
        root[j] = i;
        RANK[i]+=RANK[j];
    }
    else{
        root[i] = j;
        RANK[j]+=RANK[i];
    }
    return true;
}
int main(){
    int V, E;
    cin>>V>>E;
    for(int i = 0;i<V;i++){
        root[i] = i;
        RANK[i] = 1;
    }
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0;i<E;i++){
        int weight, start, end;
        cin>>start>>end>>weight;
        edges.push_back(make_pair(weight, make_pair(start, end)));
    }
    sort(edges.begin(), edges.end());
    long long totalweight = 0;
    for(int i = 0;i<E;i++){
        if(UNION(edges[i].second.first, edges[i].second.second)) totalweight+=edges[i].first;
    }
    cout<<totalweight<<endl;
}