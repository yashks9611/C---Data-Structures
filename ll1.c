#include<stdio.h>
#include<stdlib.h>

struct n
{
	int a;
	struct n *p;
}*h=NULL,*t,*y;


void insert(int j);
void delete(int j);
void display();

int main()
{
	int i,j;
	do
	{
		printf("\n\tMENU\n\n1.Insert\n2.Delete\n3.Display\n4.Exit\n\nEnter your choice -");
		scanf("%d",&i);
		printf("\n");
		switch(i)
		{
			case 1:
				printf("\nPosition-");
				scanf("%d",&j );
				insert(j);
				break;
			case 2:
				printf("\nPosition-");
				scanf("%d",&j );
				delete(j);
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
	int y=0;
	struct n *l=(struct n *)malloc(sizeof(struct n));
	printf("\nEnter the integer-");
	scanf("%d",&y);
	l->a=y;
	if(h == NULL || j==1)
	{
		l->p=h;
		h=l;
	}
	else
	{
		int k=0;
		t=h;
		int i;
		for(i=1;i<j-1;i++)
    {
      if(t->p==NULL)
      {
        printf("There are less elements!!");
        k++;
				break;
      }
      t=t->p;
    }
		if(k>0)
		return ;
    l->p=t->p;
    t->p=l;
	}
}

void delete(int j)
{
	if(h==NULL)
	{
		printf("\nList is empty" );
	}
	else if(j==1)
	{
		printf("\nThe deleted element is -%d",h->a );
		y=h;
		h=h->p;
		free(y);
	}
	else
	{
		t=h;
		int i;
		for(i=1;i<j-1;i++)
		{
			if(t->p==NULL)
			{
				printf("There are less elements!!");
				return;
			}
			t=t->p;
		}
		y=t->p;
		t->p=y->p;
		printf("\nThe deleted element is -%d",y->a );
		free(y);
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
