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

//1408. String Matching in an Array
//Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

// A substring is a contiguous sequence of characters within a string

//APPROACH:-
//brute force

//CODE:-
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break; 
                }
            }
        }
        return result;
    }
};


//1004. Max Consecutive Ones III
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

//APPROACH:-
//sliding window:- use a sliding window concept on a vector containing the indices of the zeroes being flipped
//for k=0 i made a separate code so it is handled separately since creating a vec of size 0 was creating errors

//CODE:-
class Solution {
public:
    void rotate(vector<int> &zeroes,int newind,int &currindex){ //creates the zeroes array  
        if(currindex==zeroes.size()){
            for(int i=0;i<zeroes.size()-1;i++){
                zeroes[i]=zeroes[i+1];
            }
            zeroes[currindex-1]=newind;
        }
        else{
            zeroes[currindex]=newind;
            currindex+=1;
        }
    }
    int longestOnes(vector<int>& nums, int k) {
        if (k == 0) { 
            // Special case: Find the longest contiguous ones without flipping any zeros
            int maxLength = 0, currentLength = 0;
            for (int num : nums) {
                if (num == 1) {
                    currentLength++;
                    maxLength = max(maxLength, currentLength);
                } else {
                    currentLength = 0;
                }
            }
            return maxLength;
        }
        vector<int> zeroes(k,-1);
        int st=0;
        int currindex=0;
        int result=INT_MIN;
        int end=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(currindex==k){
                    st=zeroes[0]+1;
                }
                rotate(zeroes,i,currindex);
            }
            result=max(result,i-st+1);
        }
        
        return result;
    }
};