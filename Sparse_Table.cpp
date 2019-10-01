#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//Sparse table is an N x Log(N) table that takes O(NLogN) preprocessing time and space to build and O(1) time to answer range queries
//This code is for range minimum queries
const int N = 1e5;
int SparseTable[N][18];
void Preprocessing(int Size, int OriginalArray[]){
    int TableWidth = floor(log2(Size)) + 1;
    for(int i = 0;i<Size;i++){
        SparseTable[i][0] = OriginalArray[i];
    }
    for(int j = 1;j<TableWidth;j++){
        for(int i = 0;i+pow(2, j-1)<Size;i++){
            SparseTable[i][j] = min(SparseTable[i][j-1], SparseTable[(int)(i + pow(2, j-1))][j-1]);
        }
    }
}
int Query(int QueryLowerBound, int QueryUpperBound){
    int QuerySize = log2(QueryUpperBound - QueryLowerBound + 1);
    int TemporaryUpperBound = QueryLowerBound + pow(2, QuerySize) - 1;
    if(QueryUpperBound == TemporaryUpperBound) return SparseTable[QueryLowerBound][QuerySize];
    return min(SparseTable[QueryLowerBound][QuerySize], Query(QueryUpperBound - QuerySize + 1, QueryUpperBound));
}
int main(){
    int Size;
    cin>>Size;
    int OriginalArray[Size];
    for(int i = 0;i<Size;i++) cin>>OriginalArray[i];
    Preprocessing(Size, OriginalArray);
}