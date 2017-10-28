#include<stdio.h>
#include<stdlib.h>

struct n
{
	int d;
	struct n * ls;
	struct n * rs;
	int h;
};
struct n *r=NULL;

struct n * delr(struct n *j,int x);
int height (struct n *j);
struct n * lios(struct n *k);
void displayin(struct n *j);
void displaypre(struct n *j);
void displaypos(struct n *j);
int bf(struct n *j);
int hup(struct n *j);
struct n * rotr(struct n *j);
struct n * rotl(struct n *j);
struct n * rotlr(struct n *j);
struct n * rotrl(struct n *j);
struct n * insertr(int k,struct n *j);

int c=0;

int main()
{
	int i;
	do
	{
		printf("\n\tMENU\n\n1.Insert\n2.Number of nodes\n3.Height of tree\n4.Display preorder\n5.Display postorder\n6.Display inorder\n7.Delete \n8.EXIT\n\nEnter your choice -");
		scanf("%d",&i);
		printf("\n");
		int k;
		switch(i)
		{
			case 1:
				printf("\nEnter element-");
				scanf("%d",&k);
				r=insertr(k,r);
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
				r=delr(r,k);
				break;
			case 8:
				printf("\nTHANK YOU\n");
				break;
			default:
				printf("\nInvalid Input\n");
		}
	}while(i!=8);
	return (0);
}

int height (struct n *j)
{
	if(j==NULL)
	{

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

int bf(struct n *j)
{
	if(j==NULL)
	{
		return(0);
	}
	else
	{
		int h1=height(j->ls);
		int h2=height(j->rs);
		return(h1-h2);
	}
}

int hup(struct n *j)
{
	if(j!=NULL)
		return(height(j));
}

struct n * rotr(struct n *j)
{
	struct n *l=j->ls;
	j->ls=l->rs;
	l->rs=j;
	j->h=height(j);
	l->h=height(l);
	return(l);
}

struct n * rotl(struct n *j)
{
	struct n *l=j->rs;
	j->rs=l->ls;
	l->ls=j;
	j->h=height(j);
	l->h=height(l);
	return(l);
}

struct n * rotrl(struct n *j)
{
	struct n *l=j->rs;
	j->rs=rotr(l);
	j->h=height(j);
	l->h=height(l);
	return(rotl(j));
}

struct n * rotlr(struct n *j)
{
	struct n *l=j->ls;
	j->ls=rotl(l);
	j->h=height(j);
	l->h=height(l);
	return(rotr(j));
}

struct n * insertr(int k,struct n *j)
{
	if(j==NULL)
	{
		struct n *l=(struct n *)malloc(sizeof(struct n));
		l->d=k;
		l->ls=NULL;
		l->rs=NULL;
		l->h=0;
		j=l;
		c++;
	}
	else
	{
		if(k>j->d)
		{
			j->rs=insertr(k,(j->rs));
			if(bf(j)>1 || bf(j)<-1)
			{
				if(k>(j->rs)->d)
				{
					j=rotl(j);
				}
				else
				{
					j=rotrl(j);
				}
			}
		}
		else
		{
			j->ls=insertr(k,(j->ls));
			if(bf(j)>1 || bf(j)<-1)
			{
				if(k>(j->ls)->d)
				{
					j=rotlr(j);
				}
				else
				{
					j=rotr(j);
				}
			}
		}
	}
	return(j);
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
				j->d=io->d;
				j->rs=delr(j->rs,j->d);
			}
		}
		if(j==NULL)
		{
			return(NULL);
		}
		j->h=height(j);
		if(bf(j)>1 && bf(j->ls)>=0)
		{
			return(rotr(j));
		}
		if(bf(j)>1 && bf(j->ls)<0)
		{
			return(rotlr(j));
		}
		if(bf(j)<-1 && bf(j->rs)<=0)
		{
			return(rotl(j));
		}
	 	if(bf(j)<-1 && bf(j->rs)>0)
		{
			return(rotrl(j));
		}
		return(j);
	}
}
