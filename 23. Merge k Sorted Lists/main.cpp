#include <iostream>
#include "bits/stdc++.h"
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> myPri;

    void addValue(vector<ListNode*>& lists){
        for (int i = 0; i < lists.size(); ++i) {
            ListNode* head = lists[i];
            while (head != nullptr){
                myPri.push(head->val);
                head = head->next;
            }
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        addValue(lists);
        ListNode* cur = nullptr, *head = cur;
        while (!myPri.empty()){
            if (cur != nullptr){
                cur->next = new ListNode(myPri.top());
                cur = cur->next;
                cur->next = nullptr;
                myPri.pop();
            } else{
                head = cur = new ListNode(myPri.top());
                myPri.pop();
                cur->next = nullptr;
            }
        }

        return head;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
