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
bool sortbysecdesc(const pair<int,pair<int,int>> &a,
                   const pair<int,pair<int,int>> &b)
{
       return a.second<b.second;
}
 
 void solve(){
    int n; 
    cin>>n; 
    int arr[n]; 
    map<int,int>mapp; 
    for(int i = 0 ; i < n ; i ++ )
    {    
    cin>>arr[i]; 
    mapp[arr[i]]++; 
    }
    int squares = 0 ; 
    for(auto i : mapp){
        int c = i.second/4; 
        squares+=c; 
        mapp[i.first] = mapp[i.first] - c*4;  
    }
    int rect = 0 ; 
    for(auto i : mapp){
        if(i.second<4 && i.second>=2){
            int c = i.second/2; 
            rect+=1; 
            mapp[i.first] = mapp[i.first] - 2; 
        }
    }
    // cout<<squares<<" "<<rect;
    int remains = rect%2;
    rect = rect/2; 
    //  cout<<squares<<" "<<rect<<" "<<remains;
    int q; 
    cin>>q; 
    while(q--){
        char c ; 
        cin>>c; 
        if(c== '+'){
            int a; 
            cin>>a; 
            if(mapp[a]==0)
            {
            mapp[a]++; 
            if(squares>=2 ||(squares>=1 && rect>=1)){
                cout<<"YES"; 
            }
            else{
                cout<<"NO"; 
            }
            }
            else if(mapp[a] == 1){
                mapp[a]++; 
                remains++; 
                if(remains == 2){
                    remains = 0 ; 
                    rect++; 
                     if(squares>=2 ||(squares>=1 && rect>=1)){
                          cout<<"YES"; 
                           }
                        else
                        cout<<"NO"; 
                }
                else{
                     if(squares>=2 ||(squares>=1 && rect>=1)){
                          cout<<"YES"; 
                           }
                           else{
                               cout<<"NO"; 
                           }
                }
            }
            else if(mapp[a] == 2){
                    mapp[a]++; 
            if(squares>=2 ||(squares>=1 && rect>=1)){
                cout<<"YES"; 
            }
            else{
                cout<<"NO"; 
            }
            }
            else{
                mapp[a] = 0 ; 
                squares++; 
                  if(squares>=2 ||(squares>=1 && rect>=1)){
                cout<<"YES"; 
            }
            else{
                cout<<"NO"; 
            }
            }

        }
        else{
            int a; 
            cin>>a; 
            if(mapp[a] == 0){
                squares--; 
                remains++; 
                if(remains == 2){
                    remains = 0 ; 
                    rect++; 
                }
                mapp[a] = 3; 
            }
            else if(mapp[a] == 1)
            {
                mapp[a]-=1; 
            }
            else if(mapp[a] == 2){
                remains -- ; 
                
            }
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