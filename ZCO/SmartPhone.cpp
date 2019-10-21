#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i =0 ;i<n;i++) cin>>a[i];
    sort(a, a+n);
    long long maxrevenue = 0;
    for(int i = n-1;i>=0;i--){
        long long price = a[i];
        long long buyers = n-i;
        maxrevenue = max(maxrevenue, price*buyers);
    }
    cout<<maxrevenue<<endl;
}