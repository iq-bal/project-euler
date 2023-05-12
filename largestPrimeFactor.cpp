#include <iostream>
#include <vector>
#include <cmath>

#define int long long int
using namespace std;

vector<int> prime(1e7 + 1, 0);
vector<int> p;

void sieve()
{
    for (int i = 2; i * i <= 1e7; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= 1e7; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= 1e7; i++)
    {
        if (prime[i] == 0)
            p.push_back(i);
    }
}

int32_t main()
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i = 0;
        int nn = n;
        int maxi = 1;
        while (p[i] <= sqrt(nn))
        {
            while (n % p[i]==0)
            {
                maxi = max(maxi , p[i]);
                n /= p[i];
                
            }
            
            i++; 
        }
        maxi = max(maxi , n);
        cout<< maxi << endl; 
    }
}