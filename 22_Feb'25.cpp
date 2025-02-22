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

// 1028. Recover a Tree From Preorder Traversal
// We run a preorder depth-first search (DFS) on the root of a binary tree.
// At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
// If a node has only one child, that child is guaranteed to be the left child.
// Given the output traversal of this traversal, recover the tree and return its root.


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
        string s;
        int idx = 0, level = 0;
    
        TreeNode* recoverFromPreorder(string traversal) {
            s = traversal;
            TreeNode* node = new TreeNode(-1);
            helper(node, 0);
            return node->left;
        }
    
        void helper(TreeNode* parent, int lvl) {
            while (idx < s.length() && lvl == level) {
                int num = 0;
                while (idx < s.length() && isdigit(s[idx])) {
                    num = num * 10 + (s[idx++] - '0');
                }
                TreeNode* node = new TreeNode(num);
                if (!parent->left)
                    parent->left = node;
                else
                    parent->right = node;
                level = 0;
                while (idx < s.length() && s[idx] == '-') {
                    level++;
                    idx++;
                }
                helper(node, lvl + 1);
            }
        }
    };