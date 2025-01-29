#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
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

// 355. Design Twitter (Very Interesting and Revision Worthy Problem)
// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

// Implement the Twitter class:

// Twitter() Initializes your twitter object.
// void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
// List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
// void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
// void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
 

//APPROACH:-
//create a unordered map for follower list
//create a unordered map for tweets by a person
//push all the tweets available along with a timestamp into a priority queue
//pop top 10 and then put them into the result vector to display

//CODE:-
class Twitter {
private:
struct Tweet{
            int id;
            int time;
            Tweet(int i,int t):id(i),time(t){}
        };
        unordered_map<int,unordered_set<int>> followers;
        unordered_map<int,vector<Tweet>> tweets;
        int timestamp;
public:
    Twitter() : timestamp(0) {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId,timestamp++);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        unordered_set<int> followList=followers[userId];
        followList.insert(userId);
        for(int follower:followList){
            auto &tw = tweets[follower];
            for (int i = max(0, (int)tw.size() - 10); i < tw.size(); ++i) {
                pq.emplace(tw[i].time, tw[i].id);
            }
        }
        vector<int> res;
        while(!pq.empty() && res.size()<10){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            followers[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */