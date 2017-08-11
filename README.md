# Algrithem
Solutions to some algrithem questions


1. Number if tasks running:

  Given n tasks that start and end at (unix) time:(n < 1000)

          [start 1, end 1), [start 2, end 2), ... , [start n, end n)
          of which all starting times are inclusive and all ending times are exclusive

  Write code to efficiently return the number of tasks that are running at m given times:(m > 100000)
          query 1, query 2, ... , query m

  Function Definition

  void number_of_tasks_running(
                               OUT int number_of_tasks_running[],
                               IN     int start[],
                               IN     int end[],
                               IN     int n,
                               IN     int query[],
                               IN     int m) 
  {

  }

  Example

  input: 

         n = 3;
         m = 4;
         start = [0, 5, 2];
         end = [4, 7, 8];
         query = [1, 9, 4, 3];

  output:

         [1, 0, 1, 2]


2. Find missed number:
  
  Given an array which have n-1 items,

  the range of this items is [1, n],

  the array missed one of them,

  Write code to find the missed number.

  Function Definition

  int find_missed_number(
  						 int array[],
  						 int n)

  {

  }

 input:

 	    int array[] = {1, 2, 4};
 	    n = 4;

 output:

 		3;







