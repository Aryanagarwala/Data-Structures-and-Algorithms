#include <iostream>
#include <cmath>
using namespace std;
int Partition(int LowerBound, int UpperBound, int Array[]){
    int Pivot = Array[UpperBound];
    int SmallerElementIndex = LowerBound;
    for(int i = LowerBound;i<UpperBound;i++){
        if(Array[i]<Pivot){
            int temp = Array[LowerBound];
            Array[LowerBound] = Array[i];
            Array[i] = temp;
            SmallerElementIndex++;
        }
    }
    Array[UpperBound] = Array[SmallerElementIndex];
    Array[SmallerElementIndex] = Pivot;
    return SmallerElementIndex;
}
void QuickSort(int LowerBound, int UpperBound, int Array[]){
    if(LowerBound>UpperBound) return;
    if(LowerBound==UpperBound) return;
    if(UpperBound==(LowerBound+1)){
        int Smaller = min(Array[LowerBound], Array[UpperBound]);
        int Larger = max(Array[LowerBound], Array[UpperBound]);
        Array[LowerBound] = Smaller;
        Array[UpperBound] = Larger;
        return;
    }
    int MidPoint = Partition(LowerBound, UpperBound, Array);
    QuickSort(LowerBound, MidPoint-1, Array);
    QuickSort(MidPoint + 1, UpperBound, Array);
}
int main(){
    int Size;
    cin>>Size;
    int Array[Size];
    for(int i =0 ;i<Size;i++){
        cin>>Array[i];
    }
    QuickSort(0, Size-1, Array);
}