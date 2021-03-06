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
#include "dollout.h"

struct arg_lit *help, *version;
struct arg_str *length;
struct arg_int *bufsize;
struct arg_file *file;
struct arg_end *end;

int main(int argc, char *argv[])
{
	void *argtable[] = {
		help = arg_litn("h", "help", 0, 1, "display this help and exit"),
		version = arg_litn("V", "version", 0, 1, "display version info and exit"),
		length = arg_strn("l", "length", "STRING", 0, 1, "final file length in bytes, default 1k"),
		bufsize = arg_intn("b", "buffer-size", "<n>", 0, 1, "write buffer size in bytes, default 4k"),
		file = arg_filen("o", "output", "<file>", 0, 1, "output file, defaults to console"),
		end = arg_end(20),
	};

	int exitcode = 0;
	char progname[] = "dollop";

	int nerrors = arg_parse(argc,argv,argtable);

	if (help->count > 0)
	{
		printf("Usage: %s", progname);
		arg_print_syntax(stdout, argtable, "\n\n");
		printf("Creates files with pseudo-random content (dollop). Generated content\nis sent to standard output, unless an output file is given.\nInvalid lengths will be treated as 0.\n\n");
		arg_print_glossary(stdout, argtable, "  %-25s %s\n");
		printf("\nReport bugs to <https://github.com/RobertoMachorro/dollop/issues>.\nDollop home page: <https://robertomachorro.github.io/dollop/>.\n");
		exitcode = 0;
	}
	else if (version->count > 0)
	{
		printf("Dollop %s\nCopyright (C) 2018 Roberto Machorro.\nLicense GPLv3+/Dollop: GNU GPL version 3 or later\n<http://gnu.org/licenses/gpl.html>, <http://gnu.org/licenses/exceptions.html>\nThis is free software: you are free to change and redistribute it.\nThere is NO WARRANTY, to the extent permitted by law.\n\nWritten by Roberto Machorro.\n", VERSION);
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
		long bytes = 1024;
		int buffersize = 4096;

		if (length->count > 0) {
			char *eptr;
			bytes = strtol(length->sval[0], &eptr, 10);
		}
		if (bufsize->count > 0) {
			buffersize = bufsize->ival[0];
		}

		dollout_seed_random();
		if (file->count > 0) {
			exitcode = dollout_random_namedfile(file->filename[0], bytes, buffersize);
		} else {
			exitcode = dollout_random_outfile(stdout, bytes, buffersize);
		}
	}

	arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
	return exitcode;
}
