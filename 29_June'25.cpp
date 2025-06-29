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