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

//2698. Find the Punishment Number of an Integer
// Given a positive integer n, return the punishment number of n.

// The punishment number of n is defined as the sum of the squares of all integers i such that:

// 1 <= i <= n
// The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.

//APPROACH:-
//traverse till the number n and check if the squares are punishment numbers
//the check will be done using a recursive function which recursively breaks down the number into different parts and adds it up in the currsum
//if at any point currsum == original i value, we break and return True

//CODE:-
class Solution {
    public:
        bool punishment(int i,int currsum,string s,int num){
            if(i==s.length()){
                return currsum==num;
            }
            if(currsum>num){
                return false;
            }
            bool possible=false;
            for(int j=i;j<s.length();j++){
                string sub=s.substr(i,j-i+1);
                int val=stoi(sub);
                possible=possible||punishment(j+1,currsum+val,s,num);
                if(possible==true){
                    break;
                }
            }
            return possible;
        }
        int punishmentNumber(int n) {
            int res=0;
            if(n==0){
                return 0;
            }
            for(int i=1;i<=n;i++){
                int curr=i*i;
                string s=to_string(curr);
                if(punishment(0,0,s,i)){
                    res+=curr;
                }
            }
            return res;
        }
    };


//144. Binary Tree Preorder Traversal
//Given the root of a binary tree, return the preorder traversal of its nodes' values.

//APPROACH:-
//recursive

//CODE:-

//  * Definition for a binary tree node.
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
        void preorder(TreeNode* root,vector<int> &vec){
            if(root!=NULL){
                vec.push_back(root->val);
                preorder(root->left,vec);
                preorder(root->right,vec);
            }
        }
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> vec;
            preorder(root,vec);
            return vec;
        }
    };


//94. Binary Tree Inorder Traversal
// Given the root of a binary tree, return the inorder traversal of its nodes' values.

//APPROACH:-
//recursive

//CODE:-

//  * Definition for a binary tree node.

class Solution {
    public:
        void recursion(TreeNode* root,vector<int> &vec){
            if(root!=NULL){
                recursion(root->left,vec);
                vec.push_back(root->val);
                recursion(root->right,vec);
            }
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> vec;
            recursion(root,vec);
            return vec;
        }
    };