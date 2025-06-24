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

//2200. Find All K-Distant Indices in an Array
// You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index i of nums for which there exists at least one index j such that |i - j| <= k and nums[j] == key.
// Return a list of all k-distant indices sorted in increasing order

// Approach: Use a loop to iterate through the array and check for k-distant indices. If the condition is met, add the index to the result vector.
//brute force approach

// CODE:
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        set<int> uniq;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                for(int j=0;j<nums.size();j++){
                    if(abs(i-j)<=k){
                        uniq.insert(j);
                    }
                }
            }
        }
        for(int it:uniq){
            res.push_back(it);
        }
        return res;
    }
};