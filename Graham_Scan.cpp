//This is an algorithm used to find the smallest convex polygon containing all given points on a plane
//"Convex Hull problem"
//This is the Graham Scan algorithm
//O(NLogN) runtime
//This is essentially a copy of the code on GeeksForGeeks but slightly cleaner due to the removal of the Points struct
//I have used integer pairs to represent the points instead of a struct
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#define MOD 100000
#define random (rand()%MOD)
using namespace std;
pair<int, int> comparisonpoint;
pair<int, int> secondHighest(stack<pair<int, int>> &S){
    pair<int, int> p = S.top();
    S.pop();
    pair<int, int> res = S.top();
    S.push(p);
    return res;
}
int distance(pair<int, int> a, pair<int, int> b){
    return pow(b.first - a.first, 2) +
           pow(b.second - a.second, 2);
}
int orientation(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    int val = (b.second - a.second) * (c.first - b.first) -
              (b.first - a.first) * (c.second - b.second);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
int comparator(const void * c, const void * d){
    pair<int, int> a = *((pair<int, int>*) c);
    pair<int, int> b = *((pair<int, int>*) d);
    int o = orientation(comparisonpoint, a, b);
    if (o == 0)
        return (distance(comparisonpoint, b) >= distance(comparisonpoint, a))? -1 : 1;

    return (o == 2)? -1: 1;
}
vector<pair<int, int>> convexHull(pair<int, int> points[], int n){
    int ymin = points[0].second, mini = 0;
    for (int i = 1; i < n; i++){
        int y = points[i].second;
        if ((y < ymin) || (ymin == y &&
                           points[i].first < points[mini].first))
            ymin = points[i].second, mini = i;
    }
    pair<int, int> temp = points[0];
    points[0] = points[mini];
    points[mini] = temp;
    comparisonpoint = points[0];
    qsort(&points[1], n-1, sizeof(pair<int, int>), comparator);
    int m = 1;
    for (int i=1; i<n; i++){
        while (i < n-1 && orientation(comparisonpoint, points[i],
                                      points[i+1]) == 0) i++;
        points[m] = points[i];
        m++;
    }
    vector<pair<int, int>> vec;
    if (m < 3) return vec;
    stack<pair<int, int>> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    for (int i = 3; i < m; i++){
        while (orientation(secondHighest(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }
    while (!S.empty()){
        vec.push_back(S.top());
        S.pop();
    }
    return vec;
}
int main(){
    int n;
    cin>>n;
    pair<int, int> points[n];
    for(int i = 0;i<n;i++){
        cin>>points[i].first>>points[i].second;
    }
    vector<pair<int, int>> vec = convexHull(points, n);
    for(pair<int, int> p: vec){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}