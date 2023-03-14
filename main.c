#include <stdio.h>



void addrecord();
void propertylist();
void search();
void findProperties();

typedef struct property {
    char address[50];
    int price;
    int area;
} Property;

typedef struct buyer {
    char name[20];
    int budget;
    int min_area;
} Buyer;

typedef struct seller {
    char name[20];
    int num_properties;
    Property properties[10];
} Seller;

typedef struct transaction {
    Seller seller;
    Property property;
    Buyer buyer;
} Transaction;

struct agent
{
    char first_name[20];
    char last_name[20];
    char Address[20];
    int Mobile_no;
    char Property_holding[20];
    int total_property;
};

struct Property
{
    char location[50];
    int price;
    int size;
    int bedrooms;
};

Seller sellers[10];
int num_sellers = 0;

Buyer buyers[10];
int num_buyers = 0;

Transaction transactions[100];
int num_transactions = 0;

int main()
{
    int choice;
    while (choice != 7)
    {
        printf("\033[1;34m");    // set text color to blue
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
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addrecord();
            break;
        case 2:
            propertylist();
            break;
        case 3:
            search();
        }
    }
}

void addrecord()
{
    char first_name[20], last_name[20], address[50], another, Property_holdings[50], total_property[50];
    int mobile_no;
    FILE *fp;
    fp = fopen("addrecord.txt", "w");

    do
    {
        fp = fopen("addrecord.txt", "a");
        printf("\t\t\t\t\nAdd New Record\t\t\t\t");
        printf("\nEnter the user first name: ");
        scanf("%c", &first_name); // first name
        printf("\nEnter the user last name: ");
        scanf("%c", &last_name); // last name
        printf("\nEnter the user Address: ");
        scanf("%c", &address); // address
        printf("\nEnter the user Mobile No.: ");
        scanf("%c", &mobile_no); // Mobile No.
        printf("\nEnter the users Property Holdings: ");
        scanf("%c", &Property_holdings); // propert holdings
        printf("\nEnter the user total property: ");
        scanf("%c", &total_property); // total property
        fclose(fp);
        printf("\t\t\t\t \nDo you want to add any other record?(y/n)"); // To add another record
        scanf("\n%s", &another);
    } while (another == 'y' || another == 'Y');
}
void propertylist()
{
    struct Property propertyList[100];
    int numProperties;

    printf("Enter the number of properties:");
    scanf("%d", &numProperties);

    for (int i = 0; i < numProperties; i++)
    {
        printf("\nProperty %d:", i + 1);
        printf("\nEnter location:");
        scanf("%s", &propertyList[i].location);
        printf("\nEnter price:");
        scanf("%d", &propertyList[i].price);
        printf("\nEnter size (in sq ft):");
        scanf("%d", &propertyList[i].size);
        printf("\nEnter number of bedrooms:");
        scanf("%d", &propertyList[i].bedrooms);
    }
}

void search()
{
}

void findProperties(struct Property propertyList[], int numProperties, int maxPrice, int minSize, int minBedrooms){
    printf("\nMatching properties:\n");

    for(int i=0; i<numProperties; i++){
        if(propertyList[i].price <= maxPrice && propertyList[i].size >= minSize && propertyList[i].bedrooms >= minBedrooms){
            printf("\nLocation: %s", propertyList[i].location);
            printf("\nPrice: $%d", propertyList[i].price);
            printf("\nSize: %d sq ft", propertyList[i].size);
            printf("\nBedrooms: %d\n", propertyList[i].bedrooms);
        }
    }
}

