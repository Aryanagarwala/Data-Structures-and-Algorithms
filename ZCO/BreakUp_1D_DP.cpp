#include <iostream>
#include <algorithm>
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++) cin>>arr[i];
    bool ispal[n][n];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++) ispal[i][j] = false;
    }

    //checking for palindromes
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            int upper = i;
            int lower = j;
            ispal[j][i] = true;
            while(upper>lower){
                if(arr[upper]!=arr[lower]) ispal[j][i] = false;
                upper--;
                lower++;
            }
        }t
    }

    //building DP array
    int DP[n];
    for(int i = 0;i<n;i++){
        DP[i] = i+1; //worst case
        if(ispal[0][i]) DP[i] = 1;
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            DP[i] = min(DP[i], DP[j] + ((ispal[j+1][i])?1:(i-j)));
        }
    }
    cout<<DP[n-1]<<endl;
}
