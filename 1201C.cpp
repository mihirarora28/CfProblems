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
     ll k ; 
     cin>>k; 
     ll arr[n+1]; 
     for(int i = 0 ;i < n ; i ++) 
      cin>>arr[i]; 
      arr[n] = 1e11; 
      sort(arr,arr+n+1);
      ll median = arr[n/2]; 
// for(int i = 0 ;i < n ; i ++) 
//       cout<<arr[i]<<" "; 
      ll c = n/2 + 1; 
      ll ans =0 ;
      ll ctr = 1; 
      while(c<=n){
          ans+= ctr*(arr[c] - arr[n/2]);
        //   cout<<ans<<"\n"; 
          if(ans == k){
              cout<<arr[c]; 
              return; 
          }
          if(ans>k){
              ans-= ctr*(arr[c] - arr[n/2]);
            //   cout<<ans; 
           cout<<arr[n/2] + (k-ans)/ctr  ; 
              return; 
          } 
          arr[n/2] = arr[c]; 
          c++; 
          ctr++; 
      }
 }
 int main()
 {

     int t = 1; 
    //  scanf("%d",&t); 
        
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }