#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, maxh, command, valid = 1, currentindex = 0, boxes = 0;
    cin>>n>>maxh;
    int a[n];
    for(int i = 0;i<n;i++) cin>>a[i];
    while(valid){
        cin>>command;
        switch(command){
            case 1: currentindex = max(0, currentindex-1); continue;
            case 2: currentindex = min(n-1, currentindex+1); continue;
            case 3: if(boxes==0 && a[currentindex]){
                    a[currentindex]--;
                    boxes = 1;
                }
                continue;
            case 4: if(boxes==1 && a[currentindex]<maxh){
                    boxes = 0;
                    a[currentindex]++;
                }
                continue;
            case 0: valid = 0;
        }
    }
    for(int i = 0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}