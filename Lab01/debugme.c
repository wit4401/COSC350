/*
  debugme.c
  Programming for use in gdb tutorial
  Based on Little Unix Programmer's Group tutorial
  Thomas Anastasio
  October 17, 2002
*/

#include <stdio.h>

/* print a given string and a number in a pre-determined format. */
void 
print_string(int num, char* string)
{
    printf("String '%d' - '%s'\n", num, string);
}

int
main(int argc, char* argv[])
{
    int i;

    /* check that there's at least one command line argument */
    if (argc < 2)
      {
        printf("Usage: %s [<string> ...]\n", argv[0]);
	exit(1);
      }

    /* loop over each argv[i], print them one by one */
    for (i = 0; i < argc; i++)
      {
        print_string(i, argv[i]);
      }

    printf("Total number of command-line arguments: %d\n", argc - 1);
   
    return 0;
}
