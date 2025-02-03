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

//3105. Longest Strictly Increasing or Strictly Decreasing Subarray
// You are given an array of integers nums. Return the length of the longest 
// subarray of nums which is either strictly increasing or strictly decreasing


//CODE:-
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(), i=0, ans=0;
        int inc=1, dec=1;
        if (n==1) return 1;
        for(i=1 ;i<n; i++){
            if (nums[i]>nums[i-1]) inc++, dec=1;
            else if (nums[i]<nums[i-1]) inc=1, dec++;
            else inc=dec=1;
            ans=max({ans, dec, inc});
        } 
        return ans;   
    }
};

 