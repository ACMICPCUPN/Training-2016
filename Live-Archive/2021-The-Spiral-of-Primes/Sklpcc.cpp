/*
	Problem: 2021 - The Spiral of Primes
	Source: Live Archive
	Author: Sklpcc (Christian)
*/
#include<bits/stdc++.h>
using namespace std;

#define _FO
#define max(a,b) (((a)>(b))?(a):(b))
#define abs(a) (((a)>0)?(a):-(a))
#define endl "\n"

#ifdef _FO
#define fast_output()\
	ios_base::sync_with_stdio(false);\
	cin.tie(0)
#else
#define fast_output() do{}while(0)
#endif // _FO

#ifdef _DEB
#define debugComplete(os,var)\
	(os) << __FILE__ << "(" << __LINE__ << ") "\
	<< #var << " = [" << (var) << "]" << std::endl
#define debug(os,var)\
	(os) << __FILE__ << "(" << __LINE__ << ") "\
	<< #var << " = [" << (var) << "]" << std::endl
#else
#define debugComplete(os,var)\
	do{}while(0)
#define debug(os,var)\
	do{}while(0)
#endif // _DEB

#ifdef _FIL
#define _str2(a) #a
#define _str(a) _str2(a)
#define in(file,ext)\
	freopen(string(string("in_")+string(_str(file))+string(".")+string(_str(ext))).c_str(),"r",stdin)
#define out(file,ext)\
	freopen(string(string("out_")+string(_str(file))+string(".")+string(_str(ext))).c_str(),"w",stdin)
#define open(file,ext)\
	freopen(string(string("in_")+string(_str(file))+string(".")+string(_str(ext))).c_str(),"r",stdin)\
	freopen(string(string("out_")+string(_str(file))+string(".")+string(_str(ext))).c_str(),"w",stdin)
#else
#define in(file) do{}while(0)
#define out(file) do{}while(0)
#define open(file) do{}while(0)
#endif // _FIL

vector<int> primos;
bitset<10025> primes;

void sieve(int n)
{
	primes.set();
	primes[0] = primes[1] = false;
	for(int i = 2; i*i <= n; i++)
		if(primes[i])
			for(int j = i*2; j <= n; j += i)
				primes[j] = false;
	for(int i = 2; i <= n; i++)
		if(primes[i])
			primos.push_back(i);
}

int main()
{
	fast_output();
	sieve(10020);
	
	pair<int,int> obj;
	int caso = 1, anillo, lado, mitadLado;
	
	while(cin >> obj.first && obj.first!=-999)
	{
		cin >> obj.second;

		anillo = max(abs(obj.first), abs(obj.second));

		if(obj.first == anillo) lado = 0;
		else if(obj.first == -anillo) lado = 2;
		else if(obj.second == anillo) lado = 1;
		else if(obj.second == -anillo) lado = 3;

		mitadLado = (anillo)*((anillo+1)*4 - (7 - lado*2));

		if(lado == 0)
		{
			if(obj.second == -anillo) mitadLado = (anillo)*(anillo+1)<<2;
			else mitadLado += obj.second;
		}
		else if(lado == 1) mitadLado -= obj.first;
		else if(lado == 2) mitadLado -= obj.second;
		else if(lado == 3) mitadLado += obj.first;

		if(caso > 1) cout << endl;
		cout << "Case " << caso++ << ": The prime at location (" << obj.first << "," << obj.second << ") is " << primos[mitadLado] << "." << endl;
	}
	return 0;
}
