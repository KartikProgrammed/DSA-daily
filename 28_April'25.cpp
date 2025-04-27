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

// 3392. Count Subarrays of Length Three With a Condition
// Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.


//Approach:-
//Iterate through the array and check if the sum of the first and third numbers equals exactly half of the second number. If it does, increment the count.

// CODE:-
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count=0;
        for(int i=2;i<nums.size();i++){
            int curr=nums[i-2]+nums[i];
            if(curr*2==nums[i-1]){
                count++;
            }
        }
        return count;
    }
};
 