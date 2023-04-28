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
void sell();
void delete_property();

struct property
{
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

int main()
{
int choice;
load_properties();

do
{
printf("\t\t\t\t\tReal Estate Advisor\n\n");
printf("Author : Pranjal Singh | https://github.com/pranjalsingh03\n\n");
printf("Git repo : https://github.com/pranjalsingh03/Real-state-Advisor\n\n");

//printf("-------------------\n");
printf("\n1. Add new property\n");
printf("2. Display available properties\n");
printf("3. Search for properties\n");
printf("4. Buy a property\n");
printf("5. Sell a property\n");
printf("6. Delete a property\n");
printf("7. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
printf("\n");

switch (choice)
{
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
delete_property();
break;
case 7:
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

void load_properties()
{
FILE *fp = fopen("properties.txt", "r");
if (fp == NULL)
{
return;
}
while (!feof(fp))
{
struct property p;
fscanf(fp, "%d %s %s %d %d %d %s\n", &p.id, p.type, p.location, &p.area, &p.bedrooms, &p.budget, p.status);
properties[num_properties++] = p;
}
fclose(fp);
}

void save_properties()
{
int i;
FILE *fp = fopen("properties.txt", "a");
for ( i = 0; i < num_properties; i++)
{
fprintf(fp, "%d %s %s %d %d %d %s\n", properties[i].id, properties[i].type, properties[i].location, properties[i].area, properties[i].bedrooms, properties[i].budget, properties[i].status);
}
fclose(fp);
}

void add_property()
{
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

void display_properties()
{
int i;
printf("ID  Type              Location          Area  Bedrooms  Budget  Status\n");
printf("------------------------------------------------------------------------\n");
for ( i = 0; i < num_properties; i++)
{
if (strcmp(properties[i].status, "Available") == 0)
{
printf("%-4d%-18s%-18s%-6d%-10d%-8d%s\n", properties[i].id, properties[i].type, properties[i].location, properties[i].area, properties[i].bedrooms, properties[i].budget, properties[i].status);
}
}
printf("------------------------------------------------------------------------\n");
}

void search_properties()
{
int i ;
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
for (i= 0; i < num_properties; i++)
{
if (strcmp(properties[i].status, "Available") == 0 &&
properties[i].area >= min_area &&
properties[i].bedrooms >= min_bedrooms &&
properties[i].budget <= max_budget)
{
printf("%-4d%-18s%-18s%-6d%-10d%-8d%s\n", properties[i].id, properties[i].type,
properties[i].location, properties[i].area, properties[i].bedrooms,
properties[i].budget, properties[i].status);
}
}
}

void buy_property()
{
int i;
int id;
printf("Enter property ID: ");
scanf("%d", &id);

for (i = 0; i < num_properties; i++)
{
if (properties[i].id == id && strcmp(properties[i].status, "Available") == 0)
{
strcpy(properties[i].status, "Sold");
save_properties();
printf("Property bought successfully.\n");
return;
}
}
printf("Property not found or not available.\n");
}

void edit_property()
{
int id,i;
printf("Enter property ID: ");
scanf("%d", &id);

for (i = 0; i < num_properties; i++)
{
if (properties[i].id == id)
{
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

void sell_property() {
int i,id;
printf("Enter property ID: ");
scanf("%d", &id);
sell(id);
for (i = 0; i < num_properties; i++) {
if (properties[i].id == id && strcmp(properties[i].status, "Sold") == 0) {
strcpy(properties[i].status, "Available");
save_properties();
printf("Property sold successfully.\n");
return;
}
}
printf("Property not found or not sold.\n");
}


void sell(int id) {
FILE *fp;
FILE *temp;
struct property p;
int found = 0;

fp = fopen("properties.txt", "r");
if (fp == NULL) {
printf("Error: Could not open file.\n");
exit(1);
}

temp = fopen("temp.txt", "w");
if (temp == NULL) {
printf("Error: Could not create temporary file.\n");
exit(1);
}

while (fread(&p, sizeof(struct property), 1, fp) == 1) {
if (p.id == id) {

strcpy(p.status, "Sold");
found = 1;
}

fwrite(&p, sizeof(struct property), 1, temp);
}

fclose(fp);
fclose(temp);

remove("properties.txt");

rename("temp.txt", "properties.txt");
}
void delete_property()
{
int id,i,j;
printf("Enter property ID: ");
scanf("%d", &id);

for (i = 0; i < num_properties; i++)
{
if (properties[i].id == id)
{
for (j = i; j < num_properties - 1; j++)
{
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