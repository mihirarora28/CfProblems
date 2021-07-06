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
      int n; 
      cin>>n; 
      int arr[n+1]; 
      for(int i=1;i<=n;i++)
      cin>>arr[i]; 
      int dp[n+1]; 
      dp[0] = 0; 
      dp[1] = 1; 
      for(int i = 2; i <= n ;i ++){
            int maxed = 0;
            int cc = sqrt(i); 
          for(int j = 1 ; j <=cc; j ++){
            
              if(i%j==0){
                  if(i == 6){
                      cout<<j<<" "; 
                  }
                  if(arr[i]>arr[j]){
                     maxed = max(maxed,dp[j]) ; 
                  } 
                  if(arr[i]>arr[i/j]){
                     maxed = max(maxed,dp[i/j]) ; 
                  } 

              }
            
          }
           dp[i] = maxed + 1; 
      }
    //   for(int i = 1 ;i <=n;i++)
    //   {
    //       cout<<dp[i]<<" "; 
    //   }
       cout<<*max_element(dp,dp+1+n); 
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