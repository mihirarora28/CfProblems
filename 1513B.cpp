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

 void solve(){
     ll n; 
     cin>>n;
     ll arr[n]; 
     for(int i = 0; i  <n ;i ++ )
     cin>>arr[i] ;
     ll c = arr[0]; 
     for(int i = 1 ; i < n; i ++ )
     c = c & arr[i]; 
     ll ctr = 0; 
     map<ll,ll>mapp; 
     for(int  i = 0; i  <n ; i ++ )
     {
         if(c == arr[i])
         mapp[arr[i]]++; 
     }
     if(mapp[c] <= 1){
         cout<<0<<"\n"; 
         return;     }
     ll cc = factorial(n-2); 
     ll cc1 = mapp[c]*(mapp[c] - 1)%mod; 
     cout<<(cc*cc1)%mod; 

}

 int main()
 {   int t = 1; 
      scanf("%d",&t);    
    while(t--){
solve(); 
cout<<"\n"; 
 }
}