#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//2364. Count Number of Bad Pairs
// You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

// Return the total number of bad pairs in nums.

//APPROACH:- (TLE)
//Brute Force the solution with complexity of O(nlogn)

//CODE:-
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long count=0;
            for(int i=0;i<nums.size();i++){
                for(int j=i+1;j<nums.size();j++){
                    if(j-i != nums[j]-nums[i]){
                        count++;
                    }
                }
            }
            return count;
        }
    };


//APPROACH 2:-
//find the number of good pairs
//use a hashmap, good pairs will always give i-nums[i] and if the maps val>1 calculate the total good pairs
//subtract the good pairs from total to find bad pairs

//CODE:-
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long count=0;
            long long n=nums.size();
            unordered_map<int,int> map;
            for(int i=0;i<nums.size();i++){
                int curr=i-nums[i];
                map[curr]++;
            }
            for(auto& iter:map){
                if(iter.second>1){
                    long long curr=iter.second;
                    count+=curr*(curr-1)/2;
                }
            }
            long long total=n*(n-1)/2;
            return total-count;
        }
    };


//1814. Count Nice Pairs in an Array
// You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

// 0 <= i < j < nums.length
// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
// Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

//APPROACH:-
//complete opposite of the prev question
//finding good pairs is all we have to do

//CODE:-
class Solution {
    public:
        int rev(int x){
            int res=0;
            while(x>0){
                int curr=x%10;
                res=res*10+curr;
                x/=10;
            }
            return res;
        }
        int countNicePairs(vector<int>& nums) {
            int count=0;
            unordered_map<int,int> map;
            for(int i=0;i<nums.size();i++){
                int reverse=rev(nums[i]);
                int curr=nums[i]-reverse;
                map[curr]++;
            }
            for(auto&iter:map){
                if(iter.second>1){
                    long long curr=iter.second;
                    count=(count + ((curr * (curr - 1) / 2) % 1000000007)) % 1000000007;
                }
            }
            return count%(1000000007);
        }
    };