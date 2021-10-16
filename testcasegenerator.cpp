#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int getRandom(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
vector<vector<int>> q;
void func() {
	vector<int> v;
	for (int i = 0 ; i < 10 ; i++) {
		int n = getRandom(50 , 10000);
		int count = 0;
		v.reserve(n);
		int m = n;
		while (count < 50) {
			v.push_back(m);
			m++;
			count++;
		}
	}
	int j = 0;
	for (int i = 0 ; i < 500 ; i++) {
		q.push_back({1 , v[j]});
		j++;
	}
	j = 0;
	for (int i = 0 ; i < 500 ; i++) {
		q.push_back({1 , v[j]});
		j++;
	}

	auto engine = std::default_random_engine{};
	std::shuffle(std::begin(q), std::end(q), engine);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/Vishal modani/OneDrive/Desktop/c++/input.txt", "r", stdin);
	freopen("C:/Users/Vishal modani/OneDrive/Desktop/c++/Rank Of The Matrix/testcases/large/in/input10.txt", "w", stdout);
#endif
	int t = 1;
	//func();
	cout << t << endl;
	while (t--) {
		int n = getRandom(30 , 50);
		n = 200;
		int m = getRandom(500 , 1000);
		//m = 150;
		cout << n << " " << m << endl;

		for (int i = 0 ; i < n ; i++) {
		    int a = getRandom(0 , 9);
		    cout<<a;
		}
	}
	return 0;
}