#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>



void addrecord();
void propertylist();
void search();
void findProperties();
void initiate_transaction();
void delete_record();
void user_profile();
void exit();
void add_property();
void list_properties();
void delete_property();
void delete_seller();
void display_seller();
void display_buyer();
void z();
void display_transaction();
void display_property();
void delete_buyer();
void delete_agent();
void display_logged_in_user();


typedef struct property {
    char address[50];
    int price;
    int area;
    int bedrooms;
    int bathrooms;
    int parking;
    int year_built;
    int year_renovated;
    int property_id;
    int seller_id;
    int buyer_id;
    int agent_id;
    int transaction_id;
    int status;
    char type[20];
    char location[20];
    char description[100];
    char seller[20];
    char buyer[20];
    char agent[20];
    char transaction[20];
    int plot_area;
    int plot_length;
    int plot_width;
    int plot_size;
    int garages;
    int storey;
    int pool;
    int garden;
    int balcony;
    int furnished;
    int security;
    int lift;
    int gym;
    char has_garden[20];
    char has_pool[20];
    char has_balcony[20];
    char has_furnished[20];
    char has_security[20];
    char has_lift[20];
    char has_gym[20];
    char has_garages[20];
    
} Property;


typedef struct User {
    char first_name[20];
    char last_name[20];
    char Address[20];
    int Mobile_no;
    char Property_holding[20];
    char total_property[50];
    char email[20];
    int num_properties;
    int num_transactions;
    int num_agents;
    int num_sellers;
    int num_buyers;
    char properties[10];
    char transactions[10];
    char agents[10];
    char sellers[10];
    char buyers[10];
    bool is_logged_in;
} User;



typedef struct buyer {
    char name[20];
    int budget;
    int min_area;
    char first_name[20];
    char last_name[20];
    char Address[20];
    int Mobile_no;
    char Property_holding[20];
    char total_property[50];
    char email[20];
    int num_properties;
    int num_transactions;
    int num_agents;
    int num_sellers;
    int num_buyers;
    char properties[10];
    char transactions[10];
    char agents[10];
    char sellers[10];
    char buyers[10];

} Buyer;

typedef struct seller {
    char name[20];
    int num_properties;
    Property properties[10];
    char first_name[20];
    char last_name[20];
    char Address[20];
    int Mobile_no;
    char Property_holding[20];
    char total_property[50];
    char email[20];
} Seller;

typedef struct transaction {
    Seller seller;
    Property property;
    Buyer buyer;
    char first_name[50];
    char last_name[50];
    char Address[20];
    int Mobile_no;
    char Property_holding[20];
    char total_property[50];
} Transaction;

struct agent
{
    char first_name[20];
    char last_name[20];
    char Address[20];
    int Mobile_no;
    char Property_holding[20];
    char total_property[50];
};

struct Property
{
    char location[50];
    int price;
    int size;
    int bedrooms;
};


typedef struct agent agent[10];
int num_agents = 0;


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
            findProperties();
            break;
        case 4:
            list_properties();
            break;
        case 5:
            delete_record();
            break;
        case 99:
            user_profile();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Invalid Choice");
        }
    }
}

void addrecord()
{
    char first_name[20], last_name[20], address[50], another, Property_holdings[50], total_property[50];
    int mobile_no;
    FILE *fp;
    fp = fopen("addrecord.txt", "w");

    if (fp == NULL)
    {
        printf("Cannot open file");
        exit(0);
    }

    do
    {
        fp = fopen("addrecord.txt", "a");
        printf("\t\t\t\t\nAdd New Record\t\t\t\t");
        printf("\nEnter the user first name: ");
        scanf("%c", first_name); // first name
        printf("\nEnter the user last name: ");
        scanf("%c", last_name); // last name
        printf("\nEnter the user Address: ");
        scanf("%c", address); // address
        printf("\nEnter the user Mobile No.: ");
        scanf("%d", &mobile_no); // Mobile No.
        printf("\nEnter the users Property Holdings: ");
        scanf("%c", Property_holdings); // propert holdings
        printf("\nEnter the user total property: ");
        scanf("%c", total_property); // total property
        fclose(fp);
        printf("\t\t\t\t \nDo you want to add any other record?(y/n)"); // To add another record
        scanf("\n%s", &another);


    } while (another == 'y' || another == 'Y');

    // fclose(fp);

    printf("\t\t\t\t \nRecord added successfully");

    printf("\t\t\t\t \nPress any key to continue");
    // getch();

    system("cls");

    main();

    

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
        scanf("%s", propertyList[i].location);
        printf("\nEnter price:");
        scanf("%d", &propertyList[i].price);
        printf("\nEnter size (in sq ft):");
        scanf("%d", &propertyList[i].size);
        printf("\nEnter number of bedrooms:");
        scanf("%d", &propertyList[i].bedrooms);
    }
}

// void findProperties(struct Property propertyList[], int numProperties, int maxPrice, int minSize, int minBedrooms){
//     printf("\nMatching properties:\n");

