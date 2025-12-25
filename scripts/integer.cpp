#include <iostream> 
#include <cmath> 
#include <vector> 
#include <queue> 
#include <string> 
#include <sstream> 
#include <algorithm>  
#include <limits>  
#include <climits>  
#include <tuple>  
#include <set>  

#define M_PI 3.14159265358979323846

using namespace std;
using ll = long long;

unsigned getDigit(unsigned num) {
	return to_string(num).length();
}

bool isPrime(ll n) {
	if (n == 1) return false;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

vector<ll> enumDivisors(ll n) {
	vector<ll> result;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			result.push_back(i);
			if (n / i != i) result.push_back(n / i);
		}
	}
	// 必要ならソート
	sort(result.begin(), result.end());
	return result;
}

vector<pair<ll, ll>> primeFactorize(ll n) {
	vector<pair<ll, ll>> result;

	for (ll i = 2; i * i < n; i++) {
		if (n % i != 0) continue;

		ll exp = 0;
		while (n % i == 0) {
			n %= i;
			exp++;
		}

		result.push_back({ i, exp });
	}

	if (n > 1) result.push_back({ n, 1 });
	return result;
}