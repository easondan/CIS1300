#include <stdio.h>
#include <string.h>
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
//Define values for number of pros and number of courses as 6 and 10 
#define NUMBER_PROFS 6
#define NUMBER_COURSES 10
//This function will read the data file called course.txt given 3 char arrays as paramets and one integer array parameter
void readCourseProfData (char filename [50], char courseNames[NUMBER_COURSES][50], char profNames[NUMBER_PROFS][30], int courseID[NUMBER_COURSES]){
	 int i;
   int lenCourses[NUMBER_COURSES];
   int lenProfs[NUMBER_PROFS];
	 char data[NUMBER_PROFS+NUMBER_COURSES+NUMBER_COURSES][50];
//Intialize a object of the type file 
 		FILE* inFile = NULL; 
		 //Opens the file and reads it 
   printf("Opening file %s.\n",filename);
   inFile = fopen(filename, "r");
	 //Check if the file is empty 
   if (inFile == NULL) {
      printf("Could not open file %s.\n",filename);
    }
		//Read the rile 
    printf("Reading %s",filename);
    for(int i =0;i<NUMBER_PROFS+NUMBER_COURSES+NUMBER_COURSES;i++){
			//Reads the data into array which will be used to seperate the data later 
     fgets(data[i], 50, inFile);
    }
		//close the file 
   printf("Closing file courses.txt.\n");
   fclose(inFile);

  //split the data up into their respective arrays in the parameters 
	//2 loops will use string copy to copy their string into course names and prof names 
     for(i=0;i<NUMBER_COURSES;i++){
        strcpy(courseNames[i], data[i]);
     }
     for(i=0;i<NUMBER_PROFS;i++){
     strcpy(profNames[i], data[NUMBER_COURSES+i]);
  
    }
		//use sscan and a loop to parse courseid as an integer 
    for(i=0;i<NUMBER_COURSES;i++){
   
     sscanf(data[NUMBER_COURSES+NUMBER_PROFS+i], "%d",&courseID[i] );
    }

	// This loop used to use get rid of the \n that fgets puts in a string and replaces with 0 at the end of the string
   for(i=0;i<NUMBER_COURSES;i++){
   lenCourses[i] = strlen(courseNames[i]);
   courseNames[i][lenCourses[i]-1] = '\0';
    }
	// This loop used to use get rid of the \n that fgets puts in a string and replaces with 0 at the end of the string
   for(i=0;i<NUMBER_PROFS;i++){
  lenProfs[i] = strlen(profNames[i]);
   profNames[i][lenProfs[i]-1] = '\0';
    } 
}
//This function is used to read the file called data where it accepts 2 char array parameters
void readData (char fileName[50], char data[NUMBER_PROFS][NUMBER_COURSES]){
	//intializes a object of the type file 
  FILE* inFile = NULL; 
  int i;
	int lenData[NUMBER_PROFS];
	//open the file and read the file 
   printf("Opening file %s.\n",fileName);
   inFile = fopen(fileName, "r");
	 //check if the file is empty 
   if (inFile == NULL) {
      printf("Could not open file %s.\n",fileName);
   }
	 //read the data in the file using fgets 
    printf("Reading File %s",fileName);
    for(int i =0;i<NUMBER_PROFS;i++){
       fgets(data[i], 50, inFile);
    }
		//close the file 
   printf("Closing file data.txt.\n");
   fclose(inFile);  
	 //use a loop to remove the \n in the data array as replace it with '\0'
      for(i=0;i<NUMBER_PROFS;i++){
   lenData[i] = strlen(data[i]);
   data[i][lenData[i]-1] = '\0';
    }
}

//This function is used determine what professors teach at least n courses 
int numProfsTeachingNCourses(char data[NUMBER_PROFS][NUMBER_COURSES], int n, char profNames[NUMBER_PROFS][30]){
	
  int i,j;
  int counter=0;
  int counterProf=0;  

	//Using a loop to go through a 2d array for data
  for(i=0;i<NUMBER_PROFS;i++){
  for(j=0;j<NUMBER_COURSES;j++){
		//check if the data has a y in it 
    if(data[i][j]=='y'){
			//counter goes up 
      counter++;
    }
   
   }
	 //if the counter is greater than or equal the n value 
   if(counter>=n){
		 //print out the professor who teaches n or more courses 
     printf("Professor %s Teaches %d or more courses a year\n",profNames[i],n);
		 //counters for how many professors teach n or more courses 
     counterProf++;
   }
  //reset counter
   counter=0;
  }
	//return the value counter prof
  return counterProf;
}
//this function is used to determine which professor only teaches n type of courses 
int numProfsTeachingNLevelCourses(char data[NUMBER_PROFS][NUMBER_COURSES], int n, int courseID[NUMBER_COURSES], char profNames[NUMBER_PROFS][30]){
	//intialied variables for counters;
	int nCourse=0;
	int notNCourse=0;
	int counterProf=0;
	//use a for loop to go through the 2d array data
  for(int i=0;i<NUMBER_PROFS;i++){
		for(int j=0;j<NUMBER_COURSES;j++){
			//check if data array has a y character 
			if(data[i][j]=='y'){
				//if it does takes the course id/1000 and check if it equals to n 
				if((courseID[j]/1000)==n){
					//if the professor does add it to the course that it only teaches 
					nCourse++;
				}else{
					//if counter does not equal to 1000 add it the counter of the courses that is not n 
					notNCourse++;
				}
			}
		}
		//this is used to check if the professor only teaches one type of course 
		if((notNCourse==0)&&(nCourse>0)){
			//counter for the amount of professor that teach only n courses goes up and print what professor teaches it
			counterProf++;
			printf("Professor %s teaches only %d level courses\n",profNames[i],n*1000);
		}
		//reset the counters 
		nCourse=0;
		notNCourse=0;
	}
	//return the amount of profs that only that n level courses 
      return counterProf;
}

