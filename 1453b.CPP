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
    for(int i = 0 ; i< n ; i ++){
        cin>>arr[i]; 
    }
    ll ans = 0 ; 
    for(int i  =0 ; i+1 < n; i ++ ){
        ans+= abs(arr[i] - arr[i+1]); 
    }
     ll mini = 1e18;  
     mini = min(mini,ans); 
     mini = min(mini,ans-abs(arr[0] - arr[1])); 
     mini = min(mini,ans-abs(arr[n-1] - arr[n-2]));
     for(int i = 1;i<n-1;i++){
         ll c = abs(arr[i] - arr[i-1]); 
         ll c1 = abs(arr[i+1] - arr[i]); 
         ll s = c + c1; 
         ll ss = ans - s;
         ss+= abs(arr[i+1]-arr[i-1]);
        //  ans-=s; 
        //  ans+=abs(arr[i+1]-arr[i-1]);
         mini=min(mini,ss); 
     } 
     cout<<mini; 
    // for(int i = 0 ; i+1 < n ; i ++ ){
    //     mini = max(mini,abs(arr[i] - arr[i+1]));
    // }
    // cout<<ans - mini; 

}

 int main()
 {   int t = 1; 
      scanf("%d",&t);    
    while(t--){
solve(); 
cout<<"\n"; 
 }
}