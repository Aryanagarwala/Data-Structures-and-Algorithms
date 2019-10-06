#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#define int long long
using namespace std;
/* This is a segment tree + lazy propagation solution to the Counting Haybales problem from USACO Platinum 2015
 * This is slightly non standard since it requires two segment trees to be simultaneously updated and queried together with different
 * merge operations
 * Despite this, however, it's an extremely standard and well known algorithm and it should not be part of platinum
*/
int NumberOfBuckets;
int MidPoint(int LowerBound, int UpperBound){
    return (LowerBound+UpperBound)/2;
}
int LeftChild(int Index){
    return Index*2 + 1;
}
int RightChild(int Index){
    return Index*2 + 2;
}
int MergeOperation1(int Value1, int Value2){
    return min(Value1, Value2);
}
int MergeOperation2(int Value1, int Value2){
    return Value1 + Value2;
}
int IdentityElement(){
    return 1e9;
}
void UpdateOperation(int LowerBound, int UpperBound, int SegmentTreeMinimum[], int SegmentTreeCount[], int Index, int Amount){
    SegmentTreeMinimum[Index] = SegmentTreeMinimum[Index] + Amount;
    SegmentTreeCount[Index] += (UpperBound - LowerBound + 1)*Amount;
}
void LazyPush(int LowerBound, int UpperBound, int Index, int lazy[]){
    if(LowerBound!=UpperBound){
        lazy[LeftChild(Index)]+=lazy[Index];
        lazy[RightChild(Index)]+=lazy[Index];
    }
}
void LazyUpdate(int LowerBound, int UpperBound, int SegmentTreeMinimum[], int SegmentTreeCount[], int Index, int lazy[]){
    if(lazy[Index]){
        UpdateOperation(LowerBound, UpperBound, SegmentTreeMinimum, SegmentTreeCount, Index, lazy[Index]);
        LazyPush(LowerBound, UpperBound, Index, lazy);
        lazy[Index] = 0;
    }
}
void BuildTree(int LowerBound, int UpperBound, int Index, int SegmentTreeMinimum[], int SegmentTreeCount[], int Array[]){
    if(LowerBound==UpperBound) SegmentTreeMinimum[Index] = SegmentTreeCount[Index] = Array[LowerBound-1];
    else{
        BuildTree(LowerBound, MidPoint(LowerBound, UpperBound), LeftChild(Index), SegmentTreeMinimum, SegmentTreeCount, Array);
        BuildTree(MidPoint(LowerBound, UpperBound)+1, UpperBound, RightChild(Index), SegmentTreeMinimum, SegmentTreeCount, Array);
        SegmentTreeMinimum[Index] = MergeOperation1(SegmentTreeMinimum[LeftChild(Index)], SegmentTreeMinimum[RightChild(Index)]);
        SegmentTreeCount[Index] = MergeOperation2(SegmentTreeCount[LeftChild(Index)], SegmentTreeCount[RightChild(Index)]);
    }
}
pair<int, int> Query(int LowerBound, int UpperBound, int Index, int QueryLowerBound, int QueryUpperBound, int SegmentTreeMinimum[], int SegmentTreeCount[], int lazy[]){
    LazyUpdate(LowerBound, UpperBound, SegmentTreeMinimum, SegmentTreeCount, Index, lazy);
    if(LowerBound>=QueryLowerBound && UpperBound<=QueryUpperBound) return make_pair(SegmentTreeMinimum[Index], SegmentTreeCount[Index]);
    if(LowerBound>QueryUpperBound || UpperBound<QueryLowerBound) return make_pair(1e9, 0);
    pair<int, int> Lquery = Query(LowerBound, MidPoint(LowerBound, UpperBound), LeftChild(Index), QueryLowerBound, QueryUpperBound, SegmentTreeMinimum, SegmentTreeCount, lazy);
    pair<int, int> Rquery = Query(MidPoint(LowerBound, UpperBound)+1, UpperBound, RightChild(Index), QueryLowerBound, QueryUpperBound, SegmentTreeMinimum, SegmentTreeCount, lazy);
    return make_pair(MergeOperation1(Lquery.first, Rquery.first), MergeOperation2(Lquery.second, Rquery.second));
}
void Update(int LowerBound, int UpperBound, int Index, int QueryLowerBound, int QueryUpperBound, int SegmentTreeMinimum[], int SegmentTreeCount[], int lazy[]){
    LazyUpdate(LowerBound, UpperBound, SegmentTreeMinimum, SegmentTreeCount, Index, lazy);
    if(LowerBound>=QueryLowerBound && UpperBound<=QueryUpperBound){
        lazy[Index]+=NumberOfBuckets;
        LazyUpdate(LowerBound, UpperBound, SegmentTreeMinimum, SegmentTreeCount, Index, lazy);
        return;
    }
    if(LowerBound>QueryUpperBound || UpperBound<QueryLowerBound) return;
    Update(LowerBound, MidPoint(LowerBound, UpperBound), LeftChild(Index), QueryLowerBound, QueryUpperBound, SegmentTreeMinimum, SegmentTreeCount, lazy);
    Update(MidPoint(LowerBound, UpperBound)+1, UpperBound, RightChild(Index), QueryLowerBound, QueryUpperBound, SegmentTreeMinimum, SegmentTreeCount, lazy);
    SegmentTreeMinimum[Index] = MergeOperation1(SegmentTreeMinimum[LeftChild(Index)], SegmentTreeMinimum[RightChild(Index)]);
    SegmentTreeCount[Index] = MergeOperation2(SegmentTreeCount[LeftChild(Index)], SegmentTreeCount[RightChild(Index)]);
}
int32_t main(){
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");
    int NumberOfElements, Queries;
    fin>>NumberOfElements>>Queries;
    int LengthOfSegmentTree = pow(2, ceil(log2(NumberOfElements)))*2 - 1;
    int SegmentTreeMinimum[LengthOfSegmentTree];
    int SegmentTreeCount[LengthOfSegmentTree];
    int lazy[LengthOfSegmentTree];
    int Array[NumberOfElements];
    for(int i = 0;i<NumberOfElements;i++) fin>>Array[i];
    for(int i = 0;i<LengthOfSegmentTree;i++) lazy[i] = 0;
    BuildTree(1, NumberOfElements, 0, SegmentTreeMinimum, SegmentTreeCount, Array);
    while(Queries--){
        char Type;
        int QueryLowerBound, QueryUpperBound;
        fin>>Type>>QueryLowerBound>>QueryUpperBound;
        if(Type=='M'){
            fout<<Query(1, NumberOfElements, 0, QueryLowerBound, QueryUpperBound, SegmentTreeMinimum, SegmentTreeCount, lazy).first<<endl;
        }
        else if(Type=='P'){
            fin>>NumberOfBuckets;
            Update(1, NumberOfElements, 0, QueryLowerBound, QueryUpperBound, SegmentTreeMinimum, SegmentTreeCount, lazy);
        }
        else{
            fout<<Query(1, NumberOfElements, 0, QueryLowerBound, QueryUpperBound, SegmentTreeMinimum, SegmentTreeCount, lazy).second<<endl;
        }
    }
}