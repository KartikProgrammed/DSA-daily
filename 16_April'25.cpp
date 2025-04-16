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
#include <iomanip>

using namespace std;


// 2537. Count the Number of Good Subarrays
// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
// A subarray is a contiguous non-empty sequence of elements within an array.

//APPROACH:-
//Two pointer approach


//CODE:-
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int l=0;
        int n=nums.size();
        int r=0;
        int pairs=0;
        long long res=0;
        unordered_map<int,int> map;
        while(l<nums.size() && r<nums.size()){
            pairs+=map[nums[r]];
            map[nums[r]]++;
            while(pairs>=k){
                res+=(n-r);
                map[nums[l]]--;
                pairs-=map[nums[l]];
                l++;
            }
            r++;
        }
        return res;
    }
};