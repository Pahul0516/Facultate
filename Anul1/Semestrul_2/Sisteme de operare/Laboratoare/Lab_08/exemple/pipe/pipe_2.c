/*
	pipe_2.c
	
	Sa se implementeze un proces care creeaza un proces copil cu care comunica
	prin pipe. Procesul parinte trimite prin pipe procesului copil doua numere
	intregi, iar procesul copil returneaza prin pipe suma lor.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char* argv[])
{
	int c2p[2];				// child to parent pipe descriptors
	int res = pipe(c2p);
	if (res == -1)			// fail to create pipe
	{
		perror("pipe(c2p)");
		exit(EXIT_FAILURE);
	}

	int p2c[2];				// parent to child pipe descriptors
	res = pipe(p2c);
	if (res == -1)			// fail to create pipe
	{
		perror("pipe(p2c)");
		exit(EXIT_FAILURE);
	}

	int pid = fork();
	if (pid == -1)			// fail to create child
	{
		perror("fork()");
		exit(EXIT_FAILURE);
	}

	// in the child process
	if (pid == 0)
	{
		// close the unused pipe descriptors
		close(c2p[0]);
		close(p2c[1]);

		while(1)
		{
			// read the first integer
			int a;
			read(p2c[0], &a, sizeof(int));
			printf("\t[In CHILD] a: %d\n", a);

			// check for stop
			if (a == 0)
				break;

			// read the second integer
			int b;
			read(p2c[0], &b, sizeof(int));
			printf("\t[In CHILD] b: %d\n", b);

			// send the sum to parent
			int sum = a + b;
			write(c2p[1], &sum, sizeof(int));

			printf("\t[In CHILD] Sum: %d\n", sum);
		}

		// close the pipe descriptors
		close(c2p[1]);
		close(p2c[0]);

		exit(EXIT_SUCCESS);
	}

	// in the parent process
	
	// close the unused pipe descriptors
	close(c2p[1]);
	close(p2c[0]);

	while(1)
	{
		// read the first integer
		int a;
		printf("[In PARENT] a: ");
		scanf("%d", &a);

		// send to the child
		write(p2c[1], &a, sizeof(int));

		if (a == 0)
			break;

		sleep(2);

		// read the second integer
		int b;
		printf("[In PARENT] b: ");
		scanf("%d", &b);

		// send to the child
		write(p2c[1], &b, sizeof(int));

		// read the sum from pipe
		int sum = 0;
		read(c2p[0], &sum, sizeof(int));

		printf("[In PARENT] Sum: %d\n", sum);
	}

	// wait for child
	int status;
	wait(&status);
	printf("\n[In PARENT] Child has finished with exit status: %d\n", status);

	// close the pipe descriptors
	close(c2p[0]);
	close(p2c[1]);

	return 0;
}
