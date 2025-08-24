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

// 1493. Longest Subarray of 1's After Deleting One Element

// Given a binary array nums, you should delete one element from it.
// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

//Approach:-
// We can use a sliding window approach to solve this problem. We will maintain a window that contains at most one zero. We will keep track of the number of zeros in the current window and the maximum length of the window that contains only 1's.

//CODE:-
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ind=-1;
        int left=0;
        int right=0;
        int res=0;
        while(right<nums.size() && left<=right){
            if(nums[right]==0){
                if(ind==-1){
                    ind=right;
                }
                else{
                    left=ind+1;
                    ind=right;
                }
            }
            int curr=right-left+1;
            res=max(res,curr);
            right++;
        }
        
        return res-1;
    }
};