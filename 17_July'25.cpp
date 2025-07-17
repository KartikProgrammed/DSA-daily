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

//876. Middle of the Linked List
// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

// Approach:
// 1. Use two pointers, slow and fast.
// 2. Move slow by one step and fast by two steps until fast reaches the end
// 3. When fast reaches the end, slow will be at the middle node.

//CODE:-
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL){
            return head;
        }
        ListNode* temp1=head;
        ListNode* temp2=head;
        while(temp2!=NULL && temp2->next!=NULL){
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp2->next!=NULL){
                temp2=temp2->next;
            }
        }
        return temp1;
    }
};

//206. Reverse Linked List
// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Approach:
// 1. Use three pointers: prev, curr, and next.
// 2. Iterate through the list, reversing the links.
// 3. At the end, prev will point to the new head of the reversed list.

// CODE:
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
    ListNode* reverseList(ListNode* head) {
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
};