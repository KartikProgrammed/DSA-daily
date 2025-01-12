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

//2116. Check if a Parentheses String Can Be Valid
// A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

// It is ().
// It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
// It can be written as (A), where A is a valid parentheses string.
// You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,

// If locked[i] is '1', you cannot change s[i].
// But if locked[i] is '0', you can change s[i] to either '(' or ')'.
// Return true if you can make s a valid parentheses string. Otherwise, return false.

//APPROACH:-
//maintain a var open which counts the number of opening brackets + flexible brackets
//reduce the var open for closing brackets which are not flexible
//if the no of flexible brackets/( are less than ) return false
//do it from the backwards too to ensure correct output


//CODE:-
class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length()%2!=0){
            return false;
        }
        int open=0;
        for(int i=0;i<s.length();i++){
            if(locked[i]=='0' || s[i]=='('){
                open++;
            }
            else{
                open--;
            }
            if(open<0)
                return false;
        }

        open=0;
        for(int i=s.length()-1;i>=0;i--){
            if(locked[i]=='0' || s[i]==')'){
                open++;
            }
            else{
                open--;
            }
            if(open<0){
                return false;
            }
            
        }
        return true;
    }
};

//992. Subarrays with K Different Integers
//Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A good array is an array where the number of different integers in that array is exactly k.
// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// A subarray is a contiguous part of an array.

//APPROACH 1:-
//count the distince numbers again and again(TLE)

//CODE:-
class Solution {
public:
    int distinct(vector<int> map){
        int count=0;
        for(int i=0;i<map.size();i++){
            if(map[i]>0){
                count++;
            }
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int maxele=*max_element(nums.begin(),nums.end());
        vector<int> map(maxele+1,0);
        int left=0;
        int right=0;
        int n=nums.size();
        int res=0;
        while(right<n){
            map[nums[right]]++;
            while(distinct(map)>k){
                map[nums[left]]--;
                left++;
            }
            if(distinct(map)==k){
                int temp=left;
                while(temp<=right && distinct(map)==k){
                    map[nums[temp]]--;
                    temp++;
                    res++;
                }
                for (int i = left; i < temp; i++) {
                    map[nums[i]]++;
                }
            }
            right++;
        }
        return res;
    }
};

//APPROACH 2:-
//maintain a var to count distinct var instead of calculating again and again

//CODE:-
class Solution {
public:
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int maxele=*max_element(nums.begin(),nums.end());
        vector<int> map(maxele+1,0);
        int left=0;
        int right=0;
        int n=nums.size();
        int res=0;
        int distinct=0;
        while(right<n){
            if(map[nums[right]]==0){
                distinct++;
            }
            map[nums[right]]++;
            while(distinct>k){
                if(map[nums[left]]==1){
                    distinct--;
                }
                map[nums[left]]--;
                left++;
            }
            if(distinct==k){
                int temp=left;
                while(temp<=right && distinct==k){
                    if(map[nums[temp]]==1){
                        distinct--;
                    }
                    map[nums[temp]]--;
                    temp++;
                    res++;
                }
                for (int i = left; i < temp; i++) {
                    if(map[nums[i]]==0){
                        distinct++;
                    }
                    map[nums[i]]++;
                }
            }
            right++;
        }
        return res;
    }
};


//76. Minimum Window Substring
//Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
// The testcases will be generated such that the answer is unique.

//APPROACH:-
//sliding window

//CODE:-
class Solution {
public:
    string minWindow(string s, string t) {
    unordered_map<char,int> freq_req;
    for(int i=0;i<t.length();i++){
        freq_req[t[i]]++;
    }
    int left=0;
    int right=0;
    int count=0;
    int m=t.length();
    int minlen=INT_MAX;
    int n=s.length();
    int stindex=-1;
    string res="";
    while(right<n){
        if(freq_req[s[right]]>0){
            count++;
        }
        freq_req[s[right]]--;
        while(count==m){
            if(right-left+1<minlen){
                minlen=right-left+1;
                stindex=left;
            }
            freq_req[s[left]]++;
            if(freq_req[s[left]]>0){
                count--;
            }
            left++;
        }
        right++;
    }
    return (stindex == -1) ? "" : s.substr(stindex, minlen);
    }
};
