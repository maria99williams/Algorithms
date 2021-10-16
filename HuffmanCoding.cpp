/*
INPUT:
abcdef
5 9 12 13 16 45
OUTPUT:
0 100 101 1100 1101 111
*/

#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int freq;
    node * left;
    node *right;

    node(int data) {
        freq = data;
        left = right = nullptr;
    }
};

class cmp {
public:
    bool operator()(node *l1, node *l2) {
        return l1->freq > l2->freq;
    }
};

void preorder(vector<string> &ans, node *root, string s) {
    if (!root) return;

    //print the root which is at leaf
    if (!root->left and !root->right) {
        ans.push_back(s);
    }
    preorder(ans, root->left, s + "0");
    preorder(ans, root->right, s + "1");
}

vector<string> huffmanCode(string s, vector<int> f, int n) {
    priority_queue<node*, vector<node*>, cmp> pq;

    for (int i = 0; i < n; i++) {
        node *temp = new node(f[i]);
        pq.push(temp);
    }
    while (pq.size() != 1) {
        node *a = pq.top();
        pq.pop();
        node *b = pq.top();
        pq.pop();

        node * temp = new node(a->freq + b->freq);
        temp->left = a;
        temp->right = b;
        pq.push(temp);
    }

    vector<string> ans;
    preorder(ans, pq.top(), "");
    return ans;
}


int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    vector<string> ans = huffmanCode(s, f, n);
    for (auto x : ans) {
        cout << x << " ";
    }
}

