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

struct node{
    node* left,*right;
    int val;
    node(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int func(node* root , bool incl){
    // base case
    if(!root){return 0;}
    // if leaf
    if(!root->left && !root->right){
        if(incl){return root->val;}
        return 0;
    }
    // two cases
    // if excluded,u must pick children to cover
    if(!incl){
        int option_left = func(root->left , true);
        int option_right = func(root->right , true);
        return option_left + option_right;
    }
    else if(incl){
        int option_left = min(func(root->left , true) , func(root->left , false));
        int option_right = min(func(root->right , true) , func(root->right , false));
        return root->val + option_left + option_right;
    }

}

int main(){
    node* root = new node(5);
    root->left = new node(1);
    root->right = new node(8);

    root->left->left = new node(6);
    root->left->right = new node(7);

    cout << min(func(root , false) , func(root , true)) << "\n";
}