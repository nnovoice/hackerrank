#include <stdio.h>

const int MAX_NUMBERS = 100001;
int numbers[MAX_NUMBERS];
int positions[MAX_NUMBERS];

void PrintNumbers(int N)
{
	for (int i = 1; i <= N; ++i) {
		printf("%d ", numbers[i]);
	}
	printf("\n");
}

void RotateNumbers(int start, int end)
{
	int i = start, j = end, temp = 0;
	if (i > j) {
		temp = i;
		i = j;
		j = temp;
	}

	while (i < j) {
		temp = numbers[i];
		numbers[i] = numbers[j];
		positions[numbers[i]] = i;

		numbers[j] = temp;
		positions[numbers[j]] = j;

		++i;
		--j;
		//printf("D: i=%d,j=%d\n", i, j);
	}
}

void Init(int N)
{
	for (int i = 1; i <= N; ++i) {
		numbers[i] = positions[i] = i;
	}
}


int main()
{
	int N = 0, Q = 0;
	int cmdType = 0, start = 0, end = 0, pos = 0, elem = 0;
	scanf ("%d %d", &N, &Q);
	//printf("D: %d %d\n", N, Q);
	
	Init(N);

	for(int i = 0; i < Q; ++i) {
		scanf("%d", &cmdType);
		switch(cmdType) {
		case 1:
			scanf("%d %d", &start, &end);
			RotateNumbers(start, end);
			//PrintNumbers(N);
			break;
		case 2:
			scanf("%d", &elem);
			printf("element %d is at position %d\n", elem, positions[elem]);
			break;
		case 3:
			scanf("%d", &pos);
			printf("element at position %d is %d\n", pos, numbers[pos]);
			break;
		default:
			break;
		}
	}

	return 0;
}
