#include <stdio.h>
#include<stdlib.h>
#include "functions.h"

struct Node{
char Word[20];
char Meaning[500];
struct Node* next;
};

int str_compare(char *str1, char *str2)
{
int i=0;
char A[100], B[100];

str_copy(A,str1);
str_copy(B,str2);

while(A[i]!='\0')
    {
    if(A[i]>='A' && A[i]<='Z')
        {
        A[i]=A[i]+32;
        }
    i++;
    }
i=0;

while(B[i]!='\0')
    {
    if(B[i]>='A' && B[i]<='Z')
        {
        B[i]=B[i]+32;
        }
    i++;
    }
i=0;

int length1=str_length(str1);
int length2=str_length(str2);

for(i=0;A[i]!='\0' && B[i]!='\0';i++)
{
if(A[i]<B[i])
{
return (-1);
break;
}

else
if(A[i]>B[i])
{
return 1;
break;
}

}

if(length1<length2)
    {
    return (-1);
    }
else
if(length1>length2)
    {
    return 1;
    }
else
    {
    return 0;
    }
}

int str_compare1(char *str1, char *str2)
{
    int f1=0,f2=0,i;
    
    for (i = 0;i < str_length(str1)||i < str_length(str2);i++)
    {
        if(*(str1+i)>*(str2+i))
        {
            f1++;
            break;
        }
        if(*(str2+i)>*(str1+i))
        {
            f2++;
            break;
        }
       
    }

    if (f1==0 && f2==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
    return 0;
}

int str_copy(char *str1, char *str2)
{
    
    while(*str2 != '\0')
    {
        *(str1++) = *(str2++);
       
    }
    *str1 = '\0';
    return *str1;
}

int str_length(char *str)
{
    int c=0;
    while(*str != '\0')
    {
        c++;
        str++;
    }
    return c;
}

int str_find_substring(char *str1, char *str2)
{
int i=0,j=0,k;
char A[500], B[100];

str_copy(A,str1);
str_copy(B,str2);

while(A[i]!='\0')
    {
    if(A[i]>='A' && A[i]<='Z')
        {
        A[i]=A[i]+32;
        }
    i++;
    }
i=0;

while(B[i]!='\0')
    {
    if(B[i]>='A' && B[i]<='Z')
        {
        B[i]=B[i]+32;
        }
    i++;
    }
i=0;

while(A[i]!='\0')
    {
    while(A[i]!=B[0] && A[i]!='\0')
        {
        i++;
        }
    if(A[i]=='\0')
        {
        return (-1);
        }
    k=i;
    
    while(A[i]==B[j] && A[i]!='\0' && B[j]!='\0')
        {
         i++;
         j++;
        }

      if(B[j]=='\0')
        {
        return (k+1);
        }

      if(A[i]=='\0')
        {
        return (-1);
        }

      i=k+1;
      j=0;
    }
return 0;
}

void *memcopy(const void* src,  void* dest, unsigned int n)
{
    int i;
    char* s= (char*)src;
    char* d= (char*)dest;
    for (i = 0; i < n; ++i)
    {
        d[i]=s[i];
    }
    return d;
}

int str_find_substring1(char*str1, char*str2)
{
int i=0,j=0,k;

while(str1[i]!=0)
    {
    while(str1[i]!=str2[0] && str1[i]!='\0')
        {
        i++;
        }
    if(str1[i]=='\0')
        {
        return (-1);
        }
    k=i;
    
    while(str1[i]==str2[j] && str1[i]!='\0' && str2[j]!='\0')
        {
         i++;
         j++;
        }

      if(str2[j]=='\0')
        {
        return k;
        }

      if(str1[i]=='\0')
        {
        return (-1);
        }

      i=k+1;
      j=0;
    }
return 0;
}

void Tweet1(struct Node* head,char* A)
{
int i,j,k=0;
int a,b=-1;
struct Node* temp;
struct Node* temp3;
    
while(A[k]!='\0')
    {  
    temp=head;
    while(temp!=NULL)
        {
        a = str_find_substring(A,(*temp).Meaning);

        if(a>=0)
            {
            temp3=(*temp).next;
            while(temp3!=NULL)
                {
                b=str_find_substring(A,(*temp3).Meaning);
                
                if(b==a && str_compare((*temp3).Meaning, (*temp).Meaning)==1)
                    {
                    temp=temp3;
                    }
                temp3=(*temp3).next;
                }
            
            int length=str_length((*temp).Meaning);
            int n=str_length((*temp).Word);
            int size=str_length(A);
            int c=length+a-1;
            int b=size-c;
            char temp1[500];
            char temp2[500];
            
            j=0;
            for(i=a-1;i<a+n-1;i++)                  
                {
                A[i]=(*temp).Word[j];
                j++;
                }
    
            for(i=0;i<a+n-1;i++)                  
                {                              
                temp1[i]=A[i];
                }
            temp1[a+n-1]='\0';      

            for(j=0;j<b;j++)                    
                {
                temp2[j]=A[j+c];
                }
            temp2[b]='\0';
            int length2=str_length(temp2);
 
            for(j=0;j<length2;j++)              
                {
                temp1[i]=temp2[j];
                i++;
                }
            temp1[i]='\0';

            for(i=0;temp1[i]!='\0';i++)         
                {
                A[i]=temp1[i];
                }
            A[i]='\0';
            }
        temp=(*temp).next;
        }
    k++;
    }
return;
}

void Insert(char* A)
{
    char B[500];
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    memcopy(A,(*temp).Word,sizeof(char)*100);
    printf("Enter the meaning of the tweet\n");
    scanf(" %[^\n]s",B);
    memcopy(B,(*temp).Meaning,sizeof(char)*100);
    (*temp).next= head;
    head=temp;

return;
}

