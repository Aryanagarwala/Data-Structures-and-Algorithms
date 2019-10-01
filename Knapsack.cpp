#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
//This is a DP solution to the famous 0/1 Knapsack problem available on SPOJ
//https://www.spoj.com/problems/KNAPSACK/
int DP[2005][2005];
//DP[i][j] = The maxmimum value of items you can buy from the ith item to the last item when you have j capacity remaining in the bag
int KnapsackProblem(int CurrentItem, int NumberOfItems, int RemainingCapacity, int Size[], int Value[]){
    if(CurrentItem==NumberOfItems) return 0;
    if(DP[CurrentItem][RemainingCapacity]>-1) return DP[CurrentItem][RemainingCapacity];
    if(RemainingCapacity < Size[CurrentItem]) return DP[CurrentItem][RemainingCapacity] = KnapsackProblem(CurrentItem+1, NumberOfItems, RemainingCapacity, Size, Value);
    return DP[CurrentItem][RemainingCapacity] = max(Value[CurrentItem] + KnapsackProblem(CurrentItem+1, NumberOfItems, RemainingCapacity - Size[CurrentItem], Size, Value), KnapsackProblem(CurrentItem+1, NumberOfItems, RemainingCapacity, Size, Value));
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); //FAST IO
    int Capacity, NumberOfItems;
    cin>>Capacity>>NumberOfItems;
    int Size[NumberOfItems];
    int Value[NumberOfItems];
    for(int i = 0;i<NumberOfItems;i++) for(int j = 0;j<=Capacity;j++) DP[i][j] = -1;
    for(int i = 0;i<NumberOfItems;i++) cin>>Size[i]>>Value[i];
    cout<<KnapsackProblem(0, NumberOfItems, Capacity, Size, Value)<<endl;
}