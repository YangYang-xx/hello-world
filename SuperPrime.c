//超级素数：它本身，各位数字的和，各位数字的平方和，都是素数。
//求 100~10000 内的所有超级素数，及它们的平均数。
#include <stdio.h>
int isPrime(int x);
int splitNum(int x, int num[]);

int main()
{
	int i,j,k,x,y,z;
	int num[5],SuperPrime[9900];
	int m=0,n=0;
	for(i=100;i<=10000;i++)
	{
		x=isPrime(i);
		if(x==1)
		{
			n=splitNum(i,num);
			int a=0,b=0;
			for(j=0;j<n;j++)
			{
				a=a+num[j];
				b=b+num[j]*num[j];
			}
			y=isPrime(a);
			z=isPrime(b);
			if(y==1 && z==1)
			{
				SuperPrime[m]=i;
				m++;
			}
		}	 
	}
	float sum=0,average=0;
	for(k=0;k<m;k++)
	{
		sum=sum+SuperPrime[k];
		printf("%-4d ",SuperPrime[k]);
	}
	average=sum/m;
	printf("\n");
	printf("The average is %f.",average);
    return 0;
}

int isPrime(int x)
{
	int n=0;
	int i;
	if(x>1)
	{
	  for(i=2;i<x;i++)
	  {
		  if(x%i==0)
		  {
			n++;
		  }
	  }
	  if(n==0)
	  {
		  return 1;
	  }
	  else
	  {
	 	return 0;
	  }	
	}
	else if(x==1)
	{
		return 0;
	}
}

int splitNum(int x, int num[])
{
	int i,n;
	for(i=x,n=0;i!=0;n++)
	{
		num[n]=i%10;
		i=i/10;
	}
	return n;
}
