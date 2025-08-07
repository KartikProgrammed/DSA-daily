#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

// 3363. Find the Maximum Number of Fruits Collected

// There is a game dungeon comprised of n x n rooms arranged in a grid.
// You are given a 2D array fruits of size n x n, where fruits[i][j] represents the number of fruits in the room (i, j). Three children will play in the game dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n - 1, 0).
// The children will make exactly n - 1 moves according to the following rules to reach the room (n - 1, n - 1):
// The child starting from (0, 0) must move from their current room (i, j) to one of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room exists.
// The child starting from (0, n - 1) must move from their current room (i, j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the target room exists.
// The child starting from (n - 1, 0) must move from their current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1) if the target room exists.
// When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.
// Return the maximum number of fruits the children can collect from the dungeon.

// Approach:
// Use dynamic programming to calculate the maximum number of fruits collected by each child at each step.
// The state can be represented by the positions of the three children and the number of fruits collected so far.
// The transitions will depend on the possible moves of each child, and we will keep track of the maximum fruits collected.

// CODE:
class Solution {
private:
    int n;
    
    // row = i, col = j
    int dfs3(int row, int col, vector<vector<int>>& mat) {
        if (row < 0 || col < 0 || row >= n || col >= n) return 0;

        if(memo[row][col] != -1){return memo[row][col];}
        
        int val = mat[row][col];
        int res = 0;

        if (row == col) {
            res = max(res, dfs3(row + 1, col + 1, mat));
        }
        else if (row - 1 == col) {
            res = max({res,
                       dfs3(row + 1, col + 1, mat),
                       dfs3(row, col + 1, mat)});
        }
        else {
            res = max({res,
                       dfs3(row + 1, col + 1, mat),
                       dfs3(row, col + 1, mat),
                       dfs3(row - 1, col + 1, mat)});
        }
        
        return memo[row][col] = val + res;
    }

    int dfs2(int row, int col, vector<vector<int>>& mat) {
        if (row < 0 || col < 0 || row >= n || col >= n) return 0;

        if(memo[row][col] != -1){return memo[row][col];}
        
        int val = mat[row][col];
        int res = 0;

        if (row == col) {
            res = max(res, dfs2(row + 1, col + 1, mat));
        }
        else if (row == col - 1) {
            res = max({res,
                       dfs2(row + 1, col + 1, mat),
                       dfs2(row + 1, col, mat)});
        }
        else {
            res = max({res,
                       dfs2(row + 1, col + 1, mat),
                       dfs2(row + 1, col, mat),
                       dfs2(row + 1, col - 1, mat)});
        }
        
        return memo[row][col] = val + res;
    }

public:
    vector<vector<int>> memo;
    int maxCollectedFruits(vector<vector<int>>& mat) {
        n = mat.size();
        int total = 0;

        memo = vector<vector<int>> (n, vector<int> (n, -1));

        // child - 1
        // he will eat all diagonal fruits, so set them to 0 
        for (int i = 0; i < n; i++) {
            total += mat[i][i];
            mat[i][i] = 0;
        }
        
        // child - 2
        total += dfs3(n - 1, 0, mat);
        // child - 3
        total += dfs2(0, n - 1, mat);

        return total;
    }
};


//131. Palindrome Partitioning
// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// Approach:
// Use backtracking to explore all possible partitions of the string, checking if each substring is a palindrome.

// CODE:
class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void recursion(vector<vector<string>> &res,vector<string> &curr,int ind,string s){
        if(ind==s.length()){
            res.push_back(curr);
            return;
        }
        for(int i=ind;i<s.length();i++){
            if(isPalindrome(s,ind,i)){
                curr.push_back(s.substr(ind,i-ind+1));
                recursion(res,curr,i+1,s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        recursion(res,curr,0,s);
        return res;
    }
};


//79. Word Search

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.


// Approach:
// Use backtracking to explore all possible paths in the grid, checking if the current path matches the word.

// CODE:
class Solution {
public:
    bool recursion(vector<vector<char>>& board,int ind,string word,int row,int col){
        if(ind==word.size()){
            return true;
        }
        int m=board.size();
        int n=board[0].size();
        if(row<0 || col<0 || row>=m || col>=n){
            return false;
        }
        if(board[row][col]!=word[ind]){
            return false;
        }
        char temp = board[row][col];

        board[row][col]='#';
        bool res=recursion(board,ind+1,word,row+1,col) || recursion(board,ind+1,word,row-1,col) || recursion(board,ind+1,word,row,col+1) || recursion(board,ind+1,word,row,col-1);
        
        board[row][col]=temp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                bool res=recursion(board,0,word,i,j);
                if(res){
                    return true;
                }
            }
        }
        return false;
    }
};