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

// 2035. Partition Array Into Two Arrays to Minimize Sum Difference
// You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.
// Return the minimum possible absolute difference.

//APPROACH:-
//BRUTE FORCE - TLE

//CODE:-
class Solution {
public:
    void dp(vector<int>& nums,vector<int>& arr,int index,int curr){
        if(index==nums.size()){
            arr.push_back(curr);
            return;
        }
        dp(nums,arr,index+1,curr+nums[index]);
        dp(nums,arr,index+1,curr);
    }
    int minimumDifference(vector<int>& nums) {
        vector<int> arr;
        dp(nums,arr,0,0);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int res=INT_MAX;
        for(int i=0;i<arr.size();i++){
            int p1=arr[i];
            int p2=sum-arr[i];
            res=min(res,abs(p1-p2));
        }
        return res;
    }
};

//APPROACH 2:-


//CODE:-
class Solution {
    void subsetSums(int i, int currSum, int len, int n, vector<int> &nums, vector<vector<int>> &result){
        if(i == n){
            result[len].push_back(currSum);
            return;
        }
        subsetSums(i + 1, currSum + nums[i], len + 1, n, nums, result);
        subsetSums(i + 1, currSum, len, n , nums, result);
        return;
    }
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int N = n/2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> left(N + 1), right(N + 1);
        subsetSums(0, 0, 0, N, nums, left);
        subsetSums(N, 0, 0, n, nums, right);
        int res = min(abs(sum - 2*left[N][0]), abs(sum - 2*right[N][0]));
        for(int sz = 0; sz <= N; sz++) sort(right[sz].begin(), right[sz].end());
        for(int sz = 1; sz < N; sz++){
            for(auto &lSum: left[sz]){
                int rSum = (sum - 2*lSum)/2, rsz = N - sz;
                auto lb = lower_bound(right[rsz].begin(), right[rsz].end(), rSum);
                if(lb != right[rsz].end()){
                    res = min(res, abs(sum - 2*(lSum + *lb)));
                }
                if(lb != right[rsz].begin()){
                    lb--;
                    res = min(res, abs(sum - 2*(lSum + *lb)));
                }
            }
        }
        return res;
    }
};


//3375. Minimum Operations to Make Array Values Equal to K
// You are given an integer array nums and an integer k.
// An integer h is called valid if all values in the array that are strictly greater than h are identical.
// For example, if nums = [10, 8, 10, 8], a valid integer is h = 9 because all nums[i] > 9 are equal to 10, but 5 is not a valid integer.
// You are allowed to perform the following operation on nums:
// Select an integer h that is valid for the current values in nums.
// For each index i where nums[i] > h, set nums[i] to h.
// Return the minimum number of operations required to make every element in nums equal to k. If it is impossible to make all elements equal to k, return -1.

//APPROACH:-
//just count the no. of int>k in the arr
///problem phrased bad thats it

//CODE:-
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mini=*min_element(nums.begin(),nums.end());
        if(mini<k){
            return -1;
        }
        unordered_map<int,int> map;
        int count=0;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
            if(map[nums[i]]==1){
                count++;
            }
        }
        if(mini==k){
            return count-1;
        }
        return count;
    }
};

//322. Coin Change
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

//APPROACH:-
//DP

//CODE:-
class Solution {
public:
    int dp(vector<int>& coins, int amount,vector<int>& memo){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(memo[amount]!=-1){
            return memo[amount];
        }
        int res=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int subres=dp(coins,amount-coins[i],memo);
            if(subres!=INT_MAX){
                res=min(res,subres+1);
            }
        }
        return memo[amount]=res;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1,-1);
        int res=dp(coins,amount,memo);
        return res==INT_MAX?-1:res;
    }
};


//518. Coin Change II
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.

//APPROACH:-
//DP

//CODE:-
class Solution {
public:
    int dp(vector<int>& coins,int ind, int amount,vector<vector<int>> &memo){
        if(amount==0){
            return 1;
        }
        if(amount<0|| ind == coins.size()){
            return 0;
        }
        if(memo[amount][ind]!=-1){
            return memo[amount][ind];
        }
        int take=dp(coins,ind,amount-coins[ind],memo);
        int nott=dp(coins,ind+1,amount,memo);

        return memo[amount][ind]=take+nott;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(amount+1,vector<int>(coins.size(),-1));
        int res=dp(coins,0,amount,memo);
        return res;
    }
};