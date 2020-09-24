#include <stdio.h>
#include <stdlib.h>

int main() {

    int option = 0;

    while(option != 5) {
        printf("(1)\n");
        printf("(2)\n");
        printf("(3)\n");
        printf("(4)\n");
        printf("(5)\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n1\n");
            break;
            case 2:
                printf("\n2\n");
            break;
            case 3:
                printf("\n3\n");
            break;
            case 4:
                printf("\n4\n");
            break;
            default:
                break;
        }
    }

    return 0;
}