#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

class disjointset
{
public:
  vector<int> parent, rank, cnt, minimum, maximum;
  int cnt_comp; // total components

  disjointset(int n)
  {
    parent.resize(n + 1);
    rank.resize(n + 1);
    cnt.resize(n + 1); // cnt of members of a component
    minimum.resize(n + 1);
    maximum.resize(n + 1);
    cnt_comp = n;
    for (int i = 1; i <= n; i++)
    {
      parent[i] = i;
      rank[i] = 1;
      minimum[i] = i;
      maximum[i] = i;
      cnt[i] = 1;
    }
  } 
  void join(int a, int b)
  {
    a = find(a);
    b = find(b);
    if (a != b)
    {
      cnt_comp--;
    }
    if (a == b)
      return;
    if (rank[a] == rank[b])
      rank[a]++;
    if (rank[a] > rank[b])
    {
      parent[b] = a;
      minimum[a] = min(minimum[a], minimum[b]);
      maximum[a] = max(maximum[a], maximum[b]);
      cnt[a] += cnt[b];
    }
    else if (rank[a] < rank[b])
    {
      parent[a] = b;
      minimum[b] = min(minimum[a], minimum[b]);
      maximum[b] = max(maximum[a], maximum[b]);
      cnt[b] += cnt[a];
    }
  }
  int find(int a)
  {
    return a == parent[a] ? a : parent[a] = find(parent[a]);
  }
  bool check(int a, int b)
  {
    return find(a) == find(b);
  }
  int getcnt(int a)
  {
    a = parent[a];
    return cnt[a];
  }
};

int main()
{

  disjointset d(5);
  cout << d.find(4) << endl;
  cout << d.check(1, 2) << endl;
  d.join(1, 2);
  cout << d.check(1, 2) << endl;
  return 0;
}
