#include <stdio.h>


void addrecord();

struct addrecord
{
    char first_name[20];
    char last_name[20];
    char Address[20];
    int Mobile_no;
    char Property_holding[20];
    int total_property;
};



void main() {
    int choice;
    while (choice!=7){
    printf("\033[1;34m"); // set text color to blue
    printf("\033[48;5;11m"); // set background color to light blue
    printf("************************************************************\n");
    printf("*                                                          *\n");
    printf("*                WELCOME TO MY REAL ESTATE ADVISOR          *\n");
    printf("*                                                          *\n");
    printf("************************************************************\n");
    printf("\033[0m"); // reset text and background color
    printf("\n[1] Add New Record\n");
    printf("[2] Property Listing\n");
    printf("[3] Search\n");
    printf("[4] Buy/sell\n");
    printf("[5] Delete Record\n");
    printf("[99] User Profile\n");
    printf("[0] Exit\n");
    printf("Select Any Option from above: ");
    scanf("%d",&choice);

    switch (choice){
    case 1:
        clrscr();
        addrecord();
        break;
        }
    }
}


void addrecord(){
    char another;
    FILE *fp;
    struct addrecord;
    do{
        clrscr();
        printf("\t\t\t\tAdd New Record\t\t\t\t");
        fp=fopen("addrecord.txt","a");
        printf("Enter the user first name: ");       
        scanf("%s",&info.first_name);                   //first name
        printf("\nEnter the user last name: ");
        scanf("%s",&info.last_name);                    //last name
        printf("\nEnter the user Address: ");
        scanf("%s",&info.Address);                      //address
        printf("\nEnter the user Mobile No.: ");
        scanf("%d",&info.Mobile_no);                    //Mobile No.
        printf("\nEnter the users Property Holdings: ");
        scanf("%s",&info.Property_holdings);            //propert holdings
        printf("\nEnter the user total property: ");
        scanf("%s",&info.total_property);               //total property

        if (fp=NULL){
            fprintf(stderr."\t\t\t\tCan't Access the user details");
        }
        else{
            printf("Record sucessfully Submitted\n");
        }
        fwrite(&info,sizeof(struct addrecord),1,fp);
        fclose(fp);
        printf("\t\t\t\t Do you want to add any other record?(y/n)");
        scanf("%s",&another);
    }while (another=='y'|| another='Y');

}