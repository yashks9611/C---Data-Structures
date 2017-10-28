#include<stdio.h>
#include<stdlib.h>

struct n
{
	int a;
	struct n *p;
}*h1=NULL,*h2=NULL,*ha=NULL,*hm=NULL,*t,*y,*g,*m,*w;


void insert(int j);
void display(int j);
void add();
void mul();

int main()
{
	int i;
	int k;
	struct n *r;
	do
	{
		printf("\n\tMENU\n\n1.Insert polynomial 1\n2.Insert Polynomial 2\n3.Add polynomials\n4.Multiply polynomials\n5.Display polynomial 1\n6.Display polynomial 2\n7.Exit\n\nEnter your choice -");
		scanf("%d",&i);
		printf("\n");
		switch(i)
		{
			case 1:
				insert(1);
				break;
			case 2:
				insert(2);
				break;
			case 3:
				add();
				break;
			case 4:
				mul();
				break;
			case 5:
				display(1);
				break;
			case 6:
				display(2);
				break;
			case 7:
				printf("\nTHANK YOU");
				break;
			default:
				printf("\nInvalid Input\n");
		}
	}while(i!=7) ;
	return(0);
}

void insert(int j)
{
	int d=0;
	if(j==1)
		t=y=h1;
	else
		t=y=h2;
	printf("\nEnter degree-");
	scanf("%d",&d);
	int i;
	for(i=0;i<=d;i++)
}

void add()
{
	t=h1;
	y=h2;
	g=ha;
	while(t!=NULL || y!=NULL)
	{
		struct n *l=(struct n *)malloc(sizeof(struct n));
		if(ha==NULL)
		{
			l->a=(t->a)+(y->a);
			l->p=NULL;
			g=l;
			ha=l;
			t=t->p;
			y=y->p;
		}
		else if(t==NULL)
		{
			l->a=(y->a);
			l->p=g->p;
			g->p=l;
			g=l;
			y=y->p;
		}
		else if(y==NULL)
		{
			l->a=(t->a);
			l->p=g->p;
			g->p=l;
			g=l;
			t=t->p;
		}
		else
		{
			l->a=(t->a)+(y->a);
			l->p=g->p;
			g->p=l;
			g=l;
			t=t->p;
			y=y->p;
		}
	}
	display(1);
	display(2);
	display(3);
}

void mul()
{
	t=h1;
	int i=0,j;
	printf("g");
	while(t!=NULL)
	{
		y=h2;
		m=hm;
		for(j=0;j<i;j++)
		{
			m=m->p;
		}
		while(y!=NULL)
		{
			if(hm == NULL)
			{
				struct n *l=(struct n *)malloc(sizeof(struct n));
				l->a=(t->a)*(y->a);
				l->p=NULL;
				hm=l;
				m=hm;
				y=y->p;
			}
			else
			{
				if(m->p!=NULL)
				{
					while(m->p!=NULL)
					{
						int s=(t->a)*(y->a);
						int f=(m->a);
						m->a=f+s;
						y=y->p;
						m=m->p;
					}
				}
				else
				{
					if(i>0)
					{
						m->a=(m->a)+(t->a)*(y->a);
						y=y->p;
					}
					struct n *l=(struct n *)malloc(sizeof(struct n));
					l->a=(t->a)*(y->a);
					l->p=m->p;
					m->p=l;
					m=l;
					y=y->p;
				}
			}
		}
		t=t->p;
		++i;
	}
	display(1);
	display(2);
	display(4);
}

void display(int j)
{
	if(j==1)
		t=h1;
	else if(j==2)
		t=h2;
	else if(j==3)
		t=ha;
	else
		t=hm;
	if(t == NULL)
		printf("\nThe polynomial does not exist");
	else
	{
		int i=0;
		printf("\nThe Polynomial is-" );
		while(t->p != NULL)
		{
			printf("%d(x^%d) + ",(t->a),i);
			i++;
			t=t->p;
		}
		printf("%d(x^%d)",(t->a),i);
	}
}
