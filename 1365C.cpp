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
    int brr[n];
    map<int,int>mapp2; 
    for(int i = 0 ;i < n ; i ++ ){
        cin>>arr[i]; 

    }
    for(int i = 0 ;i < n ; i ++ ){
        cin>>brr[i]; 
        mapp2[brr[i]] = i ; 

    }
    int f= 0 ;
    for(int i = 0 ; i < n ; i ++ ){
        if(arr[i]!=brr[i]){
            f=-1; 
           break; 
        }
    }
    if(f == 0){
        cout<<n; 
        return; 
    }
    over: 
    map<int,int>mapp; 
    vector<int>v; 
    vector<int>v2; 
    for(int i = 0 ;i  < n ; i ++ ){
        if(i > mapp2[arr[i]]){
        int c = n - 1 - i ; 
        mapp[ (mapp2[arr[i]]+1)%n + c]++; 
        }
        else{
            mapp[mapp2[arr[i]] - i] ++ ; 
        }
    }
    int maxed = -1; 
    for(auto i : mapp){
        if(i.second>maxed){
            maxed = i.second; 
        }
    }
    cout<<maxed;
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