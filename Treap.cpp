//Treap is a balancing binary search tree
//It uses randomisation to balance the tree
//It maintains a max heap property along with the binary search tree property
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
    int key, priority;
    node *lnode, *rnode;
};
node* rotater(node* root){
    node *tomakeroot = root->lnode,  *toreplace = tomakeroot->rnode;
    tomakeroot->rnode = root;
    root->lnode = toreplace;
    return tomakeroot;
}
node* rotatel(node* root){
    node *tomakeroot = root->rnode,  *toreplace = tomakeroot->lnode;
    tomakeroot->lnode = root;
    root->rnode = toreplace;
    return tomakeroot;
}
node* insert(node* root, int key){
    if(root==NULL){
        node* toreturn = new node;
        toreturn->priority = random;
        toreturn -> lnode = toreturn -> rnode = NULL;
        toreturn -> key = key;
        return toreturn;
    }
    else if(key <= root->key){
        root->lnode = insert(root->lnode, key);
        if(root->lnode->priority > root->priority){
            root = rotater(root);
        }
    }
    else{
        root->rnode = insert(root->rnode, key);
        if(root->rnode->priority > root->priority){
            root = rotatel(root);
        }
    }
    return root;
}
node* search(node* root, int key){
    if(root==NULL || root->key==key) return root;
    if(root->key < key) return search(root->rnode, key);
    if(root->key > key) return search(root->lnode, key);
}
node* deleteNode(node* root, int key){
    if (root == NULL) return root;
    else if (key < root->key) root->lnode = deleteNode(root->lnode, key);
    else if (key > root->key) root->rnode = deleteNode(root->rnode, key);
    else{
        if(root->rnode == NULL){
            node* temp = root->lnode;
            delete(root);
            root = temp;
        }
        else if(root->lnode == NULL){
            node*temp = root->rnode;
            delete(root);
            root = temp;
        }
        else{
            if(root->rnode->priority > root->lnode->priority){
                root = rotatel(root);
                root->lnode = deleteNode(root->lnode, key);
            }
            else{
                root = rotater(root);
                root->rnode = deleteNode(root->rnode, key);
            }
        }
    }
    return root;
}
int32_t main(){
    node* root = NULL;
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int toinsert;
            cin>>toinsert;
            root = insert(root, toinsert);
            if(search(root, toinsert)!=NULL) cout<<"INSERT SUCCESSFUL"<<endl;
            else cout<<"INSERT FAILED"<<endl;
            cout<<"ROOT IS "<<root->key<<endl;
        }
        else{
            int tosearch;
            cin>>tosearch;
            if(search(root, tosearch)!=NULL) cout<<"ELEMENT FOUND"<<endl;
            else cout<<"SEARCH FAILED"<<endl;
        }
    }
}