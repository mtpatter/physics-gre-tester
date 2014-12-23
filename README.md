physics-gre-tester
==================

Code I wrote a bored night a while ago that helps you practice for the Physics GRE by choosing questions for you and scoring/timing you.

Grab the five available Physics GRE practice exams.  Here's a good resource: [available exams](http://physgre.s3-website-us-east-1.amazonaws.com/exams.html)

* Test 1 = 1986 Exam (GR8677)
* Test 2 = 1992 Exam (GR9277)
* Test 3 = 1996 Exam (GR9677)
* Test 4 = 2001 Exam (GR0177)
* Test 5 = 2008 Exam (GR0877)

You input number of questions you feel like answering, and the program tells you how much time to give yourself to answer them.  The program will randomly choose questions from the five available tests.  You look up the question, work it out, input your answer, skip for later to come back to at the end, or leave blank.  Program gives you your score, an estimated score for a 100 question test, and times you based on the time you'll be allowed for the real exam.

Compile with:
```
gcc -lm practicetest.c -o testme
```

To practice with 10 questions:

```
testme 10
```

You should see:
```
You have asked for 10 questions, for example.
Answer with a capital letter always. 
To skip a question to answer later type 'S'. 
To leave an answer blank, type 'N'. 
Good luck!

Give yourself 17 minutes.
```
 

