/* increment.c
 *
 * usage:
 *    increment N file
 * open file on command line, read integer on last line, increment it, and
 * append that number to the file. It will do this the number of times N
 * given on the command line in the first argument.
 *
 * Does not like files that do not have numbers in them.
 *
 * Author: R. E. Newman, CISE Department, UF, Gainesville, FL 32611-6120
 * Created:
 * Modified:
 */

#include <stdio.h>
#define debug 0
#define USAGE "usage: increment N file"

int main(int argc, char *argv[])
{
int N;
int rv, i;
FILE *f;

	if (argc < 3) {
		(void) printf("\n%s\n",USAGE);
		(void) printf("N is number of iterations\n");
		(void) printf("file is name of file with numbers\n");
		return 1;
		}
	if (debug) (void) printf("...looking for N\n");
		/* get base from command line */
	if (sscanf(argv[1],"%d",&N) != 1)
		{
		(void) printf("sscanf failed on number of iterations\n");
		return 1;
		}
	if (debug) (void) printf("N is %d\n",N);
	if (N<=0)
		{
		(void) printf("bad N: %s\n", argv[1]);
		return 1;
		}

	if (debug) (void) printf("...looking for filename\n");
		/* get filename from command line */

	if (debug) (void) printf("filename is %s\n",argv[2]);
	while (N>0)
	{
	    if (NULL==(f = fopen(argv[2],"r+")))
		  {
				(void) printf("bad filename: %s\n", argv[2]);
				return 1;
			}
	    if (debug) printf("...working on iteration %d\n",N);
	    while ( (rv = fscanf(f,"%d",&i)) != EOF)
			{
				if (debug) printf("%d\n",i);
				if (rv == 0)
		    {
		    	fprintf(stderr,"File contains non-number\n");
		    	return 1;
		    }
		  }
	    if (debug) printf("Last value of i is %d\n",i);
	    ++i;
	    if (debug) printf("Increment i to be %d\n",i);
	    fprintf(f,"%d\n",i);
	    --N;
	    fclose(f);
   }

	(void) printf("\n");
	return 0;

}
