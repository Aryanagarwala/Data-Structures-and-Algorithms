#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int strength[n];
    for(int i =0 ;i<n;i++) cin>>strength[i];
    sort(strength, strength+n);
    long long dp[n]; dp[0] = 0;
    long long ans = 0;
    for(int i = 1;i<n;i++){
        dp[i] = dp[i-1] + (i*(strength[i]-strength[i-1]));
        ans+=dp[i];
    }
    cout<<ans<<endl;
}