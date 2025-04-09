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

// 2035. Partition Array Into Two Arrays to Minimize Sum Difference
// You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.
// Return the minimum possible absolute difference.

//APPROACH:-
//BRUTE FORCE - TLE

//CODE:-
class Solution {
public:
    void dp(vector<int>& nums,vector<int>& arr,int index,int curr){
        if(index==nums.size()){
            arr.push_back(curr);
            return;
        }
        dp(nums,arr,index+1,curr+nums[index]);
        dp(nums,arr,index+1,curr);
    }
    int minimumDifference(vector<int>& nums) {
        vector<int> arr;
        dp(nums,arr,0,0);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int res=INT_MAX;
        for(int i=0;i<arr.size();i++){
            int p1=arr[i];
            int p2=sum-arr[i];
            res=min(res,abs(p1-p2));
        }
        return res;
    }
};

//APPROACH 2:-


//CODE:-
class Solution {
    void subsetSums(int i, int currSum, int len, int n, vector<int> &nums, vector<vector<int>> &result){
        if(i == n){
            result[len].push_back(currSum);
            return;
        }
        subsetSums(i + 1, currSum + nums[i], len + 1, n, nums, result);
        subsetSums(i + 1, currSum, len, n , nums, result);
        return;
    }
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int N = n/2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> left(N + 1), right(N + 1);
        subsetSums(0, 0, 0, N, nums, left);
        subsetSums(N, 0, 0, n, nums, right);
        int res = min(abs(sum - 2*left[N][0]), abs(sum - 2*right[N][0]));
        for(int sz = 0; sz <= N; sz++) sort(right[sz].begin(), right[sz].end());
        for(int sz = 1; sz < N; sz++){
            for(auto &lSum: left[sz]){
                int rSum = (sum - 2*lSum)/2, rsz = N - sz;
                auto lb = lower_bound(right[rsz].begin(), right[rsz].end(), rSum);
                if(lb != right[rsz].end()){
                    res = min(res, abs(sum - 2*(lSum + *lb)));
                }
                if(lb != right[rsz].begin()){
                    lb--;
                    res = min(res, abs(sum - 2*(lSum + *lb)));
                }
            }
        }
        return res;
    }
};