/* CRC File Integrity Assessment Utility                               */
/* -Tests specific and commonly back-doored binaries for manipulation: */
/* Creates a database, at anytime you can create a new database and    */
/* run a grep comparison to see what binaries have changed.            */
/* CRC uses preexisting programs to perform the comparisons and        */
/* outputs changes, therefore cutting down on the size of the utility  */
/* Just gcc -o crc crc.c ; ./crc                                       */
/* (Just a simple example of checksums)                                */
/* Yeah...yeah....system commands in c again. deal!  ;) -TWG           */

#include<stdio.h>
#include<stdlib.h>

int main (void)
{
    int loop = 0;
    char num;

    printf ("\n]=A CRC File Integrity Assessment=[\n"
	    "For detecting back-doored binaries\n\n"
	    "1) Create A Clean Binary Database (1st time only)\n"
	    "2) Create New Database and Check File Integrity\n"
	    "3) Delete New Databse and DIFF File\n"
	    "4) Exit\n\n");

    while (!loop) {
	scanf ("%c", &num);

	switch (num) {
	case '1':
	    printf
		("Searching for clean binaries... (Do this ONLY the first time you run crc!)");
	    system ("cksum /bin/ls > crc.old"
	            "cksum /usr/bin/who >> crc.old"
	            "cksum /usr/bin/w >> crc.old"
	            "cksum /bin/ps >> crc.old"
	            "cksum /bin/rm >> crc.old"
	            "cksum /bin/rmdir >> crc.old"
	            "cksum /usr/local/sbin/sshd >> crc.old"
	            "cksum /usr/local/sbin/sshd2 >> crc.old"
	            "cksum /usr/sbin/in.telnetd >> crc.old"
	            "cksum /usr/sbin/wu.ftpd >> crc.old"
	            "cksum /usr/sbin/tcpd >> crc.old");
	    printf ("\nComplete! (Database: crc.old) !Save to floppy or somewhere safe!\n\n");
	    break;
	case '2':
	    printf ("One Moment Please...\n\n");
	    system ("cksum /bin/ls > crc.new"
	            "cksum /usr/bin/who >> crc.new"
	            "cksum /usr/bin/w >> crc.new"
	            "cksum /bin/ps >> crc.new"
	            "cksum /bin/rm >> crc.new"
	            "cksum /bin/rmdir >> crc.new"
	            "cksum /usr/local/sbin/sshd >> crc.new"
	            "cksum /usr/local/sbin/sshd2 >> crc.new"
	            "cksum /usr/sbin/in.telnetd >> crc.new"
	            "cksum /usr/sbin/wu.ftpd >> crc.new"
	            "cksum /usr/sbin/tcpd >> crc.new");
	    printf ("\nComplete! (Database: crc.new)\n\n");
	    printf ("Checking File Integrity...\n\n\n");
	    system ("grep -vf crc.old crc.new > crc.diff");
	    printf ("Suspicous Binary Changes (if any)");
	    system ("cat crc.diff");
	    printf ("\n\nDone!\n\n");
	    break;
	case '3':
	    system ("rm -f crc.new ; rm -f crc.diff");
	    printf ("Done!\n"); 
	    break;   
	case '4':
	    printf ("Later -TWG\n"
		    "Exiting....\n\n");
	    system ("rm -f crc.oldcksum ; rm -f crc.newcksum");
	    loop++;
	    break;
	default:
	    if ((num != '\n') && (num != '\r'))
		printf ("'%c' Not A Choice!\n", num);
	    break;
	}
    }

    return 0;
}
