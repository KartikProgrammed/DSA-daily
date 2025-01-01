#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

//1422. Maximum Score After Splitting a String
//Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

// The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.?

//APPROACH:- (Beats 100%)
//pre compute the number of zeros to the left of an index and number of 1s to the right of an index in a vector
//then in one go find the max of the scores by adding the ith index of ones and i-1 index of the zeros vectors

//CODE:-
class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        vector<int> ones(n,0);
        vector<int> zeros(n,0);
        if(n==1){
            return 1;
        }
        int curr=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                curr++;
            }
            zeros[i]=curr;
        }
        curr=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                curr++;
            }
            ones[i]=curr;
        }
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            int opt=ones[i]+zeros[i-1];
            ans=ans>opt?ans:opt;
        }
        return ans;
    }
};