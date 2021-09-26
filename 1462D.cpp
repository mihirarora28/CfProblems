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
//    int ans = n - 1; 
   ll sum = accumulate(arr,arr+n,0LL); 
   vector<int>ans1; 
   for(int i = 1; i <= sum/2; i ++ )
   {
       if(sum%i==0)
       ans1.push_back(i); 
   }
   int pref[n]; 
   int anss = 0 ;
   for(int  i = 0;  i < n; i ++ ){
       pref[i] = anss + arr[i]; 
       anss+= arr[i]; 
   }
   ll mini = n-1; 
   for(auto i : ans1){
    //    if(i == 6)
    //    {
        //     for(int j = 0;j<n;j++){
        //   cout<<pref[j]<<" "; 
         
    //    }
       int c = i; 
       int sum1 = 0 ;
       for(int j = 0;j<n;j++){
           if(pref[j]%i ==0)
           sum1+=1; 
       }
       if(sum/i == sum1){
           mini = min(mini,n - sum/i);  
       }
    //    }
   }
   cout<<mini; 

}

 int main()
 {   int t = 1; 
      scanf("%d",&t);    
    while(t--){
solve(); 
cout<<"\n"; 
 }
}