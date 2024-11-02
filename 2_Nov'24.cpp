#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<unordered_set>
using namespace std;

//DailyProblem 2490:- Circular Sentence
// A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

// For example, "Hello World", "HELLO", "hello world hello world" are all sentences.
// Words consist of only uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.

// A sentence is circular if:

// The last character of a word is equal to the first character of the next word.
// The last character of the last word is equal to the first character of the first word.
// For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.

// Given a string sentence, return true if it is circular. Otherwise, return false.

//CODE:-
//BEATS 100%
class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0]!=sentence[sentence.length()-1]){
            return false; //if the condition 2 isnt true it must not be circular sentence
        }
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]==' '){
                if(sentence[i-1]==sentence[i+1]){
                    continue;
                }
                else{
                    return false; //if condition 1 isnt true it must not be a circular sentence 
                }
            }
        }
        return true;
    }
};