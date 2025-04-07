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

//416. Partition Equal Subset Sum
// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

//APPROACH:-
//DP

//CODE:-
class Solution {
public:
    bool dp(vector<int>& nums,int sum,int curr,vector<vector<int>> &memo){
        if(sum==0){
            return true;
        }
        if(curr>=nums.size() || sum<0){
            return false;
        }
        if(memo[curr][sum]!=-1){
            return memo[curr][sum];
        }
        bool use=dp(nums,sum-nums[curr],curr+1,memo);
        bool notu=dp(nums,sum,curr+1,memo);
        return memo[curr][sum]=use||notu;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if (sum % 2 != 0) return false;
        vector<vector<int>> memo(nums.size(),vector<int>(sum+1,-1));
        return dp(nums,sum/2,0,memo);
    }
};