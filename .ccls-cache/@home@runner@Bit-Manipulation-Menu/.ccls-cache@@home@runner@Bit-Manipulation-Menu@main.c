/*
Name: Damien Ticer
Date: 03/09/2023
Assignment Title: Assignment 4
*/
#include <stdio.h>

// function declarations
void printMenu();
void printBits(int num);
void setBit(int *num, int pos);
void clearBit(int *num, int pos);

int main() {
  int num = 0; // initialize num to 0
  int choice, pos;

  do {
    // print menu options
    printMenu();

    // read user's choice
    scanf("%d", &choice);

    // skip a line
    printf("\n");

    switch (choice) {
    case 1:
      // prompt user to enter bit position to set
      printf("Enter the position of the bit to set: ");
      // read bit position from user
      scanf("%d", &pos);
      // set bit at specified position
      setBit(&num, pos);
      // skip a line
      printf("\n");
      break;
    case 2:
      // prompt user to enter bit position to clear
      printf("Enter the position of the bit to clear: ");
      // read bit position from user
      scanf("%d", &pos);
      // clear bit at specified position
      clearBit(&num, pos);
      // skip a line
      printf("\n");
      break;
    case 3:
      // print current integer and binary representation
      printf("The current integer is: %d\n", num);
      printf("In binary: ");
      printBits(num);
      printf("\n");
      // skip a line
      printf("\n");
      break;
    case 4:
      // exit program
      printf("Exiting program...\n");
      break;
    default:
      // handle invalid input
      printf("Invalid choice.\n");
      // skip a line
      printf("\n");
      break;
    }

  } while (choice != 4);

  return 0;
}

// function to print the menu
void printMenu() {
  // print menu options
  printf("Menu:\n");
  printf("1: Set a bit\n");
  printf("2: Clear a bit\n");
  printf("3: Print the integer\n");
  printf("4: Exit the program\n");
  printf("Enter your choice: ");
}

// function to print binary representation of an integer
void printBits(int num) {
  int i;
  int printed = 0; // keep track of number of printed bits
  for (i = 31; i >= 0; i--) {
    if (num & (1 << i)) {
      printf("1");
      printed++;
    } else if (printed > 0) {
      // only print 0's after first printed 1
      printf("0");
    }
  }
}

// function to set a bit at a specified position in an integer
void setBit(int *num, int pos) {
  *num |= (1 << pos); // set bit at specified position to 1
}

// function to clear a bit at a specified position in an integer
void clearBit(int *num, int pos) {
  *num &= ~(1 << pos); // set bit at specified position to 0
}
