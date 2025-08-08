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

//808. Soup Servings

// You have two soups, A and B, each starting with n mL. On every turn, one of the following four serving operations is chosen at random, each with probability 0.25 independent of all previous turns:
// pour 100 mL from type A and 0 mL from type B
// pour 75 mL from type A and 25 mL from type B
// pour 50 mL from type A and 50 mL from type B
// pour 25 mL from type A and 75 mL from type B
// Note:
// There is no operation that pours 0 mL from A and 100 mL from B.
// The amounts from A and B are poured simultaneously during the turn.
// If an operation asks you to pour more than you have left of a soup, pour all that remains of that soup.
// The process stops immediately after any turn in which one of the soups is used up.
// Return the probability that A is used up before B, plus half the probability that both soups are used up in the same turn. Answers within 10-5 of the actual answer will be accepted.

// Approach:
// Use memoization to store results for previously computed states.
// The state can be represented by the remaining amounts of soup A and B.
// The transitions will depend on the four possible serving operations.
// The base cases will handle when one or both soups are empty.

// CODE:
class Solution {
public:
    vector<vector<double>> dp;

    double recursion(int a,int b){
        if(a==0 && b==0){
            return 0.5;
        }
        else if(a==0){
            return 1;
        }
        else if(b==0){
            return 0;
        }
        if(dp[a][b]!=-1){
            return dp[a][b];
        }
        double op1=recursion(max(0,a-100),b);
        double op2=recursion(max(0,a-75),max(0,b-25));
        double op3=recursion(max(0,a-50),max(0,b-50));
        double op4=recursion(max(0,a-25),max(0,b-75));
        return dp[a][b]=0.25*(op1+op2+op3+op4);
    }
    double soupServings(int n) {
        if(n>=4800){
            return 1.0;
        }
        dp = vector<vector<double>>(n + 1, vector<double>(n + 1, -1));
        return recursion(n,n);
    }
};


//51. N-Queens

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Approach:
// Use backtracking to explore all possible placements of queens on the board.
// The state can be represented by the current board configuration and the positions of the queens.

// CODE:
class Solution {
public:
    void attack(vector<vector<bool>> &temp,int row,int col,int n){
        int r=row;
        int c=col;
        while(r<n){
            temp[r++][c]=false;
        }
        r=row;
        while(c<n){
            temp[r][c++]=false;
        }
        r=row;
        c=col;
        while(r<n && c<n){
            temp[r++][c++]=false;
        }
        r=row;
        c=col;
        while(r>=0 && c>=0){
            temp[r--][c--]=false;
        }
        r=row;
        c=col;
        while(r>=0 && c<n){
            temp[r--][c++]=false;
        }
        r=row;
        c=col;
        while(r<n && c>=0){
            temp[r++][c--]=false;
        }
    }

    void recursion(vector<vector<string>> &res,vector<string> &curr,int row,int col,int n,vector<vector<bool>> &map){
        if(row==n){
            res.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(map[row][i]){
                curr[row][i]='Q';
                vector<vector<bool>> temp=map;
                attack(temp,row,i,n);
                recursion(res,curr,row+1,0,n,temp);
                curr[row][i]='.';

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> map(n,vector<bool>(n,true));
        vector<string> curr(n, string(n, '.'));
        vector<vector<string>> res;
        
        recursion(res,curr,0,0,n,map);
        return res;
    }
};

// 139. Word Break
// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Approach:
// Use dynamic programming to check if the string can be segmented.

// CODE:
class Solution {
public:
    bool recursion(string s,unordered_set<string> &dict,int ind,unordered_map<int,bool> &memo){
        if(ind==s.length()){
            return true;
        }
        if (memo.count(ind)) return memo[ind];
        for(int i=ind;i<s.length();i++){
            if(dict.count(s.substr(ind,i-ind+1)) && recursion(s,dict,i+1,memo)){
                return memo[ind]=true;
            }
        }
        return memo[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int,bool> memo;
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        return recursion(s,dict,0,memo);
    }
};

//37. Sudoku Solver

// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

// Approach:
// Use backtracking to fill the empty cells in the Sudoku grid.
// The state can be represented by the current grid configuration and the positions of the empty cells.
// The transitions will depend on the valid numbers that can be placed in the empty cells.
// The base case will handle when all cells are filled.


// CODE:
class Solution {
public:
    bool present(vector<vector<char>> &board,char find,int row,int col){
        for(int i=0;i<9;i++){
            if(board[i][col]==find || board[row][i]==find || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == find)
                return true;
        }
        return false;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if(!present(board,k+'0',i,j)){
                            board[i][j]=k+'0';
                            if(solve(board))
                                return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board){
        solve(board);
    }
};