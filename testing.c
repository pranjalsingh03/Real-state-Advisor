#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

void addNewRecord();
void display_packages();

struct addrecord 
{
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    char propertyType[50];
    char propertyLocation[50];
    char propertyPrice[50];
    char propertySize[50];
    char propertyStatus[50];
    char propertyDescription[100];
    char propertyImage[100];
    char propertyDate[50];
    int propertyID;
    char another;
} add;


int main()
{
    int choice = 0;
    while (choice != 7)
    {
        printf("\n[1] Add New Record\n");
        printf("[2] Property Listing\n");
        printf("[3] Search\n");
        printf("[4] Buy/sell\n");
        printf("[5] Delete Record\n");
        printf("[99] User Profile\n");
        printf("[0] Exit\n");
        printf("Select Any Option from above: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addNewRecord();
            
        case 2:
            display_packages();
            // printf("Property Listing\n");
            break;
        case 3:
            printf("Search\n");
            break;
        case 4:
            printf("Buy/sell\n");
            break;
        case 5:
            printf("Delete Record\n");
            break;
        case 99:
            printf("User Profile\n");
            break;
        case 0:
            printf("Exit\n"); 
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}

void addNewRecord()
{
    struct addrecord add;
    FILE *fp;
    
    // fwrite("addrecord.txt", sizeof(struct addrecord), 1, fp);
    // fprintf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %d", add.name, add.address, add.phone, add.email, 
    // add.propertyType, add.propertyLocation, add.propertyPrice, add.propertySize, add.propertyStatus, 
    // add.propertyDescription, add.propertyImage, add.propertyDate, add.propertyID);

    do
    {
        printf("Add New Record\n");
        printf("Enter Name: ");
        scanf("%s", add.name);
        printf("Enter Address: ");
        scanf("%s", add.address);
        printf("Enter Phone: ");
        scanf("%s", add.phone);
        printf("Enter Email: ");
        scanf("%s", add.email);
        printf("Enter Property Type: ");
        scanf("%s", add.propertyType);
        printf("Enter Property Location: ");
        scanf("%s", add.propertyLocation);
        printf("Enter Property Price: ");
        scanf("%s", add.propertyPrice);
        printf("Enter Property Size: ");
        scanf("%s", add.propertySize);
        printf("Enter Property Status: ");
        scanf("%s", add.propertyStatus);
        printf("Enter Property Description: ");
        scanf("%s", add.propertyDescription);
        printf("Enter Property Image: ");
        scanf("%s", add.propertyImage);
        printf("Enter Property Date: ");
        scanf("%s", add.propertyDate);
        printf("Enter Property ID: ");
        scanf("%d", &add.propertyID);
        printf("Do you want to add another record? (y/n): ");
        scanf("%s", &add.another);

    } while (add.another == 'y' || add.another == 'Y');
        printf("\t\t\t\t\t Record Added Successfully\n");
    fp = fopen("pacakage.dat.", "f");
    if (fp == NULL)
    {
        printf("Error opening file: ");
        exit(0);
    }
        fwrite(&add, sizeof(add), 1, fp);

    printf("\nPackage added successfully!\n");

    fclose(fp);
}

void display_packages() {
    //Code to display all packages in the system
    struct addrecord add;
    FILE *fp;

    fp = fopen("pacakage.dat.", "f");
    if(fp == NULL) {
        printf("Error opening file!");
        return;
    }

    printf("\nID\tSender\tReceiver\tWeight\tStatus\n");
    printf("--------------------------------------------------\n");

    while(fread(&add, sizeof(add), 1, fp)) {
        printf("%s\t%s\t%s\t%.2f\t%s\n", add.name, add.propertyID, add.propertyLocation, add.propertyPrice, add.propertyStatus);
    }

    fclose(fp);
}