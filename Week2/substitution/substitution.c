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

int only_letters(char *s){
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        if (!isalpha(*(s + i))){
            return 0;
        }
    }
    return 1;
}

char substitute(char c, char *subs){
    if (isalpha(c)){
        char output;
        if (islower(c)){
            output = tolower(subs[c - 'a']);
        }
        else {
            output = toupper(subs[c - 'A']);
        }
        return output;
    }
    return c;
}

int main(int argc, char *argv[]) {
    if (argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!only_letters(argv[1])){
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26){
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    printf("Plaintext: ");
    char *text = get_string();
    int len = strlen(text);
    printf("ciphertext: ");
    for (int i = 0; i < len; i++){
        printf("%c", substitute(*(text + i), argv[1]));
    }
    return 0;
}