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

//1432. Max Difference You Can Get From Changing an Integer
// You are given an integer num. You will apply the following steps to num two separate times:
// Pick a digit x (0 <= x <= 9).
// Pick another digit y (0 <= y <= 9). Note y can be equal to x.
// Replace all the occurrences of x in the decimal representation of num by y.
// Let a and b be the two results from applying the operation to num independently.
// Return the max difference between a and b.
// Note that neither a nor b may have any leading zeros, and must not be 0.

// Approach:
// 1. Convert the number to a string to easily manipulate its digits.
// 2. For each digit, try remapping it to every other digit (0-9).
// 3. Calculate the maximum and minimum values after remapping.
// 4. Return the difference between the maximum and minimum values.

// CODE:
class Solution {
public:
    int maxDiff(int num) {
        string curr=to_string(num);
        string mini="";
        string maxi="";
        char selected='\0';
        for(int i=0;i<curr.length();i++){
            if(curr[i]!='9' && selected=='\0'){
                maxi=maxi+'9';
                selected=curr[i];
            }
            else if(curr[i]==selected){
                maxi=maxi+'9';
            }
            else{
                maxi=maxi+curr[i];
            }

        }
        selected='\0';
        char rep=curr[0]=='1'?'0':'1';
        if(rep==1){
            for(int i=0;i<curr.length();i++){
                if(curr[i]!='1' && selected=='\0'){
                    mini=mini+rep;
                    selected=curr[i];
                }
                else if(curr[i]==selected){
                    mini=mini+rep;
                }
                else{
                    mini=mini+curr[i];
                }

            }
        }
        else{
            for(int i=0;i<curr.length();i++){
                if(curr[i]!='1' && curr[i]!='0' && selected=='\0'){
                    mini=mini+rep;
                    selected=curr[i];
                }
                else if(curr[i]==selected){
                    mini=mini+rep;
                }
                else{
                    mini=mini+curr[i];
                }

            }
        }
        return stoi(maxi)-stoi(mini);
    }
};

//189. Rotate Array
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

//Approach:
//use an extra array to store the rotated elements.


// CODE:
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        vector<int> temp=nums;
        for(int i=nums.size()-k;i<nums.size();i++){
            temp[i-(nums.size()-k)]=nums[i];
        }
        for(int i=k;i<nums.size();i++){
            temp[i]=nums[i-k];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=temp[i];
        }
    }
};

//Approach2:-
//use reverse function to rotate the array in place.

class Solution {
public:
    vector<int> rotate(vector<int> nums,int beg,int end){
        while(beg<end){
            int temp=nums[beg];
            nums[beg]=nums[end];
            nums[end]=temp;
            beg++;
            end--;
        }
        return nums;
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        nums=rotate(nums,0,nums.size()-1);
        nums=rotate(nums,0,k-1);
        nums=rotate(nums,k,nums.size()-1);
    }
};