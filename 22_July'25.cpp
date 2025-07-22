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

//1695. Maximum Erasure Value
// You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
// Return the maximum score you can get by erasing exactly one subarray.
// An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

// Approach:
//brute force

// CODE:
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int> map;
            int sum=0;
            for(int j=i;j<nums.size();j++){
                map[nums[j]]++;
                if(map[nums[j]]>1){
                    break;
                }
                sum+=nums[j];
            }
            res=max(res,sum);
        }
        return res;
    }
};

//Approach2:
//Sliding Window

// CODE:
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left=0;
        int right=0;
        int res=0;
        int sum=0;
        unordered_map<int,int> map;
        while(right<nums.size()){
            map[nums[right]]++;
            sum+=nums[right];
            
            while(map[nums[right]]>1){
                map[nums[left]]--;
                sum-=nums[left];
                left++;
            }
            
            res=max(res,sum);
            right++;
        }
        return res;
    }
};
 