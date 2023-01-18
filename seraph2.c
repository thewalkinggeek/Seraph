/* Seraph File Administrative Utility written in my youth                                    */
/*                                                                                            */   
/* Seraph is an utility to detect uid bits, world writable files/directories,                 */
/* floating files, and places them in a txt database file for easy and *quick* viewing.       */
/* Now compares the original database with its current state and outputs changes that can     */
/* help you determine if you have been compromised.                                           */ 
/*                                                                                            */                                                                   */
/*                                                                                            */
/* system() not in .sh?: Yes, there is a reason why this is c code and not a shell script :)  */
/* I like the env and watching people rolling their eyes ;)  Take Care!                       */


#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int loop = 0;
    char answ;

    printf ("\nSeraph File Administration Utility v2 -by- TWG\n\n"
	    "1) Create a s[gu]id, word-writable, and floating databse\n"
	    "2) Create a current database and compare with the original\n"
	    "3) Exit\n");

    while (!loop) {
	scanf ("%c", &answ);

	switch (answ) {
	case '1':
	    printf ("Searching for s[gu]id root files...\n"),
		fflush (stdout);
	    system ("echo ]=S[gu]id root file=[ > db.orig");
	    system ("echo  >> db.orig");
	    system
		("find / -user root -perm -4000 -o -perm -2000 2>/dev/null 1>>db.orig");
	    system ("echo  >> db.orig");
	    system ("echo  >> db.orig");
	    printf ("Searching for world-writable files...\n"),
		fflush (stdout);
	    system ("echo ]=World writable files=[ >> db.orig");
	    system ("echo  >> db.orig");
	    system
		("find / -type f -perm -2 -o perm -20 2>/dev/null 1>>db.orig");
	    system ("echo  >> db.orig");
	    system ("echo  >> db.orig");
	    printf ("Searching for world-writable directories...\n"),
		fflush (stdout);
	    system ("echo ]=World writable directories=[ >> db.orig");
	    system ("echo  >> db.orig");
	    system
		("find / -type d -perm -2 -o perm -20 2>/dev/null 1>>db.orig");
	    system ("echo  >> db.orig");
	    system ("echo  >> db.orig");
	    printf ("Searching for floating/un-owned files...\n\n"),
		fflush (stdout);
	    system ("echo ]=Floating files=[ >> db.orig"
		    "echo  >> db.orig");
	    system ("find / -nouser -o -nogroup 2>/dev/null 1>>db.orig");
	    printf
		("Complete! (save db.orig somewhere save e.g. a floppy)\n");
	    break;

	case '2':
	    printf ("Searching for NEW s[gu]id root files...\n"),
		fflush (stdout);
	    system ("echo ]=S[gu]id root file=[ > db.current");
	    system ("echo  >> db.current");
	    system
		("find / -user root -perm -4000 -o -perm -2000 2>/dev/null 1>>db.current");
	    system ("echo  >> db.current");
	    system ("echo  >> db.current");
	    printf ("Searching for NEW world-writable files...\n"),
		fflush (stdout);
	    system ("echo ]=World writable files=[ >> db.current");
	    system ("echo  >> db.current");
	    system
		("find / -type f -perm -2 -o perm -20 2>/dev/null 1>>db.current");
	    system ("echo  >> db.current");
	    system ("echo  >> db.current");
	    printf ("Searching for NEW world-writable directories...\n"),
		fflush (stdout);
	    system ("echo ]=World writable directories=[ >> db.current");
	    system ("echo  >> db.current");
	    system
		("find / -type d -perm -2 -o perm -20 2>/dev/null 1>>db.current");
	    system ("echo  >> db.current");
	    system ("echo  >> db.current");
	    printf ("Searching for NEW floating/un-owned files...\n\n"),
		fflush (stdout);
	    system ("echo ]=Floating files=[ >> db.current");
	    system ("echo  >> db.current");
	    system
		("find / -nouser -o -nogroup 2>/dev/null 1>>db.current");
	    system ("echo **System File Changes** > db.diff");
	    system ("echo  >> db.diff");
	    system ("grep -vf db.orig db.current >> db.diff");
	    system ("cat db.diff");
	    printf ("\n\nComplete!\n");
	    break;
	case '3':
	    printf ("\n\n~Peace~\n"
		    "Smooth Exit...\n\n");
	    loop++;
	    break;
	default:
	    if ((answ != '\n') && (answ != '\r'))
		printf (" '%c' Invalid option!\n", answ);
	    break;
	}
    }

    return 0;
}

