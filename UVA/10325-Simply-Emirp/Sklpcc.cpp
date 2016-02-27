/*
	Problem: 10235 - Simply Emirp
	Source: UVa
	Author: Sklpcc (Christian)
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bitset<1000005> primes;

int _stoi(string s)
{
	stringstream c;
	int n;
	c << s;
	c >> n;
	return n;
}

void sieve(int tam){
	primes.set();
    primes[0] = primes[1] = false;
    for(int i = 2; i*i <= tam; ++i)
		if(primes[i])
			for(int h = 2; i*h <= tam; ++h)
				primes[i*h] = false;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	sieve(1000005);
	string s;
	int p1, p2;
	bool prime1, prime2;
	while(cin >> s)
	{
		prime1 = primes[p1 = _stoi(s)];
		if(!prime1)
			cout << p1 << " is not prime." << endl;
		else
		{
			reverse(s.begin(), s.end());
			prime2 = primes[p2 = _stoi(s)];
			if(!prime2 || p1 == p2) cout << p1 << " is prime." << endl;
			else cout << p1 << " is emirp." << endl;
		}
	}
	return 0;
}
