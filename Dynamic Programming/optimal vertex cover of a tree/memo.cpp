#include<bits/stdc++.h>
using namespace std;

// in the dp recurrence solution

// we do

// func(node , flag) = min(case 1  , case 2)

// case1 is including the current node,therefore either include the children or exclude them

// option_left = min(func(node->left , non_incl) , func(node->left , incl))
// option_right = min(func(node->right , non_incl) , func(node->right , incl))
// case1 = option_left + option_right + node->val;

// case2 is excluding the current node,therefore necessary to include to children

// case2 = func(node->right,incl) + func(node->right,incl)

// base case is at leaves

// func(node , incl) -> min vertex cost for tree having its ROOT node as node on the case the node is incl or not incl
// use custom hash function
struct node{
    node* left,*right;
    int val;
    node(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

struct PairHash {
    size_t operator()(const pair<node*, bool>& p) const {
        // Combine hash of pointer and hash of boolean
        size_t h1 = hash<node*>{}(p.first);
        size_t h2 = hash<bool>{}(p.second);
        // Standard bit-mixing formula
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

int func(node* root , bool incl , unordered_map<pair<node*,bool> , int , PairHash>&mpp){
    // base case
    if(!root){return 0;}
    // if leaf
    if(!root->left && !root->right){
        if(incl){return root->val;}
        return 0;
    }
    if(mpp.find({root , incl}) != mpp.end()){
        return mpp[{root , incl}];
    }
    // two cases
    // if excluded,u must pick children to cover
    if(!incl){
        int option_left = func(root->left , true , mpp);
        int option_right = func(root->right , true , mpp);
        return mpp[{root , incl}] = option_left + option_right;
    }
    else if(incl){
        int option_left = min(func(root->left , true , mpp) , func(root->left , false , mpp));
        int option_right = min(func(root->right , true , mpp) , func(root->right , false , mpp));
        return mpp[{root , incl}] = root->val + option_left + option_right;
    }

}



int main(){
    node* root = new node(5);
    root->left = new node(1);
    root->right = new node(8);
    root->left->left = new node(6);
    root->left->right = new node(7);

    unordered_map<pair<node*,bool> , int , PairHash>mpp;

    cout << min(func(root , false , mpp) , func(root , true , mpp)) << "\n";
}