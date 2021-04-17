#include <stdio.h>
#include "givenA3.h"
#include <stdlib.h>
/*
Student Name: Eason Liang Email Id: eliang@uoguelph.ca
Due Date: December 2 2020 Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material that I have used, whether directly quoted or paraphrased. Furthermore, I certify that this assignment was prepared by me specifically for this course.
*/

/*Compling instructions
	gcc -Wall LiangEasonA3Main.c LiangEasonA3.c
	./a.out courses.txt data.txt
*/
int main(int argc, char* argv []) {
//All Variables came from the parametes in givenA3.h
 char cName[50];
 char courseNames[NUMBER_COURSES][50] ;
 char profNames[NUMBER_PROFS][30] ;
 char data[NUMBER_PROFS][NUMBER_COURSES];
 int courseID[NUMBER_COURSES];
 char cNameFound [50];
  int cNumFound;
	int n;
//Variable used to get the user's input 
 int input = 3;
  readCourseProfData("courses.txt",courseNames,profNames,courseID);
  readData("data.txt",data);
	//Using a while loop where the loop only ends if the user enter an input less than 3 and an input that is greater or equal to 10
   while(input>=3&&input<=10&&input!=10){
	//Print out the main menu
 printf("\n******************************\n");
 printf("Enter a choice from the menu displayed below:\n");
 printf("3 For Task 3 - count and print all profs teaching n or more courses\n");
 printf("4 For Task 4 - count and print all profs teaching only n-level courses\n");
 printf("5 For Task 5 - count and print all courses taught by n profs\n");
 printf("6 For Task 6 - find and print the average number of courses taught by a prof this year\n");
 printf("7 For Task 7 - search for courses name, given it ID\n");
 printf("8 For Task 8 - search for courseID, given it's name\n");
 printf("9 For Task 9 - (additonal functionality) - generate a report\n");
 printf("Enter 10 to exit\n");
//Gets the user input which will be used to determine what task the user wishes to use
 scanf("%d",&input);
 // if the user types 3 
   if(input==3){
     printf("TASK 3:\n");
		 //Asks for how many courses that a prof teaches 
     printf("Number of courses? ");
		 //Gets a integer input from the user 
     scanf("%d",&n);
		 //Prints out the result 
     printf("\nNumber of profs teaching more than n courses = %d",numProfsTeachingNCourses(data,  n, profNames));

		 //If the user input is 4
   }else if(input==4){
		 printf("TASK 4:\n");
		 //Asks the user for the level of courses from 1 to 4 
		 printf("Level of course? ");
		 //gets a integer input from the user 
		 scanf("%d",&n);
		 //calls a function which will print out the result 
		 	printf("Number of profs teaching n-level courses = %d",numProfsTeachingNLevelCourses(data,n,courseID,profNames));

	//If the user input is 5
   }else if(input==5){
		 //Task 5 called 
     printf("TASK 5:\n");
		 //Prints a statemeent and asks the user for a integer input 
     printf("Number of profs for a course? ");
     scanf("%d",&n);
		 //prints out the result by calling using a statement and calling out a function 
    printf("Number of courses taught by n professors = %d",coursesWithNProfs(data,n,courseNames));
		//if the user input is 6 
   }else if(input==6){
		 //Calls task 6 and prints out the average number of courses taught by a professor 
    printf("TASK 6:\n");
    printf("Average Number of courses taught by prof = %.2f",avgNumCourses(data));
		
		//if the user input is 7 
   }else if(input==7){
		 //Prints out task 7 
    printf("TASK 7:\n");
		//asks the user to input a course id as an integer
    printf("Search for which course id? ");
		//take a integer input 
    scanf("%d",&n);
		//if a course id exists in the data 
    if(getCourseName(n, courseID, cNameFound, courseNames)==1){
			//prints out the course name
      printf("Course name found = %s",cNameFound);
    }else{
			//tells the user that the course name cannot be found 
      printf("Course name not found for %d",n);
    }
		//if the user input is 8 
   }else if(input==8){
     printf("TASK 8:\n");
		 //Asks the user for a course name 
     printf("Search for which course name? ");
		 //flushes the standard input due to scanf 
      getchar();
			//use fgets as userinput for a string 
     fgets(cName,50,stdin);
		 //if the course name exists then it prints out the course number or else it prints out that the course number is not found 
     if(getCourseNum(cName, courseID, &cNumFound, courseNames)==1){
       printf("Course number found = %d",cNumFound);
     }else{
       printf("Course number not found for %s",cName);
     }
		 //if the user input is 9 then it will generate a report of each course and what prof teaches it 
   }else if(input==9){
		 printf("TASK 9:\n");
 generateReport(data,courseID,courseNames,profNames);
   }
  }

  return 0;
}