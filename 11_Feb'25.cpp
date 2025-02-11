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

//1910. Remove All Occurrences of a Substring
// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

//APPROACH:-
//use the inbuilt library functions to find for a substring in a string 
//do it till the find return npos which is returned when the substrings is not found
//if the substr is found erase it using the erase function 

//CODE:-
class Solution {
    public:
        string removeOccurrences(string s, string part) {
            bool found=false;
            if(s.length()<part.length()){
                return s;
            }
            int n=part.size();
            do{
                size_t pos = s.find(part);
                if (pos != std::string::npos) {
                    found=true;
                    s.erase(pos,n);
                } else {
                    found=false;
                }
            }while(found);
            return s;
        }
};