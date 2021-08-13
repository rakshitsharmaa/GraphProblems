#include<iostream>
using namespace std;
#include<vector>
void solve(){
    long long m,n;
    cin>>m>>n;
    vector<int> is_prime(n+1,1);
    is_prime[0]=is_prime[1]=0;
    for (int i = 0; i*i <= n; i++)
    {
        if(is_prime[i]){
            for (int j = 2*i; j <= n; j+=i)
            {
                is_prime[j]=0;
            }
            
        }
        
    }
    for (int i = m; i <= n; i++)
    {
        if (is_prime[i])
        {
            cout<<i<<endl;
        }
        
    }
    cout<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
}