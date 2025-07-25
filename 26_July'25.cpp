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

//3487. Maximum Unique Subarray Sum After Deletion
// You are given an integer array nums.
// You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:
// All elements in the subarray are unique.
// The sum of the elements in the subarray is maximized.
// Return the maximum sum of such a subarray.

// Approach:
//brute force

// CODE:
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int curr=INT_MIN;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> map;
    
        for(int i=nums.size()-1;i>=0;i--){
            if(curr==INT_MIN){
                curr=nums[i];
                map[nums[i]]++;
            }
            else if(map[nums[i]]==0 && curr+nums[i]>curr){
                curr+=nums[i];
                map[nums[i]]++;
            }
        }
        return curr;
    }
};