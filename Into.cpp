// I/O and formatting
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

// Data structures
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <list>

// Algorithms and utilities
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <bitset>

// Strings
#include <string>
#include <string_view>

// Other useful libraries
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <chrono>
#include <random>
#include <array>
#include <tuple>
#include <limits>

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

// using namespace __gnu_pbds;
// // *X.find_by_order
// // X.order_of_key
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;// ordered_set

// Chota
#define ll long long int

// For faster I/O
#define fast_io() std::ios::sync_with_stdio(false); std::cin.tie(nullptr)

// Constants
const int MOD = 1e9 + 7;
const long long int INF = LLONG_MAX;
const double EPS = 1e-9;

// Utility functions
template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

using namespace std;

class node{
public:
    bool is_word;
    vector<node*> child;
    node(){
        child = vector<node*> (26);
        is_word = false;
        for(int i = 0; i<child.size(); i++){
            child[i] = NULL;
        }
    }
};
class Trie {
    public:
    
    node* root;
    Trie() {
        // implement Trie
        root = new node();
    }
    
    void add(string &word, int ind, node* root){
        if(ind >= word.size()){
            root->is_word = true;
            return;
        }
        
        if(root->child[word[ind]-'a'] == NULL){
            root->child[word[ind]-'a'] = new node();
        }
        add(word, ind+1, root->child[word[ind]-'a']);
    }
    void insert(string &word) {
        // insert word into Trie
        add(word, 0, root);
    }
    
    bool s(string &word, int ind, node* root){
        if(ind == word.size())  return root->is_word;
        if(root->child[word[ind]-'a'] == NULL)  return false;
        
        // bool ans = false;
        // if(root->is_word == true && ind+1 == word.size())   ans = true;
        // return ans;
        return s(word, ind+1, root->child[word[ind]-'a']);
    }
    bool search(string &word) {
        // search word in the Trie
        return s(word, 0, root);
    }

    bool p(string &word, int ind, node* root){
        if(ind >= word.size())  return true;
        if(root->child[word[ind]-'a'] == NULL)    return false;
        
        return p(word, ind+1, root->child[word[ind]-'a']);
    }
    bool isPrefix(string &word) {
        // search prefix word in the Trie
        return p(word, 0, root);
    }
};

int main() {
    int q;
    cin >> q;
    // cin.ignore();
    vector<bool> ans;
    Trie ob;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        string s;
        cin >> s;
        // cin.ignore();
        if (x == 1) {
            ob.insert(s);
        } else if (x == 2) {
            ans.push_back(ob.search(s));
        } else if (x == 3) {
            ans.push_back(ob.isPrefix(s));
        }
    }
    cout << boolalpha;
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
        // cout << "~\n";
    return 0;
}