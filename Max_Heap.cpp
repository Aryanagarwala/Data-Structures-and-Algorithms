#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
//This is an implementation of a max heap. It is available as a priority queue in C++ STL.
vector<int> Heap;
int Parent(int Index){
    return (Index-1)/2;
}
void push(int ValueToPush){
    Heap.push_back(ValueToPush);
    int CurrentIndex = Heap.size()-1;
    while(CurrentIndex>0){
        if(Heap[CurrentIndex]>Heap[Parent(CurrentIndex)]){
            int temp = Heap[Parent(CurrentIndex)];
            Heap[Parent(CurrentIndex)] = Heap[CurrentIndex];
            Heap[CurrentIndex] = temp;
        }
        else{
            return;
        }
    }
}
int top(){
    return Heap[0];
}
void pop(){
    Heap[0] = Heap[Heap.size() - 1];
    Heap.pop_back();
    int CurrentIndex = 0;
    int Child = 0;
    while((CurrentIndex*2 + 1)<Heap.size()){
        Child = CurrentIndex*2 + 1;
        if(Child+1<Heap.size() && Heap[Child+1]>Heap[Child]) Child++;
        int temp = Heap[Child];
        Heap[Child] = Heap[CurrentIndex];
        Heap[CurrentIndex] = temp;
        CurrentIndex = Child;
    }
}
int main(){
    int Size;
    cin>>Size;
    int Array[Size];
    for(int i =0 ;i<Size;i++){
        cin>>Array[i];
        push(Array[i]);
    }
    for(int i = Size-1;i>=0;i--){
        Array[i] = top();
        pop();
    }
}