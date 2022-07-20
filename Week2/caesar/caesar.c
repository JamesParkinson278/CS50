#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *get_string(){
    int max = 255;
    char *text = (char *) malloc(sizeof(char)*max);

    int len = 0;
    char ch;
    do {
        ch = getchar();
        text[len++] = ch;
        if (len == max){
            max *= 2;
            char *tmp = text;
            text = (char *) malloc(sizeof(char)*max);
            for (int i = 0; i < len; i++){
                text[i] = tmp[i];
            }
            free(tmp);
        }

    } while (ch != '\n');
    return text;
}

int only_digits(char *s){
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        if (!isdigit(*(s + i))){
            return 0;
        }
    }
    return 1;
}

char rotate(char c, int k){
    if (isalpha(c)){
        char off;
        if (islower(c)){
            off = 'a';
        }
        else {
            off = 'A';
        }
        return ((c - off + k) % 26) + off;
    }
    return c;
}

int main(int argc, char *argv[]) 
{
    if (argc != 2){
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (!only_digits(argv[1])){
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int k = atoi(argv[1]);

    printf("Plaintext: ");
    char *text = get_string();
    int len = strlen(text);
    printf("ciphertext: ");
    for (int i = 0; i < len; i++){
        printf("%c", rotate(*(text + i), k));
    }
    return 0;
}