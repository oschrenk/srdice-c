#include <stdio.h>

const int NUMBER_OF_SIDES =	6;
const int REROLL_AT = 6;

int main (int argc , char *argv [])
{
	int dice;
	int target;
	
	if (argc < 2) { //program name is argv[0]
		printf ("usage: srdice #dice [#target] eg. srdice 6 or srdice 6 5\n");
		return 1;
	}
	
	// number of dice needed for all tests
	// open and success test
	if (argc >= 2) {
		dice = atoi(argv[1]);
		if (dice <= 0) {
			printf ("You have to roll at least one dice.\n");
			printf ("usage: srdice #dice [#target] eg. srdice 6 or srdice 6 5\n");
			return 1;
		}
	}
	
	// target number needed for success test
	if (argc == 3) {
		target = atoi(argv[2]);
		
		// if we have target needs to be 2
		if (target <= 1) {
			printf ("Target number has to be at least two.\n");
			return 1;
		}
	}

	// initialize randomizer
	srandom(time(NULL));

	// roll the cup	
	int cup[dice];
	int i;
	for(i = 0; i < dice; i++) {
		cup[i] = reroll(NUMBER_OF_SIDES);	
	}

	// sort the cup
	bubblesort(cup, dice);

	// count successes, max, sum, fail
	int t;
	int succ;
	int sum = 0;
	int max = 0;
	for(i = 0; i < dice - 1 ; i++) {
		t = cup[i];
		printf ("%d, ", t );
		if (t >= target)
			succ++;
		sum += t;
		if (t > max) {
			max = t;
		}		
	}
	// last dice is special case
	t = cup[dice-1];
	printf ("%d\n", t );
	if (t >= target)
		succ++;
	sum += t;
	if (t > max) {
		max = t;
	}
	
	// all dice show 1
	if (sum == dice)
		printf ("FAIL\n");
		
	// print results
	if (argc == 3)
		printf ("Successes: %d\n", succ);
	
	printf ("Max: %d\n", max);
	printf ("Sum: %d\n", sum);

	return 0;
}

int reroll (int rerollAt ) {
	int r = (random() % NUMBER_OF_SIDES) + 1;
	if (r == rerollAt) {
		return reroll (rerollAt) + rerollAt;
	}
	
	return r; 
}

bubblesort (int *a, int length) {
	int o;
	int i;
	int t;
	for (o = length - 1; o > 1; o--) {
		for(i = 0; i < o  ; i++) {
			if (a[i] > a[i+1]) {
				t = a[i];
				a[i] = a[i+1];
				a[i+1] = t;
			}
		}
	}
	
}