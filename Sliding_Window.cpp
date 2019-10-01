#include <iostream>
using namespace std;
//Sliding window is a technique to find all sums of k contiguous elements in an array in O(N) instead of O(N.K) time
//This code finds the maximum sum of k contigiious elements and outputs it
int main(){
    int Size, WindowSize;
    cin>>Size>>WindowSize;
    int Array[Size];
    for(int i = 0;i<Size;i++){
        cin>>Array[i];
    }
    int Window = 0;
    int MaxSum =0 ;
    for(int i = 0;i<WindowSize;i++){
        Window+=Array[i];
    }
    MaxSum = Window;
    for(int i = WindowSize;i<Size;i++){
        Window+=Array[i];
        Window-=Array[i-WindowSize];
        MaxSum = max(MaxSum, Window);
    }
    cout<<MaxSum<<endl;
}