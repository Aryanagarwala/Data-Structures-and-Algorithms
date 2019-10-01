#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//Three O(LogN) algorithms based on the same dividing strategy
//Binary search returns the index of the search element
//Upper_Bound returns the index of the first element strictly greater than the search element
//Lower_Bound returns the index of the first element greater than or equal to the search element
int BinarySearch(int LowerBound, int UpperBound, int SearchElement, int Array[]){
    int MidPoint = (LowerBound + UpperBound)/2;
    if(UpperBound<LowerBound) return -1;
    if(Array[MidPoint]==SearchElement) return MidPoint;
    if(Array[MidPoint]>SearchElement) return BinarySearch(LowerBound, MidPoint-1, SearchElement, Array);
    if(Array[MidPoint]<SearchElement) return BinarySearch(MidPoint+1, UpperBound, SearchElement, Array);
}
int Upper_Bound(int LowerBound, int UpperBound, int SearchElement, int Array[]){
    int MidPoint = (LowerBound + UpperBound)/2;
    if(UpperBound<LowerBound) return -1;
    if(LowerBound == UpperBound && Array[MidPoint]>SearchElement) return MidPoint;
    if(Array[MidPoint]>SearchElement) return Upper_Bound(LowerBound, MidPoint, SearchElement, Array);
    if(Array[MidPoint]<=SearchElement) return Upper_Bound(MidPoint+1, UpperBound, SearchElement, Array);
}
int Lower_Bound(int LowerBound, int UpperBound, int SearchElement, int Array[]){
    int MidPoint = (LowerBound + UpperBound)/2;
    if(UpperBound<LowerBound) return -1;
    if(LowerBound == UpperBound && Array[MidPoint]>=SearchElement) return MidPoint;
    if(Array[MidPoint]>=SearchElement) return Lower_Bound(LowerBound, MidPoint, SearchElement, Array);
    if(Array[MidPoint]<SearchElement) return Lower_Bound(MidPoint+1, UpperBound, SearchElement, Array);
}
int main(){
    int Size;
    cin>>Size;
    int OriginalArray[Size];
    for(int i = 0;i<Size;i++) cin>>OriginalArray[i];
}