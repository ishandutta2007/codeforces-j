#include<stdio.h>
int main()
{
int n,x;
scanf("%d%d",&n,&x);
if(n%6==0)
{
	if(x==0)
	printf("0");
	if(x==1)
	printf("1");
	if(x==2)
	printf("2");
}
if(n%6==1)
{
	if(x==0)
	printf("1");
	if(x==1)
	printf("0");
	if(x==2)
	printf("2");
}
if(n%6==2)
{
	if(x==0)
	printf("1");
	if(x==1)
	printf("2");
	if(x==2)
	printf("0");
}
if(n%6==3)
{
	if(x==0)
	printf("2");
	if(x==1)
	printf("1");
	if(x==2)
	printf("0");
}
if(n%6==4)
{
	if(x==0)
	printf("2");
	if(x==1)
	printf("0");
	if(x==2)
	printf("1");
}
if(n%6==5)
{
	if(x==0)
	printf("0");
	if(x==1)
	printf("2");
	if(x==2)
	printf("1");
}
}