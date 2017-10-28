#include<stdio.h>
#include<stdlib.h>

struct n
{
	int a;
	struct n *p;
}*f=NULL,*r=NULL;

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
	if(f == NULL && r==NULL)
	{
		f=r=l;
	}
	else
	{
		r->p=l;
		r=l;
	}
}

void delete()
{
	if(r==NULL && f==NULL)
	{
		printf("\nList is empty" );
	}
	else if(r==f)
  {
		printf("\nThe deleted element is-%d",(f->a));
		struct n *g=f;
		f=r=NULL;
		free(g);
	}
	else
	{
		printf("\nThe deleted element is -%d",f->a );
		struct n *j=f;
		f=f->p;
		free(j);
	}
}

void display()
{
	struct n *t=f;
	if(f==NULL && r==NULL)
	{
		printf("\nThe list is empty" );
	}
	else
	{
		printf("\nThe list is-" );
		while(t != NULL)
		{
			printf("\n%d",(t->a));
			t=t->p;
		}
	}
}
