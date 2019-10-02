#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int SortIndex;
void TopologicalSort(int Sort[], int CurrentNode, bool Visited[], vector<int> AdjacencyList[]){
    Visited[CurrentNode] = true;
    for(int Child : AdjacencyList[CurrentNode]){
        if(!Visited[Child]){
            TopologicalSort(Sort, Child, Visited, AdjacencyList);
        }
    }
    Sort[SortIndex--] = CurrentNode;
}
int main(){
    int Vertices, Edges;
    cin>>Vertices>>Edges;
    int Sort[Vertices];
    SortIndex = Vertices - 1;
    vector<int> AdjacencyList[Vertices];
    for(int i = 0;i<Edges;i++){
        int start, end;
        cin>>start>>end;
        AdjacencyList[start].push_back(end);
    }
    bool Visited[Vertices];
    for(int i = 0;i<Vertices;i++) Visited[i] = false;
    for(int CurrentNode = 0;CurrentNode<Vertices;CurrentNode++){
        if(!Visited[CurrentNode]){
            TopologicalSort(Sort, CurrentNode, Visited, AdjacencyList);
        }
    }
    for(int i = 0;i<Vertices;i++){
        cout<<Sort[i]<<endl;
    }
}