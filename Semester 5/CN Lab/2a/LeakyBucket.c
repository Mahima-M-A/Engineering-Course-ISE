#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x

int main(){
    int rate=10,drop=0,cap=100,x,count=0,inp[10]={0},i=0,nsec,ch;
    printf("\n Bucket size : %d",cap);
    printf("\n Output rate : %d",rate);
      
    do{
        srand(time(0));
        inp[i]=rand()%200;
        printf("\n Number of packets coming at second %d : %d",(i+1),inp[i]);
        i++;
        printf("\n Enter 1 to continue or 0 to quit..........");
        scanf("%d",&ch);
    }while(ch);
    
    nsec=i;
    printf("\n   Second \t   recieved \t       sent \t   dropped \t   remaining \n");
    for(i=0;count || i<nsec;i++){
        printf("\t%d\t",i+1);
        printf("\t%d\t",inp[i]);
        printf("\t%d\t",MIN((inp[i]+count),rate));
        if((x=inp[i]+count-rate)>0){
            if(x>cap){
                count=cap;
                drop=x-cap;
            }
            else{
                count=x;
                drop=0;
            }
        }
        else{
            drop=0;
            count=0;
        }
        printf("\t%d\t\t%d\n",drop,count);
    }
    return 0;
}      
