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

//3396. Minimum Number of Operations to Make Elements in Array Distinct
// You are given an integer array nums. You need to ensure that the elements in the array are distinct. To achieve this, you can perform the following operation any number of times:
// Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.
// Note that an empty array is considered to have distinct elements. Return the minimum number of operations needed to make the elements in the array distinct.

//APPROACH:-
//Calculate the no. of unique elements from back
//now compute the operations

//CODE:-
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> map;
        int size=0;
        for(int i=nums.size()-1;i>=0;i--){
            map[nums[i]]++;
            if(map[nums[i]]>1){
                break;
            }
            else{
                size++;
            }
        }
        int op=nums.size()-size;
        return (op+2)/3;
    }
};


//931. Minimum Falling Path Sum
// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

//APPROACH:-
//DP

//CODE:-
class Solution {
public:
    int dp(vector<vector<int>>& matrix,vector<vector<int>>& memo,int x,int y){
        int m=matrix.size();
        if(x==m-1){
            return matrix[x][y];
        }
        if(memo[x][y]!=INT_MIN){
            return memo[x][y];
        }
        int left=INT_MAX,bott=INT_MAX,right=INT_MAX;
        if(y>0){
            left=matrix[x][y]+dp(matrix,memo,x+1,y-1);
        }
        if(y<m-1){
            right=matrix[x][y]+dp(matrix,memo,x+1,y+1);
        }
        bott=matrix[x][y]+dp(matrix,memo,x+1,y);
        return memo[x][y]=min({bott,left,right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res=INT_MAX;
        int n=matrix.size();
        vector<vector<int>> memo(n,vector<int>(n,INT_MIN));
        for(int i=0;i<n;i++){
            res=min(res,dp(matrix,memo,0,i));
        }
        return res;
    }
};