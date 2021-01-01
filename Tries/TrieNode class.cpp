#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define loop(i, a, b) for (int i = a; i < b; i++)
#define sloop(str, i, a) for (int i = a; str[i] != '\0'; i++)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define PII pair<int, int>
#define MAX 1000005
#define inf 1000000000000000LL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

typedef long long ll;
using namespace std;

//auto inside = [&](){
//cout<<"nigga";
//};
//inside();

template <typename T>
string to__string(T x)
{
    ostringstream ss;
    ss << x;
    return ss.str();
}

int fast_expo(ll a, ll b, ll p)
{

    if (a == 0)
        return 0;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a, ans %= p;
        a *= a, a %= p;
        b /= 2;
    }
    return ans;
}

ll inv(ll a, ll p)
{
    return fast_expo(a, p - 2, p);
}

/* ll nCk(ll n, ll k, ll p){
    return ((fact[n] * inv(fact[k],p)%p) * inv(fact[n-k],p)) % p;
} */

ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    return b;
}

ll min(ll a, ll b)
{
    if (a >= b)
        return b;
    return a;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class trienode
{

public:
    char data;
    unordered_map<char, trienode *> children;
    bool isTerminal;
    int child_count;

    trienode(char data)
    {
        this->data = data;
        isTerminal = false;
        child_count = 0;
    }
};

class trie
{

public:
    trienode *root;

    trie()
    {
        root = new trienode('\0');
    }

    void insert(string word)
    {

        int n = word.size();
        if (n == 0)
            return;

        trienode *child = root;

        for (int i = 0; i < n; i++)
        {
            if (child->children.count(word[i]) == 0)
            {
                trienode *temp = new trienode(word[i]);
                child->children[word[i]] = temp; // connection
                child->child_count++;
            }
            child = child->children[word[i]];
        }
        child->isTerminal = true;
        //   cout<<"Done\n";
    }

    bool search(string word)
    {

        int n = word.size();

        if (!n)
            return false; // no empty string can be inserted

        trienode *child = root;

        for (int i = 0; i < n; i++)
        {
            if (child->children.count(word[i]) == 0)
                return false; // word not found

            child = child->children[word[i]];
        }
        return child->isTerminal; // WORD SHOULD END HERE
    }

    vector<string> autocomplete(string str)
    { // sone prefix given need to give all connected words in trie

        string prefix = str;
        int n = str.size();

        trienode *child = root;
        for (int i = 0; i < n; i++)
        {
            if (child->children.count(str[i]) == 0)
                return {};
            child = child->children[str[i]];
        }

        // if we are here then child points at last char of prefix

        vector<string> temp;
        root_to_leaf_paths(child, temp, "");
        for (int i = 0; i < temp.size(); i++)
            temp[i] = prefix + temp[i];
        return temp;
    }

    void root_to_leaf_paths(trienode *child, vector<string> &res, string str)
    {

        if (child->isTerminal)
            res.pb(str);
        if (child->child_count == 0)
            return; // reached a leaf

        for (auto it : child->children)
        { // iterate over possible candidates
            root_to_leaf_paths(it.second, res, str + it.first);
        }
    }

    ~trie()
    {
        delete root;
    }
};


// abb-bbba = ()bba -> need to have same suffix