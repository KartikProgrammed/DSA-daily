#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

//DailyProblem 3163:- String Compression III
// Given a string word, compress it using the following algorithm:

// Begin with an empty string comp. While word is not empty, use the following operation:
// Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
// Append the length of the prefix followed by c to comp.
// Return the string comp.

//CODE:-
//Approach:- just go according to the algorithm provided make sure to treat edge cases :D
class Solution {
public:
    string compressedString(string word) {
        string result="";
        if(word==" "){
            return result;
        }
        int i=0;
        while(word[i]==' '){
            i++;
        }
        while(i<word.length()){
            int count=1;
            while(i!=word.length()-1 && word[i+1]==word[i] && count<9){
                count++;
                i++;
            }
            result+=to_string(count)+word[i]; //be sure to use += saves memory, otherwise it will give MLE
            i++;
        }
        return result;
    }
};