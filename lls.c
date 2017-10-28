#include<stdio.h>
#include<stdlib.h>

struct n
{
	int a;
	struct n *p;
}*h=NULL,*t;


void insert();
void delete();
void display();

int main()
{
	int i;
	do
	{
		printf("\n\tMENU\n\n1.Insert\n2.Delete\n3.Display\n4.Exit\n\nEnter your choice -");
		scanf("%d",&i);
		printf("\n");
		switch(i)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\n\nTHANK YOU");
				break;
			default:
				printf("\nInvalid Input\n");
		}
	}while(i!=4);
	return(0);
}

void insert()
{
	int y=0;

	struct n *l=(struct n *)malloc(sizeof(struct n));
	printf("\nEnter the integer-");
	scanf("%d",&y);
	l->a=y;
	l->p=NULL;
	l->p=h;
	h=l;
}

void delete()
{
	if(h==NULL)
	{
		printf("\nList is empty" );
	}
	else
	{
		printf("\n%d",h->a);
		h=h->p;
	}
}

void display()
{
	t=h;
	printf("\nThe list is-" );
	while(t != NULL)
	{
		printf("\n%d",(t->a));
		t=t->p;
	}
}
