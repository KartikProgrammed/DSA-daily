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

//2348. Number of Zero-Filled Subarrays

// Given an integer array nums, return the number of subarrays filled with 0.
// A subarray is a contiguous non-empty sequence of elements within an array.

//Approach:-
// 1. Initialize a count variable to keep track of the number of zero-filled subarrays.
// 2. Use a variable to count the length of consecutive zeros.
// 3. Iterate through the array:
//    - If the current element is zero, increment the count of consecutive zeros.
//    - If the current element is not zero, calculate the number of zero-filled subarrays formed by the consecutive zeros
//      using the formula count * (count + 1) / 2, and reset the count of consecutive zeros to zero.

//CODE:-
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count=0;
        long long res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                res+=count;
                count=0;
                continue;
            }
            res+=count;
            count++;
        }

        return res+count;
    }
};