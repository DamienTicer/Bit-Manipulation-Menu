#include <stdio.h>

void printBits(int num);
void setBit(int *num, int pos);
void clearBit(int *num, int pos);

int main() {
    int num = 0;
    int choice, pos;

    do {
        printf("Menu:\n");
        printf("1: Set a bit\n");
        printf("2: Clear a bit\n");
        printf("3: Print the integer\n");
        printf("4: Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the position of the bit to set: ");
                scanf("%d", &pos);
                setBit(&num, pos);
                break;
            case 2:
                printf("Enter the position of the bit to clear: ");
                scanf("%d", &pos);
                clearBit(&num, pos);
                break;
            case 3:
                printf("The current integer is: %d\n", num);
                printf("In binary: ");
                printBits(num);
                printf("\n");
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

    } while(choice != 4);

    return 0;
}

void printBits(int num) {
    int i;
    for(i = 31; i >= 0; i--) {
        if(num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

void setBit(int *num, int pos) {
    *num |= (1 << pos);
}

void clearBit(int *num, int pos) {
    *num &= ~(1 << pos);
}
