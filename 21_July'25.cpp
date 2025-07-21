#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

//1957. Delete Characters to Make Fancy String
// A fancy string is a string where no three consecutive characters are equal.
// Given a string s, delete the minimum possible number of characters from s to make it fancy.
// Return the final string after the deletion. It can be shown that the answer will always be unique.

// Approach:
// 1. Initialize a result string.
// 2. Traverse the input string and check the last two characters of the result string.
// 3. If the last two characters are the same as the current character, skip the current character.
// 4. Otherwise, append the current character to the result string.
// 5. Return the result string.

// CODE:
class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3){
            return s;
        }
        string res="";
        char prev=s[0];
        res+=s[0];
        int count=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==prev){
                count++;
                if(count<3){
                    res+=s[i];
                }
                else{
                    continue;
                }
            }
            else{
                res+=s[i];
                prev=s[i];
                count=1;
            }
        }
        return res;
    }
};

//25. Reverse Nodes in k-Group
// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Approach:
//No extra memory is used.

//CODE:-
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* first=NULL;
        ListNode* second=head;
        while(second!=NULL){
            ListNode* third=second->next;
            second->next=first;
            first=second;
            second=third;
        }
        return first;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr=head;
        ListNode* prev=&dummy;
        while(true){
            ListNode* temp=curr;
            int count=0;
            while(temp!=NULL && count<k){
                count++;
                temp=temp->next;
            }
            if(count<k){
                break;
            }

            ListNode* nextGroup = temp;
            ListNode* groupStart = curr;
            ListNode* groupEnd = curr;
            for (int i = 1; i < k; ++i)
                groupEnd = groupEnd->next;

            groupEnd->next=NULL;

            ListNode* newst=reverse(groupStart);
            prev->next=newst;
            groupStart->next=nextGroup;
            
            curr=nextGroup;
            prev=groupStart;

        }
        return dummy.next;
    }
};