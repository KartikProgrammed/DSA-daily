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

//2099. Find Subsequence of Length K With the Largest Sum
// You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.
// Return any such subsequence as an integer array of length k.
// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

// Approach:
// Sort the array in descending order and take the first k elements.
// Then find the indices of these elements in the original array and return them sorted.

// CODE:
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res;
        vector<pair<int,int>> temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end(),[](auto &a,auto &b){
            return a.first>b.first;
        });
        vector<pair<int,int>> t2(temp.begin(),temp.begin()+k);
        sort(t2.begin(),t2.begin()+k,[](auto &a,auto &b){
            return a.second<b.second;
        });
        
        for(int i=0;i<k;i++){
            res.push_back(t2[i].first);
        }
        return res;
    }
};