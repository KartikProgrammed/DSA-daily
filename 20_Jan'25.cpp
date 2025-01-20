#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

// 2661. First Completely Painted Row or Column
// You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

// Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

// Return the smallest index i at which either a row or a column will be completely painted in mat.

//APPROACH:-
//store the row and index of every element in a vector pair
//go through the array arr and increase the rowcount and col count for every index
//if the counts reach m||n return index

//CODE:-
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> colCount(n+1,0);
        vector<int> rowCount(m+1,0);
        vector<pair<int,int>> trace(n*m+1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                trace[mat[i][j]]={i,j};
            }
        }
        int res=0;
        for(int i=0;i<arr.size();i++){
            auto [row, col] = trace[arr[i]];
            rowCount[row]++;
            colCount[col]++;
            if(colCount[col]==m || rowCount[row]==n){
                res=i;
                break;
            }
        }
        return res;
    }
};