#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
bool visited[2005]; 
long long int mod = 1000000007;
void SieveOfEratosthenes(ll n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true) 
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (ll p = 2; p <= n; p++)
        if (prime[p])
        primes.push_back(p); 
}
ll power(ll x,  ll y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return ((power(x, y / 2)%mod) * (power(x, y / 2)%mod))%mod;
    else
        return ((((x  %mod) * ((power(x, y / 2)%mod)))%mod * (power(x, y / 2)%mod))%mod)%mod;
}
 void solve(){
      ll n; 
       cin>>n; 
        ll arr[n];
     for(int i=0;i<n;i++)
     {
     cin>>arr[i]; 

     }
     vector<pair< ll, ll>>v; 
     for(int i=0;i<n;i++){
        v.push_back(make_pair(arr[i],i+1)); 
     }
     sort(v.begin(),v.end());
       ll pref[n]; 
       ll ans = 0 ;
      for( ll i=0;i<n;i++){
         pref[i] = ans + v[i].first; 
         ans+= v[i].first; 
      }
      vector< ll>vv; 
      vv.push_back(v[v.size()-1].second); 
      bool c = true; 
for(int i = n-2 ;i >=0;i--){
    // cout<<pref[i]<<" "<<v[i+1].first<<"\n"; 
    if(v[i] == v[i+1] && c == true)
    {
        vv.push_back(v[i].second); 
        continue; 
    }
    else{
        c = false; 
    }
   if(pref[i]>=v[v.size() - 1].first)
   {
       c = true; 
   vv.push_back(v[i].second); 
   }
}
sort(vv.begin(),vv.end());
cout<<vv.size()<<"\n"; 
for(auto i :vv)
{
cout<<i<<" "; 
}
    
 
}

 int main()
 {   int t = 1; 
      scanf("%d",&t);    
    while(t--){
solve(); 
cout<<"\n"; 
 }
}