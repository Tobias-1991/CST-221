/*
Zachary Gardner
CST-221
MemoryManagement

In this program we will be taking a decimal number,
and converting it into different formats:
binary and hexadecimal.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//User must enter a decimal number between 0 and 4095
float requestRandom() {
    //Declaring variable
    float f;
    //printing instructions for user
    printf("Please enter decimal number between 0 and 4095\n");
    //scanf allows us to receive user input.
    scanf("%f", &f);
    //if statement enforcing number range
    if (f >= 0 && f <= 4095) {
        printf("You entered %f\n", f);
        } else {
        printf("You have entered an invalid number.");
    }
        //returning chosen number for access within main()
        return f;
}
//this function establishes the format the numbers are displayed in.
void convertBinary(int n, int i){
    int k;
    for (k = i-1; k >= 0; k--) {
        if ((n >> k) & 1)
                printf("1");
            else
                printf("0");

    }

}
typedef union {
    float f;
    struct {
        //The variables defining the IEEE format
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;

    } raw;

}   myfloat;
    //Display as 32 bit binary number displaying each digit as
    //a 1 or a 0 least significant bit on the right.
void printIEEE(myfloat var) {
    //prints the IEEE 754 representation
    //of a float value

    printf("%d | ", var.raw.sign);
    convertBinary(var.raw.exponent, 8);
    printf(" | ");
    convertBinary(var.raw.mantissa, 23);
    printf( "\n");

}



//Display the number as a 32 bit hexadecimal number
//This is displaying the correct hex value, but not in the long format.
long decimalToHex(long decimalNum) {

    long quotient, remainder;
    int i, j = 0;
    char hexaDeci[100];

    quotient = decimalNum;
    //If the remainder is under 10 after dividing by 16, add 48 to the remainder.
    //If the remainder is over 10, add 55 to the remainder.
    //Continue this until the quotient value is equal to 0.
    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10)
            hexaDeci[j++] = 48 + remainder;
        else
            hexaDeci[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    printf("Decimal to Hexadecimal\n");
    for (i = j; i >= 0; i--) {

        printf("%c", hexaDeci[i]);
    }
    return 0;
}


//Transform the input by shifting the number 16 bits
//to the left, then mask out (AND) the bottom 16 bits
//and finally add (OR) the hex number 0x07FF to produce
//the final result

//Finally display the final result in binary, hexadecimal
//and decimal to the console
int main()
{

    myfloat var;
    //Getting the decimal number from user.
    var.f = requestRandom();
    printf("IEEE 754 representation of %f is : \n",
          var.f);
    //Printing out the 32 bit binary.
    printIEEE(var);

    decimalToHex(var.f);

    return 0;



}
