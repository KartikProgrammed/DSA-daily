#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
using namespace std;

// 846. Hand of Straights
// Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

//APPROACH:-
//sort the hands vector first,create a map then to keep a count of the frequencies
//now make pairs of groupsize and check if the cards are consecutive
//TIP:- making the same code with vector wouldnt be accepted so save memory and use unorderedmaps

//CODE:-
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        sort(hand.begin(), hand.end());
        unordered_map<int,int> map;
        for(int i=0;i<hand.size();i++){
            map[hand[i]]++;
        }
        for(int iter:hand){
            if(map[iter]>0){
                int curr=map[iter];
                for(int j=0;j<groupSize;j++){
                    if(map[iter+j]<curr){
                        return false;
                    }
                    map[iter+j]-=curr;
                }
            }
        }
        return true;
    }
};