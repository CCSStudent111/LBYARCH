#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern int accelerationcalculator(float vi, float vf, float time);

int main() {
	int rows;
	int i, j, accel, nums;
	float vi, vf, time;
	char line[1000];
	int accelerations[10000];

	LARGE_INTEGER frequency, start, end;
	double elapsed, avg_time;
	double exec_times[30]; // to store execution times

	QueryPerformanceFrequency(&frequency);

	// get inputs
	scanf_s(" %d", &rows);
	getchar(); // gets newline

	for (i = 0; i < rows; i++) {

		nums = 0;

		fgets(line, sizeof(line), stdin);
		nums = sscanf_s(line, "%f, %f, %f", &vi, &vf, &time);

		if (nums == 3) {
			avg_time = 0.0;
			for (j = 0; j < 30; j++) { // 30 trials
				QueryPerformanceCounter(&start);

				accelerations[i] = accelerationcalculator(vi, vf, time);

				QueryPerformanceCounter(&end);
				elapsed = (double)(end.QuadPart - start.QuadPart) * 1e9 / frequency.QuadPart;
				exec_times[j] = elapsed;
				avg_time += elapsed;
			}
		}
		else {
			printf("Error reading line %d.\n", i + 1);
		}

	}

	// print results
	for (i = 0; i < rows; i++) {
		printf("\n%d\n", accelerations[i]);
	}

	avg_time /= 30.0;

	printf("\nAverage Execution Time for all 30 trials: %.0f ns\n", avg_time);

	return 0;
}
