/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : 
	ID     : 
	Email  : 
	Section: 
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>
#include <string.h>


// User Libraries
#include "w6p1.h"

int i;

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *number) {
  int value;
  scanf("%d", &value);
  while(value <= 0) {
    printf("ERROR: Enter a positive value: ");
    scanf("%d", &value);
  }
  *number = value;

  return value;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *number) {
  double value;
  scanf("%lf", &value);
  while(value <= 0) {
    printf("ERROR: Enter a positive value: ");
    scanf("%lf", &value);
  }

  *number = value;

  return value;
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numberOfProducts) {
  printf("\n\n===========================\nStarting Main Program Logic\n===========================\n\nCat Food Cost Analysis\n======================\n\nEnter the details for %d dry food bags of product data for analysis. NOTE: A 'serving' is %dg", numberOfProducts, SUGGESTED_SERVING);
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int numberOfProducts) {
  struct CatFoodInfo catFoodInfo;

  printf("\nCat Food Product #%d\n--------------------", numberOfProducts);

  printf("SKU           : ");
  getIntPositive(&catFoodInfo.sku);
  printf("PRICE         : ");
  getDoublePositive(&catFoodInfo.price);
  printf("WEIGHT (LBS)  : ");
  getDoublePositive(&catFoodInfo.weight);
  printf("CALORIES/SERV.: ");
  getIntPositive(&catFoodInfo.calories);

  return catFoodInfo;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *price, const int calories, const double *weight) {
  printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// 7. Logic entry point
void start() {
  struct CatFoodInfo catFoods[MAX_PRODUCTS] = {};
  openingMessage(MAX_PRODUCTS);
  for(i = 0; i < MAX_PRODUCTS; i++) {
    catFoods[i] = getCatFoodInfo(i);
  }

  displayCatFoodHeader();

  for(i = 0; i < MAX_PRODUCTS; i++) {
    displayCatFoodData(catFoods[i].sku, &catFoods[i].price, catFoods[i].calories, &catFoods[i].weight);
  }
}
