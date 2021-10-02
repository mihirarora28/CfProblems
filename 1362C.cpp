#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
bool visited[2005]; 
 ll mod = 1000000007;
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
bool sortbysecdesc(const pair<int,pair<int,int>> &a,
                   const pair<int,pair<int,int>> &b)
{
       return a.second<b.second;
}
 
 void solve(){
     ll n; 
     cin>>n; 
     ll sum = 1; 
     ll dp[64]; 
     dp[0] = 1; 
     for(int i = 2; i <= 64; i ++ ){
         dp[i-1] = sum + i; 
         sum = sum + dp[i-1]; 
     }
    //  for(int i =0; i <= 63; i ++ )
    //  cout<<dp[i]<<" ";
    ll ctr = 0;
    ll ans =0 ;
    while(n!=0){
        // int c = n<<ctr; 
        int c1 = n&1;
        if(c1==1)
        ans+=dp[ctr]; 
        ctr++; 
        n = n  / 2; 
    }
    cout<<ans;
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