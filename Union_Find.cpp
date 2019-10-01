#include <iostream>
using namespace std;
//This is an implementation of the Union Find algorithm
//This algorithm is commonly used to find the connected components in a graph and is also used in Kruskal's Minimum Spanning Tree algorithm
//The FindRoot function implements path compression
//The UNION function merges two components
//The FIND function checks whether two nodes are connected
const int N = 1e5;
int root[N];
int RANK[N];
int FindRoot(int i){
    if(root[i] == i) return i;
    return root[i] = FindRoot(root[i]);
}
void UNION(int i, int j){
    int RootOfI = FindRoot(i);
    int RootOfJ = FindRoot(j);
    if(RootOfI==RootOfJ) return;
    if(RANK[RootOfJ]<RANK[RootOfI]){
        root[j] = i;
        RANK[i]+=RANK[j];
    }
    else{
        root[i] = j;
        RANK[j]+=RANK[i];
    }
}
bool FIND(int i, int j){
    return FindRoot(i)==FindRoot(j);
}
int main(){
    for(int i = 0;i<N;i++){
        root[i] = i;
        RANK[i] = 1;
    }
}