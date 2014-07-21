#include <stdio.h>

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> substringsMap;

int main()
{
	int len = 0, max_fn_val = 0, cur_fn_val = 0;
	string input;

	cin >> input;

	len = input.length();

	string s = "";
	
	for(int i = 0; i < len; ++i) {
		s = "";
		s += input[i];
		//substringsMap[s] += 1;

		for (int j = i + 1; j < len; ++j) {
			s += input[j];
			cout << "Debug: " << "adding: " << s << " to the map.\n";
			substringsMap[s] += 1;
		}
	}

	max_fn_val = len;

	map<string, int>::iterator iter = substringsMap.begin();
	map<string, int>::iterator end_iter = substringsMap.end();
	int count = 0;
	for( ; iter != end_iter; ++iter) {
		cur_fn_val = iter->first.length() * iter->second;
		cout << "Debug: " << "Count= " << ++count << " "<< cur_fn_val << " "<< iter->first.length() << " "<< iter->first << " " << iter->second << endl;
		if (cur_fn_val > max_fn_val)
			max_fn_val = cur_fn_val;
	}

	cout << max_fn_val;

	return 0;
}
