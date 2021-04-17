/*
Student Name: Eason Liang   Email Id: eliang@uoguelph.ca
Due Date: October 7 2020  Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic
integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self
Test.
I assert that this work is my own. I have appropriately acknowledged any
and all material that I have used, whether directly quoted or
paraphrased. Furthermore, I certify that this assignment was prepared by
me specifically for this course.
*/

/* COMPILING INSTRUCTIONS 
  gcc LiangEasonA1.c -std=c99 -Wall
                or 
  gcc LiangEasonA1.c -std=c99 -Wall -o assn1
  
  RUNNING THE PROGRAM 
   ./a.out

*/
/*
Eason Liang 
October 4 2020 
This program is used as a travel agency to find the closest flight time and as well offer incentives such as hotels,rides and discounts
*/
#include <stdio.h>
#include <string.h>
//bubble sorting function where it accept an array parameters and the size of the array 
void SortDifferences(int a[], int size) {

  // run loops two times: one for walking throught the array
  // and the other for comparison
  for (int j = 0; j < size - 1; j++) {
    for (int i = 0; i < size- j - 1; ++i) {
      
      // Checks if the array in front to see if it's smaller than the from before   
      if (a[i] > a[i + 1]) {
        
        // swap if greater is at the rear position
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
      }
    }
  }
}
void SortDifferencesF(float a[], int size) {

  // run loops two times: one for walking throught the array
  // and the other for comparison
  for (int j = 0; j < size - 1; j++) {
    for (int i = 0; i < size - j - 1; i++) {
      
      // To sort in descending order, change">" to "<".
      if (a[i] > a[i + 1]) {
        
        // swap if greater is at the rear position
        float temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
      }
    }
  }
}
int main () {
  //Variables involved with time
  int timeFormat,hour,minute,conMin,diff[8],diffCon[8],smallest;
  //Variables involved with hotel and rides
  int hotel,pickHotel,days,ride;
  //Variables involved with the discount
  int sumOfDay,dayOfBirth,total2;
  float hotelCost,hotelRide;
  //Variables involved with the total pricing 
  float total,totalBeforeTax;
  //String variables used with the Time
  char ampm;
  char times[8][50] =
    { "7:15 a.m., arriving at 8:25 a.m.", "8:15 a.m., arriving at 9:25 a.m.",
"9:15 a.m., arriving at 10:25 a.m.", "10:15 a.m., arriving at 11:25 a.m.",
"11:15 a.m., arriving at 12:25 p.m.", "3:15 p.m., arriving at 4:25 p.m.",
"4:15 p.m., arriving at 5:25 p.m.", "5:15 p.m. arriving at 6:25 p.m." };
  //Cost of each flight
  float cost[8] = { 231, 226, 226, 283, 283, 226, 226, 401 };
  //Time converted into minutes 
  int TMin[8] = { 435, 495, 555, 615, 675, 915, 975, 1035 };
  //Used for pricing 
  float beforeTax = 0; 
  //Variables used to find the cheapest option 
  int shortestCost;
  float miniCost[3];
  float miniCost2[3];
  
  
  //loop use to gather user input which will be used to determine minimum price 
  for(int input =0;input < 3;input++){

    //everytime the loop is invoked it will set the total and beforetax to equal to zero 

    beforeTax = 0;
    total =0;

     //This is used to print out info about the time the person wants and also accepts an integer input and is accepted into the timeformat variable

     printf("Would you like to enter the time in 12-Hour Format (enter 1) or 24-Hour Format (enter 2)? ");
     scanf ("%d", &timeFormat);
      //checks if timeformat is = to one 
  if (timeFormat == 1)
    {
      //Asks the user for the hour and minutes in a 12 hour format and asks for am or pm 
     printf("\nEnter time in 12 hour format\n");
     printf ("\nEnter a value between 0 and 12 for hour: ");
     scanf ("%d", &hour);
     printf ("Enter a value between 0 and 60 for minutes: ");
     scanf ("%d", &minute);
     printf ("Enter a for am or p for pm: ");
     scanf (" %c", &ampm);
     printf("\n---------------------------");
    // if the variable am pm is equal to a 
      if (ampm == 'a'){
        //check if the hour is equal to 12 and if the minute is less than 10 
        if(hour == 12 && minute < 10 )
        {
          //outputs the time the user entered 
          printf ("\nYou entered %d:0%d am", hour, minute);
          printf("\nIn 24 hour format - you entered 0%d:0%d",hour-12 ,minute);
          printf("\n---------------------------");
  // if hour is equal to 12 but minute is greater or equal to 10 
        }
        else if(hour == 12 && minute >= 10)
        {
          //output the time 
          printf ("\nYou entered %d:%d am", hour, minute);
          printf("\nIn 24 hour format - you entered 0%d:%d",hour-12 ,minute);
          printf("\n---------------------------");
            // if hour is greater or equal to 10 and minute is not equal to 12 and minute is less than 10 
        }
        else if(hour >= 10 && minute <10 && hour < 12)
        {
          //output the time 
           printf ("\nYou entered %d:0%d am", hour, minute);
           printf("\nIn 24 hour format - you entered %d:0%d",hour ,minute);
           printf("\n---------------------------");
    // if hour is greater of equal to 10 and minute is greater and equal to 10 and hour is not equal to 12      
        }
        else if(hour >= 10 && minute >=10 && hour < 12)
        {
          //print out a specific time in 12 and 24 hour format 
           printf ("\nYou entered %d:%d am", hour, minute);
           printf("\nIn 24 hour format - you entered %d:%d",hour ,minute);
           printf("\n---------------------------");
            //if hour is less than 10 and minute is less than or equal to 10 and hour is not equal to 12 
        }
        else if(hour < 10 && minute < 10)
        {
          //outputs a speciifc time in 12 and 24 hours format 
           printf ("\nYou entered 0%d:0%d am", hour, minute);
           printf("\nIn 24 hour format - you entered 0%d:0%d",hour ,minute);
           printf("\n---------------------------");
            //when hours is less than 10 and minute is greater or equal to 10 and hours is not equal to 12 
        }
        else if(hour < 10 && minute >= 10)
        {
          //output a specific time in 12 and 24 hours format 
           printf ("\nYou entered 0%d:%d am", hour, minute);
           printf("\nIn 24 hour format - you entered 0%d:%d",hour ,minute);
           printf("\n---------------------------");
        }
        //if the hour is = to 12 then in this case hour becomes 0 as this value will be used later on in the program
	  if (hour == 12)
	    {
	      hour = 0;
	    }
    //Used to convert hours into minutes 
	  conMin = (hour * 60) + minute;

	}
  // in the scanf where it asks for timeformat is user enter p 
   else if (ampm == 'p') {

	// if hours equal to 12 and minute is less than 10 
	if(hour == 12 && minute < 10)
  {
    //outputs a specific time in 12 and 24 hour format 
    printf("\nYou entered %d:0%d pm", hour, minute);
    printf("\nIn 24 hour format - you entered %d:0%d",hour ,minute);
    printf("\n---------------------------");
  }
  //when hour equal and 12 and minute is greater or equal to 10 
  else if(hour == 12 && minute >= 10)
  {
    //outputs a specific time in 12 and 24 hour format 
    printf ("\nYou entered %d:%d pm", hour, minute);
    printf("\nIn 24 hour format - you entered %d:%d",hour ,minute);
    printf("\n---------------------------");
  }
  //when hour is less than 10 and minute is less than 10 and hour is not equal to 12
  else if(hour < 10 && minute < 10 ){
    //output a specific time in 12 and 24 hour format
    printf ("\nYou entered 0%d:0%d pm", hour, minute);
    printf("\nIn 24 hour format - you entered %d:0%d",hour+12 ,minute);
    printf("\n---------------------------");
  }
  // if hour is less than 10 and minute is greater or equal to 10 and hour is not equal to 12 
  else if(hour < 10 && minute >= 10)
  {
    //output the time in a 12 and 24 hour format 
    printf ("\nYou entered 0%d:%d pm", hour, minute);
    printf("\nIn 24 hour format - you entered %d:%d",hour+12 ,minute);
    printf("\n---------------------------");
  }
  //when hour is greater or equal to 10 and minute is less than 10 and hour is not equal to 12 
  else if(hour >= 10 && minute < 10 && hour< 12)
  { //output the time in a 12 or 24 hour format 
    printf ("\nYou entered %d:0%d pm", hour+12, minute);
    printf("\nIn 24 hour format - you entered %d:0%d",hour+12 ,minute);
    printf("\n---------------------------");
  }
  //when hour is greater or equal to 12 and minute is greater or equal to 10 and hour is not equal 12
  else if(hour >= 10 && minute >= 10&& hour < 12)
  { 
    //outputs the time entered in 12 and 24 hour format 
      printf ("\nYou entered %d:%d pm", hour, minute);
      printf("\nIn 24 hour format - you entered %d:%d",hour+12 ,minute);
      printf("\n---------------------------");
  }
  //if hour is greater than 1 and hours is not equal to 12 
	  if ((hour >= 1) && (hour != 12))
	    {
        //takes the pm hours and converts them to 24 hours after 12 hours 
	      conMin = ((hour * 60) + minute) + (12 * 60);
	    }
	  else
	    {
        // if hours is equal to 12 then hour+12 is not needed 
	      conMin = ((hour * 60) + minute);
        
	    }

	}
    }
    // when the user inputs 2 then the 24 hour format run 
    else if (timeFormat == 2)
    {
      // Asks the user to enter a value for the hour 0-24 and minutes 0-60 
        printf("\nEnter time in 24 hour format\n");
        printf ("\nEnter a value Between 0-24 for hour: ");
        scanf ("%d", &hour);
        printf ("Enter a value between 0-60 for minutes: ");
        scanf ("%d", &minute);
        printf("--------------------------");
    //When hour ==0 (12am) and minute is less than 10 
    if(hour == 0 && minute < 10)
    {
      //outputs the time in 12 and 24 hours format
       printf("\nYou entered 0%d:0%d",hour,minute);
       printf("\nIn 12 hour format - you entered %d:0%d am",hour+12,minute);
       printf("\n---------------------------");
    }
    //when hour is = to zero (12am) and minute is greater or equal to 10 
    else if(hour == 0 && minute >= 10)
    {
      //outputs the time in 24 and 12 hour format 
       printf("\nYou entered 0%d:%d",hour,minute);
       printf("\nIn 12 hour format - you entered %d:%d am",hour+12,minute);
       printf("\n---------------------------");
    }
    //if hours is less than or equal to 12 as well minute and hour are both less than 10 
     else if(minute < 10 && hour < 10){
       //outputs the time in 24 and 12 hour format 
       printf("\nYou entered 0%d:0%d",hour,minute);
       printf("\nIn 12 hour format - you entered 0%d:0%d am",hour,minute);
       printf("\n---------------------------");
     }
     // if hour is less than 12 or equal to 12 and minute is greater than 10 and hours is less than 10 
     else if(minute >=10 && hour < 10)
     {
        //outputs the time in 24 and 12 hour format  
       printf("\nYou entered 0%d:%d",hour,minute);
       printf("\nIn 12 hour format - you entered 0%d:%d am",hour,minute);
       printf("\n---------------------------");
     }
      //when hour is between 10 and 12 and minute is less than 10 
     else if( hour <=12 && minute <10 && hour >= 10)
     {
        //outputs the time in 24 and 12 hour format 
       printf("\nYou entered %d:0%d",hour,minute);
       printf("\nIn 12 hour format - you entered %d:0%d am",hour,minute);
       printf("\n---------------------------");
       
     }
     //when hours is between 10 and 12 and minute is greater or equal to 10 
     else if(hour <= 12 && minute >= 10 && hour >= 10)
     {
        //outputs the time in 24 and 12 hour format 
       printf("\nYou entered %d:%d",hour,minute);
       printf("\nIn 12 hour format - you entered %d:%d am",hour,minute);
       printf("\n---------------------------");
        
     } 
     //when hours is is between 12 and 22 and minute is less than 10 
     else if(hour >= 12 && minute <10 && hour < 22)
     {
        //outputs the time in 24 and 12 hour format 
       printf("\nYou entered %d:0%d",hour,minute);
       printf("\nIn 12 hour format - you entered 0%d:0%d pm",hour-12,minute);
       printf("\n---------------------------");
       
     }
     //when hours is between 10 and 22  and minute is greater or equal to 10 
     else if(minute >= 10 && hour < 22)
     {
      
       printf("\nYou entered %d:%d",hour,minute);
       printf("\nIn 12 hour format - you entered 0%d:%d pm",hour-12,minute);
       printf("\n---------------------------");
    
     } 
     //when hours is greater than 22 and less than 10 
     else if(minute <10 && hour >= 22)
     {
        //outputs the time in 24 and 12 hour format 
       printf("\nYou entered %d:0%d",hour,minute);
       printf("\nIn 12 hour format - you entered %d:0%d pm",hour-12,minute);
       printf("\n---------------------------");
      
     }
     //when hour is greater than 22 and minute is greater or equal to 10 
     else if(minute >= 10 && hour >= 22)
     {
         //outputs the time in 24 and 12 hour format 
       printf("\nYou entered %d:%d",hour,minute);
       printf("\nIn 12 hour format - you entered %d:%d pm",hour-12,minute);
       printf("\n---------------------------");
       
     }
    
      //takes the time and converts it into minutes 
      conMin = (hour * 60) + minute;

    }
  //loop used to add elements into the array 
  for (int i = 0; i < 8; i++)
    {
      //calculate the differnce between all the arriving times and the time you enereted and multiply itself to make it positive 
      diff[i] = (conMin - TMin[i]) * (conMin - TMin[i]);
      //This array diffcon will be used to be sorted later 
      diffCon[i] = diff[i];
    }
    //Sort the array from smallest to greatest 
  SortDifferences (diffCon, 8);
 //Go through the array 
  for (int index = 0; index < 8; index++) {
    //if the smallest array is equal to the original array 
      if (diffCon[0] == diff[index])
	     {
         //This value is the closes unit from 0 
	      smallest = index;
     	 }
    }

  //Take the cost of the flight and add it to the beforetax variable
  beforeTax = beforeTax + cost[smallest];

  //prints out the closes departure time 
  printf ("\nClosest departure Time is %s\n", times[smallest]);
  //Asks the user if they want a hotel 
  printf  ("\nWould you like a hotel in Montreal - enter 0 for no; 1 for yes? ");
  scanf ("%d", &hotel);
// if the user enters 1 being yes 
  if (hotel == 1)
    {
      //Asks the user what hotel they would want to stay in 
      printf("\nThere are 3 hotels:\n1. Marriott: $248 per night\n2. Sheraton: $90 per night\n3. Double Tree: $128 per night");
      printf ("\n\nYour choice?: ");
      scanf ("%d", &pickHotel);
      //Asks how many day they would like to stay in the hotel 
      printf ("How many days in Montreal? ");
      scanf ("%d", &days);
      //Asks the user if they want a ride from the airport to hotel 
    printf ("\nWould you like a ride from airport to hotel - enter 0 for no; 1 for yes? ");
	  scanf ("%d", &ride);
       //When the user wants a hotel and not a ride 
      if (pickHotel == 1 && ride == 0){
        //calculate the amount of days the person will stay in the hotel for 
        beforeTax = beforeTax + (248 * days);
        //sets cost of the hotel and the ride 
        hotelRide = 0;
        hotelCost = 248;
       
      }
       // When user picks hotel number 1 and wants a  ride 
      else if(pickHotel ==1 && ride == 1)
      {
        //Calculates the amount of days the person will stay in the hotel 
        beforeTax = beforeTax + (248 * days) + 0;
        //Sets costs of the hotel and the ride 
         hotelRide = 0;
         hotelCost = 248;
     
      }
       //when the user picks the 2nd option for the hotel but don't want a ride 
      else if(pickHotel == 2 && ride == 0)
      {
          //calculates the cost for the stay and sets costs of the hotel and the ride 
          beforeTax = beforeTax + (90 * days);
          hotelRide = 0;
          hotelCost = 90;
     
      }
       //When the user want to pick the 2nd hotel but wants a ride 
      else if(pickHotel == 2 && ride == 1)
      {
        //calculates the cost for the stay and sets costs of the hotel and the ride 
        beforeTax = beforeTax + (90 * days)+25;
        hotelRide = 25;
        hotelCost = 90;
      
      }
      //when the user picks the 3rd hotel but doesn't want a ride to the hotel
      else if(pickHotel == 3 && ride == 0)
      {
         //calculates the cost for the stay and sets costs of the hotel and the ride 
         beforeTax = beforeTax+ (128 * days);
         hotelRide =0;
         hotelCost =128;
        
      }
       //when the user picks the 3rd hotel but wants a ride to the hotel 
      else if(pickHotel == 3 && ride== 1)
      {
         //calculates the cost for the stay and sets costs of the hotel and the ride 
         beforeTax = beforeTax + (128 * days) + 20;
         hotelRide = 20;
        hotelCost = 128;
      }
      else 
      {
       //if the user enter a valid input sets the hotel cost,ride cost and days at the hotel to zero
        hotelCost =0;
        hotelRide =0;
        days = 0;
     
      }
    
    }
    //if the user doesn't want a hotel 
    else if(hotel==0)
    {
      //set the cost of hotel,ride, and days to zero 
        hotelCost = 0;
        hotelRide =0;
        days = 0;
    
    }
    // if user enters invalid input 
    else
    {
       //set the cost of hotel,ride, and days to zero 
       hotelCost = 0;
        hotelRide = 0;
        days = 0;
    }
    //Asks user for their day of birth which will be used later
  printf ("\nNow enter your day of birth to qualify for discount2: ");\
  scanf ("%d", &dayOfBirth);
  //Takes the sum of your day of birth example: 25 2+5 = 7 
  sumOfDay = (dayOfBirth)%10+(dayOfBirth/10);
  //outputs the total cost of the flight,hotel,ride and cost before taxes
  printf("\nYour total cost comes to:\n");
  printf("\nCost of closest departure flight: $ %.2f",cost[smallest]);
  printf("\nCost of Hotel for %d days: $ %.2f",days,hotelCost*days);
  printf("\nCost of Ride: $ %.2f",hotelRide);
  printf("\n\nTotal cost before Tax: $ %.2f\n",beforeTax);
  //use total2 to set beforetax as a integer 
   total2 = beforeTax;
   //check if total2 is a multiple of 11 
  if((total2 % 11) == 0){
    //apply the 5 percent discount
    beforeTax = beforeTax * 0.95;
     printf("\nYou get a 5%% discount because the total cost was a multiple of 11 :)");
      totalBeforeTax = beforeTax;
      //loops till total after discount 1 goes less than or = to 0 
    while(totalBeforeTax > 0)
    {
      totalBeforeTax = totalBeforeTax - sumOfDay;
    }
     if(totalBeforeTax == 0)
     {
       //applies an addiotnal 5 percent off 
        beforeTax = beforeTax * 0.95;
         printf("\nYou get an additional 5%% discount because the total cost after discount1 was a multiple of the sum of digits in your date of birth :)");
         //when totalBeforeTax==0 is false
      }
      else
      {
        //tells the user that they did not get discount 2 
         printf("\nSorry - you missed out on the additional 5%% discount because the total cost after discount1 was a not a multiple of the sum of digits in your day of birth");
      }
      //checks if the total before taxes and discount is a mutlple of sum of your birthday
  }
  else if((total2 % sumOfDay) == 0)
  {
    //if true 5 percent discount is applied 
      beforeTax = beforeTax * 0.95;
       printf("\nSorry - you missed out on 5%% discount because the total cost was not a multiple of 11");
       printf("\nYou get an additional 5%% discount because the total cost after discount1 was a multiple of the sum of digits in your date of birth :)");
      //user misses both discouns 
  }
  else
  {
      printf("\nSorry - you missed out on 5%% discount because the total cost was not a multiple of 11");
      printf("\nSorry - you missed out on the additional 5%% discount because the total cost after discount 1 was a not a multiple of the sum of digits in your day of birth");
  }
  //prints out the total cost after discount 1 and discount 2 regardless if their applied or not 
  printf("\n\nTotal cost after discounts 1 and 2: $ %.2f",beforeTax);
  //calculate tax
  total = beforeTax *1.13;
  //prints out final cost statement 
  printf("\n\nFinally, your total cost after taxes: $ %.2f\n",total);
  printf("--------------------------------------\n\n");
  //takes three different total and adds them to the array 
  miniCost[input] = total;
  miniCost2[input] = total;
  }

  //sort the 3 different total from smallest to largest 
  SortDifferencesF(miniCost2, 3);
  //go through the array 
  for(int j = 0;j<3;j++)
  {
    //look where the smallest element is 

    if(miniCost2[0]==miniCost[j]){
      //used in output statement later 
      shortestCost = j;
     
    }
  }
  //Displays the option with a minimum cost 
  printf("Option number %d is the best option for you with a minimum cost of $ %.2f\n",shortestCost+1,miniCost2[0]);
 
  return 0;
}