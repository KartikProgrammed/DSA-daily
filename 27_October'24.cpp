#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<unordered_set>
using namespace std;

//DailyProblem 1277:- Count Square Submatrices with all Ones
//Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.


//APPROACH1:- Brute Force
class Solution {
public:
    int helper2(vector<vector<int>> &matrix,int side,int m,int n,int i,int j){
        int result=0;
        if(i+side>m || j+side>n){
            return 0;
        }
        for (int k = 0; k < side; k++) {
            for (int l = 0; l < side; l++) {
                if (matrix[i + k][j + l] != 1) {
                    return 0; 
                }
            }
        }
        return 1;
    }
    int helper(vector<vector<int>> &matrix,int side,int m,int n){
        int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for (int s = 1; s <= side; s++) { 
                    result += helper2(matrix, s, m, n, i, j);
                }
            }
        }
        return result;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int side=min(m,n);
        return helper(matrix,side,m,n);
    }
};

//APPROACH 2:- DP(Beats 67%+)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int total=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    if(i==0|| j==0){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                    }
                    total+=dp[i][j];
                }
            }
        }
        return total;
    }
};
