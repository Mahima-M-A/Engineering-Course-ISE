#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int checksum(char data[30]){
    int buf[25];
    int i,sum=0,n,temp,temp1;
    if(strlen(data)%2!=0)
        n=(strlen(data)+1)/2;
    else
        n=(strlen(data))/2;

    for(i=0;i<n;i++){
        temp=data[i*2];
        temp=(temp*256)+data[(i*2)+1];
        printf("\n%x",temp);
        sum=sum+temp;
    }
    if(sum%65536!=0){
        n=sum%65536;
        sum=(sum/65536) + n;
    }
    printf("\nSum= %x",sum);

    sum=65535-sum;
    return sum;
}

int main(){
    char data[30];
    int csum,ch;
    printf("\nEnter data: ");
    scanf("%s",data);
    
    printf("\nOriginal data: %s",data);
    csum=checksum(data);
    printf("\nChecksum to append: %x",csum);
    
    printf("\nEnter \n0 for erroneous data \n1 for error free data: ");
    scanf("%d",&ch);
    if(ch==0){
        srand(time(0));
        int r=rand()%strlen(data);
        data[r]++;
    }
    printf("\nNew data: %s",data);
    int ncsum=checksum(data);
    int check=csum-ncsum;
    printf("\nValidated checksum: %x",check);
    if(check!=0){
        printf("\nError is detected!");
    }
    else{
        printf("\nNo Error is detected!");
    }
}
