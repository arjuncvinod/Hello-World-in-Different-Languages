#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1000000007;
double eps = 1e-12;
#define ln "\n"
#define printVector(a) for(int i=0; i<a.size(); i++){cout<<a[i]<<" ";}cout<<ln;
#define print_array(a,n) for(int i=0; i<n; i++){cout<<a[i]<<" ";}cout<<ln;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define take_vector(a) for(auto &x:a)cin>>x;
#define take_array(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define take_matrix(a,m,n) for(int i=0; i<m; i++){for(int j=0; j<n; j++){cin>>a[i][j];}}
#define print_matrix(a,m,n) for(int i=0; i<m; i++){for(int j=0; j<n; j++){cout<<a[i][j]<<" ";}cout<<ln;}
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b))*b
// #define count(a,x) count(a.begin(), a.end(),x)
// #define sum(a) accumulate(a.begin(), a.end(),0)
#define max_ele(a) *max_element(a.begin(), a.end())
#define min_ele(a) *min_element(a.begin(), a.end())
// double pi = 3.1415926535;



void solve(int it)
{ 
  int n;
  cin>>n;
  string s;
  cin>>s;
  int q;
  cin>>q;
  vector<int>que(q),fq;
  map<int,int>mp;
  for(int i=0;i<q;i++){
    cin>>que[i];
    mp[que[i]]++;
  }
  for(auto x:mp){
    if(x.second%2==1)fq.pb(x.first);
  }
  for(int i=0;i<fq.size();i++){
        for(int j=fq[i]-1;i<n;i+=fq[i]){
            if(s[i]=='0')s[i]=='1';
            else s[i]=='0';
            }
  }
  
  vector<int>ans;
  for(int i=2;i<42;i++){
      if(n%i==0){
          while(n%i==0){
          ans.push_back(i);
          n/=i;}
          
        //   cout<<i<<" ";
      }
  }
  if(n>1)ans.push_back(n);
    
ll sum=0;
for(int i=0;i<ans.size();i++)sum+=ans[i];
if(sum<41 and ans.size()>0){
    int x=41-sum;
    for(int i=0;i<x;i++)ans.pb(1);
}
cout<<"Case #"<<it<<": ";
if(sum<=41 and ans.size()>0){
cout<<ans.size()<<" ";
for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}

  
  
  else cout<<"-1";
cout<<"\n";
}


int main()
{

#ifndef ONLINE_JUDGE
  freopen("input1.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  
  fast_cin();

  
  ll t = 1;
  cin >> t;
  
  for (int it = 1; it <= t; it++)
  {
    solve(it);
  }
  // solve();


  return 0;
}
