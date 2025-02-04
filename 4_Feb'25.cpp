#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

// 1800. Maximum Ascending Subarray Sum
// Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

// A subarray is defined as a contiguous sequence of numbers in an array.

// A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.

//APPROACH:- (beats 100%)
//calculate the sum while iterating and compare with res when ascending order mismatch

//CODE:-
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        else if(nums.size()==1){
            return nums[0];
        }
       

        int curr=nums[0];
        int res=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                curr+=nums[i];
            }
            else{
                res=max(res,curr);
                curr=nums[i];
            }
        }
        return max(res,curr);
    }
};