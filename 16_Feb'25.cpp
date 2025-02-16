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

// 1718. Construct the Lexicographically Largest Valid Sequence
// Given an integer n, find a sequence that satisfies all of the following:

// The integer 1 occurs once in the sequence.
// Each integer between 2 and n occurs twice in the sequence.
// For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
// The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

// Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

// A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

 
//APPROACH:-
//Backtracking

//CODE:- 
class Solution {
public:
    bool backtrack(vector<int>& res, vector<bool>& used, int index, int n) {
        if (index == res.size()) return true;  // Successfully placed all numbers

        if (res[index] != 0)  // Skip already filled positions
            return backtrack(res, used, index + 1, n);

        for (int i = n; i > 0; i--) {
            if (!used[i]) {
                if (i == 1) {  // Place '1' only at index
                    res[index] = 1;
                    used[i] = true;
                    if (backtrack(res, used, index + 1, n)) return true;
                    res[index] = 0;
                    used[i] = false;
                } 
                else if (index + i < res.size() && res[index + i] == 0) { 
                    // Place 'i' at index and index + i
                    res[index] = res[index + i] = i;
                    used[i] = true;

                    if (backtrack(res, used, index + 1, n)) return true;

                    // Backtrack
                    res[index] = res[index + i] = 0;
                    used[i] = false;
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        backtrack(res, used, 0, n);
        return res;
    }
};


//94. Binary Tree Inorder Traversal
// Given the root of a binary tree, return the inorder traversal of its nodes' values.

//APPROACH:-
//Iterative Approach

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
    vector<int> inorderTraversal(TreeNode* root) {
      stack<TreeNode*> stk;
      vector<int> res;
      struct TreeNode* curr=root;
      while(!stk.empty() || curr!=NULL){
        if(curr!=NULL){
            stk.push(curr);
            curr=curr->left;
        }
        else{
            curr=stk.top();
            stk.pop();
            res.push_back(curr->val);
            curr=curr->right;
        }
      }
      return res;
    }
};