#include <stdio.h>


struct Property {
    int id;
    char name[100];
    char address[200];
    float price;
    char agent[100];
};

void buy(struct Property *database, int *count);
void sell(struct Property *database, int *count, int id);

int main() {
    int option;
    
    do {
        printf("REAL ESTATE ADVISOR\n");
        printf("-------------------\n");
        printf("1. Buy property\n");
        printf("2. Sell property\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("\nBUYING PROPERTY...\n");
                // Your buy property function code goes here
                break;
            case 2:
                printf("\nSELLING PROPERTY...\n");
                // Your sell property function code goes here
                break;
            case 3:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while(option != 3);
    
    return 0;
}
void buy(struct Property *database, int *count) {
    printf("Enter ID: ");
    scanf("%d", &database[*count].id);
    
    printf("Enter name: ");
    scanf("%s", database[*count].name);
    
    printf("Enter address: ");
    scanf("%s", database[*count].address);
    
    printf("Enter price: ");
    scanf("%f", &database[*count].price);
    
    printf("Enter agent: ");
    scanf("%s", database[*count].agent);
    
    (*count)++;
}

void sell(struct Property *database, int *count, int id) {
    int i, j;
    for (i = 0; i < *count; i++) {
        if (database[i].id == id) {
            for (j = i; j < *count - 1; j++) {
                database[j] = database[j + 1];
            }
            (*count)--;
            return;
        }
    }
    printf("Property with ID %d not found!\n", id);
}
