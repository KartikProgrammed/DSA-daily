#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

// 1800. Maximum Ascending Subarray Sum
// Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

// A subarray is defined as a contiguous sequence of numbers in an array.

// A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.

//APPROACH:- (beats 100%)
//calculate the sum while iterating and compare with res when ascending order mismatch

//CODE:-
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        else if(nums.size()==1){
            return nums[0];
        }
       

        int curr=nums[0];
        int res=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                curr+=nums[i];
            }
            else{
                res=max(res,curr);
                curr=nums[i];
            }
        }
        return max(res,curr);
    }
};

//455. Assign Cookies
// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

//APPROACH 1:- 
//create a hashmap which is by default sorted since used vector and store the frequencies of the sizes
//traverse the map from the min size of greed and reduce the frequency as required

//CODE:-
//memory limit exceeds
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty()) return 0;
        int maxi=*max_element(s.begin(),s.end());
        vector<int> map(maxi+1,0);
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        int count=0;
        for(int i=0;i<g.size();i++){
            if(g[i]>maxi){
                continue;
            }
            for(int j=g[i];j<map.size();j++){
                if(map[j]>0){
                    count++;
                    map[j]--;
                    break;
                }
            }
        }
        return count;
    }
};

//APPROACH2:-
//sort both the arrays and move forward as per requirement 
//basically traded off memory for time not a big deal

//CODE:-
//BEATS 100%
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int st=0;
        int st2=0;
        int count=0;
        while(st<g.size()&&st2<s.size()){
            if(g[st]>s[st2]){
                st2++;
            }
            else if(g[st]<=s[st2]){
                st++;
                st2++;
                count++;
            }
        }
        return count;
    }
};