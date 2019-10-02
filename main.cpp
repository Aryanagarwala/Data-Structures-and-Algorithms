#include <iostream>
using namespace std;
int INF = 1e9;
int Kadanes(int Array[], int Size){
    int MaxSum = -INF;
    int CurrentSum = 0;
    for(int CurrentIndex = 0;CurrentIndex<Size;CurrentIndex++){
        CurrentSum+=Array[CurrentIndex];
        MaxSum = max(MaxSum, CurrentSum);
        CurrentSum = max(CurrentSum, 0);
    }
    return MaxSum;
}
int main(){
    int Size;
    cin>>Size;
    int Array[Size];
    for(int i = 0;i<Size;i++) cin>>Array[i];
    int MaxSum = Kadanes(Array, Size);
}