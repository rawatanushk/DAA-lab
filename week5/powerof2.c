#include<stdio.h>
#include<stdbool.h>
bool ispow(int n){
if (n<0)
return false;
while(n>1)
{
if(n%2!=0)
return false;
n=n/2;
}
return true;
}

int main(){
int num;
printf("Enter a number:");
scanf("%d",&num);
if(ispow(num))
printf("%d is power of 2",num);
else 
printf("%d is not a power of 2",num);
}
