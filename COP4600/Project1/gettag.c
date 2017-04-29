/* gettag.c
	by R. Newman
	1/27/17
	allows shell command to read tag for Minix project 1 in COP4600
 */

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define ARGCNT 2
#define HELPMSG "Usage: gettag <PID>\n"

int main(int argc, char** argv) {
    int PID, tag;
    int retval;

	// check and get command line arguments
	if (argc < ARGCNT) {
		printf("%s", "No PID\n");
		printf("%s", HELPMSG);
		return 0;
	}

	retval = sscanf(argv[1], "%d", &PID);
	if (retval != 1) {
		printf("%s", "Bad PID\n");
		printf("%s", HELPMSG);
		return 0;
	}

	// attempt call
	tag = get_tag(PID);
	if (tag == -1) {
		printf("%s", "get_tag failed\n");
		printf("%s", HELPMSG);
		return 0;
	}

	// print result if success
	printf("%d\n", tag);
	return 0;
}

