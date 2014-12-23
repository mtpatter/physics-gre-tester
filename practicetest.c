// Maria Patterson
// Created:      08Sept2011
// Last Updated: 08Sept2011
//
// Compile with > "gcc -lm practicetest.c -o testme" 
// Must have the 5 input .txt files to run.
// These have the answers for the 5 available Physics GREs.
//
// Run program with > "testme NUM"
// where NUM = the number of questions you would like.
//
// TASK:
// Question chooser/ scorer for practicing the Physics GRE.
// Input the number of questions you would like to answer.
// This program will randomly select that number of questions
// from one of the five available tests.
// Selects question number, you look it up in the practice book, 
// you answer (A-E), skip for later (S), or leave blank (N).
// At the end of the test, you receive your score.
// Also times the test and lets you know how much time to
// give yourself for the number of questions you selected.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define ARRAYLIM 200
#define FILENMLIM 100
#define LINELIM 1000
#define TIME_SIZE 40
#define LOOPLIM 100

void shuffle(int *array, int *array2, size_t n);
char getInput();

int main( int argc, char **argv){
  double elapsedsec, elapsedmin;
  time_t start, end;

  FILE *fp1, *fp2, *fp3, *fp4, *fp5;
  int countright, countwrong, countnoanswer, countskip;
  int skippedquestionnumber[ARRAYLIM];
  int skippedtestquestion[ARRAYLIM];
  int skippedtestnumber[ARRAYLIM];
  int skippedanswer[ARRAYLIM];
  float rawscore;
  float score;
  float timeslot;
  int NUM, i,j1,j2,j3,j4,j5;
  int TESTNUMBER,HIGH1, LOW1;
  int QNUMBER1[ARRAYLIM],QNUMBER2[ARRAYLIM],QNUMBER3[ARRAYLIM];
  int QNUMBER4[ARRAYLIM],QNUMBER5[ARRAYLIM],HIGH2, LOW2;
  int shufftest1questionnumber[ARRAYLIM];
  int shufftest2questionnumber[ARRAYLIM];
  int shufftest3questionnumber[ARRAYLIM];
  int shufftest4questionnumber[ARRAYLIM];
  int shufftest5questionnumber[ARRAYLIM];
  int dum1_1[ARRAYLIM], dum1_3[ARRAYLIM];
  int test1questionnumber[ARRAYLIM], test1p[ARRAYLIM];
  char dum1_2[ARRAYLIM];
  char test1answerletter[ARRAYLIM];
  int dum2_1[ARRAYLIM], dum2_3[ARRAYLIM];
  int test2questionnumber[ARRAYLIM], test2p[ARRAYLIM];
  char dum2_2[ARRAYLIM];
  char test2answerletter[ARRAYLIM];
  int dum3_1[ARRAYLIM], dum3_3[ARRAYLIM];
  int test3questionnumber[ARRAYLIM], test3p[ARRAYLIM];
  char dum3_2[ARRAYLIM];
  char test3answerletter[ARRAYLIM];
  int dum4_1[ARRAYLIM], dum4_3[ARRAYLIM];
  int test4questionnumber[ARRAYLIM], test4p[ARRAYLIM];
  char dum4_2[ARRAYLIM];
  char test4answerletter[ARRAYLIM];
  int dum5_1[ARRAYLIM], dum5_3[ARRAYLIM];
  int test5questionnumber[ARRAYLIM], test5p[ARRAYLIM];
  char dum5_2[ARRAYLIM];
  char test5answerletter[ARRAYLIM];
  char answer[ARRAYLIM];
  char newline[LINELIM];
  char TEST1FILE[FILENMLIM]= "1solutions8677.txt";
  char TEST2FILE[FILENMLIM]= "2solutions9277.txt";
  char TEST3FILE[FILENMLIM]= "3solutions9677.txt";
  char TEST4FILE[FILENMLIM]= "4solutions0177.txt";
  char TEST5FILE[FILENMLIM]= "5solutions0877.txt";
  
  //////////////////////////////////////////////////////////////////////////////////////////////////
  //READ FROM COMMAND LINE THE NUMBER OF QUESTIONS.
  if ( argc != 2 ) {
    fputs ( "run with: $prog <number> \n", stderr );
    exit ( EXIT_FAILURE );
  }
  NUM = (int)strtol ( argv[1], NULL, 10 );  
  printf ( "You have asked for %d questions.\n", NUM );
  if ( argv[argc] == NULL )
    puts ( "Answer with a capital letter always. \nTo skip a question to answer later type 'S'. \nTo leave an answer blank, type 'N'. \nGood luck!\n" );
  //
  timeslot=1.7*NUM;
  printf ("Give yourself %g minutes.\n", timeslot);
  time (&start);
  
  //////////////////////////////////////////////////////////////////////////////////////////////////
   //SEEDS RANDOM NUMBER GENERATOR 
  //Declare variable to hold seconds on clock.
  time_t seconds;
  //Get value from system clock and
  //place in seconds variable.
  time(&seconds);
  //Convert seconds to a unsigned integer.
  srand((unsigned int) seconds);     
  
  //////////////////////////////////////////////////////////////////////////////////////////////////
   //READ ANSWER FILES
  if	((fp1 = fopen(TEST1FILE,"r")) == NULL)	{
    printf("Could not open input file: %s -", TEST1FILE);
    abort();
  }
  i=0;
  while (fgets(newline, sizeof(newline), fp1))	{
    if(newline[0] != '#') {
      if(  ((sscanf(newline,"%d %c %d", &dum1_1[i],&dum1_2[i],&dum1_3[i])) == 3)){
	test1questionnumber[i]=dum1_1[i]; 
	test1answerletter[i]=dum1_2[i];
	test1p[i]=dum1_3[i];
      }
    }
    //printf("%d %c %d\n", test1questionnumber[i], test1answerletter[i], test1p[i]);
    i++;
  }	
  fclose(fp1);

  if	((fp2 = fopen(TEST2FILE,"r")) == NULL)	{
    printf("Could not open input file: %s -", TEST2FILE);
    abort();
  }
  i=0;
  while (fgets(newline, sizeof(newline), fp2))	{
    if(newline[0] != '#') {
      if(  ((sscanf(newline,"%d %c %d", &dum2_1[i],&dum2_2[i],&dum2_3[i])) == 3)){
	test2questionnumber[i]=dum2_1[i]; 
	test2answerletter[i]=dum2_2[i];
	test2p[i]=dum2_3[i];
      }
    }
    //printf("%d %c %d\n", test2questionnumber[i], test2answerletter[i], test2p[i]);
    i++;
  }	
  fclose(fp2);

  if	((fp3 = fopen(TEST3FILE,"r")) == NULL)	{
    printf("Could not open input file: %s -", TEST3FILE);
    abort();
  }
  i=0;
  while (fgets(newline, sizeof(newline), fp3))	{
    if(newline[0] != '#') {
      if(  ((sscanf(newline,"%d %c %d", &dum3_1[i],&dum3_2[i],&dum3_3[i])) == 3)){
	test3questionnumber[i]=dum3_1[i]; 
	test3answerletter[i]=dum3_2[i];
	test3p[i]=dum3_3[i];
      }
    }
    //printf("%d %c %d\n", test3questionnumber[i], test3answerletter[i], test3p[i]);
    i++;
  }	
  fclose(fp3);

  if	((fp4 = fopen(TEST4FILE,"r")) == NULL)	{
    printf("Could not open input file: %s -", TEST4FILE);
    abort();
  }
  i=0;
  while (fgets(newline, sizeof(newline), fp4))	{
    if(newline[0] != '#') {
      if(  ((sscanf(newline,"%d %c %d", &dum4_1[i],&dum4_2[i],&dum4_3[i])) == 3)){
	test4questionnumber[i]=dum4_1[i]; 
	test4answerletter[i]=dum4_2[i];
	test4p[i]=dum4_3[i];
      }
    }
    //printf("%d %c %d\n", test4questionnumber[i], test4answerletter[i], test4p[i]);
    i++;
  }	
  fclose(fp4);
  
  if	((fp5 = fopen(TEST5FILE,"r")) == NULL)	{
    printf("Could not open input file: %s -", TEST5FILE);
    abort();
  }
  i=0;
  while (fgets(newline, sizeof(newline), fp5))	{
    if(newline[0] != '#') {
      if(  ((sscanf(newline,"%d %c %d", &dum5_1[i],&dum5_2[i],&dum5_3[i])) == 3)){
	test5questionnumber[i]=dum5_1[i]; 
	test5answerletter[i]=dum5_2[i];
	test5p[i]=dum5_3[i];
      }
    }
    //printf("%d %c %d\n", test5questionnumber[i], test5answerletter[i], test5p[i]);
    i++;
  }	
  fclose(fp5);

  i=0;

  ////////////////////////////////////////////////////////////////////////////////////////////////////////
  // SHUFFLE QUESTIONS
  shuffle(test1questionnumber,shufftest1questionnumber,100);
  shuffle(test2questionnumber,shufftest2questionnumber,100);
  shuffle(test3questionnumber,shufftest3questionnumber,100);
  shuffle(test4questionnumber,shufftest4questionnumber,100);
  shuffle(test5questionnumber,shufftest5questionnumber,100);
 
  ////////////////////////////////////////////////////////////////////////////////////////////////////////
  // CHOOSE QUESTIONS.
  j1=0;
  j2=0;
  j3=0;
  j4=0;
  j5=0;
  countright=0;
  countwrong=0;
  countnoanswer=0;
  countskip=0;
  
  for (i=0; i<(NUM) ; i++){
    
    // CHOOSE A TEST.
    LOW1=1;
    HIGH1=5;
    LOW2=1;
    HIGH2=100;
    TESTNUMBER=rand() % (HIGH1 - LOW1 + 1) + LOW1;
    printf ( "Question %d is from test %d", i+1, TESTNUMBER );
    
    if (TESTNUMBER==1){
      QNUMBER1[j1]=shufftest1questionnumber[j1];
      printf ( " and number %d. \n", QNUMBER1[j1] );
      answer[i]=getInput();
      printf( "You answered %c\n\n", answer[i]);
      //IF CORRECT ANSWER
      if ( answer[i] == test1answerletter[(QNUMBER1[j1]-1)]){
	countright++;
      }
      //IF NOT CORRECT ANSWER
      if ( ( answer[i] != test1answerletter[(QNUMBER1[j1]-1)]) && (answer[i] != 'N') && (answer[i] != 'S')){
	countwrong++;
      }
      //IF BLANK
      if ( ( answer[i] != test1answerletter[(QNUMBER1[j1]-1)]) && (answer[i] == 'N')){
	countnoanswer++;
      }
      //IF SKIPPED
      if ( ( answer[i]  == 'S')){
	skippedtestnumber[countskip]=1;
	skippedquestionnumber[countskip]=i+1;
	skippedtestquestion[countskip]=shufftest1questionnumber[j1];
	skippedanswer[countskip]=test1answerletter[(QNUMBER1[j1]-1)];
	//printf ( " and number %d. \n", QNUMBER1[j1] );
      printf( "You skipped this question.\n\n");
      countskip++;
      }
      
      j1++;
    }
    
    if (TESTNUMBER==2){
      QNUMBER2[j2]=shufftest2questionnumber[j2];
      printf ( " and number %d. \n", QNUMBER2[j2]);
      answer[i]=getInput();
      printf( "You answered %c\n\n", answer[i]);
      //IF CORRECT ANSWER
      if ( answer[i] == test2answerletter[(QNUMBER2[j2]-1)]){
	countright++;
      }
      //IF NOT CORRECT ANSWER
      if ( ( answer[i] != test2answerletter[(QNUMBER2[j2]-1)]) && (answer[i] != 'N') && (answer[i] != 'S')){
	countwrong++;
      }
      //IF BLANK
      if ( ( answer[i] != test2answerletter[(QNUMBER2[j2]-1)]) && (answer[i] == 'N' )){
	countnoanswer++;
      }
      //IF SKIPPED
      if ( ( answer[i]  == 'S')){
	skippedtestnumber[countskip]=2;
	skippedquestionnumber[countskip]=i+1;
	skippedtestquestion[countskip]=shufftest2questionnumber[j2];
	skippedanswer[countskip]=test2answerletter[(QNUMBER2[j2]-1)];
	//printf ( " and number %d. \n", QNUMBER1[j1] );
	printf( "You skipped this question.\n\n");
	countskip++;
      }
      j2++; 
    }
    
    if (TESTNUMBER==3){
      QNUMBER3[j3]=shufftest3questionnumber[j3];
      printf ( " and number %d. \n", QNUMBER3[j3] );
      answer[i]=getInput();
      printf( "You answered %c\n\n", answer[i]);
      //IF CORRECT ANSWER
      if ( answer[i] == test3answerletter[(QNUMBER3[j3]-1)]){
	countright++;
      }
      //IF NOT CORRECT ANSWER
      if ( ( answer[i] != test3answerletter[(QNUMBER3[j3]-1)]) && (answer[i] != 'N') && (answer[i] != 'S')){
	countwrong++;
      }
      //IF BLANK
      if ( ( answer[i] != test3answerletter[(QNUMBER3[j3]-1)]) && (answer[i] == 'N' )){
	countnoanswer++;
      }
       //IF SKIPPED
      if ( ( answer[i]  == 'S')){
	skippedtestnumber[countskip]=3;
	skippedquestionnumber[countskip]=i+1;
	skippedtestquestion[countskip]=shufftest3questionnumber[j3];
	skippedanswer[countskip]=test3answerletter[(QNUMBER3[j3]-1)];
	//printf ( " and number %d. \n", QNUMBER1[j1] );
      printf( "You skipped this question.\n\n");
      countskip++;
      }
      j3++;
    }
    
    if (TESTNUMBER==4){
      QNUMBER4[j4]=shufftest4questionnumber[j4];
      printf ( " and number %d. \n", QNUMBER4[j4] );
      answer[i]=getInput();
      printf( "You answered %c\n\n", answer[i]);
      //IF CORRECT ANSWER
      if ( answer[i] == test4answerletter[(QNUMBER4[j4]-1)]){
	countright++;
      }
      //IF NOT CORRECT ANSWER
      if ( ( answer[i] != test4answerletter[(QNUMBER4[j4]-1)]) && (answer[i] != 'N') && (answer[i] != 'S')){
	countwrong++;
      }
      //IF BLANK
      if ( ( answer[i] != test4answerletter[(QNUMBER4[j4]-1)]) && (answer[i] == 'N')){
	countnoanswer++;
      }
      //IF SKIPPED
      if ( ( answer[i]  == 'S')){
	skippedtestnumber[countskip]=4;
	skippedquestionnumber[countskip]=i+1;
	skippedtestquestion[countskip]=shufftest4questionnumber[j4];
	skippedanswer[countskip]=test4answerletter[(QNUMBER4[j4]-1)];
	//printf ( " and number %d. \n", QNUMBER1[j1] );
	printf( "You skipped this question.\n\n");
	countskip++;
      }
      j4++;
    }

    if (TESTNUMBER==5){
      QNUMBER5[j5]=shufftest5questionnumber[j5];
      printf ( " and number %d. \n", QNUMBER5[j5] );
      answer[i]=getInput();
      printf( "You answered %c\n\n", answer[i]);
      //IF CORRECT ANSWER
      if ( answer[i] == test5answerletter[(QNUMBER5[j5]-1)]){
	countright++;
      }
      //IF NOT CORRECT ANSWER
      if ( ( answer[i] != test5answerletter[(QNUMBER5[j5]-1)]) && (answer[i] != 'N') && (answer[i] != 'S')){
	countwrong++;
      }
      //IF BLANK
      if ( ( answer[i] != test5answerletter[(QNUMBER5[j5]-1)]) && (answer[i] == 'N')){
	countnoanswer++;
      }
      //IF SKIPPED
      if ( ( answer[i]  == 'S')){
	skippedtestnumber[countskip]=5;
	skippedquestionnumber[countskip]=i+1;
	skippedtestquestion[countskip]=shufftest5questionnumber[j5];
	skippedanswer[countskip]=test5answerletter[(QNUMBER5[j5]-1)];
	//printf ( " and number %d. \n", QNUMBER1[j1] );
	printf( "You skipped this question.\n\n");
	countskip++;
      }
      j5++;
    }
    
  }

  //GO BACK TO SKIPPED QUESTIONS
  printf("Let's go back to the questions you skipped.\n");
  i=0;
  for(i=0; i<countskip;i++){
    printf("You skipped question %d.\n", skippedquestionnumber[i]);
    printf("Question %d was from test %d question number %d.\n", skippedquestionnumber[i], skippedtestnumber[i], skippedtestquestion[i]);
 
    if(skippedtestnumber[i] ==1){
      answer[i]=getInput();
      printf( "You answered %c\n\n", answer[i]);
      //IF CORRECT
      if (answer[i]== skippedanswer[i]){
	countright++;
      }
      //IF NOT CORRECT
      if ( (answer[i] != skippedanswer[i]) && (answer[i]!='N')){
	countwrong++;
      }
      //IF BLANK
      if ( answer[i]=='N'){
	countnoanswer++;
      }
    }

    if(skippedtestnumber[i] ==2){
      answer[i]=getInput();
      printf( "You answered %c\n\n", answer[i]);
      //IF CORRECT
      if (answer[i]== skippedanswer[i]){
	countright++;
      }
      //IF NOT CORRECT
      if ( (answer[i] != skippedanswer[i]) && (answer[i]!='N')){
	countwrong++;
      }
      //IF BLANK
      if ( answer[i]=='N'){
	countnoanswer++;
      }
    }

    if(skippedtestnumber[i] ==3){
      answer[i]=getInput();
      printf( "You answered %c\n\n", answer[i]);
      //IF CORRECT
      if (answer[i]== skippedanswer[i]){
	countright++;
      }
      //IF NOT CORRECT
      if ( (answer[i] != skippedanswer[i]) && (answer[i]!='N')){
	countwrong++;
      }
      //IF BLANK
      if ( answer[i]=='N'){
	countnoanswer++;
      }
    }
    
    if(skippedtestnumber[i] ==4){
      answer[i]=getInput();
      printf( "You answered %c\n\n", answer[i]);
      //IF CORRECT
      if (answer[i]== skippedanswer[i]){
	countright++;
      }
      //IF NOT CORRECT
      if ( (answer[i] != skippedanswer[i]) && (answer[i]!='N')){
	countwrong++;
      }
      //IF BLANK
      if ( answer[i]=='N'){
	countnoanswer++;
      }
    }

    if(skippedtestnumber[i] ==5){
      answer[i]=getInput();
      printf( "You answered %c\n\n", answer[i]);
      //IF CORRECT
      if (answer[i]== skippedanswer[i]){
	countright++;
      }
      //IF NOT CORRECT
      if ( (answer[i] != skippedanswer[i]) && (answer[i]!='N')){
	countwrong++;
      }
      //IF BLANK
      if ( answer[i]=='N'){
	countnoanswer++;
      }
    }

  }
    
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //printf("%d %d %d %d %d\n", j1, j2, j3, j4,j5);
  
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  time (&end);
  elapsedsec= difftime (end,start); 
  elapsedmin= elapsedsec/60.0;
  printf("\nYou were aiming for %g minutes.\n", timeslot);
  printf("That took you %g minutes.\n", elapsedmin);

  printf("\nYou answered %d of %d correctly.\n", countright, NUM);
  printf("You answered %d of %d incorrectly.\n", countwrong, NUM);
  printf("You left %d of %d blank.\n\n", countnoanswer, NUM);

  rawscore=(countright)-(countwrong/4.0);
  score=(100.0/NUM)*rawscore;
  printf("Your raw score for %d questions is %g.\n", NUM, rawscore);
  printf("If you answered 100 questions at this rate\nyour score would be %g.\n",score);
  
  return 0;
}
// end of main program


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void shuffle(int *array, int *array2, size_t n)
{
  int count;
  if (n > 1) {
    size_t count;
    for (count = 0; count < n - 1; count++) {
      size_t j = count + rand() / (RAND_MAX / (n - count) + 1);
      int t = array[j];
      array2[j] = array[count];
      array2[count] = t;
    }
  }
  count=0;
}

char getInput()
{
   char line[10] = {0};

   while (true)
   {
      printf("Enter answer: ");
      fgets(line, sizeof(line), stdin);

      if (strlen(line) == 2 && (line[0] == 'A' || line[0] == 'B' || line[0] == 'C' || line[0] == 'D' || line[0] == 'E' || line[0] == 'S' || line[0] == 'N'))
      {
         break;
      }
      else
      {
         printf("Bad input (try uppercase?); try again...\n\n");

         const size_t pos = sizeof(line) - 1; 
         if (strlen(line) == pos && line[pos] != '\n') while (fgetc(stdin) != '\n');
      }
   }

   return line[0];
}
