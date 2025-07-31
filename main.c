#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern int accelerationcalculator(float vi, float vf, float time);

int main() {
	int rows;
	int i, accel, nums;
	float vi, vf, time;
	char line[100];
	int accelerations[100];

	// get inputs
	scanf_s(" %d", &rows);
	getchar(); //gets newline

	for (i = 0; i < rows; i++) {

		//printf("Row %d: ", i + 1);
		nums = 0;
		
		fgets(line, sizeof(line), stdin);
		nums = sscanf_s(line, "%f, %f, %f\n", &vi, &vf, &time);

		if (nums == 3) {
			accelerations[i] = accelerationcalculator(vi, vf, time);
		
		}
		else {
			nums = 0;  // if fgets failed
			printf("Error reading line %d.", i + 1);
		}
		
	}

	//print output
	for (i = 0; i < rows; i++) {
		printf("\n%d\n", accelerations[i]);
	}

	return 0;
}