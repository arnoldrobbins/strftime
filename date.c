/*
 * date.c
 *
 * Public domain implementation of POSIX 1003.1
 * date command.  Lets strftime() do the dirty work.
 *
 * Initial version.
 * April, 1991
 *
 * Bug fix courtesy of Chris Ritson (C.R.Ritson@newcastle.ac.uk).
 * February, 1994.
 *
 * Add more header files, use ANSI prototype.
 * January, 2011.
 *
 * Arnold Robbins
 * arnold@skeeve.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

extern size_t strftime();
extern int getopt();
extern int optind;

int main(int argc, char **argv)
{
	time_t clock;
	struct tm *now;
	int c, size, ret;
	char *defhow = "%a %b %e %H:%M:%S %Z %Y";
	char *howto = defhow;
	char *buf;

	while ((c = getopt(argc, argv, "u")) != -1) {
		switch (c) {
		case 'u':
			putenv("TZ=GMT0");
			break;
		default:
			fprintf(stderr, "usage: %s [-u] [+format_str]\n",
				argv[0]);
			exit(1);
		}
	}

	time(& clock);
	now = localtime(& clock);

	if (optind < argc && argv[optind][0] == '+')
		howto = & argv[optind][1];

	size = strlen(howto) * 10;
	if (size < 26)
		size = 26;
	if ((buf = malloc(size)) == NULL) {
		perror("not enough memory");
		exit(1);
	}

	ret = strftime(buf, size, howto, now);
	if (ret != 0)
		printf("%s\n", buf);
	else {
		fprintf(stderr, "conversion failed\n");
		exit(1);
	}
	
	exit(0);
}
