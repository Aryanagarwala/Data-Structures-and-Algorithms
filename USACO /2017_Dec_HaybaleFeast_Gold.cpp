#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;
//This is another problem that I felt shouldn't have been included in gold
//This was a very direct imlpementation of sparse table, binary search, and prefix sums
long long SparseTable[(int)(1e5 + 5)][25];
void Preprocessing(long long Size, long long OriginalArray[]){
    int TableWidth = floor(log2(Size)) + 1;
    for(int i = 0;i<Size;i++){
        SparseTable[i][0] = OriginalArray[i];
    }
    for(int j = 1;j<TableWidth;j++){
        for(int i = 0;(i+pow(2, j)-1)<Size;i++){
            SparseTable[i][j] = max(SparseTable[i][j-1], SparseTable[(int)(i + pow(2, j-1))][j-1]);
        }
    }
}
long long Query(int QueryLowerBound, int QueryUpperBound){
    int QuerySize = log2(QueryUpperBound - QueryLowerBound + 1);
    int TemporaryUpperBound = QueryLowerBound + pow(2, QuerySize) - 1;
    if(QueryUpperBound == TemporaryUpperBound) return SparseTable[QueryLowerBound][QuerySize];
    return max(SparseTable[QueryLowerBound][QuerySize], Query(QueryUpperBound - pow(2, QuerySize) + 1, QueryUpperBound));
}
int main(){
    ifstream fin("hayfeast.in");
    ofstream fout("hayfeast.out");
    long long n, m;
    fin>>n>>m;
    long long f[n]; long long s[n];
    for(int i = 0;i<n;i++){
        fin>>f[i]>>s[i];
    }
    vector<long long> prefixf;
    prefixf.push_back(0);
    for(int i = 0;i<n;i++){
        prefixf.push_back(prefixf[i]+f[i]);
    }
    Preprocessing(n, s);
    long long minimum = 1e12;
    for(int i = 1;i<=n;i++){
        long long tofind = prefixf[i-1] + m;
        auto ind = lower_bound(prefixf.begin(), prefixf.end(), tofind);
        if(ind == prefixf.end()) break;
        int index = (ind - prefixf.begin()) - 1;
        minimum = min(Query(i-1, index), minimum);
    }
    fout<<minimum<<endl;
}