
#include <stdio.h>

#define PI 3.1415927

int main(){

	float dInInches;
	int r,count=0;
	float timeInSecond;

	while(1){
		count++;
		scanf("%f %d %f",&dInInches,&r,&timeInSecond);

		if(r == 0)
			break;

	    float distance = (float)(dInInches * PI * r) / (float)(5280 * 12);
	    float MPH = (float)(distance * 3600) / (float)timeInSecond;
	    printf("Trip #%i: %0.2f %0.2f\n",count,distance,MPH);
		
	}

	return 0;
}
