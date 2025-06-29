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

//1498. Number of Subsequences That Satisfy the Given Sum Condition
//You are given an array of integers nums and an integer target.
// Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

// Approach:
// Sort the array.
// Use two pointers to find the range of elements that can form valid subsequences.
// For each valid range, calculate the number of subsequences that can be formed using the formula 2^(r - l + 1) - 1, where r is the right pointer and l is the left pointer.

// CODE:
class Solution {
public:
    int MOD=1e9+7;

    int numSubseq(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int res=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % MOD;
        }
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                int dist=right-left;
                res=(res+power[dist])%MOD;
                left++;
            }
            else{
                right--;
            }
        }    
        return res;
    }
};

//152. Maximum Product Subarray
// Given an integer array nums, find a subarray that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.

// Approach:
// Use 2 pointers one from the start and one from the end of the array.
// Calculate the maximum product subarray by iterating through the array and keeping track of the maximum and minimum products at each step.
// This is because a negative number can turn a small product into a large one.

// CODE:
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=INT_MIN;
        int curr=1;
        int curr2=1;
        int n=nums.size();
        for(int i=0,j=n-1;i<n,j>=0;i++,j--){
            if(curr==0)
                curr=1;
            if(curr2==0){
                curr2=1;
            }
            curr*=nums[i];
            curr2*=nums[j];
            if(curr>res){
                res=curr;
            }
            if(curr2>res){
                res=curr2;
            }
        }
        return res;
    }
};
 