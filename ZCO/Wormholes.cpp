#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
    int n, x, y, num;
    cin>>n>>x>>y;
    vector<long long> v, w;
    pair<long long, long long> contest[n];
    for(int i = 0;i<n;i++) cin>>contest[i].first>>contest[i].second;
    for(int i = 0;i<x;i++){
        cin>>num;
        v.push_back(num);
    }
    for(int i = 0;i<y;i++){
        cin>>num;
        w.push_back(num);
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    long long minimumtime = 1e16;
    for(int i = 0;i<n;i++){
        int s = contest[i].first, e = contest[i].second;
        int indexofstart = upper_bound(v.begin(), v.end(), s) - v.begin() - 1;
        int indexofend = lower_bound(w.begin(), w.end(), e) - w.begin();
        if(indexofstart<0 || indexofend>=y) continue;
        minimumtime = min(minimumtime, w[indexofend] - v[indexofstart] + 1);
    }
    cout<<minimumtime<<endl;
}