#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	

	vector<int> l1;
	vector<int> l2;
	int t1; int t2;
	while (cin >> t1 >> t2) {
		l1.push_back(t1);
		l2.push_back(t2);
	}

	sort(l1.begin(), l1.end());
	sort(l2.begin(), l2.end());

	int total = 0;

	for (int i = 0; i < l1.size(); i++) {
		total += abs(l1[i] - l2[i]);
	}

	int similarity = 0;

	for (int i = 0; i < l1.size(); i++) {
		similarity += l1[i] * count(l2.begin(), l2.end(), l1[i]);
	}

	cout << similarity;

	return 0;
}
