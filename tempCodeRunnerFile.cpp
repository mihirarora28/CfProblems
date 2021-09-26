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
     int arr[n]; 
     int odd = 0 ; 
     int even =  0; 
     vector<int>evens; 
     vector<int>odds; 
     for(int i = 0; i < n ; i ++ )
     {
     cin>>arr[i]; 
     if(arr[i]%2==0)
     {
     even++; 
     evens.push_back(arr[i]);
     }
     else
     {
     odd++; 
     odds.push_back(arr[i]);
     }
     }
     int l = 0 ;
     if(n%2==0){
         if(even == odd){
             for(int i = 0; i  < even ; i ++ ){
                 cout<<evens[i]<<" "; 
                 cout<<odds[i]<<" "; 
             }
         }
         else{
             cout<<-1; 
             return; 
         }
     }
     else{
         if(even == n/2 || odd == n/2){
             if(even == n/2){
                 cout<<odds[0]<<" ";
                 for(int i = 1; i < odd; i ++ ){
                     cout<<evens[i-1]<<" ";
                     cout<<odds[i]<<" "; 
                 }
             }
             else{
                   cout<<evens[0]<<" ";
                 for(int i = 1; i < even; i ++ ){
                     cout<<odds[i-1]<<" ";
                     cout<<evens[i]<<" "; 
                 }
             }
         }
         else{
             cout<<"-1"; 
         }
     }

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