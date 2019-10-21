#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long a[n+1], dp[n+1];
    for(int i = 0;i<n;i++) cin>>a[i];
    a[n] = 0;
    for(int i = 0;i<3;i++) dp[i] = a[i];
    for(int i = 3;i<=n;i++){
        long long MIN = 1e16;
        for(int j = 1;j<=3;j++) MIN = min(dp[i-j], MIN);
        dp[i] = a[i] + MIN;
    }
    cout<<dp[n]<<endl;
}