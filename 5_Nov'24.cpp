#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

//DailyProblem 2914:- minimum number of changes to make binary string beautiful
// You are given a 0-indexed binary string s having an even length.

// A string is beautiful if it's possible to partition it into one or more substrings such that:

// Each substring has an even length.
// Each substring contains only 1's or only 0's.
// You can change any character in s to 0 or 1.

// Return the minimum number of changes required to make the string s beautiful.

//CODE:-
//Intruisive approach:-
//why take pair of 2? since an even number of same digit is the requirement, a pair of 2 is the smallest even pair
class Solution {
public:
    int minChanges(string s) {
        if(s.length()%2!=0){ //if the length to the input is not even returning -1 since invalid string
            return -1;
        }
        int change=0;
        int j=0;
        int i=1; //working in pairs 
        while(i<s.length()){
            j=i-1; //j is the previous element i is the 2nd
            if(s[i]==s[j]){ //if both the elements same 00 || 11 skip
                i+=2;
                continue;
            }
            else{
                change++; // 01 -> 00 so change increases by 1
            }
            i+=2;
        }
        return change;
    }
};

//Problem 37:- Soduko Solver
// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(board,c,i,j)){
                            board[i][j]=c;
                            if(solve(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>> &board,char c,int row,int col){
        for(int i=0;i<9;i++){
            if(board[i][col]==c){
                return false;
            }
            if(board[row][i]==c){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c){
                return false;
            }
        }
        return true;
    }
};

//Problem 282:- Expression add Operator
// Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

// Note that operands in the returned expressions should not contain leading zeros.

//CODE:-
class Solution {
public:
    vector<string> ans;
    
    vector<string> addOperators(string s, int target) {
        helper(s,target, 0, "", 0, 0);
        return ans;
    }
    void helper(string s, int target,int i, const string& path, long eval, long residual) {
        if(i==s.length()){
            if(eval==target){
                ans.push_back(path);
                return;
            }
        } 
        string currStr;
        long num=0;
        for(int j=i;j<s.length();j++){
            if(j>i && s[i]=='0') return;
            currStr+= s[j]; 
            num= num*10 + s[j]- '0';
            if(i==0){
                helper(s,target, j+1,path+ currStr,num, num);
            }
            else{
                helper(s,target,j+1,path + "+" + currStr, eval + num, num);
                helper(s,target,j+1,path + "-" + currStr, eval - num, -num);
                helper(s,target,j+1,path + "*" + currStr, eval -residual + residual*num , residual*num);
            }
        }   
    }
};