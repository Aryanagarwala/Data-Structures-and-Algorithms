#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream fin("feast.in");
    ofstream fout("feast.out");
    int t, a, b;
    fin>>t>>a>>b;
    long long dp[t+1][2];
    dp[t][0] = 0;
    for(int i = t-1;i>=0;i--){
        dp[i][0] = t-i;w
        if((i+a)<=t) dp[i][0] = min(dp[i][0], dp[i+a][0]);
        if((i+b)<=t) dp[i][0] = min(dp[i][0], dp[i+b][0]);
    }
    for(int i = t;i>=0;i--){
        dp[i][1] = dp[i][0];
        if((i+a)<=t) dp[i][1] = min(dp[i][1], dp[i+a][1]);
        if((i+b)<=t) dp[i][1] = min(dp[i][1], dp[i+b][1]);
        dp[i][1] = min(dp[i][1], dp[i/2][0]);
    }
    fout<<(t-dp[0][1])<<endl;
}