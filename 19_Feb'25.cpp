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

// 1415. The k-th Lexicographical String of All Happy Strings of Length n
// A happy string is a string that:

// consists only of letters of the set ['a', 'b', 'c'].
// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

// Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

// Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

//APPROACH:-
//use basic recursion to find all happy strings possible 
//at each recursive call there's exactly 3/2 character addition out of abc
//return the k-1th element if present else return ""

//CODE:-
class Solution {
public:
    void recursion(vector<string>& res,string curr,char prev,int n){
        if(curr.length()==n){
            res.push_back(curr);
            return ;
        }
        if(prev!='a'){
            string newcurr=curr;
            recursion(res,newcurr.append("a"),'a',n);
        }
        if(prev!='b'){
            string newcurr=curr;
            recursion(res,newcurr.append("b"),'b',n);
        }
        if(prev!='c'){
            string newcurr=curr;
            recursion(res,newcurr.append("c"),'c',n);
        }
    }
    string getHappyString(int n, int k) {
        vector<string> res;
        recursion(res,"",'z',n);
        if(k>res.size()){
            return "";
        }
        return res[k-1];
    }
};

//CODE 2:-
//cutting off the append function to space some space of the new variable and some time as well
class Solution {
public:
    void recursion(vector<string>& res,string curr,char prev,int n){
        if(curr.length()==n){
            res.push_back(curr);
            return ;
        }
        if(prev!='a'){
            recursion(res,curr+'a','a',n);
        }
        if(prev!='b'){
            recursion(res,curr+'b','b',n);
        }
        if(prev!='c'){
            recursion(res,curr+'c','c',n);
        }
    }
    string getHappyString(int n, int k) {
        vector<string> res;
        recursion(res,"",'z',n);
        if(k>res.size()){
            return "";
        }
        return res[k-1];
    }
};