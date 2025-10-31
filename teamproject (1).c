#include <stdio.h>

//constant to store total students and total subjects
const int STUDENT_NUM = 8;
const int SUBJECT_NUM = 6;

//array for subject names
const char* subjects[] = {"English", 
    "Maths", 
    "Science", 
    "Social Science", 
    "Computer", 
    "Physical Education"
};

//calculating student stats
void calculateStudentStats(int subjectMarksArray[], int numSubjects, int* total, float* average) {
    int sum = 0;
    
    // 1. Loop through all 6 subject's marks and add them up
    for (int i = 0; i < numSubjects; i++) {
        sum = sum + subjectMarksArray[i];
    }

    // 2. Calculate the average
    //adding (float) to ensure the result is a float and not an integer
    float avg = (float)sum / numSubjects;

    // 3. Store the results back in main's variables using pointers
    *total = sum;
    *average = avg;
}

int main(){
    //using 2D Array to store students and their marks for each subject
    int marks [STUDENT_NUM][SUBJECT_NUM];
    int studenttotal;
    float studentaverage;

    //for storing the sum of all individual student averages
    float classaveragesum = 0.0;

    printf("STUDENT MARKS CALCULATOR. \n");
    printf("Please enter marks for %d subjects for all the %d students. \n\n", SUBJECT_NUM, STUDENT_NUM);

    //1. GET INPUT

    //Outer Loop: Repeats for each student
    for (int i=0; i < STUDENT_NUM; i++){
       printf("  ===Entering Marks for Student %d===  \n", i+1);
       
       //Inner Loop: Repeats for each subject for the current student
       for (int j=0; j < SUBJECT_NUM; j++){
        printf("Enter marks for %s : ", subjects[j]);
        scanf("%d", &marks[i][j]);
       }
       printf("\n");
    }
    
    //2. DISPLAYS RESULT

    printf("\n\n===INDIVIDUAL STUDENT RESULTS.=== \n\n");

    //Loop through each student again to calculate and display their stats
    for (int i=0; i<STUDENT_NUM; i++){
      
        //Call the function to calculate stats for the current student
        calculateStudentStats (marks[i], SUBJECT_NUM, &studenttotal, &studentaverage);

        //Display the result
        printf("---STUDENT %d---", i+1);
        printf("\n Total Marks : %d", studenttotal);
        printf("\n Average : %.2f", studentaverage);

        //to show performance
        printf("\n Performance: ");
        if (studentaverage>=90){
            printf("Excellent.\n");
        } else if(studentaverage>=80){
            printf("Very Good.\n");
        } else if(studentaverage>=60){
            printf("Good.\n");
        } else if(studentaverage>=50){
            printf("Average.\n");
        }
        else if(studentaverage>=40){
            printf("Needs Improvement.\n");
        }
        else {
            printf("Fail.\n");
        }
        printf("\n");

        classaveragesum += studentaverage;
    }

    //3. DISPLAY OVERALL CLASS PERFORMANCE
    
    //calculataing the final class average from the sum of individual averages
    float finalclassaverage = classaveragesum/STUDENT_NUM;
    printf("OVERALL CLASS AVERAGE: %.2f\n", finalclassaverage);
    return 0;
}