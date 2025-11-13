#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	freopen("input.txt", "r", stdin);

	string input;
	regex pattern("mul\\((\\d+),(\\d+)\\)");
	int count = 0;
	
	while (getline(cin, input)) {
		/* part 1 solution
		for (sregex_iterator it = begin; it != end; it++) {
			smatch match = *it;
			count += stoi(match[1]) * stoi(match[2]);
		}
		*/

		int pos = 0;
		int latest = 0;
		vector<string> valid_segments;

		while ((pos = input.find("do()", pos + 1)) != string::npos) {
			valid_segments.push_back(input.substr(latest, pos - latest));
			latest = pos;
		} 
		valid_segments.push_back(input.substr(latest, input.size()));

		vector<string> trimmed_segments;
		for (string i: valid_segments) {
			int dont = i.find("don't()");

			if (dont == string::npos) {
				trimmed_segments.push_back(i);
				continue;
			}

			trimmed_segments.push_back(i.substr(0, dont - 7));
		}

		for (string i: trimmed_segments) {
			auto begin = sregex_iterator(i.begin(), i.end(), pattern);
			auto end = sregex_iterator();

			for (sregex_iterator it = begin; it != end; it++) {
				smatch match = *it;
				count += stoi(match[1]) * stoi(match[2]);
			}
		}
	}

	cout << count << endl;

	return 0;
}
