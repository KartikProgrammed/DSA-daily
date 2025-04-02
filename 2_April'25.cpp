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

// 2873. Maximum Value of an Ordered Triplet I
// You are given a 0-indexed integer array nums.
// Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.
// The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

//APPROACH:-
//3 POINTER

//CODE:-
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        long long res = 0;
        int maxe = nums[0];
        int maxdif = 0; 

        for (int i = 1; i < nums.size()-1; i++) {
            maxdif = max(maxdif, maxe - nums[i]);
            res = max(res, (long long)maxdif * nums[i+1]);
            maxe = max(maxe, nums[i]);
        }
        return res;
    }
};