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
int dp[100][100];
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
     ll a,b,c; 
     cin>>a>>b>>c; 
    ll sum = 0;
    ll a1 = a; 
   ll  b1 = b; 
  ll   c1 = c; 
     a1 = a1/3; 
     b1 = b1/2;
     c1=  c1/2; 
     sum+=min(a1,min(b1,c1))*7; 
     ll weeks = min(a1,min(b1,c1)); 
     a = a - weeks*3;  b = b - weeks*2;  c = c - weeks*2;
    //   sum+=min(a,min(b,c))*3;
    //monday; 
    ll ctr = 0 ;
    ll maxed = -1; 
    // cout<<a<<" "<<b<<" "<<c; 
    for(int  i = 0 ; i <= 6 ; i ++ )
    {
        ll ans = 0 ;
        ll ctr = i ; 
        ll a3 = a; 
        ll b3 = b; 
        ll c3 = c; 
     while(ans < 7){
         ctr =ctr % 7 ; 
         if(ctr == 1 || ctr == 4 || ctr == 0)
         {
             if(a3 == 0)
             break; 
         a3--;
         
         }
         else if(ctr == 2 || ctr == 6)
         {
              if(b3 == 0)
         break; 
         b3--;
        
         }
         else
         {
             if(c3 == 0)
             break; 
         c3--; 
         }

         ctr= ctr + 1; 
         ans ++ ; 
     }
    //  cout<<ans<<"\n"; 
     maxed = max(maxed,ans); 
    }
    cout<<sum + maxed; 
    // ll mini = min(a,min(b,c)); 
    // if(mini == 0){
    //     vector<int>v; 
    //     int ans = 0 ;
    //     v.push_back(a); 
    //       v.push_back(b); 
    //         v.push_back(c);
    //         for(auto i : v){
    //             if(i > 0)
    //             ans++; 
    //         }
    //         cout<<ans + sum;  
    //         return; 
    // }
    // if(mini == 1){
    //     a = a - 1; 
    //     b = b - 1; 
    //     c = c - 1;  
    //     vector<int>v; 
    //     int ans = 0 ;
    //     v.push_back(a); 
    //       v.push_back(b); 
    //         v.push_back(c);
    //         for(auto i : v){
    //             if(i > 0)
    //             ans++; 
    //         }
    //         cout<<ans + sum + 3;  
    //         return;
    // }
    // if(mini == 2){
    //     cout<<sum + 6; 
    //     return; 
    // }
    // //  cout<<sum; 

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