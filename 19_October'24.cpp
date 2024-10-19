#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 90:- Subset II
//DESCRIPTION:- Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.
//NOTE:- the order of return must also be a sorted order and lexical order

//CODE:-
class Solution {
public:

    void recursion(int ind,vector<int> &nums,vector<vector<int>> &result,vector<int> &subs){
        result.push_back(subs);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]){ //continues the loop for any duplicate elements if found
                continue; //[1,2,2] if suppose we at 2, the other 2 will be skipped since it is expected to create only 1 recursive call if not done, we would have 2 [2,2]
            }
            subs.push_back(nums[i]);
            recursion(i+1,nums,result,subs); // updates the index and head recursion is executed
            subs.pop_back();  //backtracks to other possible subsets
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subs;
        sort(nums.begin(),nums.end());
        recursion(0,nums,result,subs);
        return result;
    }
};


//DAILY PROBLEM :- Find Kth bit in Nth binary String
// Given two positive integers n and k, the binary string Sn is formed as follows:

// S1 = "0"
// Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
// Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

// For example, the first four strings in the above sequence are:

// S1 = "0"
// S2 = "011"
// S3 = "0111001"
// S4 = "011100110110001"
// Return the kth bit in Sn. It is guaranteed that k is valid for the given n.


//APPROACH 1:- 
//creating strings explicitly and checking the kth bit
//very intuitive 

class Solution {
public:
    void inversion(vector<char> &result){ //inverses the binary string 
        for(int i=0;i<result.size();i++){
            if(result[i]=='0'){
                result[i]='1';
            }
            else{
                result[i]='0';
            }
        }
    }
    vector<char> recursion(int n,vector<char> &result){ //recursion can be skipped but since im obsessed with recursion i build this code
        if(n==1){
            return result; //stop when n==1 since thats the string we need
        }
        vector<char> old=result;
        inversion(old);
        reverse(old.begin(), old.end()); //the string to be appended is expected to add the newString as inversed and reversed 

        vector<char> newS=result;
        newS.push_back('1');
        newS.insert(newS.end(),old.begin(),old.end());
        return recursion(n-1,newS); //decrements n
    }
    char findKthBit(int n, int k) {
        vector<char> result;
        result.push_back('0');
        result=recursion(n,result);
        return result[k-1];
    }
};

//APPROACH 2
//doesnt need creating strings uses pure logic
//BEATS 100%

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1){
            return '0'; //if n==1 the only bit possible is 0
        }
        int length= (1 << n) -1;
        if(k<ceil(length/2.0)){
            return findKthBit(n-1,k); //if k is to the left side, it must be exactly in the previous Sn
        }
        else if(k==ceil(length/2.0)){
            return '1'; //if k is to the mid, it will always be 1 
        }
        else{
            char ch=findKthBit(n-1,length-(k-1)); //if to the right subset, it will be reversed and then inversed to find the value of k
            return (ch=='0')?'1':'0';
        }
    }
};