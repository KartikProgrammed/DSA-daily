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
#include <climits>
#include <cstring>
#include <cstdlib>

using namespace std;


//2563. Count the Number of Fair Pairs
// Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
// A pair (i, j) is fair if:
// 0 <= i < j < n, and
// lower <= nums[i] + nums[j] <= upper

//APPROACH:-
//Brute Force approach
//Check all pairs and count the number of fair pairs

//CODE:-
//TLE
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                long long curr=nums[i]+nums[j];
                if(curr>=lower && curr<=upper){
                    res++;
                }
            }
        }
        return res;
    }
};