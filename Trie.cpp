#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#define int long long
#define MOD 100000
#define random (rand()%MOD)
using namespace std;
struct node{
    int endofword;
    node* next[26];
};
node* newnode(){
    node* temp = new node;
    temp->endofword = 0;
    for(int i = 0;i<26;i++) temp->next[i] = NULL;
    return temp;
}
void insert(node* currentnode, string s){
    for(int i = 0;i<s.length();i++){
        if(currentnode->next[s[i]-'a']!=NULL){
            currentnode = currentnode->next[s[i]-'a'];
        }
        else{
            currentnode = currentnode->next[s[i]-'a'] = newnode();
        }
    }
    currentnode->endofword++;
}
bool prefixExists(node* currentnode, string s){
    for(int i = 0;i<s.length();i++){
        if(currentnode->next[s[i]-'a']!=NULL){
            currentnode = currentnode->next[s[i]-'a'];
        }
        else{
            return false;
        }
    }
    return true;
}
bool wordSearch(node* currentnode, string s){
    for(int i = 0;i<s.length();i++){
        if(currentnode->next[s[i]-'a']!=NULL){
            currentnode = currentnode->next[s[i]-'a'];
        }
        else{
            return false;
        }
    }
    return currentnode->endofword>=1?true:false;
}
int32_t main(){
    node* root = newnode();
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            string toinsert;
            cin>>toinsert;
            insert(root, toinsert);
        }
        else{
            string prefixsearch;
            cin>>prefixsearch;
            bool prexist = prefixExists(root, prefixsearch);
            bool wordexist = wordSearch(root, prefixsearch);
            if(prexist){
                cout<<"Prefix exists"<<endl;
                if(wordexist){
                    cout<<"Word exists"<<endl;
                }
            }
            else{
                cout<<"Does not exist"<<endl;
            }
        }
    }
}