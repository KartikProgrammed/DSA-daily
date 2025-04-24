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
#include <numeric>

using namespace std;

// 2799. Count Complete Subarrays in an Array
// You are given an array nums consisting of positive integers.
// We call a subarray of an array complete if the following condition is satisfied:
// The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
// Return the number of complete subarrays.
// A subarray is a contiguous non-empty part of an array.
 

// APPROACH:-
//use a sliding window approach to count the number of distinct elements in the array
//when the distinct elements in the window is equal to the distinct elements in the whole array, we can count the number of complete subarrays

// CODE:-
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        unordered_map<int,int> map;
        int distinct=set.size();
        int l=0;
        int r=0;
        int n=nums.size();
        int res=0;
        while(l<=r && r<nums.size()){
            map[nums[r]]++;
            while(map.size()==distinct){
                res+=(n-r);
                map[nums[l]]--;
                if(map[nums[l]]==0){
                    map.erase(nums[l]);
                }
                l++;
            }
            r++;
        }
        return res;
    }
};