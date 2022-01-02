#include <bits/stdc++.h>
 
using namespace std;
 
 
template <typename T>
class fenwick {
  public:
  vector<T> arr;
  int n;
 
  fenwick(int n) : n(n) {
      arr.resize(n);
    }

    // increase value of elem x by v
    void inc(int x, T v) {
      while (x < n) {
          arr[x] += v;
          x = x | (x + 1);
      }
    }

  // inclusive 
    T get(int x) {
      T v{};
      while (x >= 0) {
          v += arr[x];
          x = (x & (x + 1)) - 1;
      }
      return v;
    }

};
 
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      string a, b;
      cin >> a >> b;
      vector<vector<int>> indices(26);
      for (int i = 0; i < n; i++) {
        indices[a[i]-'a'].push_back(i);
      }
      fenwick<int> f(n);
      for (int i = 0; i < n; i++) {
        f.inc(i, 1);
      }
      vector<int> ptr(26);
      long long inf = 1e18;
      long long ans = inf;
      long long cur = 0;
      for (int i = 0; i < n; i++) {
        int goal = b[i] - 'a';
        for (int d = 0; d < goal; d++) {
          if (ptr[d] < indices[d].size()) {
            int x = indices[d][ptr[d]];
            ans = min(ans, cur + f.get(x-1));
          }
        }
        if (ptr[goal] == indices[goal].size()) {
          break;
        }
        int x = indices[goal][ptr[goal]];
        cur += f.get(x-1);
        f.inc(x,-1);
        ptr[goal] += 1;
      }
      cout << (ans == inf ? -1 : ans) << endl;
    }
 
  return 0;
}