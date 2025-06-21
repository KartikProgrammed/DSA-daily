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

// 3085. Minimum Deletions to Make String K-Special
// You are given a string word and an integer k.
// We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.
// Here, freq(x) denotes the frequency of the character x in word, and |y| denotes the absolute value of y.
// Return the minimum number of characters you need to delete to make word k-special.

// Approach: Count frequency of each character, then check the maximum frequency and minimum frequency.

// CODE:
class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<word.size();i++){
            map[word[i]-'a']++;
        }
        int res=INT_MAX;
        for(auto curr:map){
            int mini=curr.first;
            int count=curr.second;
            int del=0;
            for(auto y:map){
                if(count>y.second){
                    del+=y.second;
                }
                else if(y.second>count+k){
                    del+=y.second-count-k;
                }
            }
            res=min(del,res);
        }
        return res;
    }
};

//121. Best Time to Buy and Sell Stock
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//Approach: brute force to find the maximum profit by checking all pairs of days. (TLE for large inputs)

// CODE:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        for(int i=0;i<prices.size();i++){
            int curr=0;
            for(int j=i+1;j<prices.size();j++){
                curr=max(prices[j]-prices[i],curr);
            }
            res=max(res,curr);
        }
        return res;
    }
};

//Approach: use a single pass to find the maximum profit by keeping track of the minimum price seen so far and the maximum profit.
//kadane's algorithm can be used to find the maximum profit in O(n) time.

// CODE:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<mini){
                mini=prices[i];
            }
            else{
                res=max(res,prices[i]-mini);
            }
        }
        return res;
    }
};


//2149. Rearrange Array Elements by Sign
// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
// You should return the array of nums such that the the array follows the given conditions:
// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

//Apprach: use pos,neg and curr pointers to rearrange the elements in the array.

// CODE:
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0;
        int neg=0;
        int curr=0;
        int n=nums.size();
        bool flag=true;
        while(curr<nums.size()){
            if(flag && nums[curr]<0){
                pos=max(pos,curr+1);
                while(pos<n){
                    if(nums[pos]>0){
                        swap(nums[curr],nums[pos]);
                        break;
                    }
                    pos++;
                }
                
            }
            else if(!flag && nums[curr]>0){
                neg=max(neg,curr+1);
                while(neg<n){
                    if(nums[neg]<0){
                        swap(nums[curr],nums[neg]);
                        break;
                    }
                    neg++;
                }
                
            }
            flag=!flag;
            curr++;
        }
        return nums;
   }
};
//wont work because the arr has more positive integers than negative integers.

//Approach 2:- use 3 vectors to store positive and negative integers, then merge them in the required order.

// CODE:
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        vector<int> pos;
        vector<int> neg;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        int posi=0;
        int nega=0;
        bool flag=true;
        for(int i=0;i<n;i++){
            if(flag){
                res.push_back(pos[posi++]);
            }
            else{
                res.push_back(neg[nega++]);
            }
            flag=!flag;
        }
        return res;
    }
};