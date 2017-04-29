/* settag.c
	by R. Newman
	1/27/17
	allows shell command to change tag for Minix project 1 in COP4600
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define ARGCNT 3
#define HELPMSG "Usage: settag <PID> <new tag>\n"

int main(int argc, char** argv) {
    int PID, tag;
    int retval;

	// check and get command line arguments
	if (argc < ARGCNT) {
		printf("%s", "Missing PID or tag value\n");
		printf("%s", HELPMSG);
		return 0;
	}

	retval = sscanf(argv[1], "%d", &PID);
	if (retval != 1) {
		printf("%s", "Bad PID\n");
		printf("%s", HELPMSG);
		return 0;
	}

	retval = sscanf(argv[2], "%d", &tag);
	if (retval != 1) {
		printf("%s", "Bad tag\n");
		printf("%s", HELPMSG);
		return 0;
	}

	// advise on invalid tag
	if (tag < 0) {
		printf("%s", "Bad tag: must be non-negative\n");
	}

	// advise on non-root process
	retval = geteuid();
	if (retval != 0) {
		printf("%s", "Not root user\n");
	}

	// attempt call
	tag = set_tag(PID, tag);
	if (tag == -1) {
		printf("%s", "set_tag failed\n");
		printf("%s", HELPMSG);
		return 0;
	}

	// print result if success
	printf("%d\n", tag);
	return 0;
}
