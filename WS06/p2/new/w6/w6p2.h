/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   :
	ID     :
	Email  :
	Section:
*/

// ----------------------------------------------------------------------------
// defines/macros


// ----------------------------------------------------------------------------
// structures
struct ReportData {
	int sku;
	double price;
	int caloriesPerServing;
	double pounds;
	double kgs;
	int grams;
	double servings;
	double costPerServing;
	double costOfCaloriesPerServing;
};


// ----------------------------------------------------------------------------
// function prototypes

// PART-1
#define MAX_PRODUCTS 3
#define SUGGESTED_SERVING 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
  int sku;
  double price;
  int calories;
  double weight;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *number);


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *number);


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numberOfProducts);


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int numberOfProducts);


// 5. Display the formatted table header
void displayCatFoodHeader();


// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *price, const int calories, const double *weight);


// 7. Logic entry point
void start();

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double *pounds, double *result);

// 9. convert lbs: g
int convertLbsG(const double *pounds, int *result);

// 10. convert lbs: kg / g
void convertLbs(const double *pounds, double *kgs, double *grams);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeInGrams, const int totalWeightInGrams, double *result);

// 12. calculate: cost per serving
double calculateCostPerServing(const double *price, const double *servings, double *result);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price, const double *calories, double *result);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int isCheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFoodInfo);

// ----------------------------------------------------------------------------

// 7. Logic entry point 

