#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<unordered_set>
using namespace std;

//DailyProblem 1957:- Delete Characters to Make Fancy String
// A fancy string is a string where no three consecutive characters are equal.
// Given a string s, delete the minimum possible number of characters from s to make it fancy.
// Return the final string after the deletion. It can be shown that the answer will always be unique.


//CODE:-
//Approach 1:- deleting from the string(TLE since erase function traverses again to the string)
class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3){
            return s;
        }
        int one=0;
        int two=1;
        int three=2;
        while(three<s.length()){
            if(s[one]==s[two] && s[two]==s[three]){
                //delete
                s.erase(one,1);
            }
            else{
                one++;
                two++;
                three++;
            }
        }
        return s;
    }
};

//Approach 2:- Create a new string and push into it
class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3){ //return the string if it is shorter than length 3
            return s;
        }
        int one=0;
        int two=1;
        int three=2;
        string result="";
        result=result+s[one]+s[two];
        while(three<s.length()){
            if(result[one]==result[two] && result[two]==s[three]){
                //do nothing just incr three
                three++; //only three incremented because if updated all might run into index not found err
            }
            else{
                result.push_back(s[three]);  
                one++;
                two++;
                three++;  
            }
        }
        return result;
    }
};