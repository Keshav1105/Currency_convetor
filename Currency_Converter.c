#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct currency
{
	float currencyvalue;
	char currencyname[10];
};

float search(struct currency s[],int n,char asd[])
{
    float val = -1;
    for(int i=0;i<n;i++)
    {
        if(strcmp(s[i].currencyname,asd)==0)
            {
                val = s[i].currencyvalue;
                break;
            }
    }
    return val;
}

void disp(struct currency s[],int n)
{
	for(int i=0;i<n;i++)
		printf("%s\t%f\n",s[i].currencyname,s[i].currencyvalue);
}

int main()
{
    float amount,first,second,final;
    
    struct currency s[100];
    int i=0;
    FILE* fp = fopen("value.csv", "r");

    if (fp==NULL)
		printf("Can't open file\n");

	else 
	{
		char buffer[1024];
        while(fgets(buffer,100,fp)!=NULL)
	    {
		    char *va=strtok(buffer,",");
		    s[i].currencyvalue=atof(va);
            char *na=strtok(NULL,",");
            if(na[strlen(na)-1] == '\n')
            {
                na[strlen(na)-1]='\0';
            }
		    strcpy(s[i].currencyname,na);
            i++;
	    }
        fclose(fp);
    }

    int n=i;
    disp(s,n);
    char taken[10];

    printf("\nEnter input currency:");
    gets(taken);
    first=search(s,n,taken);

    while (first==(-1))
    {
        printf("\nCurrency not exist \nEnter valid Currency\n");
        printf("\nEnter input currency:");
        gets(taken);
        first=search(s,n,taken);
    }

    char output[10];
    printf("\nEnter output currency:");
    gets(output);
    second=search(s,n,output);

    while(second==(-1))
    {
        printf("\nCurrency not exist \nEnter valid Currency\n");
        printf("\nEnter output currency:");
        gets(output);
        second=search(s,n,output);
    }

    printf("\nEnter amount:");
    scanf("%f",&amount);  
    final=(amount*first)/second;
    printf("\n%.3f %s is %.3f %s",amount,taken,final,output);

    return 0;
}