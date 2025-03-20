#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include <map>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

//APPROACH:-
//curr root will always be start of preorder

//CODE:-
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* Recursion(vector<int> &preorder,int prest,int prend,vector<int>& inorder,int inst,int inend,unordered_map<int,int> &map){
        if(inst>inend||prest>prend){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[prest]);
        int ind=map[root->val];
        int numst=ind-inst;

        root->left=Recursion(preorder,prest+1,prest+numst,inorder,inst,ind-1,map);
        root->right=Recursion(preorder,prest+numst+1,prend,inorder,ind+1,inend,map);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        TreeNode* root=Recursion(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,map);
        return root;
    }
};