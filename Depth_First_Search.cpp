#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
//This graph traversal visits the nodes in postorder. However, you can modify this to visit the graph in preorder or inorder as well.
//This is a DFS solution to the 'Wealth Disparity' problem from INOI 2016. It finds the maximum difference between a
//node and its ancestor
//This solution also involves some DP on trees. DFS on its own has very few uses as compared to BFS so this seemed like a good problem.

pair<int, int> DepthFirstSearch(int CurrentNode, vector<int> Children[], int Value[]){
    int MinimumValue = 1e9;
    int MaximumDifference = 0;
    for(int Child: Children[CurrentNode]){
        pair<int, int> ChildAnswer = DepthFirstSearch(Child, Children, Value);
        //First element contains the maximum difference between two nodes below CurrentNode
        //Second element contains the minimum value of any node below the CurrentNode
        MinimumValue = min(MinimumValue, ChildAnswer.second);
        MaximumDifference = max(ChildAnswer.first, MaximumDifference);
    }
    if(Children[CurrentNode].size()==0){ //if the node is a leaf
        return make_pair(0, Value[CurrentNode]);
    }
    else{
        return make_pair(max(Value[CurrentNode]-MinimumValue, MaximumDifference), min(Value[CurrentNode], MinimumValue));
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); //FAST IO
    int Nodes, Root;
    cin>>Nodes;
    int Value[Nodes];
    for(int i = 0;i<Nodes;i++) cin>>Value[i];
    vector<int> Children[Nodes];
    for(int i = 0;i<Nodes;i++){
        int ParentOfI;
        cin>>ParentOfI;
        if(ParentOfI==-1){
            Root = i; //Because the root has no parent
            continue;
        }
        Children[ParentOfI-1].push_back(i); //I have done -1 because I use 0 based indexing for nodes whereas the problem uses 1 based
    }
    pair<int, int> Answer = DepthFirstSearch(Root, Children, Value);
    cout<<Answer.first<<endl;
}