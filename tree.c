#include<stdio.h>
#include<stdlib.h>

struct n
{
	int d;
	struct n * ls;
	struct n * rs;
};
struct n *r=NULL;


void displayin(struct n *j);
void displaypre(struct n *j);
void displaypos(struct n *j);
void insert(int k);
void insertr(int k,struct n *j);
void delete(struct n *p,struct n *j,int k);
struct n *lios(struct n *o);
struct n * delr(struct n *j,int x);
int height (struct n *j);


int c=0;

int main()
{
	int i;
	do
	{
		printf("\n\tMENU\n\n1.Insert\n2.Number of nodes\n3.Height of tree\n4.Display preorder\n5.Display postorder\n6.Display inorder\n7.Insert recursively\n8.Delete \n9.Delete recursively\n10.EXIT\n\nEnter your choice -");
		scanf("%d",&i);
		printf("\n");
		int k;
		switch(i)
		{
			case 1:
				printf("\nEnter element-");
				scanf("%d",&k);
				insert(k);
				break;
			case 2:
				printf("No. of nodes=%d",c);
				break;
			case 3:
				printf("Height of tree=%d",height(r));
				break;
			case 4:
				displaypre(r);
				break;
			case 5:
				displaypos(r);
				break;
			case 6:
				displayin(r);
				break;
			case 7:
				printf("\nEnter element-");
				scanf("%d",&k);
				insertr(k,r);
				break;
			case 8:
				printf("\nEnter element-");
				scanf("%d",&k);
				delete(r,r,k);
				break;
			case 9:
				printf("\nEnter element-");
				scanf("%d",&k);
				delr(r,k);
				break;
			case 10:
				printf("\nTHANK YOU");
				break;
			default:
				printf("\nInvalid Input\n");
		}
	}while(i!=10);
	return (0);
}

void insertr(int k,struct n *j)
{
	if(r==NULL)
	{
		struct n *l=(struct n *)malloc(sizeof(struct n));
		l->d=k;
		l->ls=NULL;
		l->rs=NULL;
		r=l;
		c++;
	}
	else
	{
		if(k>j->d)
		{
			if( j->rs!=NULL)
			{
				insertr(k,(j->rs));
			}
			else
			{
				struct n *l=(struct n *)malloc(sizeof(struct n));
				l->d=k;
				l->ls=NULL;
				l->rs=NULL;
				j->rs=l;
				c++;
			}
		}
		else
		{
			if( j->ls!=NULL)
			{
				insertr(k,(j->ls));
			}
			else
			{
				struct n *l=(struct n *)malloc(sizeof(struct n));
				l->d=k;
				l->ls=NULL;
				l->rs=NULL;
				j->ls=l;
				c++;
			}
		}
	}
}

void delete(struct n *p,struct n *j,int k)
{
	if(r==NULL)
	{
		printf("\nTree is empty");
		return;
	}
	else if(k<(j->d))
	{
		delete(j,(j->ls),k);
	}
	else if(k>(j->d))
	{
		delete(j,(j->rs),k);
	}
	else
	{
		if((j->ls)==NULL && (j->rs)==NULL)
		{
			if((p->d)>k)
			{
				p->ls=NULL;
			}
			else
			{
				p->rs=NULL;
			}
			free(j);
			c--;
		}
		else if((j->ls)==NULL)
		{
			if((p->d)>k)
			{
				p->ls=j->rs;
			}
			else
			{
				p->rs=j->rs;
			}
			free(j);
			c--;
		}
		else if((j->rs)==NULL)
		{
			if((p->d)>k)
			{
				p->ls=j->ls;
			}
			else
			{
				p->rs=j->ls;
			}
			free(j);
			c--;
		}
		else
		{
			struct n *i=j->rs;
			struct n *o=j;
			while(i->ls!=NULL)
			{
				o=i;
				i=i->ls;
			}
			o->ls=i->rs;
			if((p->d)>k)
			{
				p->ls=i;
			}
			else
			{
				p->rs=i;
			}
			i->ls=j->ls;
			i->rs=j->rs;
			free(j);
			c--;
		}
	}
}

void insert(int k)
{
	struct n *l=(struct n *)malloc(sizeof(struct n));
	l->d=k;
	l->ls=NULL;
	l->rs=NULL;
	if(r==NULL)
	{
		r=l;
		c++;
	}
	else
	{
		struct n *p,*t=r;
		while(t!=NULL)
		{
			p=t;
			if(k<t->d)
			{
				t=t->ls;
			}
			else
			{
				t=t->rs;
			}
		}
		if(k<p->d)
			p->ls=l;
		else
			p->rs=l;
			c++;
	}
}

void displayin(struct n *j)
{
	if(j==NULL)
	{
		return;
	}
	else
	{
		displayin((j->ls));
		printf("%d ",j->d);
		displayin((j->rs));
	}
}

void displaypos(struct n *j)
{
	 if(j==NULL)
	 {
		 return;
	 }
	 else
	 {
		 displaypos((j->ls));
		 displaypos((j->rs));
		 printf("%d ",j->d);
	 }
}

void displaypre(struct n *j)
{
	if(j==NULL)
	{
		return;
	}
	else
	{
		printf("%d ",j->d);
		displaypre((j->ls));
		displaypre((j->rs));
	}
}

struct n * delr(struct n *j,int x)
{
	if(j==NULL)
	{
		return (NULL);
	}
	else
	{
		if(x<(j->d))
		{
			j->ls=delr(j->ls,x);
		}
		else if(x>j->d)
		{
			j->rs=delr(j->rs,x);
		}
		else
		{
			if(j->ls==NULL && j->rs==NULL)
			{
				free(j);
				c--;
				return (NULL);
			}
			else if(j->ls==NULL)
			{
				struct n *k=j->rs;
				free(j);
				c--;
				return(k);
			}
			else if(j->rs==NULL)
			{
				struct n *k=j->ls;
				free(j);
				c--;
				return(k);
			}
			else
			{
				struct n *io=lios(j->rs);
				int y=io->d;
				delr(r,y);
				j->d=y;
			}
		}
	}
}

struct n * lios(struct n *k)
{
	if(k->ls!=NULL)
	{
		struct n *i=lios(k->ls);
		return(i);
	}
	else
	{
		printf("lios-%d\n",k->d);
		return(k);
	}
}

int height (struct n *j)
{
	if(j==NULL)
	{
		printf("NO TREE FOUND");
		return(-1);
	}
	else
	{
		if(j->ls==NULL && j->rs==NULL)
		{
			return(0);
		}
		else if(j->ls==NULL)
		{
			return(1+height(j->rs));
		}
		else if (j->rs==NULL)
		{
			return(1+height(j->ls));
		}
		else
		{
			int h1=height(j->ls);
			int h2=height(j->rs);
			if(h1>=h2)
			{
				return(1+h1);
			}
			else
			{
				return(1+h2);
			}
		}
	}
}
