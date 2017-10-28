#include<stdio.h>
#include<stdlib.h>

int a[100];

void merge(int b,int e);
void msort(int p,int q);
void mer(int b,int e);

int main()
{
	int n,i;
	printf("\nEnter size of Array-");
	scanf("%d",&n);
	printf("\nEnter elements of array-");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	msort(0,n-1);
	printf("\nSorted Array-");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return(0);
}

void msort(int p,int q)
{
	int m=(p+q)/2;
	if(p<q)
	{
		msort(p,m);
		msort(m+1,q);
		merge(p,q);
	}
}

void mer(int b,int e)
{
	int m=(b+e)/2;
	int i=b;
	int j=m+1;
	do
	{
		if(a[i]>a[j])
		{
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
			i++;
		}
		else
		{
			j++;
		}
	}while(i!=m && j!=e);
}

void merge(int b,int e)
{
	int m=(b+e)/2;
	int i=b;
	int j=m+1;
	int k=0;
	int be[100];
	while((i<=m) && (j<=e))
	{
		if(a[i]<a[j])
		{
			be[k]=a[i];
			i++;
		}
		else
		{
			be[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=m)
	{
		be[k]=a[i];
		k++;
		i++;
	}
	while(j<=e)
	{
		be[k]=a[j];
		k++;
		j++;
	}
	for(i=b;i<=e;i++)
	{
		a[i]=be[i-b];
	}
}
