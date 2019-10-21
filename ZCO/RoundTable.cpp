#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long cost[n];
    for(int i = 0;i<n;i++) cin>>cost[i];
    long long dp[n][2];
    dp[0][0] = 1e16; dp[0][1] = cost[0];
    dp[1][0] = cost[1]; dp[1][1] = cost[0] + cost[1];
    for(int i = 2;i<n;i++) {
        dp[i][0] = min(dp[i - 2][0], dp[i - 1][0]) + cost[i];
        dp[i][1] = min(dp[i - 2][1], dp[i - 1][1]) + cost[i];
    }
    long long ans = min(dp[n-1][0], dp[n-1][1]);
    if(n>3) ans = min(ans, dp[n-2][1]);
    cout<<ans<<endl;
}