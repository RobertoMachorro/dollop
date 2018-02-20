/*
	Dollop - https://github.com/RobertoMachorro/dollop
	Roberto Machorro. Contact author via GitHub.

	Dollop is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Dollop is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <time.h>
#include "dollout.h"

void dollout_seed_random()
{
	time_t t;
	srand((unsigned)time(&t));
}

int dollout_random_outfile(FILE* outfile, long length)
{
	long i;

	for (i=0; i<length; i++) {
		char c = (rand()%94+32);
		fputc(c, outfile);
	}

	return 0;
}

int dollout_random_namedfile(const char* filename, long length)
{
	FILE* outfile = fopen(filename, "w");
	if (outfile == NULL) {
		fprintf(stderr, "Unable to create output file named %s.\n\n", filename);
		return 1;
	}

	int result = dollout_random_outfile(outfile, length);

	fclose(outfile);

	return result;
}
