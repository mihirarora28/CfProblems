#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
bool visited[2005]; 
long long int mod = 1000000000000000000;
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
 
 void solve(){
      ll n; 
      cin>>n; 
    //   ll g = 1099511627777^3; 
    ll abc = 1; 

    int c = 55; 
    while(c--)
    abc = abc*2LL; 
    //   cout<<2*g<<"\n"; 
      ll arr[n]; 
      ll xor1 = 0; 
      for(int i = 0 ;i < n ; i ++ ) 
      {
      cin>>arr[i]; 
      xor1 = xor1 ^ arr[i]; 
      }
      
      ll sum = accumulate(arr,arr+n,0LL); 
        if( sum%2==0 && xor1%2==0 )
        {
              cout<<3<<"\n"; 
          xor1+=abc; 
          sum+=abc;
          cout<<abc<<' '; 
    //   }
    //   if(ans == false)
    //       cout<<2<<"\n"; 
      
      assert(sum%2 == xor1%2); 
  
      cout<<llabs(sum-2*xor1)/2<<" "<<llabs(sum-2*xor1)/2; 
        }
        else{
            sum+=abc+1; 
            xor1+=abc;
            xor1-=1; 
            cout<<"3\n"; 
            cout<<abc+1<<" "; 
             cout<<llabs(sum-2*xor1)/2<<" "<<llabs(sum-2*xor1)/2<<"\n"; 
            //  cout<<abs(sum-2*xor1) + sum<<' '<<2*xor1; 

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