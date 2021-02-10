#include <stdio.h>
#include <string.h>

int
main(int argc, char* argv[]) {
	// Flag - show frequency relative to stream length
	int relative = 0;

	// Count characters inside stream
	int length = 0;

	// 95 printable ASCII characters (from 0x20 to 0x7E)
	int freq[95];

	// -r from command line enables relative mode
	if (argc == 2 && !strcmp("-r", argv[1]))
		relative = 1;

	// Initialize array with 0s
	for (int i = 0; i < 95; i++)
		freq[i] = 0;

	// Buffer variable
	short c;

	do {
		c = getchar();
		// Limit within the specified range
		if (c >= 0x20 && c <= 0x7E) {
			// Use received char as the index
			// 	and update its frequency
			freq[c-0x20]++;
			length++;
		}
	} while (c != EOF);

	for (int i = 0; i < 95; i++)
		// Don't print chars which didn't show up
		if (freq[i] != 0) {
			// Add offset to get the right char back with (index + 0x20)
			if (relative)
				printf("%f\t%c\n", (float) freq[i] / length, i + 0x20);
			else
				printf("%d\t%c\n", freq[i], i + 0x20);
		}
}
