#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
//In this algorithm I have used priority queue from C++ STL. Priority queue is essentially the same as max heap.
int main(){
    int Size;
    cin>>Size;
    int Array[Size];
    priority_queue<int> PriorityQueue;
    for(int i =0 ;i<Size;i++){
        cin>>Array[i];
        PriorityQueue.push(Array[i]);
    }
    for(int i = Size-1;i>=0;i--){
        Array[i] = PriorityQueue.top();
        PriorityQueue.pop();
    }
}