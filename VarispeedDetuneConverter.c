#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// sign: returns "+" if the value is positive
const char *sign(float f){
    char *c;
    if (f >= 0) {
        c = "+";
    } else c = "";
    return c;
}


// converts detune (in semitones) to Varispeed percentage
void detuneToVarispeed(){
    float sem;
    printf("Semitone shift: ");
    scanf("%f", &sem); 

    float var = 100 * pow(2, sem/12) - 100;
    printf("Varispeed percentage needed for detune of %s%.4f semitones:\n", sign(sem), sem);
    printf("%s%.4f%s\n", sign(var), var, "%");
}


// converts Varispeed percentage to detune (in semitones)
void varispeedToDetune(){
    float var;
    printf("Varispeed percentage: ");
    scanf("%f", &var);

    float det = 12 * log2((var + 100) / 100);
    printf("Detune resulting from Varispeed percentage of %s%.4f:%s\n", sign(var), var, "%");
    printf("%s%.4f\n", sign(det), det);
}


// exits if non-whitespace is typed
void process(){
    char input[3];
    printf("\nType:\n");
    scanf("%s", input);

    if (strcmp (input, "det") == 0){
        detuneToVarispeed();

    } else if (strcmp (input, "var") == 0){ 
        varispeedToDetune();

    } else {
	exit(1);
    }
}


int main(){
    printf("\nFor detune to Varispeed, enter 'det'\n");
    printf("For Varispeed percentage to detune, enter 'var'.\n");
    printf("To exit the program, type any other non-whitespace text.\n");
    printf("NOTE: This currently only works for the Chromatic scale.\n");
    while (1) {
        process();
    }
}
