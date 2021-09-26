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
 int main()
 {

      int t = 1; 
       scanf("%d",&t); 
        
         while(t--){
         
           string s; 
    cin>>s; 
    // scanf("%s",&s); 
    int len = s.length();  
    int zero = 0 ; 
    int ones = len ;
    if(len<=2){
        cout<<0<<"\n"; 
      continue;
    }
    int mini = 1e9; 
    ////////////////////////
    char t[104] ; 
       for(int j = 0 ; j < ones; j ++ )
     t[j] = '1'; 
     
     int f = -1; 
     int onespref = 0; 
     int zerospref = 0 ; 
     int onessuff = 0 ; 
     int zerossuff = 0; 
     for(int i = 0 ; i < len; i ++ )
     {
         if(s[i] == '1')
         onessuff++; 
         else
         zerossuff++; 
     }
     mini = min(onessuff,zerossuff); 
      
///////////////////////
    for(int i = 0 ;i < len; i ++ ){
        int ans = 0 ;
        int ans1 =0 ;
        if(s[i] == '1')
        {
        onessuff--; 
        onespref++;
        }
        else{
            zerossuff--; 
            zerospref++; 
        }
        zero++; 
        ones--; 
        mini = min(mini,onespref+zerossuff); 
        mini=min(mini,zerospref+onessuff); 
        // ones--; 
        // for(int  j = 0 ; j < len ; j ++ ){
        //     if(s[j]!=t[j]){
        //         ans++; 
        //     }
        //      char c = (t[j] == '1')?'0':'1'; 
        //     if(s[j]!= c){
        //         ans1++; 
        //     }
        // }
        // if(mini > ans)
        // mini = ans; 
        // ans = 0 ; 
        //  for(int  j = 0 ; j < len ; j ++ )
        //  {
            
        // }
        //    if(mini > ans1)
        // mini = ans1; 
    }
    cout<<mini; 
            cout<<"\n"; 
         }
 }