#include <iostream>
#include <cmath>
using namespace std;
void Merge(int LowerBound, int UpperBound, int LowerBound1, int UpperBound1, int Array[]){
    int Width = UpperBound1 - LowerBound + 1;
    int TemporaryArray[UpperBound1 - LowerBound + 1];
    int FirstIndex = LowerBound; int SecondIndex = LowerBound1; int TemporaryIndex = 0;
    while(FirstIndex<=UpperBound && SecondIndex<=UpperBound1){
        if(Array[FirstIndex]<Array[SecondIndex]){
            TemporaryArray[TemporaryIndex] = Array[FirstIndex];
            FirstIndex++;
        }
        else{
            TemporaryArray[TemporaryIndex] = Array[SecondIndex];
            SecondIndex++;
        }
        TemporaryIndex++;
    }
    for(;FirstIndex<=UpperBound;FirstIndex++, TemporaryIndex++){
        TemporaryArray[TemporaryIndex] = Array[FirstIndex];
    }
    for(;SecondIndex<=UpperBound1;SecondIndex++, TemporaryIndex++){
        TemporaryArray[TemporaryIndex] = Array[SecondIndex];
    }
    TemporaryIndex = 0;
    for(int i = LowerBound;i<=UpperBound1;i++, TemporaryIndex++){
        Array[i] = TemporaryArray[TemporaryIndex];
    }
}
void MergeSort(int LowerBound, int UpperBound, int Array[]){
    if(LowerBound>UpperBound) return;
    if(LowerBound==UpperBound) return;
    if(UpperBound==(LowerBound+1)){
        int Smaller = min(Array[LowerBound], Array[UpperBound]);
        int Larger = max(Array[LowerBound], Array[UpperBound]);
        Array[LowerBound] = Smaller;
        Array[UpperBound] = Larger;
        return;
    }
    int MidPoint = (LowerBound+UpperBound)/2;
    MergeSort(LowerBound, MidPoint, Array);
    MergeSort(MidPoint + 1, UpperBound, Array);
    Merge(LowerBound, MidPoint, MidPoint+1, UpperBound, Array);
}
int main(){
    int Size;
    cin>>Size;
    int Array[Size];
    for(int i =0 ;i<Size;i++){
        cin>>Array[i];
    }
    MergeSort(0, Size-1, Array);
}