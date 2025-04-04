#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include <sstream>
#include <map>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

// 1123. Lowest Common Ancestor of Deepest Leaves
// Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.
// Recall that:
// The node of a binary tree is a leaf if and only if it has no children
// The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
// The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.

//APPROACH:-
//First find maxheight
//then find the ancestor based on if 2 nodes are at maxh-1 or 1

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
    int maxheight(TreeNode* root,int depth){
        
        if(root==NULL){
            return depth;
        }
        int left=maxheight(root->left,depth+1);
        int right=maxheight(root->right,depth+1);
        return max(left,right);
    }
    TreeNode* parent(TreeNode* root,int curr,int maxh){
        if(root==NULL){
            return NULL;
        }
        
        if(curr==maxh){
          return root;  
        }
        TreeNode* left = parent(root->left, curr + 1, maxh);
        TreeNode* right= parent(root->right, curr + 1, maxh);
        if(left&&right){
            return root;
        }
        return left==NULL?right:left;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxh=maxheight(root,0);
        return parent(root,0,maxh-1);
    }
};