#include  "unistd.h" 
#define __NR_myservice        289

_syscall0(int, myservice);

int main()
{
	myservice();
	return 0;
}


