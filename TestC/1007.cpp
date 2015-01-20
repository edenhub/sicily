#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
//¶ÔAÊý×é[x,y)Êý¾Ý¶Î½øÐÐ¹é²¢ÅÅÐò£¬TÊÇ¸¨Öú¿Õ¼ä 
void merge_sort(int *A, int x, int y, int* T)
{
	if (y-x > 1)
	{
		int m = x + (y-x) / 2;	// divide
		int p = x, q = m, i = x;
		merge_sort(A, x, m, T);	// µÝ¹éÇó½â
		merge_sort(A, m, y, T);	// µÝ¹éÇó½â
		while (p < m || q < y)
		{
		    if(q >= y || (p < m && A[p] <= A[q])) 
			  T[i++] = A[p++];
		    else {T[i++] = A[q++];} 
		}
		for(i=x; i<y; i++) A[i] = T[i];
	}
}

int inversion_num = 0; //´æ·ÅÄæÐò¶Ô¸öÊý£¬Ã¿´Îµ÷ÓÃÇ°Çå0 
void inversion_number(int *A, int x, int y, int* T)
{
	if (y-x > 1)
	{
		int m = x + (y-x) / 2;	// divide
		int p = x, q = m, i = x;
		merge_sort(A, x, m, T);	// µÝ¹éÇó½â
		merge_sort(A, m, y, T);	// µÝ¹éÇó½â
		while (p < m || q < y)
		{
		    if(q >= y || (p < m && A[p] <= A[q])) 
			  T[i++] = A[p++];
		    else {T[i++] = A[q++]; inversion_num += m-p;} 
		}
		for(i=x; i<y; i++) A[i] = T[i];
	}
}

int main(){
	int num;
	while(scanf("%d",&num)!=EOF){
		int a[num];
		for(int i=0;i<num;i++)
			cin>>a[i];
		int b[2*num];

		inversion_num = 0;
		inversion_number(a,0,num,b);
		cout<<inversion_num<<endl;
	}
}
// int main(){
//     int a[] = {3, 1, 4, 5, 2};
//     int b[10];
//     inversion_num = 0;
//     inversion_number(a,0,5,b);

//     for (int k=0; k<=4; k++)
//       cout << a[k] << " ";
//     cout << inversion_num << endl;
//     for (int k=0; k<=4; k++)
//       cout << a[k] << " ";
//     cout << endl;
// }
