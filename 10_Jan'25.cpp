#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

// 916. Word Subsets
// You are given two string arrays words1 and words2.
// A string b is a subset of string a if every letter in b occurs in a including multiplicity.
// For example, "wrr" is a subset of "warrior" but is not a subset of "world".
// A string a from words1 is universal if for every string b in words2, b is a subset of a.
// Return an array of all the universal strings in words1. You may return the answer in any order.

//understand the question:-
//were given 2 vectors of strings, words1,2 we need to find strings from words1 such that every char in every string in words2 is present in words1's every string
//example:-
//words1["cat","dog","okaaay"]
//words2["holaaa"]
//so words1's every string must contain "atleast" 1h 1o 1l and 3a
//o/p :- okaaay

//APPROACH:-
//make a map/vec to contain the max freq of each char in words2 and then search every char of every string in words1 and push string into result whenever the freq of a(word1)>b(words2)

//CODE:-
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> b(26,0);
        vector<string> result;
        for(int i=0;i<words2.size();i++){
            vector<int> ref(26,0);
            for(int j=0;j<words2[i].size();j++){
                ref[words2[i][j]-'a']++;
            }
            for(int k=0;k<26;k++){
                b[k]=max(b[k],ref[k]);
            }
        }
        for(int i=0;i<words1.size();i++){
            vector<int> a(26,0);
            bool flag=true;
            for(int j=0;j<words1[i].size();j++){
                a[words1[i][j]-'a']++;
            }
            for(int k=0;k<26;k++){
                if(a[k]<b[k]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                result.push_back(words1[i]);
            }
        }
        return result;
    }
};


//930. Binary Subarrays With Sum
//Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
// A subarray is a contiguous part of the array.


//APPROACH:-
//sliding window

//CODE:-
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal == 0) {
            int count = 0, zeroCount = 0;
            for (int num : nums) {
                if (num == 0) {
                    zeroCount++;
                    count += zeroCount;
                } else {
                    zeroCount = 0;
                }
            }
            return count;
        }
        int res=0;
        int n=nums.size();
        int left=0;
        int right=0;
        int curr=0;
        while(right<n){
            curr+=nums[right];
            while(left<=right && curr>goal){
                curr-=nums[left];
                left++;
            }
            if(curr==goal){
                int temp=left;
                while(nums[temp]==0 && temp<=right){
                    res++;
                    temp++;
                }
                res++;
            }
            right++;
        }
        return res;
    }
};

//1248. Count Number of Nice Subarrays
//Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.

//APPROACH:-
//sliding window

//CODE:-
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int curr=0;
        int n=nums.size();
        int res=0;
        while(right<n){
            if(nums[right]%2!=0){
                curr++;
            }
            while(curr>k && left<=right){
                if(nums[left]%2!=0){
                    curr--;
                }
                left++;
            }
            if(curr==k){
                int temp=left;
                while(temp<right && nums[temp]%2==0){
                    temp++;
                    res++;
                }
                res++;
            }
            right++;
        }
        return res;
    }
};

//1358. Number of Substrings Containing All Three Characters
//Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.


//APPROACH:-
//Sliding window basics

//CODE:-
class Solution {
public:
    bool is1(vector<int> map){
        for(int i=0;i<3;i++){
            if(map[i]==0){
                return false;
            }
        }
        return true;
    }
    int numberOfSubstrings(string s) {
        vector<int> map(3,0);
        int left=0;
        int right=0;
        int n=s.length();
        int res=0;
        while(right<n){
            map[s[right]-'a']++;
            while(left<=right && is1(map)){
                res += n - right;
                map[s[left] - 'a']--;
                left++;
            }
            right++;
        }
        return res;
    }
};


//1423. Maximum Points You Can Obtain from Cards
// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

//APPROACH:-
//the only thing to notice is we can pick the card only from either of the ends i.e left or right 
//so for k=2 either 2 from left or 2 from right or 1-1 from left-right
//find a sliding window of k-n with minimum score - it from total sum

//CODE:-
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int curr=0;
        int res=0;
        int left=0;
        int right;
        int n=cardPoints.size();
        int newsize=n-k;
        int tot=0;
        for(int i=0;i<n;i++){
            tot+=cardPoints[i];
        }
        for(right=0;right<newsize;right++){
            curr+=cardPoints[right];
        }
        res=curr;
        for(int i=newsize;i<n;i++){
            curr = curr - cardPoints[i - newsize] + cardPoints[i];
            res=min(res,curr);
            left++;
        }
        return tot-res;
    }
};