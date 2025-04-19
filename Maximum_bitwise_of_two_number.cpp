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

class Node{
public:
    vector<Node*> index;
    Node(){
        index = vector<Node*>(2, NULL);
    }
};
class Solution {
    public:
    void add(Node* root, int no, int ind){
        if(ind < 0)   return;
        
        int deciding = (no>>ind) & 1;
        if(root->index[deciding] == NULL){
            root->index[deciding] = new Node();
        }
        add(root->index[deciding], no, ind-1);
    }
    int find(Node* root, int no, int ind){
        if(ind < 0)     return 0;
        
        int deciding = (no>>ind)&1;
        int local = 0;
        if(deciding == 0)   local = 1;
        
        if(root->index[local] == NULL){
            return find(root->index[deciding], no, ind-1);
        }
        return (1<<ind) + find(root->index[local], no, ind-1);
    }
    int maxXor(vector<int> &arr) {
        // code here
        Node* root = new Node();
        add(root, arr[0], 30);
        int ans = 0;
        for(int i = 1; i<arr.size(); i++){
            int local = find(root, arr[i], 30);
            ans = max(ans, local);
            add(root, arr[i], 30);
        }
        return ans;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for (int i=0; i<n; i++)
        cin>>arr[i];

    Solution ob;
    cout<<ob.maxXor(arr)<<endl;

}