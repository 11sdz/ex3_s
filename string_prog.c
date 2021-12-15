#include<stdio.h>
#include<ctype.h>
#include <stdlib.h>

typedef enum bool {
	True=1,
	False=0
	}bool;

int sum_word(int size, char word[size]){
    int i=0;
    int sum=0;
    while(word[i]!='\0'){
        if(isupper(word[i])==1){
            int c= (int) word[i]- (int)'A';
            c=c+1;//A = 1
            sum=sum+c;
        }else{
            int c= (int) word[i]- (int)'a';
            c=c+1;//a = 1
            sum=sum+c;
        }
        i+=1;
    }
    return sum;
}

void print_specific_word(int i, int j, int size ,char text[size]){
    while(j<i){
        printf("%c",text[j]);
        j+=1;
    }
}

void print_same_gimmetry(int word_size ,int text_size,char word[word_size], char text[text_size]){
    int sum=sum_word(word_size , word);
    printf("sum= %d\n",sum);
    int cur_sum=0;
    int i=0;
    int j=0;
    bool first_print=True;
    while(text[i]!='\0'){
        if(isupper(text[i])==1){
            int c= (int) text[i]- (int)'A';
            c=c+1;//A = 1
            cur_sum=cur_sum+c;
            i++;
        }else if(islower(text[i])){
            int c= (int) text[i]- (int)'a';
            c=c+1;//a = 1
            cur_sum=cur_sum+c;
            i++;
        }else{
            i++;
        }
        if(cur_sum==sum){
            if(first_print==False){
                printf("~");
            }
            print_specific_word(i,j,text_size,text);
            if(first_print==True){
                printf("~");
                first_print=False;
            }
            cur_sum=0;
            j=j+1;
            while(isspace(text[j])){
                j+=1;
            }
            i=j;
        }else if(cur_sum>sum){
            cur_sum=0;
            j=j+1;
            while(isspace(text[j])){
                j+=1;
            }
            i=j;
        }
    }
    printf("\n");
}

void copy_attbash(int size, char word[size], char word_atbsh[size]){
    int i=0;
    while(word[i]!='\0'){
        if(isupper(word[i])){
            int asci_val=(int)word[i]-(int)'Z';
            asci_val=abs(asci_val)+(int)'A';
            word_atbsh[i]=(char) asci_val;
        }else if(islower(word[i])){
            int asci_val=(int)word[i]-(int)'z';
            asci_val=abs(asci_val)+(int)'a';
            word_atbsh[i]=(char) asci_val;
        }
        i+=1;
    }
    word_atbsh[i]=word[i];
}

void print_atbash(int word_size ,int text_size,char word[word_size], char text[text_size]){
    char word_atbsh[word_size];
    copy_attbash(word_size,word,word_atbsh);
    printf("%s %s \n",word_atbsh,word);
    int i=0;
    int j=0;
    bool first_print=True;
    while(text[i]!='\0'){
    }
    printf("\n");
}

// void print_minimum_contains(int word_size ,int text_size,char word[word_size], char text[text_size]);