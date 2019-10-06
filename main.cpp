#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");
    int n;
    fin >> n;
    bool used[2 * n + 1];
    for (int i = 1; i <= (2 * n); i++) used[i] = false;
    vector<int> opp; vector<int> ours;
    for(int i = 0;i<n;i++){
        int num; fin>>num;
        opp.push_back(num);
        used[num] = true;
    }
    for(int i = 1;i<=(2*n);i++) if(!used[i]) ours.push_back(i);
    sort(ours.begin(), ours.end());
    auto it = opp.begin();
    for(int i = 0;i<(n/2);i++) it++;
    sort(it, opp.end()); sort(opp.begin(), it);
    int count = 0;
    int i = (n/2), j = 0;
    while(i<n&&j<(n/2)){
        if(ours[i]<opp[j]){
            i++;
        }
        else{
            count++; j++; i++;
        }
    }
    i = (n/2) - 1; j = n-1;
    while(i>=0 && j>=(n/2)){
        if(ours[i]>opp[j]){
            i--;
        }
        else{
            count++; j--; i--;
        }
    }
    fout<<count<<endl;
}
