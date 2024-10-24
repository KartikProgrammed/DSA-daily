#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

//DAILY PROBLEM 951:- Flip Equivalent Binary Trees
// For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.
// A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.
// Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.

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

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL){
            return true;
        }
        if(root1==NULL||root2==NULL){
            return false;
        }
        if(root1->val==root2->val){
            bool without=flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
            bool with=flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);
            return with || without;
        }
        else{
            return false;
        }
    }
};


//Problem 79:-Word Search
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// CODE:-
class Solution {
public:
    bool recursion(vector<vector<char>> &board,string word,int i,int j,int curr,vector<vector<bool>> &check){
        int m=board.size();
        int n=board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[curr] || check[i][j]) {
            return false;
        }

        if(curr==word.length()-1){
            return true;
        }
        check[i][j] = true;
        bool found= recursion(board,word,i+1,j,curr+1,check)||recursion(board,word,i-1,j,curr+1,check)||recursion(board,word,i,j+1,curr+1,check)||recursion(board,word,i,j-1,curr+1,check);
        check[i][j]=false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> check(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (recursion(board, word, i, j, 0, check)) {
                    return true;
                }
            }
        }
        return false;
    }
};

//Problem 51:- N-Queens Problem

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

//CODE:-
class Solution {
public:
    void attacks(int i,int j,vector<vector<bool>> &occ, int n){
        for(int width=0;width<n;width++){
            occ[i][width]=true;
        }
        for(int len=0;len<n;len++){
            occ[len][j]=true;
        }

        int x = i, y = j;
        while (x >= 0 && y >= 0) {
            occ[x--][y--] = true;
        }

        x = i, y = j;
        while (x < n && y < n) {
            occ[x++][y++] = true;
        }

        x = i, y = j;
        while (x >= 0 && y < n) {
            occ[x--][y++] = true;
        }

        x = i, y = j;
        while (x < n && y >= 0) {
            occ[x++][y--] = true;
        }
    }
    void recursion(vector<vector<string>> &solutions,vector<string> &board,int row,vector<vector<bool>> occ,int n){
        if (row == n) {
            solutions.push_back(board); 
            return;
        }
        for(int i=0;i<n;i++){
            if(!occ[row][i]){
                board[row][i]='Q';
                vector<vector<bool>> tempOcc = occ;
                attacks(row, i,tempOcc, n);
                recursion(solutions, board, row + 1, tempOcc, n);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.')); 
        vector<vector<bool>> occ(n, vector<bool>(n, false));

        recursion(solutions, board, 0, occ, n);

        return solutions;
    }
};