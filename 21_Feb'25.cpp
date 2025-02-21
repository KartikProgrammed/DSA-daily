#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

// 1261. Find Elements in a Contaminated Binary Tree
// Given a binary tree with the following rules:

// root.val == 0
// For any treeNode:
// If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
// If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
// Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

// Implement the FindElements class:

// FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
// bool find(int target) Returns true if the target value exists in the recovered binary tree.

//APPROACH:-
//create a recursive function to recover the nodes by using the formula given
//store the recovered elements in a map for the find() function in O(1) time complexity

//CODE:-

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
    private:
        unordered_map<int,int> map;
    public:
        FindElements(TreeNode* root) {
            root->val=0;
            map[0]++;
            recursion(root,map);
        }
        void recursion(TreeNode* root,unordered_map<int,int> &map){
            int newval;
            if(root->right!=NULL){
                newval=root->val*2+2;
                root->right->val=newval;
                map[newval]++;
                recursion(root->right,map);
            }
            if(root->left!=NULL){
                newval=root->val*2+1;
                root->left->val=newval;
                map[newval]++;
                recursion(root->left,map);
            }
        }
        bool find(int target) {
            if(map.find(target)!=map.end()){
                return true;
            }
            return false;
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */