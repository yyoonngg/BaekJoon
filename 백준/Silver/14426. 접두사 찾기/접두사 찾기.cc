#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool is_end;

    TrieNode() {
        is_end = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }

    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) delete children[i];
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->is_end = true;
    }

    bool isPrefix(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return true; // 접두사면 여기까지 도달 가능
    }

private:
    TrieNode* root;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Trie trie;
    string s;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        trie.insert(s);
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        if (trie.isPrefix(s)) count++;
    }

    cout << count << "\n";
    return 0;
}
