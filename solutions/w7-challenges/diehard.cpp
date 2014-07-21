#include <stdio.h>

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int max_of(int a, int b) 
{
	return (a < b) ? b : a;
}

int main()
{
	int nCases = 0, a = 0, b = 0, c = 0, gcd_num = 0, max_of_inputs = 0;
	scanf ("%d", &nCases);
	//printf("D: %d\n", nCases);
	
	for(int i = 0; i < nCases; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		//printf("D: %d %d %d\n", a, b, c);
		max_of_inputs = max_of(a, b);
		gcd_num = gcd(a, b);
		//printf("D: GCD=%d\n", gcd_num);
		if (c <= max_of_inputs) {
			if (gcd_num == 1) {
				printf("YES\n");
			}
			else if ((c % gcd_num) == 0) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}