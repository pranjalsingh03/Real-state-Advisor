#include <stdio.h>


void addrecord();
void propertylist();

struct agent{
    char first_name[20];
    char last_name[20];
    char Address[20];
    int Mobile_no;
    char Property_holding[20];
    int total_property;
};

int main() {
    int choice;
    while (choice!=7){
    printf("\033[1;34m");                                                      // set text color to blue
    printf("\033[48;5;11m");                                                   // set background color to light blue
    printf("************************************************************\n");
    printf("*                                                          *\n");
    printf("*                WELCOME TO MY REAL ESTATE ADVISOR          *\n");
    printf("*                                                          *\n");
    printf("************************************************************\n");
    printf("\033[0m");                                                        // reset text and background color
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
        addrecord();
        break;
    case 2:
        propertylist();
        break;
        }
    
    }
}

void addrecord(){
    char first_name[20],last_name[20],address[50] ,another, Property_holdings[50], total_property[50];
    int mobile_no;
    FILE *fp;
    fp = fopen("addrecord.txt","w");

    do
    {
        fp=fopen("addrecord.txt","a");
        printf("\t\t\t\t\nAdd New Record\t\t\t\t");
        printf("\nEnter the user first name: ");
        scanf("%s", &first_name);                   //first name
        printf("\nEnter the user last name: ");
        scanf("%s",&last_name);                    //last name
        printf("\nEnter the user Address: ");
        scanf("%s",&address);                      //address
        printf("\nEnter the user Mobile No.: ");
        scanf("%d",&mobile_no);                    //Mobile No.
        printf("\nEnter the users Property Holdings: ");
        scanf("%s",&Property_holdings);            //propert holdings
        printf("\nEnter the user total property: ");
        scanf("%s",&total_property);               //total property
        fclose(fp);
        printf("\t\t\t\t \nDo you want to add any other record?(y/n)");     //To add another record
        scanf("\n%s",&another);
    } while (another=='y' || another=='Y');
    
    
}
void propertylist(){

}

