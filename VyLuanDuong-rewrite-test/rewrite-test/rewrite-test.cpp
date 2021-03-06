// rewrite-test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
signed int __cdecl f0700(int a1, int *a2, int a3, int *a4)
{
	// Pre-Condition:
	//    a1: possible input value = [64, 128, 256]
	//    a2: is an int[1408] array
	//        possible input value for each element = [-4095 ... 4095]
	//    a3: possible input value = [2, 3, 4, 5, 6]
	//    a4: is an int[116] array
	//        possible input value for each element = [0]
	//
	// Post-Condition:
	//    a1: value shouldn't change
	//    a2: value shouldn't change
	//    a3: value shouldn't changed
	//    a4: value can changed


	int *v4;
	int *v10;
	int v5;
	int v6;
	int v7;
	int o1;
	int v9;
	int v11;
	int v12;
	int v13;
	int v14;
	int v15;
	int a2a;

	v4 = a2;
	v5 = a1;
	v6 = 0;
	v7 = a2[a1];
	v14 = a2[a1 - 1];
	o1 = 0;
	v9 = -1;
	a2[a1 - 1] = 10000;
	v15 = v7;
	a2[a1] = -10000;
	a2a = 0;

	if (a1 > 0)
	{
		v10 = a4;
		do
		{
			
			v11 = (int)&v4[v6++];
			*v10 = v11;
			v12 = (int)&v4[v6];
			// printf("a2[a1-1]=a2[%d-1]=%d , a2[a1]=a2[%d]=%d\n", a1, a2[a1 - 1], a1, a2[a1]);
			// printf("v14=%d , v7=%d\n", v14, v7);
			// printf("v9= %d,v6= %d, v11= %d, v12= %d\n",v9,v6, *(int *)v11, *(int *)v12);
			if (v9 * (*(int *)v11 - *(int *)v12) < a3)
			{
				do
				{
					//printf("-> v12= %d > *v10= %d ?\n", *(int *)v12, *(int *)*v10);
					if (v9 * *(int *)v12 > v9 * *(int *)*v10)
						*v10 = v12;
					 //printf("--> v12= %d, *v10= %d\n", *(int *)v12, *(int *)*v10);
					v13 = *(int *)(v12 + 4);
					v12 += 4;
					// printf("--> v13= %d\n", v13);
					++v6;
				} while (v9 * (*(int *)*v10 - v13) < a3);
				v5 = a1;
			}
			printf("Mang v10/a4= %d\n", *(int *)*v10);
			++v10;
			v9 = -v9;
			o1 = a2a++ + 1;
			//printf("o1= %d, a2a= %d\n", o1, a2a);
		} while (v6 < v5);
	}
	if (o1 % 2)
	{
		--o1;
		printf("--o1= %d\n", o1);
	}
	v4[v5 - 1] = v14;
	v4[v5] = v15;
	//printf("v4[v5-1]=v4[%d-1]=%d, v4[v5]=v4[%d]=%d\n", v5, v4[v5 - 1],v5, v4[v5]);
	return o1;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
signed int __cdecl f0700_rewrite(int a1, int *a2, int a3, int *a4)
{
	int *p4=a4;
	int a, b,o1=0;
	int v9 = -1;
	int save1 = a2[a1 - 1];
	int save2 = a2[a1];
	int i=0;
	//set up new value at a1-1 and a1 for limitation
	a2[a1 - 1] = 10000;
	a2[a1] = -10000;

	if (a1 > 0)
	{
		do
		{
			a = a2[i++];
			b = a2[i];
			*p4 = a;
			if (v9*(a-b) < a3)
			{		
				do {
					if (v9 == 1) *p4 = max(a, b);
					if (v9 == -1) *p4 = min(a, b);
					b = a2[++i];
				} while (v9*(*p4 - b) < a3);
			}
			printf("p4 = %d\n ", *p4);
			++p4;
			v9 = -v9;
			++o1;
		} while (i < a1);
		if(o1 % 2) --o1;
		printf("o1= %d\n", o1);
		//give back old value at a2[a1-1] and a2[a1]
		a2[a1 - 1]=save1;
		a2[a1] = save2;
		
	}

	return o1;
}



int main()
{
	int a1 = 64;
	int a2[1408];
	int a3 = 3;
	int a4[116] = { 0 };
	int lower = -4095;
	int upper = 4095;
	
	for (int i = 0; i < 1048; i++) {
		int num = (rand() % (upper - lower + 1) + lower);
		a2[i] = num;
		//printf("a2[%d]= %d\n", i, num);
	}
	
	f0700(a1, a2, a3, a4);
	
	f0700_rewrite(a1, a2, a3, a4);

	

    return 0;
}

