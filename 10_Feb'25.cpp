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

//3174. Clear Digits
// You are given a string s.

// Your task is to remove all digits by doing this operation repeatedly:

// Delete the first digit and the closest non-digit character to its left.
// Return the resulting string after removing all digits.

//APPROACH:-
//basic string operation erase

//CODE:-
class Solution {
    public:
        string clearDigits(string s) {
            bool flag;
            do{
                flag=false;
                for(int i=0;i<s.length();i++){
                    if(isdigit(s[i])){
                        for(int j=i-1;j>=0;j--){
                            if(isalpha(s[j])){
                                s.erase(i,1);
                                s.erase(j,1);
                                flag=true;
                                break;
                            }
                        }
                        break;
                    }
                }
            }while(flag);
            return s;
        }
    };


//135. Candy
// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

//APPROACH:-
//1st iteration from left to right increase the candies if LHS > curr
//2nd iteration from right to left increase the candies if RHS>curr && new arr curr<RHS
//find total sum

//CODE:- (beats 100%)
class Solution {
    public:
        int candy(vector<int>& ratings) {
            vector<int> arr(ratings.size(),1);
            for(int i=1;i<ratings.size();i++){
                if(ratings[i]>ratings[i-1]){
                    arr[i]=arr[i-1]+1;
                }
            }
            for(int i=ratings.size()-2;i>=0;i--){
                if(ratings[i]>ratings[i+1] && arr[i]<=arr[i+1]){
                    arr[i]=arr[i+1]+1;
                }
            }
            int tot=0;
            for(int i=0;i<ratings.size();i++){
                tot+=arr[i];
            }
            return tot;
        }
    };