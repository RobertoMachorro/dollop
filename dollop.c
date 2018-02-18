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
#include "argtable3.h"

struct arg_lit *help, *version, *verbose;
struct arg_int *length;
struct arg_file *file;
struct arg_end *end;

int main(int argc, char *argv[])
{
	void *argtable[] = {
		help = arg_litn(NULL, "help", 0, 1, "display this help and exit"),
		version = arg_litn(NULL, "version", 0, 1, "display version info and exit"),
		verbose = arg_litn(NULL, "verbose", 0, 1, "verbose output"),
		length = arg_intn("l", "length", "<n>", 0, 1, "final file length in bytes, default 1k"),
		file = arg_filen(NULL, NULL, "<file>", 0, 1, "output file, defaults to console"),
		end = arg_end(20),
	};

	int exitcode = 0;
	char progname[] = "dollop";
	char progdesc[] = "Creates files with pseudo-random content (dollop).";

	int nerrors = arg_parse(argc,argv,argtable);

	if (help->count > 0)
	{
		printf("Usage: %s", progname);
		arg_print_syntax(stdout, argtable, "\n");
		printf("%s\n\n", progdesc);
		arg_print_glossary(stdout, argtable, "  %-25s %s\n");
		exitcode = 0;
	}
	else if (version->count > 0)
	{
		printf("Dollop v%1.1f\n", 1.0);
		printf("%s\n", progdesc);
		printf("Copyright (c) 2018 Roberto Machorro\n");
		exitcode = 0;
	}
	else if (nerrors > 0)
	{
		arg_print_errors(stderr, end, progname);
		fprintf(stderr, "Try '%s --help' for more information.\n", progname);
		exitcode = 1;
	}
	else
	{
		FILE *out = stdout;

		if (file->count > 0) {
			out = fopen(file->filename[0], "w");
			if (out == NULL) {
				fprintf(stderr, "Unable to create output file named %s.\n\n", file->filename[0]);
				exitcode = 1;
			}
		}

		if (exitcode == 0) {
			time_t t;
			long i, bytes = (length->count > 0)? *length->ival : 1024;

			srand((unsigned) time(&t));
			for (i=0; i<bytes; i++) {
				char c = (rand()%94+32);
				fputc(c, out);
			}

			if (file->count > 0) {
				fclose(out);
			}
		}
	}

	arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
	return exitcode;
}
