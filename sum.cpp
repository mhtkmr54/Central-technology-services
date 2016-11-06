#include <stdio.h>
 
int equilibrium(int arr[], int n)
{
   int sum = 0;      // initialize sum of whole array
   int leftsum = 0; // initialize leftsum
   int i;
 
   /* Find sum of the whole array */
   for (i = 0; i < n; ++i)
        sum += arr[i];
 
   for( i = 0; i < n; ++i)
   {
      sum -= arr[i]; // sum is now right sum for index i
 
      if(leftsum == sum)
        return i;
 
      leftsum += arr[i];
   }
 
    /* If no equilibrium index found, then return 0 */
    return -1;
}
 
int main()
{
  int arr[] = {-7, 1, 5, 2, -4, 3, 0};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printf("First equilibrium index is %d\n", equilibrium(arr, arr_size));
 
  getchar();
  return 0;
}


1) Initialize leftsum  as 0
2) Get the total sum of the array as sum
3) Iterate through the array and for each index i, do following.
    a)  Update sum to get the right sum.  
           sum = sum - arr[i] 
       // sum is now right sum
    b) If leftsum is equal to sum, then return current index. 
    c) leftsum = leftsum + arr[i] // update leftsum for next iteration.
4) return -1 // If we come out of loop without returning then
             // there is no equilibrium index







             select s.rollNo, s.name
from student s
where s.advisor IN
(select empId
from professor
where sex = ‘F’);



select f.empId, f.name
where EXISTS ( select s.rollNo
from student s
where s.advisor = f.empId and
s.sex = ‘F’ );

select d.deptId, d.name
from department d
where NOT EXISTS ( select courseId
from course c
where c.deptNo = d.deptId and
c.credits = ‘4’ );

(SELECT rollNo
FROM enrollment
WHERE courseId = ‘CS230’ and
sem = odd and year = 2005 ) UNION
(SELECT rollNo
FROM enrollment
WHERE courseId = ‘CS232’ and
sem = odd and year = 2005 );

Select max(marks), min(marks), avg(marks)
from gateMarks
where city = ‘Hyderabad’;

Select regNo, name, marks
from gateMarks
where branch = ‘EC’ and marks =
                  (select max(marks)
                  from gateMarks
                  where branch = ‘EC’);

having

Select courseId, count(rollNo) as Enrollment
from enrollment
where sem = 2 and year = 2004
group by courseId
having count(rollNo) ≥ 10;


select f.name
from (professor as f join department as d on
f.deptNo = d.deptId)
where d.name = ‘CSE’;
