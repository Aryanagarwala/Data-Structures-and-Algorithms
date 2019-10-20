#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int n, k;
    ofstream fout("snakes.out");
    ifstream fin("snakes.in");
    fin>>n>>k;
    int a[n];
    for(int i = 0;i<n;i++){
        fin>>a[i];
    }
    long long dp[n][k+5];
    for(int i = 0;i<n;i++){
        int maxi = a[i];
        int sum = a[i];
        for(int j = i+1;j<n;j++){
            maxi = max(a[j], maxi);
            sum+=a[j];
        }
        for(int j = 0;j<=k;j++){
            dp[i][j] = (n - i)*maxi - sum;
        }
    }
    for(int i = n-2;i>=0;i--){
        for(int j = k;j>0;j--){
            int maxi = a[i];
            int sum = a[i];
            for(int l = i+1;l<n;l++){
                dp[i][j] = min(dp[i][j], dp[l][j-1] + (l - i)*maxi - sum);
                maxi = max(a[l], maxi);
                sum+=a[l];
            }
        }
    }
    fout<<dp[0][k]<<endl;
}