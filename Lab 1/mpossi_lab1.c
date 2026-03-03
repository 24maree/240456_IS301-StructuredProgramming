/*  Problem:
    Algorithm:
    Developed by: Mareerose Possi
    Date: 3th of March 2026

*/

#include <stdio.h>

//Defining constants for prices and tax rate
#define PRICE_TV 400.00
#define PRICE_MONITOR 220.00
#define PRICE_FLASH 35.20
#define PRICE_HARD 150.00
#define PRICE_PRINTER 300.00
#define TAX_RATE 0.0835

int main(){

//your program statements goes here

//Integer variables for quantities
int q_tv, q_monitor, q_flash, q_hard, q_printer;

//Floating-point variables for costs
float total_tv, total_monitor, total_flash, total_hard, total_printer;
float subtotal, tax_amount, final_total;

//Prompts
printf("How many TV's were sold? ");
scanf("%d", &q_tv);

printf("How many monitors were sold? ");
scanf("%d", &q_monitor);

printf("How many flash drives were Sold? ");
scanf("%d", &q_flash);

printf("How many Hard Drives were sold? ");
scanf("%d", &q_hard);

printf("How many Deskjet Printers were sold? ");
scanf("%d", &q_printer);

//Calculations
total_tv = q_tv * PRICE_TV;
total_monitor = q_monitor * PRICE_MONITOR;
total_flash = q_flash * PRICE_FLASH;
total_hard = q_printer * PRICE_PRINTER;

subtotal = total_tv + total_monitor + total_flash + total_hard + total_printer;
tax_amount = subtotal * TAX_RATE;
final_total = subtotal + tax_amount;

//Formatted Table Output
printf("\nQTY\tDESCRIPTION\t\tUNIT PRICE\tTOTAL PRICE\n");
printf("%d\tTV\t\t400.00\t\t%.2f\n", q_tv, total_tv);
printf("%d\tMonitor\t\t220.00\t\t%.2f\n", q_monitor, total_monitor);
printf("%d\tFlash Drive\t35.20\t\t%.2f\n", q_flash, total_flash);
printf("%d\tHard Drive\t150.00\t\t%.2f\n", q_hard, total_hard);
printf("%d\tDeskjet Printer\t300.00\t\t%.2f\n", q_printer, total_printer);

printf("\n\t\t\tSubtotal:\t%.2f", subtotal);
printf("\n\t\t\tTax:\t\t%.2f", tax_amount);
printf("\n\t\t\tTotal:\t\t%.2f\n", final_total);

return 0;
}
