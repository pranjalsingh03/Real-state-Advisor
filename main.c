#include <stdio.h>

int main() {
    printf("\033[1;34m"); // set text color to blue
    printf("\033[48;5;11m"); // set background color to light blue
    printf("************************************************************\n");
    printf("*                                                          *\n");
    printf("*                WELCOME TO MY REAL ESTATE ADVISOR          *\n");
    printf("*                                                          *\n");
    printf("************************************************************\n");
    printf("\033[0m"); // reset text and background color
    printf("\n[1] Add New Record\n");
    printf("[99] User Profile\n");
    printf("[2] Property Listing\n");
    printf("[3] Search\n");
    printf("[4] Buy/sell\n");
    printf("[5] Delete Record\n");
    printf("[0] Exit\n");
    printf("Select Any Option from above: ");
}