#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

//73. Set Matrix Zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

//APPROACH:-
//maintain an array of pairs which would contain the i,j of the poisitions of 0 in the matrix which would be then traced and their rows and columns would be converted to 0

//CODE:-
class Solution {
public:
    void helper(vector<vector<int>> &matrix,int i,int j){
        for(int k=0;k<matrix[0].size();k++){
            matrix[i][k]=0;
        }
        for(int k=0;k<matrix.size();k++){
            matrix[k][j]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> map;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    map.push_back({i,j});
                }
            }
        }
        for(auto x:map){
            helper(matrix,x.first,x.second);
        }
    }
};