#include <stdio.h>

int main(void) 
{
    int height;
    do{
        printf("Height: ");
        scanf("%d", &height);
    } while(height <= 0 || height > 8);

    for (int i = 1; i <= height; i++){
        int j;
        for (j = 0; j < height - i; j++){
            printf(" ");
        }
        for (j; j < height; j++){
            printf("#");
        }
        printf(" ");
        for (int k = 0; k < i; k++){
            printf("#");
        }
        printf("\n");
    }
}