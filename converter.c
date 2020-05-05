/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{				

	for (unsigned i = 0; i < nlines; i++) { // goal: 0.2884

		unsigned line_len = (sizeof(lines[i])/2); // dividing by 2 works but not by sizeof(char)?
		unsigned exp = line_len-1; // exponent for base-ten int addition
		unsigned conversion = 0; // result
		for (unsigned j=0; j<line_len; j++){
			conversion = conversion + ((pow(10,exp)) * lines[i][j]);
			exp--;
		}
		printf("conversion %u\n",conversion);
		nums[i] = conversion;

	}

}
