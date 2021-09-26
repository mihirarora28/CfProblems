#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
// vector<int>Graph[2005]; 
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
bool sortbysecdesc(const pair<int,pair<int,int>> &a,
                   const pair<int,pair<int,int>> &b)
{
       return a.second<b.second;
}
ll dp[100005][4]; 
ll n; 
ll arr[100005];
ll brr[100005];  
ll rec(ll i, ll chose){
    if(i ==n){
        return 0; 
    }
    if(dp[i][chose] != -1){
        return dp[i][chose]; 
    }
    if(chose == 0){
       ll a =  rec(i+1,1) + arr[i]; 
       ll b = rec(i+1,2) + brr[i]; 
       ll c = rec(i+1,0); 
           dp[i][chose] = max(a,max(b,c)); 
       return max(a,max(b,c)); 
    }
   else if(chose == 1)
    {
    ll a = rec(i+1,2) + brr[i]; 
    ll b = rec(i+1,1); 
        dp[i][chose] =  max(a,b); 
    return max(a,b); 
    }
  else  if(chose == 2){
         ll a = rec(i+1,1) + arr[i]; 
       ll b = rec(i+1,2); 
           dp[i][chose]  = max(a,b);
       return max(a,b); 
    }

}
void solve(){
    // int n; 
    cin>>n; 
    memset(dp,-1,sizeof(dp)); 
    for(int i = 0 ; i  <n ; i++ )
    cin>>arr[i]; 
        for(int i = 0 ; i  <n ; i++ )
    cin>>brr[i]; 
    cout<<rec(0,0); 
}
 int main()
 {

     int t = 1; 
    //   scanf("%d",&t); 
        
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }