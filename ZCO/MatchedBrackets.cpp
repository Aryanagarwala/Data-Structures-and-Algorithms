#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int brackets[n];
    for(int i = 0;i<n;i++){
        cin>>brackets[i];
        brackets[i]=(brackets[i]==1?1:-1);
    }
    int currentcount = 1, startindex = 0, maximumdepth = 1, positionachieved = 0, maximumelements = 1, positionachieved1 = 0;
    for(int i = 1;i<n;i++){
        currentcount+=brackets[i];
        if(currentcount>maximumdepth){
            maximumdepth = currentcount; positionachieved = i;
        }
        if(currentcount==0){
            if((i-startindex+1)>maximumelements){
                maximumelements = i-startindex+1;
                positionachieved1 = startindex;
            }
            startindex = i+1;
        }
    }
    cout<<maximumdepth<<" "<<(positionachieved+1)<<" "<<maximumelements<<" "<<(positionachieved1+1)<<endl;
}