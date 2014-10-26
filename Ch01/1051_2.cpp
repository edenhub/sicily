#include <stdio.h>
#define  pi  3.1415927
int main()
{
    double  diameter,time1;
    int revolutions; 
    int n=1;
    while(scanf("%lf %d %lf ",&diameter,&revolutions,&time1) && revolutions!=0)
    {
        double  distance;
         distance = (double)(pi*diameter*revolutions)/(double)(12*5280);
        double t = time1/3600;
        double MPH = distance/(double)(t);
        printf("Trip #%d: %.2lf %.2lf\n",n++,distance,MPH);
    }
    return 0;
}     