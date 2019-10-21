#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
#include <queue>
#define double long double
using namespace std;
int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    int n;
    fin >> n;
    pair<pair<double, double>, double> cows[n];
    vector<int> adj[n];
    for (int i = 0; i < n; i++) fin >> cows[i].first.first >> cows[i].first.second >> cows[i].second;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if ((pow(cows[i].first.first - cows[j].first.first, 2) +
                 pow(cows[i].first.second - cows[j].first.second, 2)) <= pow(cows[i].second, 2)) {
                adj[i].push_back(j);
            }
        }
    }
    int longestbfs = 0;
    for (int i = 0; i < n; i++) {
        int currentlen = 0;
        bool vis[n];
        for (int j = 0; j < n; j++) vis[j] = false;
        queue<int> bfs;
        vis[i] = true;
        bfs.push(i);
        while (!bfs.empty()) {
            int current = bfs.front();
            bfs.pop();
            currentlen++;
            for (int j: adj[current]) {
                if (vis[j]) continue;
                vis[j] = true;
                bfs.push(j);
            }
        }
        longestbfs = max(longestbfs, currentlen);
    }
    fout << longestbfs << endl;
}