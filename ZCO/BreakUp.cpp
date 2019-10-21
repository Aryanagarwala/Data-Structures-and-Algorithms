#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    int dp[n][n];
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            bool pal = true;
            for(int k = 0;(j - 2*k)>=i;k++){
                if(a[j-k]!=a[i+k]) pal = false;
            }
            dp[i][j] = pal?1:(j-i+1);
        }
    }
    for(int k = 1;k<n;k++){
        for(int i = 0;(i+k)<=(n-1);i++){
            for(int j = i;j<(i+k);j++){
                dp[i][i+k] = min(dp[i][i+k], dp[i][j] + dp[j+1][i+k]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}