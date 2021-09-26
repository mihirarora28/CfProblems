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
     int n; 
     cin>>n; 
     int arr[n]; 
     for(int i = 0 ; i < n; i ++ )
     cin>>arr[i]; 
     for(int i = 0 ; i + 1 < n ; i ++ ){
         if(arr[i+1] + arr[i] == 5){
             cout<<"Infinite"; 
             return; 
         }
     }
     int sum = 0;
     cout<<"Finite\n"; 
     for(int i = 1 ; i <n ; i ++ ){
         if(n >= 3 && i < n -1  && arr[i-1] == 3 && arr[i] == 1 && arr[i+1] == 2){
             sum+=6; 
             i = i + 1; 
             continue;
         }
         if( (arr[i-1] == 2 && arr[i] == 1) ||( arr[i-1] == 1 && arr[i] == 2)){
             sum+=3; 
             continue; 
         }
          if( (arr[i-1] == 1 && arr[i] == 3) ||( arr[i-1] == 3 && arr[i] == 1)){
             sum+=4; 
             continue; 
             
         }
     }
     cout<<sum; 

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