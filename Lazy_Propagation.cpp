#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//Lazy Propagation is an algorithm that allows you to perform range updates on a segment tree in O(LogN)
//This is the solution for a problem that counts the number of heads up coins on a table with all coins initially tails up
//https://www.codechef.com/problems/FLIPCOIN
int MidPoint(int LowerBound, int UpperBound){
    return (LowerBound+UpperBound)/2;
}
int LeftChild(int Index){
    return Index*2 + 1;
}
int RightChild(int Index){
    return Index*2 + 2;
}
int MergeOperation(int Value1, int Value2){
    return Value1 + Value2;
}
int IdentityElement(){
    return 0;
}
void UpdateOperation(int LowerBound, int UpperBound, int SegmentTree[], int Index){
    SegmentTree[Index] = (UpperBound-LowerBound+1) - SegmentTree[Index];
}
void LazyPush(int LowerBound, int UpperBound, int Index, bool lazy[]){
    if(LowerBound!=UpperBound){
        lazy[LeftChild(Index)]^=1;
        lazy[RightChild(Index)]^=1;
    }
}
void LazyUpdate(int LowerBound, int UpperBound, int SegmentTree[], int Index, bool lazy[]){
    if(lazy[Index]){
        UpdateOperation(LowerBound, UpperBound, SegmentTree, Index);
        lazy[Index] = false;
        LazyPush(LowerBound, UpperBound, Index, lazy);
    }
}
void BuildTree(int LowerBound, int UpperBound, int Index, int SegmentTree[]){
    if(LowerBound==UpperBound) SegmentTree[Index] = 0;
    else{
        BuildTree(LowerBound, MidPoint(LowerBound, UpperBound), LeftChild(Index), SegmentTree);
        BuildTree(MidPoint(LowerBound, UpperBound)+1, UpperBound, RightChild(Index), SegmentTree);
        SegmentTree[Index] = MergeOperation(SegmentTree[LeftChild(Index)], SegmentTree[RightChild(Index)]);
    }
}
int Query(int LowerBound, int UpperBound, int Index, int QueryLowerBound, int QueryUpperBound, int SegmentTree[], bool lazy[]){
    LazyUpdate(LowerBound, UpperBound, SegmentTree, Index, lazy);
    if(LowerBound>=QueryLowerBound && UpperBound<=QueryUpperBound) return SegmentTree[Index];
    if(LowerBound>QueryUpperBound || UpperBound<QueryLowerBound) return IdentityElement();
    return MergeOperation(Query(LowerBound, MidPoint(LowerBound, UpperBound), LeftChild(Index), QueryLowerBound, QueryUpperBound, SegmentTree, lazy), Query(MidPoint(LowerBound, UpperBound)+1, UpperBound, RightChild(Index), QueryLowerBound, QueryUpperBound, SegmentTree, lazy));
}
void Update(int LowerBound, int UpperBound, int Index, int QueryLowerBound, int QueryUpperBound, int SegmentTree[], bool lazy[]){
    LazyUpdate(LowerBound, UpperBound, SegmentTree, Index, lazy);
    if(LowerBound>=QueryLowerBound && UpperBound<=QueryUpperBound){
        lazy[Index]^=1;
        LazyUpdate(LowerBound, UpperBound, SegmentTree, Index, lazy);
        return;
    }
    if(LowerBound>QueryUpperBound || UpperBound<QueryLowerBound) return;
    Update(LowerBound, MidPoint(LowerBound, UpperBound), LeftChild(Index), QueryLowerBound, QueryUpperBound, SegmentTree, lazy);
    Update(MidPoint(LowerBound, UpperBound)+1, UpperBound, RightChild(Index), QueryLowerBound, QueryUpperBound, SegmentTree, lazy);
    SegmentTree[Index] = MergeOperation(SegmentTree[LeftChild(Index)], SegmentTree[RightChild(Index)]);
}
int main(){
    int NumberOfElements, Queries;
    cin>>NumberOfElements>>Queries;
    int LengthOfSegmentTree = pow(2, ceil(log2(NumberOfElements)))*2 - 1;
    int SegmentTree[LengthOfSegmentTree];
    bool lazy[LengthOfSegmentTree];
    for(int i = 0;i<LengthOfSegmentTree;i++) lazy[i] = false;
    BuildTree(0, NumberOfElements-1, 0, SegmentTree);
    while(Queries--){
        int Type, QueryLowerBound, QueryUpperBound;
        cin>>Type>>QueryLowerBound>>QueryUpperBound;
        if(!Type){
            Update(0, NumberOfElements-1, 0, QueryLowerBound, QueryUpperBound, SegmentTree, lazy);
        }
        else{
            cout<<Query(0, NumberOfElements-1, 0, QueryLowerBound, QueryUpperBound, SegmentTree, lazy)<<endl;
        }
    }
}