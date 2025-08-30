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


//3021. Alice and Bob Playing Flower Game

// Alice and Bob are playing a turn-based game on a field, with two lanes of flowers between them. There are x flowers in the first lane between Alice and Bob, and y flowers in the second lane between them.


//Approach:-
// We can use a greedy approach to solve this problem. Alice will always try to maximize her score
// and Bob will always try to minimize Alice's score. We can simulate the game by iterating through the flowers and keeping track of the scores of both players.
// If Alice's score is greater than Bob's score at the end of the game, we return true. Otherwise, we return false.


//CODE:-
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((j+i)%2==0){
                    continue;
                }
                res++;
            }
        }
        return res;
    }
};


//Approach2:-
// We can use a mathematical approach to solve this problem. We can calculate the number of ways Alice can win by considering the parity of the sum of the indices of the flowers. If the sum is odd, Alice wins. We can calculate the number of odd sums by considering the number of odd and even indices in both lanes.


//CODE:-
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long res=floor((double) n*m/2);
        return res;
    }
};


//36. Valid Sudoku
// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.


//Approach:-
// We can use a set to keep track of the numbers we have seen in each row, column, and 3x3 sub-box. If we encounter a number that we have already seen in the same row, column, or sub-box, we return false. If we finish checking all the cells without finding any duplicates, we return true.


//CODE:-
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9],col[9],box[9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c=board[i][j];
                if(c=='.'){
                    continue;
                }
                int boxid=(i/3)*3+(j/3);
                if(box[boxid].count(c) || row[i].count(c) || col[j].count(c)){
                    return false;
                }
                box[boxid].insert(c);
                row[i].insert(c);
                col[j].insert(c);
            }
        }
        return true;
    }
};