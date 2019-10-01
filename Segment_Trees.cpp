#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//Segment Tree is a data structure that allows range query and update operations in O(LogN) time
//The entire structure takes O(N) time and space to build
//Range Updates are difficult to do efficiently, the require an algorithm called Lazy Propagation
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
    return min(Value1, Value2);
}
int IdentityElement(){
    return 1e9;
}
void BuildTree(int LowerBound, int UpperBound, int Index, int SegmentTree[], int OriginalArray[]){
    if(LowerBound==UpperBound) SegmentTree[Index] = OriginalArray[LowerBound];
    else{
        BuildTree(LowerBound, MidPoint(LowerBound, UpperBound), LeftChild(Index), SegmentTree, OriginalArray);
        BuildTree(MidPoint(LowerBound, UpperBound)+1, UpperBound, RightChild(Index), SegmentTree, OriginalArray);
        SegmentTree[Index] = MergeOperation(SegmentTree[LeftChild(Index)], SegmentTree[RightChild(Index)]);
    }
}
int Query(int LowerBound, int UpperBound, int Index, int QueryLowerBound, int QueryUpperBound, int SegmentTree[]){
    if(LowerBound>=QueryLowerBound && UpperBound<=QueryUpperBound) return SegmentTree[Index];
    if(LowerBound>QueryUpperBound || UpperBound<QueryLowerBound) return IdentityElement();
    return MergeOperation(Query(LowerBound, MidPoint(LowerBound, UpperBound), LeftChild(Index), QueryLowerBound, QueryUpperBound, SegmentTree), Query(MidPoint(LowerBound, UpperBound)+1, UpperBound, RightChild(Index), QueryLowerBound, QueryUpperBound, SegmentTree));
}
void Update(int LowerBound, int UpperBound, int Index, int UpdateIndex, int UpdateValue, int SegmentTree[]){
    if(LowerBound==UpperBound && UpperBound==UpdateIndex){
        SegmentTree[UpdateIndex] = UpdateValue;
    }
    if(LowerBound>UpdateIndex || UpperBound<UpdateIndex) return;
    Update(LowerBound, MidPoint(LowerBound, UpperBound), LeftChild(Index), UpdateIndex, UpdateValue, SegmentTree);
    Update(MidPoint(LowerBound, UpperBound)+1, UpperBound, RightChild(Index), UpdateIndex, UpdateValue, SegmentTree);
    SegmentTree[Index] = MergeOperation(SegmentTree[LeftChild(Index)], SegmentTree[RightChild(Index)]);
}
int main(){
    int NumberOfElements;
    cin>>NumberOfElements;
    int OriginalArray[NumberOfElements];
    for(int i = 0;i<NumberOfElements;i++) cin>>OriginalArray[i];
    int LengthOfSegmentTree = pow(2, ceil(log2(NumberOfElements)))*2 - 1;
    int SegmentTree[LengthOfSegmentTree];
    BuildTree(1, NumberOfElements, 0, SegmentTree, OriginalArray);
}