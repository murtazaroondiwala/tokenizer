#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node* head;
int str_copy(char *str1, char *str2);
int str_find_substring(char*str1, char*str2);
int str_find_substring1(char*str1, char*str2);
int str_length(char *str);
int str_compare1(char *str1, char *str2);
int str_compare(char *str1, char *str2);
void *memcopy(const void* src,  void* dest, unsigned int n);
void Tweet1(struct Node* head,char* A);
void Insert(char* A);

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


// struct Node{
// char Word[20];
// char Meaning[500];
// struct Node* next;
// };

int main(int argc, char* argv[])
{
    int n;
    char d;
    int size;
    FILE* fp;
    char A[500];
    char B[20];

    struct Node* head=NULL;
    struct Node* temp;

    if(argc!=2)
    {
    	printf("Error.Please enter 2 arguments in the command line\n");
        return 0;
    }
    else
        {
        FILE* fp;
        fp=fopen(argv[1], "r");
        
        while(!feof(fp))
        	{
            temp=(struct Node*)malloc(sizeof(struct Node));
        
            fscanf(fp, "%s\n",(*temp).Word);
            fscanf(fp, "%[^\n]s",(*temp).Meaning);

            if(feof(fp))
                {
                break;
                }

            (*temp).next=head;
            head=temp;
            }
        fclose(fp);
        }

    while(n!=5)
        {
        printf(" Press 1, To convert a string into a tweet\n");
        printf(" Press 2, To add a new word to the dictionary\n");
        printf(" Press 3, To save the current dictionary to a file\n");
        printf(" Press 4, To load a new batch of dictionary items from the file\n");
        printf(" Press 5, To exit the application\n");
        scanf("%d",&n);
        
        switch(n)
            {
            case 1:
            printf("Enter a string to be converted\n");
            scanf(" %[^\n]s",A);

            Tweet1(head,A);
            size=str_length(A);
            printf("size of A %d\n",size);
            if(size<=140)
                {
                printf("%s\n",A);
                printf("\n");

                printf("Do you want to log this conversion ?(Enter y for Yes or n for No): \n");
                scanf(" %c", &d);

                if(d=='y')
                    { 
                    time_t t = time(NULL);
                    struct tm tm = *localtime(&t);

                    FILE* fpointer;
                    fpointer=fopen("Conversion Log.txt","a");
                    fprintf(fpointer,"\n Conversion Successful on %d-%d-%d at %d:%d:%d\n",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
                    fprintf(fpointer, "%s\n", A);
                    fclose(fpointer);
                    }
                
                else
                if(d=='n')
                    {
                    printf("Conversion not logged.\n");
                    printf("\n");
                    }
                }

            if(size>140)
                {
                printf("The message cannot be converted into a tweet\n");
                printf("\n");

                printf("Do you want to log this conversion ?(Enter y for Yes or n for No): \n");
                scanf(" %c", &d);

                if(d=='y')
                    { 
                    time_t t = time(NULL);
                    struct tm tm = *localtime(&t);

                    FILE* fpointer;
                    fpointer=fopen("Conversion Log.txt","a");
                    fprintf(fpointer,"\n Conversion Failed on %d-%d-%d at %d:%d:%d\n",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
                    fprintf(fpointer, "%s\n", A);
                    fclose(fpointer);
                    }
                
                else
                if(d=='n')
                    {
                    printf("Conversion not logged.\n");
                    printf("\n");
                    }
                }
            break;
        
            case 2:
            printf("Enter the Tweet:\n");
            scanf("%s",B); 
            Insert(B);
            printf("Tweet added succesfully\n");
            printf("\n");
            break;
        
            case 3:
            temp=head;
            fp=fopen("Words.txt","w");

            while(temp!=NULL)
                {
                fprintf(fp,"%s\n" ,(*temp).Word);
                fprintf(fp,"%s\n" ,(*temp).Meaning);
                fprintf(fp,"\n");
                temp=(*temp).next;
                }
            fclose(fp);
            break;

            case 4:
            head=NULL;

            fp=fopen("Words.txt","r");

            while(!feof(fp))
                {
                temp=(struct Node*)malloc(sizeof(struct Node));

                fscanf(fp,"%s\n",(*temp).Word);
                fscanf(fp,"%[^\n]s",(*temp).Meaning);

                if(feof(fp))
                    {
                    break;
                    }

                (*temp).next=head;
                head=temp;
                }    
            
            fclose(fp);
            break;

            case 5:
            break;

            default:
            printf("Invalid option. Please try again.\n");
            printf("\n");
            }
        }
    return 0;
}




