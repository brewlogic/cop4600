/* consecutive.c
 *
 *  George Brewster COP 4600 EX3 Race Conditions
 *  Demonstrates race condition
 *
 *  Instructions:
 *  Write a program "consecutive" that reads a file of
    numbers, one per line, then outputs two adjacent lines
    for which the number in the second line is not exactly
    one greater than the number in the first line.  It
    shall output the line numbers of each line before that
    line in a field at least five characters wide with leading
    spaces, followed by a colon and a space before printing
    the contents of the line. It shall read from standard in
    and write to standard out.
 *
 */

#include <stdio.h>
#define debug 0
#define USAGE "usage: find when two consecutive lines of numbers do not increment by only one"

int main(int argc, char *argv[])
{
//int N;
int rv, i, prev;
int line = 0;
FILE *f;

while ((rv = fscanf(f,"%d",&i)) != EOF){
  if(prev + 1 == i){
    // do nothing if increments by only one
  }else{
    printf("\t%d : %d", line, i);
  }
  prev = i;
  ++line;
}
	return 0;

}
