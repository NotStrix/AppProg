/*
Jose Rosario 
ECE Application Programming
Project 1
Due: 09/29/2025
*/


#include <stdio.h>

int main() {
    double sqft;
    int roomWidth;
    int roomLength;
    double laborCost;
    double salesTax;

    //Order #1 Code

    printf("Enter enter the price per square foot for order #1: \n");
    scanf("%lf", &sqft);
    printf("Enter the width of the room: \n");
    scanf("%d", &roomWidth);
    printf("Enter the length of the room: \n");
    scanf("%d", &roomLength);

    int roomArea = roomWidth * roomLength;           //Calculate area of room
    double carpetCost = (roomArea * sqft) * 1.20;    //Carpet cost with 20% markup
    double totalCost1;   
    
    laborCost = roomArea * 0.75;
    salesTax = (carpetCost + laborCost) * 0.07;
    totalCost1 = carpetCost + laborCost + salesTax;  //Sum costs for order 1

    printf("\nOrder #1\n");
    printf("Room: %d sq ft\nCarpet: $%.2lf\n", roomArea, carpetCost);
    printf("Labor: $%.2lf\n", laborCost);
    printf("Tax: $%.2lf\n", salesTax);
    printf("Cost: $%.2lf\n\n", totalCost1);
    
    // Order #2 Code

    printf("Enter enter the price per square foot for order #2: \n");
    scanf("%lf", &sqft);
    printf("Enter the width of the room: \n");
    scanf("%d", &roomWidth);
    printf("Enter the length of the room: \n");
    scanf("%d", &roomLength);

    roomArea = roomWidth * roomLength;           //Calculate area of room
    carpetCost = (roomArea * sqft) * 1.20;       //Carpet cost with 20% markup
    double totalCost2;   
    
    laborCost = roomArea * 0.75;
    salesTax = (carpetCost + laborCost) * 0.07;
    totalCost2 = carpetCost + laborCost + salesTax;  //Sum costs for order 2

    printf("\nOrder #2\n");
    printf("Room: %d sq ft\nCarpet: $%.2lf\n", roomArea, carpetCost);
    printf("Labor: $%.2lf\n", laborCost);
    printf("Tax: $%.2lf\n", salesTax);
    printf("Cost: $%.2lf\n\n", totalCost2);

    // Order #3 Code

    printf("Enter enter the price per square foot for order #3: \n");
    scanf("%lf", &sqft);
    printf("Enter the width of the room: \n");
    scanf("%d", &roomWidth);
    printf("Enter the length of the room: \n");
    scanf("%d", &roomLength);

    roomArea = roomWidth * roomLength;           //Calculate area of room
    carpetCost = (roomArea * sqft) * 1.20;       //Carpet cost with 20% markup
    double totalCost3;   
    
    laborCost = roomArea * 0.75;
    salesTax = (carpetCost + laborCost) * 0.07;
    totalCost3 = carpetCost + laborCost + salesTax;  //Sum costs for order 3

    printf("\nOrder #3\n");
    printf("Room: %d sq ft\nCarpet: $%.2lf\n", roomArea, carpetCost);
    printf("Labor: $%.2lf\n", laborCost);
    printf("Tax: $%.2lf\n", salesTax);
    printf("Cost: $%.2lf\n\n", totalCost3);



    double totalSales = totalCost1 + totalCost2 + totalCost3;     //Sum total sales for all orders
    printf("Total Sales: $%.2lf\n", totalSales);


    return 0;
    
}