#include <stdio.h>

int
main() {
	// 95 printable ASCII characters (from 0x20 to 0x7E)
	int freq[95];
	
	// Initialize array with 0s
	for (int i = 0; i < 95; i++)
		freq[i] = 0;

	// Buffer variable
	char c;

	do {
		c = getchar();
		// Limit within the specified range
		if (c >= 0x20 && c <= 0x7E)
			// Use received char as the index
			// 	and update its frequency
			freq[c-0x20]++;
	} while (c != EOF);

	for (int i = 0; i < 95; i++)
		// Don't print chars which didn't show up
		if (freq[i] != 0)
			// Add offset 0x20 to get the right char
			printf("%d\t%c\n", freq[i], i + 0x20);
}
