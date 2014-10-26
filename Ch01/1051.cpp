
#include <stdio.h>

#define PI 3.1415927

int main(){

	double dInInches;
	int r,timeInSecond,count=0;

	while(1){
		count++;
		scanf("%f %d %d",&dInInches,&r,&timeInSecond);

		if(r == 0)
			break;

	    double distance = (double)(dInInches * PI * r) / (double)(5280 * 12);
	    double MPH = (double)(distance * 3600) / (double)timeInSecond;
	    printf("Trip #%i:%0.2f %0.2f\n",count,distance,MPH);
		
	}

	return 0;
}
