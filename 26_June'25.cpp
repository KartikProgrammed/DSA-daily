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

//2311. Longest Binary Subsequence Less Than or Equal to K
// You are given a binary string s and a positive integer k.
// Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.
// Note:
// The subsequence can contain leading zeroes.
// The empty string is considered to be equal to 0.
// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

//Approach: Dynamic Programming

//CODE:-(TLE)
class Solution {
    string s;
    int n;
    vector<unordered_map<long long,int>> memo;   //  i → { k : answer }

    int dfs(int i, long long k) {
        if (i < 0) return 0;

        if (auto it = memo[i].find(k); it != memo[i].end())
            return it->second;

        int bit = s[i] - '0';
        long long val = bit ? (1LL << (n - i - 1)) : 0LL;

        int take = 0;
        if (val <= k) take = 1 + dfs(i - 1, k - val);

        int skip = dfs(i - 1, k);

        return memo[i][k] = max(take, skip);
    }

public:
    int longestSubsequence(string &str, int k) {
        s = str;
        n = s.size();
        memo.assign(n, {});
        return dfs(n - 1, k);
    }
};

//Approach: Greedy

//CODE:-(Accepted)
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int length = 0;
        long long powerValue = 1;
        
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                length++;
            } else if(powerValue <= k) {
                length++;
                k -= powerValue;
            }

            if (powerValue <= k)
                powerValue <<= 1; //powerValue *= 2;
        }
        
        return length;
    }
};


//15. 3Sum
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.


// Approach: Sort the array and use a two-pointer technique to find pairs that sum to the negative of the current element.


// CODE:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    res.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
            }
        }
        return res;
    }
};

//18. 4Sum
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Approach: Sort the array and use a four-pointer technique to find quadruplets that sum to the target value.

// CODE:
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                int k=j+1;
                int z=n-1;
                while(k<z){
                    long long sum=1LL *nums[i]+nums[j]+nums[k]+nums[z];
                    if(sum<target){
                        k++;
                    }
                    else if(sum>target){
                        z--;
                    }
                    else{
                        vector<int> temp={nums[i],nums[j],nums[k],nums[z]};
                        res.push_back(temp);
                        k++;
                        z--;
                        while(k<z && nums[k]==nums[k-1])
                            k++;
                        while(k<z && nums[z]==nums[z+1])
                            z--;
                    }
                }
            }
        }
        return res;
    }
};