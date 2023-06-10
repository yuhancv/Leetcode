#include <iostream>
#include "bits/stdc++.h"
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:

    map<int, vector<Node* >> treeMap;

    Node* connect(Node* root) {
        if (root == nullptr)
            return root;
        bfs(root);

        for (auto it = treeMap.begin(); it !=  treeMap.end(); it++) {
            auto v = it->second;

            if (v.size() == 1){
                v.front()->next = nullptr;
                continue;
            }

            for (int i = 0; i < v.size() - 1; ++i) {
                v[i]->next = v[i + 1];
            }

            v.back()->next = nullptr;
        }

        return root;
    }

    void bfs(Node* root){
        if (root == nullptr)
            return;

        queue<Node*> myQueue;
        int height = 0;
        myQueue.push(root);

        while (!myQueue.empty()){
            int width = myQueue.size();
            height++;

            for (int i = 0; i < width; ++i) {
                auto cur = myQueue.front();
                myQueue.pop();
                treeMap[height].push_back(cur);

                if (cur->left != nullptr)
                    myQueue.push(cur->left);
                if (cur->right != nullptr)
                    myQueue.push(cur->right);
            }
        }
    }
};





class Solution1 {
public:

    map<int, vector<Node* >> treeMap;

    Node* connect(Node* root) {
        if (root == nullptr)
            return root;

        dfs(root, 1);

        for (auto it = treeMap.begin(); it != treeMap.end(); it++) {
            vector<Node* > v = it->second;

            if (v.size() == 1)
                v.front()->next = nullptr;

            for (int i = 0; i < v.size() - 1; ++i) {
                v[i]->next = v[i + 1];
            }

            v.back()->next = nullptr;
        }

        return root;

    }

    void dfs(Node* cur, int height){
        if (cur == nullptr)
            return;

        treeMap[height].push_back(cur);
        dfs(cur->left, height + 1);
        dfs(cur->right, height + 1);
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
