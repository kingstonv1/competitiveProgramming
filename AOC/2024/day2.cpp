#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	

	string curin;
	vector<vector<int>> reports;

	while (getline(cin, curin)) {
		stringstream ss(curin);
		vector<int> report; string n;
		while (getline(ss, n, ' ')) report.push_back(stoi(n));
		reports.push_back(report);
	}

	int count = 0;

	for (vector<int> report: reports) {
		bool safe = true;
		bool sign = report[1] - report[0] > 0;

		for (int i = 1; i < report.size(); i++) {
			if (report[i] - report[i - 1] > 0 != sign) {
				safe = false; break;
			}

			int diff = abs(report[i] - report[i - 1]);

			if (diff > 3 || diff < 1) {
				safe = false; break;
			}
		}
		
		if (safe) count++;
	}

	int dcount = 0;

	for (vector<int> report: reports) {
		bool safe = true; bool damp = false;
		bool sign = report[1] - report[0] > 0;

		for (int i = 1; i < report.size(); i++) {
			if (report[i] - report[i - 1] > 0 != sign) {
					if (damp) {
					safe = false; break;
				} else {
					damp = true;
					report[i] = report[i - 1];
					continue;
				}
		}

			int diff = abs(report[i] - report[i - 1]);

			if (diff > 3 || diff < 1) {
				if (damp) {
					safe = false; break;
				} else {
					damp = true;
					report[i] = report[i - 1];
					continue;
				}
			}
		}
		
		if (safe) dcount++;
	}

	cout << dcount << '\n';

	return 0;
}


