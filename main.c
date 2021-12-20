#include "string_prog.h"
#include <stdio.h>
#include <ctype.h>

#define TXT 1024
#define WORD 30

typedef enum bool {
	True=1,
	False=0
	}bool;
int main(){
char word[WORD+1];
char text[TXT+1];

int word_counter=0;
int text_counter=0;
bool is_word=True;
char c;
while(c!='~'){
    c =getchar();
    if(is_word){
        if(isspace(c)){
            word[word_counter]='\0';
            is_word=False;
        }else{
            word[word_counter]=c;
            word_counter+=1;
        }
    }else{
            text[text_counter]=c;
            text_counter+=1;
        }
}
text[text_counter]='\0';
print_same_gimmetry(word_counter,text_counter,word,text);
print_atbash(word_counter,text_counter,word,text);
print_minimum_contains(word_counter,text_counter,word,text);
}
