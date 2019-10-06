#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;
long long mod = 1e9 + 7;
bool vis[105][105];
bool lighton[105][105];
vector<pair<int, int>> canturnon[105][105];
bool canreach[105][105];
int n;
void dfs(int x, int y){
    if(x<1 || y<1 || x>n || y>n) return;
    canreach[x][y] = true;
    if(!lighton[x][y]) return;
    if(vis[x][y]) return;
    vis[x][y] = true;
    for(pair<int, int> ab: canturnon[x][y]){
        lighton[ab.first][ab.second] = true;
        if(canreach[ab.first][ab.second] && !vis[ab.first][ab.second]) dfs(ab.first, ab.second);
    }
    dfs(x+1, y); dfs(x, y+1); dfs(x-1, y); dfs(x, y-1);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); //FAST IO
    ifstream fin("lightson.in");
    ofstream fout("lightson.out");
    int m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            vis[i][j] = false;
            lighton[i][j] = false;
            canreach[i][j] = false;
        }
    }
    lighton[1][1] = true; canreach[1][1] = true;
    while(m--){
        int x, y, a, b;
        cin>>x>>y>>a>>b;
        canturnon[x][y].push_back(make_pair(a, b));
    }
    dfs(1, 1);
    int count = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            count+=lighton[i][j];
        }
    }
    cout<<count<<endl;
}