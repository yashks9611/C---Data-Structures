#include<stdio.h>

int a[100];
int c=-1;

void delete();
void insert(int j);
void display();

int main()
{
	int i,j;
	int k=0;
	for(k=0;k<100;k++)
		a[k]=-1;
	do
	{
		printf("\n\tMENU\n\n1.Insert\n2.Delete\n3.Display\n4.Exit\n\nEnter your choice -");
		scanf("%d",&i);
		printf("\n");
		switch(i)
		{
			case 1:
				printf("\nElement-");
				scanf("%d",&j );
				insert(j);
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nTHANK YOU");
				break;
			default:
				printf("\nInvalid Input\n");
		}
	}while(i!=4);
	return(0);
}

void insert(int j)
{
	c++;
	a[c]=j;
	int d=c;
	while(a[d]<a[(d-1)/2])
	{
		a[d]=a[d]+a[(d-1)/2];
		a[(d-1)/2]=a[d]-a[(d-1)/2];
		a[d]=a[d]-a[(d-1)/2];
		d=(d-1)/2;
		if(d<0)
			break;
	}
}

void delete()
{
	int g=a[0];
	a[0]=a[c];
	a[c]=-1;
	c--;
	if(c<-1)
	{
		printf("\nEmpty Heap\n");
		c=-1;
		return;
	}
	int tmp =0;
	int i=0;
	if(c>-1)
		printf("The last element is -:%d\n",a[i]);
	while((a[i]>a[(2*i)+1] || a[i]>a[(2*i)+2]) && i<c)
	{
		tmp=0;
		if(((2*i)+1)<c && ((2*i)+2)<=c)
		{
			if(a[(2*i)+1]<a[(2*i)+2])
			{
				tmp=a[i];
				a[i]=a[(2*i)+1];
				a[(2*i)+1]=tmp;
				i=(2*i)+1;
				if(((2*i)+1)>c)
					break;
			}
			else
			{
				tmp=a[i];
				a[i]=a[(2*i)+2];
				a[(2*i)+2]=tmp;
				i=(2*i)+2;
				if(((2*i)+1)>c)
					break;
			}
		}
		else if(((2*i)+1)<=c)
		{
			tmp=a[i];
			a[i]=a[(2*i)+1];
			a[(2*i)+1]=tmp;
			i=(2*i)+1;
				break;
		}
	}
	display();
}

void display()
{
	int k=0;
	for(k=0;k<=c;k++)
		printf("%d ",a[k]);
}
