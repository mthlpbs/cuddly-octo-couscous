// Saved as a.c in "D:\Codespace\C" directory.
// "math_grades.txt" file is also in the above directory which included student's names and marks.

#include <stdio.h>  // Include stdio header file
#include <stdlib.h> // Include stdlib header file for using exit function in this program
#define maxNam  20  // Define maxNam as a constant and a preprocessor directive
#define maxStdn 6   // Define maxStdn as a constant and a preprocessor directive

// Function to calculate the average of marks. 
// It takes a pointer to the array of marks and the count of marks as parameters.
float average(float *mark, int cnt) { 
    float tot = 0; 
    for (int i=0; i < cnt; i++){ tot = tot + mark[i];} // Calculate the addition of student marks array's values as tot
    return tot/cnt; //Calculate the average
}

int main() {
    FILE *file; 
    int count, y=0, x=0, res;
    char stdnNam[maxStdn][maxNam], *aboveStdn[maxStdn], *belowStdn[maxStdn];
    float stdnMrk[maxStdn], avg;
    if ((file = fopen("math_grades.txt", "r")) == NULL) {  // Check if the file is successfully opened or not?
        printf("Error: 'math_grades.txt' file is missing in your program's current directory."); // Print an error message if it is not found
        printf("\n\tTo fix it, place 'math_grades.txt' in current directory");
        exit(0);                                            // Exit the program after printing the error message
    }
    for (int i = 0; i <= (maxStdn+1000); i++){ // maxStdn + 1000 = Extend the loop because text file can have more students rather than the maximum student ammount
        if (i == maxStdn+1) { // To print an error message When exceeded the limit of maximum student ammount
            printf("Error : Your text file's inputs overloaded the program. This error can be occured because of below reasons."); // Explain the above error message
            printf("\n      > Exceeded student limit, This program only allowed %d students per one execution.", maxStdn);
            printf("\n      > Incorrect data format on a line. The data must be entered as below example.");
            printf("\n\t     ex:- Sadun 88.88");
            exit(0);
        }
        // Reads a string and a float from the file, stores the string in stdnNam[i] and the float in stdnMrk[i]
        // The result of fscanf (number of successfully read items) is stored in res
        res = fscanf(file, "%s %f", stdnNam[i], &stdnMrk[i]);
        if (res == EOF){ // If the result is end of file , break the loop
            break;
        }
        /* This code block checks if the current index is less than the maximum student amount. If it is, it
           increments the count variable to keep track of the actual number of students included in the input file. */
        else if (i < maxStdn) { 
            count++; 
        }
    }
    fclose(file); // <-------------------------------------- Close the file ------------------------------------------>
    avg = average(stdnMrk, count); // Pass array of student's marks and actual count of students to average function.
    for (int i = 0; i < count; i++){
        if (avg > stdnMrk[i]) { // If student's marks lower than average marks
            belowStdn[x] = stdnNam[i]; // Add their names to belowStdn array.
            x++; // Count the students who got lower marks than average marks as x
        }
        else { // else
            aboveStdn[y] = stdnNam[i]; // Add all students who got greater than average marks to aboveStdn array.
            y++; // Count the students who got greater marks than average marks as y
        }
    }
    printf("\nAverage of %d students = %.2f", count, avg); // Print the average marks
    printf("\n\nThe students who got higher than average mark"); // Print the names of student's who got higher than  average marks
    for (int i=0; i < y;i++){
        printf("\n%d. %s", i+1, aboveStdn[i]); // eg:- 1. John
    }
    printf("\n\nThe students who got lower than average mark"); // Print the names of student's who got lower than  average marks
    for (int i=0; i < x;i++){
        printf("\n%d. %s", i+1, belowStdn[i]); // eg:- 1. John
    }
    printf("\n\n"); 
}
