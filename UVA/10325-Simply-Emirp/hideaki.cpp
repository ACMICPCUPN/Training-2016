#include <bits/stdc++.h>
using namespace std;

bool primes[1000000];

void toPrime(){
	for(int i=2;i<1000000;i++){
		if(primes[i] == true){
			for(int j=i*2;j<1000000;j+=i){
				primes[j] = false;
			}
		}
	}
}

int sti(string s){
	int r;
	stringstream c;
	c << s;
	c >> r;
	return r;
}

string its(int n){
	stringstream c;
	c << n;
	return c.str();
}

int main(int argc, char *argv[]) {
	for(int i=0;i<1000000;i++) primes[i] = true;
	toPrime();
	string num;
	while(cin>>num){
		int n = 0, m = 0;
		n = sti(num);
		reverse(num.begin(), num.end());
		m = sti(num);
		if(primes[m] && n!=m && primes[n]) cout<<n<<" is emirp.\n";
		else
		if(primes[n]) cout<<n<<" is prime.\n";
		else cout<<n<<" is not prime.\n";
	}
	return 0;
}
