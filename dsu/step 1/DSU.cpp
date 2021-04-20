#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0);std::cin.tie(0);
using namespace std;

class UnionFind{
  std::vector<int> p, r;
  public:
  UnionFind(int n) {
    p.resize(n, 0);
    r.resize(n, 0);
    for (int i = 0; i < n; i++) p[i] = i;
  }
  int   findSet(int n)          { return (n == p[n] ? n : p[n] = findSet(p[n])); }
  bool   isSame(int a, int b)   { return findSet(a) == findSet(b);               }
  void unionSet(int a, int b)   {
    if (!isSame(a, b))          { int x = findSet(a); int y = findSet(b);
      if (r[x] > r[y])            p[x] = y;
      else {                      p[x] = y;
        if (r[x] == r[y])         r[y] ++; } }
  }
};

int main() {
  fast;
  int n, q;
  cin >> n >> q;

  UnionFind dsu(n + 1);
  while (q --) {
    string s;
    int a, b;
    cin >> s >> a >> b;

    if (s.front() == 'u') dsu.unionSet(a, b);
    else cout << (dsu.isSame(a, b) ? "YES" : "NO") << '\n';
  }
}

