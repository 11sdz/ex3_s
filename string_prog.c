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
        if(isupper(word[i])){
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
    int cur_sum=0;
    int i=0;
    int j=1;
    bool first_print=True;
    printf("Gematria Sequences: ");
    while(text[i]!='\0'){
        if(isupper(text[i])){
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
            if(first_print){
                first_print=False;
                print_specific_word(i,j,text_size,text);
            }else{
                printf("~");
                print_specific_word(i,j,text_size,text);
            }
            cur_sum=0;
            j=j+1;
            while(isspace(text[j]) || (!islower(text[j]) && !isupper(text[j]))){
                j+=1;
            }
            i=j;
        }else if(cur_sum>sum){
            cur_sum=0;
            j=j+1;
            while(isspace(text[j]) || (!islower(text[j]) && !isupper(text[j]))){
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
    printf("Atbash Sequences: ");
    char word_atbsh[word_size];
    copy_attbash(word_size,word,word_atbsh);
    // printf("%s -- %s \n",word_atbsh,word);
    int last_char_index=word_size-1;
    bool flag=False;
    bool first_print=True;
    int counter=-1;
    for(int i=0;i<text_size;i++){
        if(word_atbsh[last_char_index]==text[i]){
            int index=last_char_index-1;
            for(int j=i+1;j<text_size;j++){
                if(islower(text[j]) || isupper(text[j])){
                    if(text[j]==word_atbsh[index]){
                         index-=1;
                    }else{
                        break;
                    }
                }else{
                    continue;
                }
                if(index==0-1){
                    flag=True;
                    counter=j+1;
                    break;
                }
            }
        }
        if(word_atbsh[0]==text[i]){
            int index=1;
            for(int j=i+1;j<text_size;j++){
                if(islower(text[j]) || isupper(text[j])){
                    if(text[j]==word_atbsh[index]){
                        index+=1;
                    }else{
                        break;
                    }
                }else{
                    continue;
                }
                if(index==last_char_index+1){
                    flag=True;
                    counter=j+1;
                    break;
                }
            }
        }
        if(flag){
            flag=False;
            if(first_print){
                first_print=False;
                print_specific_word(counter,i,text_size,text);
            }else{
            printf("~");
            print_specific_word(counter,i,text_size,text);
            }
        }
    }
    printf("\n");
}

void initialize_counter(int size_word, char word[size_word],int counter[130]){
    for (int i=0;i<130;i++){
        counter[i]=0;
    }
    for(int i=0;i<=size_word;i++){
        int index= (int)word[i];
        counter[index]+=1;
    }
}

void print_minimum_contains(int word_size ,int text_size,char word[word_size], char text[text_size]){
    int counter[130];
    printf("Anagram Sequences: ");
    bool to_print=False;
    bool first_print=True;
    int end=-1;
    for(int i=0;i<text_size;i++){
        initialize_counter(word_size,word,counter);
        int index=(int) text[i];
        if(islower(text[i]) || isupper(text[i])){
            if(counter[index]>0){
                int num_of_letters=word_size;
                for(int j=i;j<text_size;j++){
                    if(!isspace(text[j])){
                    if(islower(text[i]) || isupper(text[i])){
                        index=(int)text[j];
                        if(counter[index]==0){
                            to_print=False;
                            break;
                        }else{
                            counter[index]=counter[index]-1;
                            num_of_letters=num_of_letters-1;
                        }
                        if(num_of_letters==0){
                            to_print=True;
                            end=j+1;
                            break;
                        }
                    }else{
                        continue;
                    }
                }
                }
            }
        }
        if(to_print){
            if(first_print){
                first_print=False;
                print_specific_word(end,i,text_size,text);
            }else{
                printf("~");
                print_specific_word(end,i,text_size,text);
            }
        to_print=False;
        }
    }
}