//     for(int i=0; i<numProperties; i++){
//         if(propertyList[i].price <= maxPrice && propertyList[i].size >= minSize && propertyList[i].bedrooms >= minBedrooms){
//             printf("\nLocation: %s", propertyList[i].location);
//             printf("\nPrice: $%d", propertyList[i].price);
//             printf("\nSize: %d sq ft", propertyList[i].size);
//             printf("\nBedrooms: %d\n", propertyList[i].bedrooms);

//         }
//     }
// }


// //Implement a function for adding a new property to a seller's list of properties:


// void add_property(Seller *seller, Property property) {
//     seller->properties[seller->num_properties] = property;
//     seller->num_properties++;
// }

// //Implement a function for listing all available properties that meet a buyer's requirements:


// void list_properties(Buyer buyer, Seller *sellers, int num_sellers) {
//     for (int i = 0; i < num_sellers; i++) {
//         for (int j = 0; j < sellers[i].num_properties; j++) {
//             if (sellers[i].properties[j].price <= buyer.budget &&
//                 sellers[i].properties[j].area >= buyer.min_area) {
//                 printf("Address: %s\nPrice: %d\nArea: %d\n", 
//                        sellers[i].properties[j].address,
//                        sellers[i].properties[j].price,
//                        sellers[i].properties[j].area);
//             }
//         }
//     }
// }

// //Implement a function for initiating a transaction between a buyer and seller for a specific property:


// void initiate_transaction(Buyer buyer, Seller seller, Property property) {
//     Transaction transaction = {seller, property, buyer};
//     transactions[num_transactions] = transaction;
//     num_transactions++;

//     // Remove the property from the seller's list of properties
//     for (int i = 0; i < seller.num_properties; i++) {
//         if (strcmp(seller.properties[i].address, property.address) == 0) {
//             for (int j = i + 1; j < seller.num_properties; j++) {
//                 seller.properties[j-1] = seller.properties[j];
//             }
//             seller.num_properties--;
//             break;
//         }
//     }

//     // Deduct the price of the property from the buyer's budget
//     buyer.budget -= property.price;
// }

// //Implement a function for displaying all transactions that have been initiated:


// void display_transactions() {
//     for (int i = 0; i < num_transactions; i++) {
//         printf("Seller: %s %s (%s) - %s - %d - %d - %d - %d - %d - %d - %d - %s )\n", 
//                transactions[i].seller.first_name,
//                transactions[i].seller.last_name,
//                transactions[i].seller.email,
//                transactions[i].seller.properties[0].address,
//                transactions[i].seller.properties[0].price,
//                transactions[i].seller.properties[0].area,
//                transactions[i].seller.properties[0].bedrooms,
//                transactions[i].seller.properties[0].bathrooms,
//                transactions[i].seller.properties[0].garages,
//                transactions[i].seller.properties[0].year_built,
//                transactions[i].seller.properties[0].plot_size,
//                transactions[i].seller.properties[0].has_pool);
//         printf("Buyer: %s %s (%s) - %d)\n",
//                 transactions[i].buyer.first_name,
//                 transactions[i].buyer.last_name,
//                 transactions[i].buyer.email,
//                 transactions[i].buyer.budget);
//     }
// }


// //Implement a function for displaying all properties that are currently available for sale:


// void display_properties(Seller *sellers, int num_sellers) {
//     for (int i = 0; i < num_sellers; i++) {
//         for (int j = 0; j < sellers[i].num_properties; j++) {
//             printf("Address: %s\nPrice: %d\nArea: %d\n", 
//                    sellers[i].properties[j].address,
//                    sellers[i].properties[j].price,
//                    sellers[i].properties[j].area);
//         }
//     }
// }

// //Implement a function for displaying all sellers:


// void display_sellers(Seller *sellers, int num_sellers) {
//     for (int i = 0; i < num_sellers; i++) {
//         printf("Name: %s %s\nEmail: %s\n", 
//                sellers[i].first_name,
//                sellers[i].last_name,
//                sellers[i].email);
//     }
// }


// //Implement a function for displaying all buyers:


// void display_buyers(Buyer *buyers, int num_buyers) {
//     for (int i = 0; i < num_buyers; i++) {
//         printf("Name: %s %s\nEmail: %s\n", 
//                buyers[i].first_name,
//                buyers[i].last_name,
//                buyers[i].email);
//     }
// }

// //Implement a function for displaying all users:


// void display_users(User *users, int num_users) {
//     for (int i = 0; i < num_users; i++) {
//         printf("Name: %s %s\nEmail: %s\n", 
//                users[i].first_name,
//                users[i].last_name,
//                users[i].email);
//     }
// }

// //Implement a function for displaying all users that are currently logged in:


// void display_logged_in_users(User *users, int num_users) {
//     for (int i = 0; i < num_users; i++) {
//         if (users[i].is_logged_in) {
//             printf("Name: %s %s\nEmail: %s\n", 
//                    users[i].first_name,
//                    users[i].last_name,
//                    users[i].email);
//         }
//     }
// }

void exit_program() {
    printf("Exiting program...\n");
    exit(0);
}