//This function is used to check the number of courses  taught by n professsor 
int coursesWithNProfs(char data[NUMBER_PROFS][NUMBER_COURSES], int n, char courseNames[NUMBER_COURSES][50]){
  int i;
  int j;
  int counter=0;
  int counterCourses=0;
	//using a nested for loop to go through the 2d array data 
  for(i=0;i<NUMBER_COURSES;i++){
    for(j=0;j<NUMBER_PROFS;j++){
			//check if the data array has a y in it 
    if(data[j][i]=='y'){
			//counter increases 
      counter++;
    }
  }
	//checks if the counter is taught by n professors 
  if(counter==n){
		//counter for the amount of courses taught by n professors goes up and he course name is printed along with it 
    counterCourses++;
    printf("%s is taught by %d profs\n",courseNames[i],n);
  }
//resets the counter 
  counter=0;
  }
 //return the amount of coures taught by n professors used later to print in main 
  return counterCourses;
}
//This function is used to calculate the average number of courses taught by a professor 
float avgNumCourses(char data[NUMBER_PROFS][NUMBER_COURSES]){
  float counterTeach=0;
  int i;
  int j;
  float average;
	//use a nested for loop to go through the array called data 
  for(i=0;i<NUMBER_PROFS;i++){
    for(j=0;j<NUMBER_COURSES;j++){
			//check which professor teaches which courses 
      if(data[i][j]=='y'){
				//counter goes up if data[i][j] is y
        counterTeach++;
      }
    }
  }
	//take all the y in the counter and divide by the number of prof
	average = counterTeach/NUMBER_PROFS;
	//return the average of courses taught by a single prof which will be used later to print out in the main 
  return average;
}
//this function is used to get the course name given the course id
int getCourseName (int courseNum, int courseID[NUMBER_COURSES], char cNameFound [50], char courseNames[NUMBER_COURSES][50]){
    int i;
    //use a loop to go through the courseID array
  for(i=0;i<NUMBER_COURSES;i++){
		//Check if the coursenumber enter by the user matches a value in the array 
  if(courseNum==courseID[i]){
		//copies the coursename string into cNameFound
    strcpy(cNameFound, courseNames[i]);
	//shows that a coursename does exist given a course ID
  return 1;
  }
  }
	//return 0 or false
   return 0;
}

//This function is used to get the course number given a course name 
int getCourseNum (char cName [50], int courseID[NUMBER_COURSES], int * cNumFound, char courseNames[NUMBER_COURSES][50]){
 int i;
 int lengthCourse;
 //since in the menu uses fgets we have to replace the \n with '\0' in order for the string functions to work
 lengthCourse = strlen(cName);
 cName[lengthCourse-1] = '\0';
 //Use a loop that goes through the courseName array 
 for(i=0;i<NUMBER_COURSES;i++){
	 //using string compare to check if the string matches 
  if(strcmp(cName,courseNames[i])==0){
		//cNumFound equal to the course Id to the course name
    *cNumFound = courseID[i];
		//return 1 or true 
    return 1;
  }
   }
  
	//return 0 or false
   return 0;
}

//this function is used to generate a report of the courses and which profs teaches what courses 
void generateReport(char data[NUMBER_PROFS][NUMBER_COURSES],int courseID[NUMBER_COURSES],char courseNames[NUMBER_COURSES][50],char profNames  [NUMBER_PROFS][30])
{
	//use to seperate the main menu and the report 
  printf("*****************");
  int i;
  int j;
	//use this integer as a true or false value 
	int check=0;
	//use this counter to represent the index of the location array 
	int counter=0;
	//use this array which will accept an integer into the array and will act as a location allocation for the prof's name
	int location[NUMBER_PROFS];
	//use a nested forloop to go through and read an array and print out the report 
  for(i=0;i<NUMBER_COURSES;i++){
		//use to print out the course numbers, course name and the professors who will teach that course 
    printf("\n%d.\tCourse No: CIS%d",i+1,courseID[i] );
   printf("\n\tCourse Name: %s",courseNames[i]);
	  printf("\n\n\tTaught by: ");
    for(j = 0;j<NUMBER_PROFS;j++){
			//checks if the the data array has a y in a certain course 
      if(data[j][i]=='y'){
				//check becomes 1 or true 
				check =1;
				//allocated the location of the array for prof names using the counter as an index value 
				location[counter] = j;
				//counter goes up 
		counter++;
    }
		}
		//if check is 0 or false that means no professors teach that certain course 
		if(check==0){
			//prints out that no professors teach that course 
				printf("None");
				//if check is = 1 or true 
			}else{
				//use a loop to print out what professor teach what course 
				for(int i=0;i<counter;i++){
					//using i=0 as a base case if a course if only taught by one prof 
					if(i==0){
					
							printf("%s",profNames[location[i]]);
							//if there are 2 people who teach the same course 
					}else if(i==1&&counter==2){
						//print out the second professor name with and
							printf(" and %s",profNames[location[i]]);
						//if the array is at it's end and counter is not equal to 1 or 2 
					}else if(i==counter-1&&counter!=2&&counter!=1){
						//print out the professors name with and 
							printf(" and %s",profNames[location[i]]);
					}else{
						//if the professor's list goes on and does not have a ending then print the professors name with a comma 
						printf(", %s",profNames[location[i]]);
					}
				}
			
			}
			//reset the counter and make check false again or zero in this case
			counter=0;
				check =0;
				printf("\n");
			}
	

}