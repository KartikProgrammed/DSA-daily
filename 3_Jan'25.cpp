#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

//2270. Number of Ways to Split Array
// You are given a 0-indexed integer array nums of length n.
// nums contains a valid split at index i if the following are true:
// The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
// There is at least one element to the right of i. That is, 0 <= i < n - 1.
// Return the number of valid splits in nums.

//APPROACH:-
//maintain 2 vectors 1 would store the sum of the element and the elements to the right to it and the other would store the sum of the elements to the left of it
//run a loop to find indexes wherein the left sum is greater than = to the right sum of i+1
//vectors and curr have been declared double because int overflowed for some test cases

//CODE:-
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=size(nums);
        vector<double> left(n,0);
        vector<double> right(n,n);
        double curr=0;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            left[i]=curr;
        }
        curr=0;
        for(int i=n-1;i>=0;i--){
            curr+=nums[i];
            right[i]=curr;
        }
        int result=0;
        for(int i=0;i<n-1;i++){
            if(left[i]>=right[i+1]){
                result++;
            }
        }
        return result;
    }
};

//3. Longest Substring Without Repeating Characters
//Given a string s, find the length of the longest 
// substring without repeating characters.


//APPROACH 1:- Brute Force

//CODE:-
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int currlen=1;
        int res=1;
        if(s.length()==0){
            return 0;
        }
        for(int i=0;i<s.length();i++){
            unordered_map<int,int> map;
            map[s[i]]=1;
            for(int j=i+1;j<s.length();j++){
                if(map[s[j]]==1){
                    break;
                }
                currlen=j-i+1;
                res=res>currlen?res:currlen;
                map[s[j]]=1;
            }
        }
        return res;
    }
};

//APPROACH 2:- (Beats 78%)
//use indices of the last same-appeared character to find the result

//CODE:-
    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int currlen=1;
            int res=1;
            if(s.length()==0){
                return 0;
            }
            int i=0;
            int j=1;
            unordered_map<char,int> map;
            map[s[i]]=0;
            while(i<s.length() && j<s.length()){
                if(map.find(s[j])!=map.end() && map[s[j]]>=i){
                    i=map[s[j]]+1;
                    map[s[j]]=j;
                }
                else{
                    map[s[j]]=j;
                }
                currlen=j-i+1;
                res=res>currlen?res:currlen;
                j++;
            }
            return res;
        }
    };