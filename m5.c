/* M5 File Integrity Assessment Utility                                */
/* -Tests specific and commonly back-doored binaries for manipulation: */
/* Creates a database, at anytime you can create a new database and    */
/* run a grep comparison to see what binaries have changed.            */
/* M5 uses preexisting programs to perform the comparisons and         */
/* outputs changes, therefore cutting down on the size of the utility  */
/* Just gcc -o m5 m5.c ; ./m5                                          */
/* (An example of md5 checksums -by- TWG                               */
/* Yeah...yeah....system commands in c again. deal!  ;)                */

#include<stdio.h>
#include<stdlib.h>

int main (void)
{
    int loop = 0;
    char num;

    printf ("\n]=A MD5 File Integrity Assessment=[\n"
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
		("Searching for clean binaries... (Do this ONLY the first time you run m5!)");
	    system ("md5sum /bin/ls > m5.old"
	            "md5sum /usr/bin/who >> m5.old"
	            "md5sum /usr/bin/w >> m5.old"
	            "md5sum /bin/ps >> m5.old"
	            "md5sum /bin/rm >> m5.old"
	            "md5sum /bin/rmdir >> m5.old"
		    "md5sum /bin/login >> m5.old"
	            "md5sum /usr/local/sbin/sshd >> m5.old"
	            "md5sum /usr/local/sbin/sshd2 >> m5.old"
	            "md5sum /usr/sbin/in.telnetd >> m5.old"
	            "md5sum /usr/sbin/wu.ftpd >> m5.old"
	            "md5sum /usr/sbin/tcpd >> m5.old");
	    printf ("\nComplete! (Database: m5.old) !Save to floppy or somewhere safe!\n\n");
	    break;
	case '2':
	    printf ("One Moment Please...\n\n");
	    system ("md5sum /bin/ls > m5.new"
	            "md5sum /usr/bin/who >> m5.new"
	            "md5sum /usr/bin/w >> m5.new"
	            "md5sum /bin/ps >> m5.new"
	            "md5sum /bin/rm >> m5.new"
	            "md5sum /bin/rmdir >> m5.new"
		    "md5sum /bin/login >> m5.new"
	            "md5sum /usr/local/sbin/sshd >> m5.new"
	            "md5sum /usr/local/sbin/sshd2 >> m5.new"
	            "md5sum /usr/sbin/in.telnetd >> m5.new"
	            "md5sum /usr/sbin/wu.ftpd >> m5.new"
	            "md5sum /usr/sbin/tcpd >> m5.new");
	    printf ("\nComplete! (Database: m5.new)\n\n");
	    printf ("Checking File Integrity...\n\n\n");
	    system ("grep -vf m5.old m5.new > m5.diff");
	    printf ("Suspicous Binary Changes (if any)");
	    system ("cat m5.diff");
	    printf ("\n\nDone!\n\n");
	    break;
	case '3':
	    system ("rm -f m5.new ; rm -f m5.diff");
	    printf ("Done!\n"); 
	    break;   
	case '4':
	    printf ("Later -TWG\n"
		    "Exiting....\n\n");
	    system ("rm -f m5.oldmd5sum ; rm -f m5.newmd5sum");
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
