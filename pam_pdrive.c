#include <security/pam_modules.h>
#include <security/pam_ext.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>


PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) 
{
	return PAM_SUCCESS;
}


PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) 
{
	/*int serial1, serial2, result;
	
	FILE *pendrive1;
	FILE *pendrive2;
	pendrive1 = popen("lsblk --output SERIAL /dev/sdb", "r");
	pendrive2 = popen("cat /etc/pam.d/pam.pdrive/teste.txt", "r");
	
	
	serial1 = pclose(pendrive1);
	serial2 = pclose(pendrive2);
	
	char a[60];
	char b[60];

	fgets(a, 512 , serial1);
	fgets(b, 512 , serial2);*/
//system("lsblk --output SERIAL /dev/sdb > /etc/pam.d/pam.pdrive/teste2.txt");
	system("/sbin/udevadm info -n /dev/sdb -a | grep serial > /etc/pam.d/pam.pdrive/teste2.txt");
	char pdrive[512];
	char pdrive2[512];

	FILE *pendrive1;
	FILE *pendrive2;
		
	pendrive1 = fopen("/etc/pam.d/pam.pdrive/teste2.txt", "r");
	pendrive2 = fopen("/etc/pam.d/pam.pdrive/teste.txt", "r");

	fgets(pdrive, 512, pendrive1);
	fgets(pdrive2, 512, pendrive2);
	
	if(strcmp(pdrive, pdrive2) == 0)
	   {	
		printf("iguais");
	}
	else {
		printf("nao iguais");
	}
	
	printf("Esse é um %s", &pdrive);
	
	
	sleep(2);
	fclose(pendrive1);
	if(system("lsblk --output SERIAL /dev/sdb") == system("cat /etc/pam.d/pam.pdrive/teste.txt"))
	{
		printf("\nseriais iguais\n");
		sleep(2);
		return PAM_SUCCESS;
	}
	else 
	{
		printf("\nSeriais diferentes\n");
		sleep(2);
		return PAM_SUCCESS;		

	}

	
}
