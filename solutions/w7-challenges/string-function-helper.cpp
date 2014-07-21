#include <stdio.h>

#include <iostream>
#include <string>
#include <map>
using namespace std;

const int MAX_CHARS = 100001;
char input[MAX_CHARS];

int main()
{

	for (int i = 0; i < MAX_CHARS; ++i) {
		input[i] = 'a';
	}
	
	cout << input;

	return 0;
}
