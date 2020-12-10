#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {

    char name[50];
    float score;
    char grade;

};

void clear();
char getLetterGrade(float score);

int main() {

    struct student student1;
    char tempName[50];

    while(1) {

        //  set index 0 of tempName to null for checking if enter was pressed imemdiately
        tempName[0] = '\0';
        printf("Please enter a student name:\n");
        gets(tempName);

        //  now check if TempName was modified, if not, then we can exit the loop
        if(tempName[0] == '\0')
            break;
        strcpy(student1.name, tempName);

        printf("Please enter a student score:\n");
        scanf("%f", &student1.score);

        //  we need to clear the input buffer, because the trailing endline is still there
        clear();

    }

    student1.grade = getLetterGrade(student1.score);
    printf("name: %s, score: %c", student1.name, student1.grade);

    return 0;

}

void clear() {

    //  clears out the input buffer
    while ( getchar() != '\n' );

}

char getLetterGrade(float score) {

    if(score >= 90)
        return 'A';
    else if(score >= 80)
        return 'B';
    else if(score >= 70)
        return 'C';
    else if(score >= 60)
        return 'D';
    else
        return 'F';

}
