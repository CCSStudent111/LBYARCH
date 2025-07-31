#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern int accelerationcalculator(float vi, float vf, float time);

int main() {
	int rows;
	int i, accel, nums;
	float vi, vf, time, cputime;
	char line[100];
	int accelerations[100];
	LARGE_INTEGER frequency, start, end;
	double ns;

	QueryPerformanceFrequency(&frequency);

	// get inputs
	scanf_s(" %d", &rows);
	getchar(); //gets newline

	for (i = 0; i < rows; i++) {

		printf("Row %d: ", i + 1);
		nums = 0;
		
		fgets(line, sizeof(line), stdin);
		nums = sscanf_s(line, "%f, %f, %f\n", &vi, &vf, &time);

		QueryPerformanceCounter(&start);
		if (nums == 3) {
			
			for (int j = 0; j < 30; j++){
				accelerations[i] = accelerationcalculator(vi, vf, time);
			}
			
		}
		else {
			nums = 0;  // if fgets failed
			printf("Error reading line %d.", i + 1);
		}
		QueryPerformanceCounter(&end);
	}

	//print output
	for (i = 0; i < rows; i++) {
		printf("\n%d\n", accelerations[i]);
	}
	ns = (double)(end.QuadPart - start.QuadPart) * 1e9 / frequency.QuadPart;
	printf("\nTime: %.0f ns", ns);

	return 0;
}