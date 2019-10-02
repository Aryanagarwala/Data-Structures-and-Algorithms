#include <iostream>
using namespace std;
void SieveOfEratosthenes(bool IsPrime[], int Limit){
    for(int i = 2;i<=Limit;i++){
        if(IsPrime[i]){
            for(int j = i*2;j<=Limit;j+=i){
                IsPrime[j] = false;
            }
        }
    }
}
int main(){
    int Limit;
    cin>>Limit;
    bool IsPrime[Limit+1];
    for(int i = 0;i<=Limit;i++) IsPrime[i] = true;
}