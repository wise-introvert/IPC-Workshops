/*
   ==================================================
   Workshop #6 (Part-2):
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


// User-Defined Libraries
#include "w6p2.h"


// ----------------------------------------------------------------------------
// PART-1
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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *pounds, double *result) {
  double value = *pounds / 2.2046;
  *result = value;
  return value;
}


// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *pounds, int *result) {
  int value = (int) (*pounds / 2.2046) * 1000;
  *result = value;
  return value;
}

// 10. convert lbs: kg and g
void convertLbs(const double *pounds, double *kgs, double *grams) {
  convertLbsKg(pounds, kgs);
  convertLbsG(pounds, grams);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeInGrams, const int totalWeightInGrams, double *result) {
  *result = (float) totalWeightInGrams / servingSizeInGrams;
  return *result;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double *price, const double *servings, double *result) {
  *result = *servings / *price;

  return *result;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price, const double *calories, double *result) {
  *result = *calories / *price;

  return *result;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo) {
  struct ReportData reportData;
  reportData.sku = catFoodInfo.sku;
  reportData.price = catFoodInfo.price;
  reportData.pounds = catFoodInfo.weight;
  convertLbsKg(&catFoodInfo.weight, &reportData.kgs);
  convertLbsG(&catFoodInfo.weight, &reportData.grams);
  calculateServings(SUGGESTED_SERVING, reportData.grams, &reportData.servings);
  calculateCostPerServing(&reportData.price, &reportData.servings, &reportData.costPerServing);
  double cals = (double) catFoodInfo.calories;
  calculateCostPerCal(&reportData.price, &cals, &reportData.costOfCaloriesPerServing);
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void) {
  printf("Analysis Report (Note: Serving = %dg\n", SUGGESTED_SERVING);
  printf("---------------\n");
  printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
  printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int isCheapest) {
  printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", reportData.sku, reportData.price, reportData.pounds, reportData.kgs, reportData.grams,  reportData.caloriesPerServing, reportData.servings, reportData.costPerServing, reportData.costOfCaloriesPerServing);
  if(isCheapest > 0) {
    printf("***");
  }
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFoodInfo) {
  printf("Final Analysis\n--------------\nBased on the comparison data, the PURRR-fect economical option is:\nSKU:%d Price: $%.2lf\n\nHappy shopping!", catFoodInfo.sku, catFoodInfo.price);
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start() {
  struct CatFoodInfo catFoods[MAX_PRODUCTS] = {};
  struct CatFoodInfo cheapest;
  struct ReportData reports[MAX_PRODUCTS] = {};

  openingMessage(MAX_PRODUCTS);

  for(i = 0; i < MAX_PRODUCTS; i++) {
    catFoods[i] = getCatFoodInfo(i);
    reports[i] = calculateReportData(catFoods[i]);
    if(reports[i].costPerServing < cheapest.price) {
      cheapest = catFoods[i];
    }
  }

  displayCatFoodHeader();

  for(i = 0; i < MAX_PRODUCTS; i++) {
    displayCatFoodData(catFoods[i].sku, &catFoods[i].price, catFoods[i].calories, &catFoods[i].weight);
  }

  displayReportHeader();

  for(i = 0; i < MAX_PRODUCTS; i++) {
    displayReportData(reports[i], reports[i].sku == cheapest.sku ? 1 : 0);
  }

  displayFinalAnalysis(cheapest);
}
