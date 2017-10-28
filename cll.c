#include<stdio.h>
#include<stdlib.h>

struct n
{
	int a;
	struct n *p;
}*h=NULL,*t,*y;

void insert(int j);
void insatbeg();
void insatend();
void display();
void delete(int j);
void delatbeg();
void delatend();

int main()
{
	int i,j;
	do
	{
		printf("\n\tMENU\n\n1.Insert\n2.Insert at beginning\n3.insert at end\n4.Delete\n5.Delete at beginning\n6.Delete at end\n7.Display\n8.Exit\n\nEnter your choice -");
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
				insatbeg();
				break;
			case 3:
				insatend();
				break;
			case 4:
				printf("\nPosition-");
				scanf("%d",&j );
				delete(j);
				break;
			case 5:
				delatbeg();
				break;
			case 6:
				delatend();
				break;
			case 7:
				display();
				break;
			case 8:
				printf("\nTHANK YOU");
				break;
			default:
				printf("\nInvalid Input\n");
		}
	}while(i!=8);
	return(0);
}

void insert(int j)
{
	int y=0;
	struct n *l=(struct n *)malloc(sizeof(struct n));
	printf("\nEnter the integer-");
	scanf("%d",&y);
	l->a=y;
	t=h;
	if(h == NULL || j==1)
	{
		if(h==NULL)
		{
			h=l;
			l->p=h;
		}
		else
		{
			while(t->p!=h)
			{
				t=t->p;
			}
			l->p=h;
			h=l;
			t->p=h;
		}
	}
	else
	{
		int k=0;
		t=h;
		int i;
		for(i=1;i<j-1;i++)
    {
      if((t->p==h))
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

void insatbeg()
{
	int y=0;
	struct n *l=(struct n *)malloc(sizeof(struct n));
	printf("\nEnter the integer-");
	scanf("%d",&y);
	t=h;
	if (h==NULL) {
		l->a=y;
		h=l;
		l->p=h;
	}
	else
	{
		while(t->p!=h)
		{
			t=t->p;
		}
		l->a=y;
		printf("g");
		l->p=h;
		printf("g");
		h=l;
		printf("g");
		t->p=h;
		printf("g");
	}
}

void insatend()
{
	int y=0;
	struct n *l=(struct n *)malloc(sizeof(struct n));
	printf("\nEnter the integer-");
	scanf("%d",&y);
	l->a=y;
	t=h;
	if(h==NULL)
	{
		h=l;
		l->p=h;
	}
	else
	{
		while(t->p!=h)
		{
			t=t->p;
		}
		l->p=t->p;
		t->p=l;
	}
}

void delete(int j)
{
	t=h;
	if(h==NULL)
	{
		printf("\nList is empty" );
	}
	else if(j==1)
	{
		if(t->p==h)
		{
			y=h;
			printf("\nThe deleted element is -%d",y->a);
			h=NULL;
			free(y);
		}
		else
		{
			while(t->p != h)
			{
				t=t->p;
			}
			printf("\nThe deleted element is -%d",h->a );
			y=h;
			h=h->p;
			t->p=h;
			free(y);
		}
	}
	else
	{
		int i;
		for(i=1;i<j-1;i++)
		{
			if(t->p==h)
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

void delatend()
{
	t=h;
	if(h==NULL)
	{
		printf("\nThe list is empty");
	}

	else
	{
		while(t->p->p != h)
		{
			t=t->p;
		}
		if(t->p==h)
		{
			printf("\nThe deleted element is -%d",t->a);
			free(t);
			h=NULL;
		}
		else
		{
			y=t->p;
			t->p=h;
			printf("\nThe deleted element is -%d",y->a);
			free(y);
		}
	}
}

void delatbeg()
{
	t=h;
	if(h==NULL)
	{
		printf("\nThe list is empty");
	}
	else if(t->p==h)
	{
		y=t;
		printf("\nThe deleted element is :-%d",y->a );
		h=NULL;
		free(y);
	}
	else
	{
		do
		{
			t=t->p;
		}while(t->p != h);
		y=h;
		h=h->p;
		t->p=h;
		printf("\nThe deleted element is :-%d",y->a );
		free(y);
	}
}
void display()
{
	t=h;
	if(h==NULL)
	{
		printf("\nThe list is empty");
	}
	else
	{
	printf("\nThe list is-" );
		while(t->p!=h)
		{
			printf("\n%d",(t->a));
			t=t->p;
		}
		printf("\n%d",t->a);
	}
}
