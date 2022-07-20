#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int count_letters(char* text, int len){
    int num_letters = 0;
    for (int i = 0; i < len; i++){
        if (isalpha(*(text + i))){
            num_letters++;
        }
    }
    return num_letters;
}

int count_words(char* text, int len){
    if (len == 1) return 0;

    int num_words = 1;
    for (int i = 0; i < len; i++){
        if (*(text + i) == ' '){
            num_words++;
        }
    }
    return num_words;
}

int count_sentences(char* text, int len){
    int num_sentences = 0;
    for (int i = 0; i < len; i++){
        char c = *(text + i);
        if (c == '.' || c == '!' || c == '?'){
            num_sentences++;
        }
    }
    return num_sentences;
}asdf

int main() 
{
    int max = 255;
    char *text = (char *) malloc(sizeof(char)*max);
    printf("Enter some text: ");

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

    float num_letters = (float)count_letters(text, len);
    float num_words = (float)count_words(text, len);
    float num_sentences = (float)count_sentences(text, len);
    float L = num_letters / num_words * 100.0f;
    float S = num_sentences / num_words * 100.0f;
    float tmp = (0.0588f * L - 0.296f * S - 15.8f);
    int grade = round(0.0588f * L - 0.296f * S - 15.8f);

    printf("%d letters \n%d words \n%d sentences\n", (int)num_letters, (int)num_words, (int)num_sentences);

    if (grade >= 16){
        printf("Grade 16+\n");
    }
    else if (grade < 1){
        printf("Before Grade 1\n");
    }
    else{
        printf("Grade %d\n", grade);
    }

    free(text);
}