#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001
vector<ll> isPrime(100001);
vector<ll> primes;
ll MOD =pow(10,9) + 7;
void seive() {
	for (ll i = 2; i*i < 100001; i++)
	{
		if (isPrime[i] == 0) {
			for (ll j = i * i; j < MAX; j += i)
			{
				isPrime[j] = 1;
			}
		}
	}
	primes.push_back(2);
	for (ll i = 3; i < MAX; i+=2)
	{
		if (isPrime[i] == 0)
			primes.push_back(i);
	}
}
void segmentSeive(ll l, ll r)
{
	vector<ll> ans(r - l + 1);
	for (ll i = 0; primes[i] * primes[i] <= r; i++)
	{
		ll index = (l / primes[i])*primes[i];
		if (index < l)
			index += primes[i];
		for (ll j = index; j <= r; j += primes[i])
			ans[j - l] = 1;
		if (index == primes[i])
			ans[index - l] = 0;
	}
	//ll res = 1;
	for (ll i = l; i <= r; i++)
	{
		if (ans[i - l] == 0)
		{
			cout << i << ' ';
		}
	}
	cout << endl;
}
int main()
{
	seive();
	ll t;
	cin >> t;
	while (t--)
	{
		ll l, r;
		cin >> l >> r;
		segmentSeive(l, r);
	}
}
