/*
 * Program:  Payroll Register Generator
 * Developer: Mareerose Possi
 * Lab:      Lab 3 - Text Input/Output
 * Date:    08/04/26
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    /* ── File pointers ──── */
    FILE *inFile  = NULL;
    FILE *outFile = NULL;

    /* ── Variables to hold one employee record ─── */
    char   empNo[10];       /* employee number (kept as string → left-justify) */
    int    dept;            /* department number                               */
    float  payRate;         /* hourly pay rate                                 */
    char   exempt;          /* exempt flag: 'Y' or 'N'                        */
    int    hoursWorked;     /* hours worked in the period                      */
    float  basePay;         /* calculated: payRate * hoursWorked               */

    char   headerLine[256]; /* buffer to read and discard the header line      */

    /* ── 1. Open input file ──*/
    inFile = fopen("employee.txt", "r");
    if (inFile == NULL) {
        printf("Error: Could not open employee.txt\n");
        return 1;
    }

    /* ── 2. Open / create output file ── */
    outFile = fopen("payroll_register.txt", "w");
    if (outFile == NULL) {
        printf("Error: Could not create payroll_register.txt\n");
        fclose(inFile);
        return 1;
    }

    /* ── 3. Read and discard the header line from input ──*/
    fgets(headerLine, sizeof(headerLine), inFile);

    /* ── 4. Write formatted headers to output file ─── */
    fprintf(outFile, "%-8s %-6s %-8s %-7s %-13s %s\n",
            "EmpNo", "Dept", "PayRate", "Exempt", "HoursWorked", "BasePay");
    fprintf(outFile, "%-8s %-6s %-8s %-7s %-13s %s\n",
            "--------", "------", "--------", "-------", "-------------", "--------");

    /* ── 5. Loop: read each employee record and write to output ──── */
    while (fscanf(inFile, "%s %d %f %c %d",
                  empNo, &dept, &payRate, &exempt, &hoursWorked) == 5) {

        /* Calculate base pay */
        basePay = payRate * hoursWorked;

        /* Write one formatted line to payroll register */
        fprintf(outFile, "%-8s %-6d %-8.2f %-7c %-13d %.2f\n",
                empNo, dept, payRate, exempt, hoursWorked, basePay);
    }

    /* ── 6. Close both files ── */
    fclose(inFile);
    fclose(outFile);

    printf("Payroll register has been created.\n");

    return 0;
}
