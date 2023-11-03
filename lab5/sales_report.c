#include <stdio.h>
#include <stdlib.h>

// Function to print monthly sales report
void print_monthly_sales(double sales[], char *months[])
{
    printf("Monthly sales report for 2022:\n");
    printf("Month\tSales\n");
    for (int i = 0; i < 12; i++){
        printf("%s\t$%.2lf\n", months[i], sales[i]);
    }
    printf("\n");
}

// Function to print minimum sales
void print_min_sales(double sales[], char *months[])
{
    double min_sales = sales[0];
    char *month = months[0];
    for (int i = 0; i < 12; i++){
        if (sales[i] < min_sales) {
            min_sales = sales[i];
            month = months[i];
        }
    }
    printf("Minimum sales: $%.2lf (%s)\n", min_sales, month);
}

// Function to print maximum sales
void print_max_sales(double sales[], char *months[])
{
    double max_sales = sales[0];
    char *month = months[0];
    for (int i = 0; i < 12; i++){
        if (sales[i] > max_sales){
            max_sales = sales[i];
            month = months[i];
        }
    }
    printf("Maximum sales: $%.2lf (%s)\n", max_sales, month);
}

// Function to print average sales
void print_average_sales(double sales[], char *months[])
{
    double sum = 0;
    for (int i = 0; i < 12; i++){
        sum += sales[i];
    }
    printf("Average sales: $%.2lf\n", sum / 12);
}

// Function to print sales summary
void sales_summary(double sales[], char *months[])
{
    print_min_sales(sales, months);
    print_max_sales(sales, months);
    print_average_sales(sales, months);
    printf("\n");
}

// Function to print a six-month moving average report
void print_six_month(double sales[], char *months[])
{
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++){
        double sum = 0;
        for (int j = 0; j < 6; j++){
            sum += sales[i + j];
        }
        double average = sum / 6;
        printf("%s - %s\t$%.2lf\n", months[i], months[i + 5], average);
    }
    printf("\n");
}

// Function to print sales in descending order
void print_descending_order(double sales[], char *months[])
{
    for (int i = 0; i < 12; i++){
        for (int j = i + 1; j < 12; j++){
            if (sales[i] < sales[j]){
                // Swap sales and months elements to sort in descending order
                double temp_sales = sales[i];
                char *temp_month = months[i];
                sales[i] = sales[j];
                months[i] = months[j];
                sales[j] = temp_sales;
                months[j] = temp_month;
            }
        }
    }
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");
    for (int k = 0; k < 12; k++){
        printf("%s\t$%.2lf\n", months[k], sales[k]);
    }
}

int main() 
{
    char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
                      "Aug", "Sep", "Oct", "Nov", "Dec"};
    double sales[12];

    // Open the sales report file for reading
    FILE *file;
    file = fopen("sales_report.txt", "r");
    if (file == NULL) {
        perror("Can't open file\n");
        exit(1);
    }

    // Read sales data from the file
    for (int i = 0; i < 12; i++){
        if (fscanf(file, "%lf", &sales[i]) != 1){
            printf("Error on sales file\n");
            exit(1);
        }
    }
    fclose(file); 

    // Call various functions to print different reports
    print_monthly_sales(sales, months);
    sales_summary(sales, months);
    print_six_month(sales, months);
    print_descending_order(sales, months);
}
