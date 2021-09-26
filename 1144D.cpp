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
    map<int,int>mapp; 
    for(int i = 0 ; i <n ; i  ++ ){
        cin>>arr[i]; 
        mapp[arr[i]]++; 
    }
    int maxed = -1; 
    int c1 = -1; 
    for(auto i :mapp){
        maxed = max(maxed, i.second); 

    }
    for(auto i : mapp){
        if(maxed == i.second){
            c1 = i.first; 
            break; 
        }
    }
    int c =  -1; 
    for(int i = 0 ;i < n ; i ++ ){
        if(arr[i] == c1){
            c = i; 
            break; 
        }
    }

    cout<<n  - maxed<<"\n"; 
    for(int i = c + 1 ; i < n ;i ++ ){
        if(arr[i]  == arr[c]){
            continue; 
        }
        if(arr[i] > arr[c]){
            cout<<2<<" "<<i+1<<" "<<i; 
               cout<<"\n"; 
        }
        else{
            cout<<1<<" "<<i+1<<" "<<i; 
               cout<<"\n"; 
        }
    }
    // cout<<c; 

       for(int i = c - 1 ; i >=0 ;i -- ){
        if(arr[i]  == arr[c]){
            continue; 
        }
        if(arr[i] > arr[c]){
            cout<<2<<" "<<i+1<<" "<<i+2; 
            cout<<"\n"; 
        }
        else{
            cout<<1<<" "<<i+1<<" "<<i+2; 
               cout<<"\n"; 
        }
    }
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