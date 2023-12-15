#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

#define N 1000000

void foo(){
	//empty func
}

int main(){
	struct timeval start,end;
	long elapsed;

	//measure the time of calling foo() N times
	gettimeofday(&start, NULL);
	for(int i =0;i<N;i++){
		foo();
	}
	gettimeofday(&end,NULL);
	elapsed = (end.tv_sec - start.tv_sec) * 1000000 +(end.tv_usec - start.tv_usec);
	printf("calling foo for %d times:%ld microseconds\n",N,elapsed);

	//measure the time of calling getpid() N times
	gettimeofday(&start,NULL);
	for(int i=0;i<N;i++){
		getpid();
	}
	gettimeofday(&end,NULL);
	elapsed = (end.tv_sec - start.tv_sec) * 1000000+(end.tv_usec - start.tv_usec);
	printf("calling getpid() %d times:%ld microseconds\n",N,elapsed);

	return 0;
}
