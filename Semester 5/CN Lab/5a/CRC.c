#include<stdio.h>
#include<string.h>

#define N strlen(g)  
char data[30],cs[30],b[250],r[7]; 

char g[] = "10001000000100001"; 
int a,e,c;

void rev(){
    int n=strlen(r)-1;
    int s=strlen(b);
    int i;
    for(i=n;i>=0;i--){
        b[s++]=r[i];
    }
}

void strtobin(){
    int n = strlen(data); 
    int k=0,i;
  
    for (i = 0; i < n; i++) { 
        // convert each char to ASCII value 
        strcpy(r,"");
        int val = (int)(data[i]); 
        char ch='1',ch1='0';
        // Convert ASCII value to binary 
        while (val > 0){ 
            (val % 2)? strncat(r,&ch,1) : strncat(r,&ch1,1); 
            val /= 2; 
        } 
        rev();
    } 
    printf("Entered data in binary: %s",b);
}

void xor(){
    for(c=1;c<N;c++)
        cs[c] = ((cs[c] == g[c]) ? '0' : '1');
}


void crc(){
    for(e=0;e<N;e++)
        cs[e] = b[e];

    do{
        if(cs[0] == '1'){
            xor(); 
        }
        
        for(c=0;c<N-1;c++)
            cs[c] = cs[c+1];

        cs[c] = b[e++];
    }while(e <= a+N-1); 

}

int main(){
    int ch;
    printf("\nEnter:\n0. to enter binary input\n1. to enter string input:");
    scanf("%d",&ch);
    if(ch==1){
        printf("\nEnter a string data: ");
        scanf("%s",data); 
        strtobin();
    }
    else{
        printf("\nEnter a binary data: ");
        scanf("%s",data);
        strcpy(b,data);
    }

    printf("\nGenerating Polynomial:\t %s",g); 
    
    a = strlen(b); 

    for(e=a;e<a+N-1;e++){
        b[e] = '0';
    }

    printf("\nPadded data is: %s",b);

    crc(); 

    printf("\nSyndrome or remainder is %s",cs);

    for(e=a;e<a+N-1;e++){
        b[e] = cs[e-a]; 
    }

    printf("\nFinal codeword is %s",b);

    printf("\nWant to test error detection. Press 0 for yes and 1 for no:\t");
    scanf("%d",&e);

    if(e == 0){
        srand(time(0));
        int pos=rand()%a;
        b[pos]=(b[pos]=='0')?'1':'0';
        printf("\nErroneous data: %s",b); 
    }

    crc(); 
           
    for(e=0;(e<N-1) && (cs[e] != '1');e++){
        printf("\n Checking... "); 
    }

    if(e<N-1){
        printf("\nError detected\n\n");
    }
    else{
        printf("\nNo error detected.");
    }
    return 0;
}
