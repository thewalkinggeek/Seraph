/*Seraph Administrative Utility written in my youth.
*
*Seraph is an utility to detect uid bits, world writable files/directories,
*floating files, and place them in log files for easy and *quick* viewing,
*
* -Hark
*
*/

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
  int loop = 0;
  char answ;

        printf("\nSeraph Administration Utility\n\n"
               "1) local s[gu]id root file check\n"
               "2) local world-writable directoy check\n"
               "3) local world-writable file check\n"
               "4) local floating (unknown) file check\n"
               "5) Exit\n");

        while(!loop) {
                scanf("%c", &answ);

                switch(answ) {
                        case '1':
                                printf("Searching for s[gu]id root files..."), fflush(stdout);
                                system("find / -user root -perm -4000 2>/dev/null 1>sguid.log");
                                printf("Done!\n");
                                break;
                        case '2':
                                printf("Searching for world-writeable directories..."), fflush(stdout);
                                system("find / -type d -perm -2 -o perm -20 2>/dev/null 1>wdir.log");
                                printf("Done!\n");
                                break;
                        case '3':
                                printf("Searching for world-writeable files..."), fflush(stdout);
                                system("find / -type f -perm -2 -o perm -20 2>/dev/null 1>wfile.log");
                                printf("Done!\n");
                                break;
                        case '4':
                                printf("Searching for floating files..."), fflush(stdout);
                                system("find / -nouser -o -nogroup 2>/dev/null 1>float.log");
                                printf("Done!\n");
                                break;
                        case '5':
                                printf("Later@#$!\n"); loop++;
                                break;
                        default:
                                if((answ != '\n') && (answ != '\r'))printf("Invalid option '%c'!\n",
answ);     
                                break;
                }
        }
        
        return 0;
}
