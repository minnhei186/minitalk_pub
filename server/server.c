#include <stdio.h>
#include <signal.h>

#include <unistd.h>



int signal_bit;

void	ft_putchar_fd(char c, int fd);

void handler1(int sig)
{
	signal_bit=0;
}

void handler2(int sig)
{
	signal_bit=1;
}

int main(void)
{
	struct sigaction sa1;
	struct sigaction sa2;

	int i;
	int c;
	char out;
	char bit_output;

	char onebit;
	onebit=1;



	sa1.sa_handler=handler1;  
	sa1.sa_flags=0;
	sigemptyset(&sa1.sa_mask);
	sigaction(SIGUSR1,&sa1,NULL);

	sa2.sa_handler=handler2;  
	sa2.sa_flags=0;
	sigemptyset(&sa2.sa_mask);
	sigaction(SIGUSR2,&sa2,NULL);



	pid_t pid;
	pid=getpid();
	printf("pid:%d\n",pid);

	while(1)
	{
		i=8;
		c=0;
		while(i)
		{
			pause();
			c=c|signal_bit;
			if(i==1)
				break;
			c=c<<1;
			i--;
		}
		out=0;
		i=8;
		while(i)
		{
			bit_output=c&onebit; 		 
			c=c>>1;
			out=out|bit_output;
			if(i==1)
				break;
			out=out<<1;
			i--;
		}
		ft_putchar_fd(out,STDOUT_FILENO);
	}


	return 0;
}
