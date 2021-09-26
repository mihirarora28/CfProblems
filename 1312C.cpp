#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
bool visited[2005]; 
long long int mod = 1e18;
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
     int n; 
     cin>>n ;
     ll k; 
     cin>>k; 
     ll arr[n] ;
     ll ans = 0 ;
     vector<ll>v; 
     set<int>s; 
     for(int  i = 0; i < n ; i ++){
         cin>>arr[i]; 
     }
     bool cond = true; 
     for(int i = 0 ; i < n ; i++){
         if(arr[i]%k == 1 && cond == true){
             cond = false; 
             arr[i] = arr[i] - 1; 
         }
         if(cond == false && arr[i]%k == 1)
         {
             cout<<"NO"; 
             return; 
         }
         int ctr =0 ; 
         if(arr[i]%k!=0){
             cout<<"NO"; 
             return; 
         }
         while(arr[i]!=0){
             ll c = arr[i]; 
             ll ctr = 0; 
             while(c!=0){
                 c = c / k; 
                 ctr++; 
             }
             auto it = s.find(ctr-1); 
             if(it == s.end())
             {
             s.insert(ctr-1); 
             }
             else{
                 cout<<"NO"; 
                 return; 
             }
             arr[i] = arr[i] - power(k,ctr-1);
         }
     }
    //  cout<<"\n"; 
    // for(auto i : s){
    //     cout<<i<<" "; 
    // }
    // cout<<"\n"; 
     cout<<"YES"; 
     return; 
}

 int main()
 {

     int t = 1; 
      scanf("%d",&t); 
        
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }