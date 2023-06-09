#include <iostream>
#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    vector<vector<int>> tree;
    vector<int> temp;

    vector<int> rightSideView(TreeNode* root) {
        if (root)
            dfs(root);
        if (!tree.empty())
            return tree.back();
        else
            return temp;
    }

    void dfs(TreeNode* cur){
        if (cur == nullptr)
            return;
        if (cur->left == nullptr && cur->right == nullptr){
            temp.push_back(cur->val);
            tree.push_back(temp);
            temp.pop_back();
            return;
        }

        temp.push_back(cur->val);
        dfs(cur->left);
        dfs(cur->right);
        temp.pop_back();
    }
};







/*
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int target;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        this->target = targetSum;
        if (root)
            dfs(root);
        return ans;
    }

    void dfs(TreeNode* cur){
        if (cur->left == nullptr && cur->right == nullptr){
            temp.push_back(cur->val);
            int sum = 0;
            for (int i = 0; i < temp.size(); ++i) {
                sum += temp[i];
            }

            if (sum == target){
                ans.push_back(temp);
            }

            temp.pop_back();
            return;
        }

        temp.push_back(cur->val);

        if (cur->left != nullptr)
            dfs(cur->left);
        if (cur->right != nullptr)
            dfs(cur->right);
        temp.pop_back();
    }
};

 */





























/*
class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<int>> edges;
    bool visited[30010] = {false};

    void buildGraph(){
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    bool isLeaf(int u){
        int child = 0;

        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i];
            if (visited[v] == false)
                child++;
        }

        return (child == 0) ? true : false;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        this->edges = edges;
        buildGraph();
        vector<int> ans;
        int minHeight = INT_MAX;

        for (int i = 0; i < n; ++i) {
            fill(visited, visited + 30010, false);
            int nowHeight = dfs(i);
            if (nowHeight < minHeight){
                minHeight = nowHeight;
                ans.clear();
                ans.push_back(i);
            } else if (nowHeight == minHeight){
                ans.push_back(i);
            }
        }

        return ans;
    }

    int dfs(int u){
        if (isLeaf(u)){
            visited[u] = true;
            return 1;
        }

        visited[u] = true;
        int maxHeight = 0;
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u].size();
            if (visited[v] == false){
                maxHeight = max(maxHeight, dfs(v));
            }
        }

        return maxHeight + 1;
    }
};*/


struct Node{
    int val;
    Node *left, *right;
    vector<Node*> child;

    Node(int val){
        this->val = val;
    }
};

int dfs(Node* cur){
    if (cur == nullptr)
        return 0;
    if (cur->left == nullptr && cur->right == nullptr)
        return 1;

    int maxHeight = INT_MAX * (-1);
    for (auto it = cur->child.begin(); it != cur->child.end(); it++) {
        maxHeight = max(maxHeight, dfs(*it));
    }

    return maxHeight + 1;
}




int main() {
    Node *n0 = new Node(0), *n1 = new Node(1), *n2 = new Node(2), *n3 = new Node(3)
            , *n4 = new Node(4), *n5 = new Node(5);

    n4->child.push_back(n5), n4->child.push_back(n3);
    n3->child.push_back(n0), n3->child.push_back(n1), n3->child.push_back(n2);



    cout << dfs(n3);
    return 0;
}



/*
class Solution {
public:

    vector<int> ans;
    int minHeight = INT_MAX;
    bool visited[30010] = {false};
    vector<vector<int>> edges;

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        this->edges = edges;

        for (int i = 0; i < n; ++i) {
            fill(visited, visited + 30010, false);
            int nowHeight = dfsHeight(i);
            if (nowHeight < minHeight){
                minHeight = nowHeight;
                ans.clear();
                ans.push_back(i);
            } else if (nowHeight == minHeight){
                ans.push_back(i);
            }
        }

        return ans;
    }

    bool isLeaf(int u){
        int num = 0;
        for (int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i];
            if (visited[v] == false)
                num++;
        }

        return (num == 0) ? true : false;
    }

    int dfsHeight(int u){
        visited[u] = true;

        if (isLeaf(u))
            return 1;

        int height = -INT_MAX;
        for (int i = 0; i < edges[u].size(); ++i) {
            auto v = edges[u][i];
            if (visited[v] != false){
                height = max(height, dfsHeight(v));
            }
        }

        return height + 1;
    }




};

 */