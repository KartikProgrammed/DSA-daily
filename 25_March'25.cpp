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

//3394. Check if Grid can be Cut into Sections
// You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:
// (startx, starty): The bottom-left corner of the rectangle.
// (endx, endy): The top-right corner of the rectangle.
// Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:
// Each of the three resulting sections formed by the cuts contains at least one rectangle.
// Every rectangle belongs to exactly one section.
// Return true if such cuts can be made; otherwise, return false.


//APPROACH:-
//MERGING PROBLEM

//CODE:-
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(begin(intervals), end(intervals));

        vector<vector<int>> result;

        result.push_back(intervals[0]);
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < result.back()[1]) { //overlapping
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x;
        vector<vector<int>> y;
        for (auto& coord : rectangles) {
            int x1 = coord[0];
            int y1 = coord[1];
            int x2 = coord[2];
            int y2 = coord[3];

            x.push_back({x1, x2});
            y.push_back({y1, y2});
        }
        vector<vector<int>> res1=merge(x);
        if(res1.size()>=3){
            return true;
        }
        vector<vector<int>> res2=merge(y);
        return res2.size() >= 3;
    }
};


//173. Binary Search Tree Iterator
// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):
// BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
// boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
// int next() Moves the pointer to the right, then returns the number at the pointer.
// Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.
// You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

//APPROACH:-
//use an inorder vector to store the inorder trav
//use iterator for next and has nxt functions

//CODE:-
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class BSTIterator {
private:
    int it=-1;
    vector<int> inorder;
public:
    void inordertrav(TreeNode* root){
        if(root!=NULL){
            inordertrav(root->left);
            inorder.push_back(root->val);
            inordertrav(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
        inordertrav(root);
    }
    
    int next() {
        return inorder[++it];
    }
    
    bool hasNext() {
        int curr=it;
        curr++;
        if(curr<inorder.size()){
            return true;
        }
        return false;
    }
};


//653. Two Sum IV - Input is a BST
// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

//APPROACH:-
//find inorder and run simple 2sum

//CODE:-
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inordertrav(TreeNode* root,vector<int> &inorder){
        if(root!=NULL){
            inordertrav(root->left,inorder);
            inorder.push_back(root->val);
            inordertrav(root->right,inorder);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inordertrav(root,inorder);
        int left=0;
        int right=inorder.size()-1;
        while(left<right){
            if(inorder[left]+inorder[right]==k){
                return true;
            }
            else if(inorder[left]+inorder[right]<k){
                left++;
            }
            else{
                right--;
            }
        }
        return false;
    }
};


//99. Recover Binary Search Tree
// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

//CODE:-
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (prev && prev->val > root->val) {
            if (!first) first = prev; 
            second = root;
        }
        prev = root; 
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first && second) swap(first->val, second->val);
    }
};
