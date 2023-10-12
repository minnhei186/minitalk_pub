#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int main(void)
{
	int pid;
	char *string;
	char num;

	char bit_output;
	char onebit;
	int i;

	onebit=1;
	scanf("%i%*c",&pid);

	while(1)
	{

		scanf("%s%*c",string);
		while(*string)
		{
			num=*string;
			i=8;
			while(i)
			{
				bit_output=num&onebit; 				
				num=num>>1;
				if(bit_output==0)
					kill(pid,SIGUSR1);
				else

					kill(pid,SIGUSR2);
				i--;
				usleep(3*100);
			}
			string++;
		}
	}
	return 0;
}
