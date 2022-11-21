#include<bits/stdc++.h>
using namespace std;

#define int long long


int rand(int  a, int b) {
   // x = [a,b]
   return a + rand() % (b - a + 1);
}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


void printTreeEdges(int prufer[], int m) {
   int vertices = m + 2;
   int vertex_set[vertices];
   for (int i = 0; i < vertices; i++) {
      vertex_set[i] = 0;
   }
   for (int i = 0; i < vertices - 2; i++) {
      vertex_set[prufer[i] - 1] += 1;
   }

   int j = 0;

   for (int i = 0; i < vertices - 2; i++) {
      for (int j = 0; j < vertices; j++) {
         if (vertex_set[j] == 0) {
            vertex_set[j] = -1;
            cout << (j + 1) << " " << prufer[i] << "\n";
            vertex_set[prufer[i] - 1]--;
            break;
         }
      }
   }
   j = 0;
   for (int i = 0; i < vertices; i++) {
      if (vertex_set[i] == 0 && j == 0) {
         cout << (i + 1) << " ";
         j++;
      } else if (vertex_set[i] == 0 && j == 1) {
         cout << (i + 1) << " \n";
      }
   }
}
int MAXN = 1e6 + 5;
vector<int> spf;
vector<int> p;
void sieve() {
   spf.resize(MAXN);
   spf[1] = 1;
   for (int i = 2; i < MAXN; i++) {
      spf[i] = i;
   }
   for (int i = 4; i < MAXN; i += 2) {
      spf[i] = 2;
   }
   p.push_back(2);
   for (int i = 3; i * i <= MAXN; i += 2) {
      if (spf[i] == i) {
         p.push_back(i);
         for (int j = i * i; j < MAXN; j += i) {
            if (spf[j] == j) {
               spf[j] = i;
            }
         }
      }
   }
}
void generateRandomTree(int n) {
   int length = n - 2;
   int arr[length];
   for (int i = 0; i < length; i++) {
      arr[i] = rand(0, length + 1) + 1;
   }
   printTreeEdges(arr, length);
}

void solve() {
   int r = rand(5, 10);
   int c = rand(5, 10);
   int u = rand(1, 10);
   int p = rand(4, 5);
   // int m = rand(p, r * c);

   int m = rand(2 * p, 4 * p);
   cout << r << " " << c << " " << u << " " << p << " " << m << "\n";

   set<pair<int, int>> s;
   while (s.size() < u) {
      int x = rand(0, r - 1), y = rand(0, c - 1);
      s.insert({x, y});
   }

   for (auto [x, y] : s) {
      cout << x << " " << y << "\n";
   }

   for (int i = 0; i < m; i++) {
      cout << rand(1, 4) << " " << rand(1, 100) << " " << rand(1, 100) << "\n";
   }

   for (int i = 0; i < p; i++) {
      cout << rand(1, 100) << " ";
   }
   cout << "\n";
}

signed main() {
   srand (time (0));  // needs ctime header
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t = 1;

   sieve();

   // cout << t << "\n";
   while (t--) {
      solve();
   }
}
