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
int factorial( int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res = ((res)%mod * (i)%mod)%mod;
    return res%mod;
}
bool sortbysec(const pair<ll,vector<ll>> &a,
              const pair<ll,vector<ll>> &b)
{
    return (a.first < b.first);
}

 void solve(){
     ll n,k; 
     cin>>n>>k; 
     ll arr[n]; 
     vector<ll>v; 
     bool f = true; 
     for(int  i = 0 ; i < n ; i ++ ){
         cin>>arr[i]; 
         if(arr[i]%k ==0){
           continue; 
         }
         else
         {
         f = false;
         }
         if(arr[i] <= k){
             v.push_back(k - arr[i]); 
         }
         else{
             v.push_back(k - (arr[i]%k)); 

         }
     }
     if(f == true){
         cout<<0; 
         return; 
     }
     map<ll,ll>mapp; 
     for(int  i = 0; i < v.size(); i ++)
     mapp[v[i]]++; 
     ll ans = 0 ;
     for(auto i :mapp){
         ll current = i.first + (i.second - 1)*(k);
         ans = max(ans,current);  

     }
     cout<<ans + 1; 
}

 int main()
 {   int t = 1; 
       scanf("%d",&t);    
    while(t--){
solve(); 
cout<<"\n"; 
 }
}