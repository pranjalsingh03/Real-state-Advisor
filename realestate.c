#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROPERTIES 100

void load_properties();
void save_properties();
void add_property();
void display_properties();
void search_properties();
void buy_property();
void sell_property();


struct property {
   int id;
   char type[20];
   char location[20];
   int area;
   int bedrooms;
   int budget;
   char status[10];
};

struct property properties[MAX_PROPERTIES];
int num_properties = 0;

int main() {
   int choice;
   load_properties();

   do {
      printf("Real Estate Advisor\n");
      printf("-------------------\n");
      printf("1. Add new property\n");
      printf("2. Display available properties\n");
      printf("3. Search for properties\n");
      printf("4. Buy a property\n");
      printf("5. Sell a property\n");
      printf("6. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      printf("\n");

      switch (choice) {
         case 1:
            add_property();
            break;
         case 2:
            display_properties();
            break;
         case 3:
            search_properties();
            break;
         case 4:
            buy_property();
            break;
         case 5:
            sell_property();
            break;
         case 6:
            save_properties();
            printf("Exiting program...\n");
            break;
         default:
            printf("Invalid choice, try again.\n");
            break;
      }

      printf("\n");
   } while (choice != 6);

   return 0;
}


void load_properties() {
   FILE *fp = fopen("properties.txt", "r");
   if (fp == NULL) {
      return;
   }
   while (!feof(fp)) {
      struct property p;
      fscanf(fp, "%d %s %s %d %d %d %s\n", &p.id, p.type, p.location, &p.area, &p.bedrooms, &p.budget, p.status);
      properties[num_properties++] = p;
   }
   fclose(fp);
}

void save_properties() {
   FILE *fp = fopen("properties.txt", "w");
   for (int i = 0; i < num_properties; i++) {
      fprintf(fp, "%d %s %s %d %d %d %s\n", properties[i].id, properties[i].type, properties[i].location, properties[i].area, properties[i].bedrooms, properties[i].budget, properties[i].status);
   }
   fclose(fp);
}


void add_property() {
   struct property p;
   printf("Enter property details:\n");
   printf("ID: ");
   scanf("%d", &p.id);
   printf("Type: ");
   scanf("%s", p.type);
   printf("Location: ");
   scanf("%s", p.location);
   printf("Area: ");
   scanf("%d", &p.area);
   printf("Bedrooms: ");
   scanf("%d", &p.bedrooms);
   printf("Budget: ");
   scanf("%d", &p.budget);
   strcpy(p.status, "Available");

   properties[num_properties++] = p;
   save_properties();
   printf("Property added successfully.\n");
}

void display_properties() {
   printf("ID  Type              Location          Area  Bedrooms  Budget  Status\n");
   printf("---------------------------------------------------------------------\n");
   for (int i = 0; i < num_properties; i++) {
      if (strcmp(properties[i].status, "Available") == 0) {
         printf("%-4d%-18s%-18s%-6d%-10d%-8d%s\n", properties[i].id, properties[i].type, properties[i].location, properties[i].area, properties[i].bedrooms, properties[i].budget, properties[i].status);
      }
   }
}

void search_properties() {
   int min_area, min_bedrooms, max_budget;
   printf("Enter search criteria:\n");
   printf("Minimum area: ");
   scanf("%d", &min_area);
   printf("Minimum bedrooms: ");
   scanf("%d", &min_bedrooms);
   printf("Maximum budget: ");
   scanf("%d", &max_budget);

   printf("Search results:\n");
   printf("ID  Type              Location          Area  Bedrooms  Budget  Status\n");
   printf("---------------------------------------------------------------------\n");
   for (int i = 0; i < num_properties; i++) {
      if (strcmp(properties[i].status, "Available") == 0 &&
          properties[i].area >= min_area &&
          properties[i].bedrooms >= min_bedrooms &&
          properties[i].budget <= max_budget) {
         printf("%-4d%-18s%-18s%-6d%-10d%-8d%s\n", properties[i].id, properties[i].type,
                properties[i].location, properties[i].area, properties[i].bedrooms,
                properties[i].budget, properties[i].status);
      }
   }
}



void buy_property() {
   int id;
   printf("Enter property ID: ");
   scanf("%d", &id);

   for (int i = 0; i < num_properties; i++) {
      if (properties[i].id == id && strcmp(properties[i].status, "Available") == 0) {
         strcpy(properties[i].status, "Sold");
         save_properties();
         printf("Property bought successfully.\n");
         return;
      }
   }
   printf("Property not found or not available.\n");
}

void edit_property() {
   int id;
   printf("Enter property ID: ");
   scanf("%d", &id);

   for (int i = 0; i < num_properties; i++) {
      if (properties[i].id == id) {
         printf("Enter new property details:\n");
         printf("Type: ");
         scanf("%s", properties[i].type);
         printf("Location: ");
         scanf("%s", properties[i].location);
         printf("Area: ");
         scanf("%d", &properties[i].area);
         printf("Bedrooms: ");
         scanf("%d", &properties[i].bedrooms);
         printf("Budget: ");
         scanf("%d", &properties[i].budget);
         save_properties();
         printf("Property edited successfully.\n");
         return;
      }
   }
   printf("Property not found.\n");
}

void delete_property() {
   int id;
   printf("Enter property ID: ");
   scanf("%d", &id);

   for (int i = 0; i < num_properties; i++) {
      if (properties[i].id == id) {
         for (int j = i; j < num_properties - 1; j++) {
            properties[j] = properties[j + 1];
         }
         num_properties--;
         save_properties();
         printf("Property deleted successfully.\n");
         return;
      }
   }
   printf("Property not found.\n");
}
