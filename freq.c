#include <stdio.h>
#define RANGE 95

int
main() {
	char c;
	int freq[RANGE];
	
	for(int i = 0; i < RANGE; i++)
		freq[i] = 0;

	do {
		c = getchar();
		if (c >= 0x20 && c <= 0x7F)
			freq[c-0x20]++;
	} while(c != EOF);

	for (int i = 0; i < RANGE; i++)
		if (freq[i] != 0)
			printf("%d\t%c\n", freq[i], i + 0x20);
}
