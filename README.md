# DS-LAB-07
Q1. A university stores students marks in an integer array. Sort the marks in ascending order using
recursive Merge Sort.
Input: {78, 45, 92, 63, 45, 88, 51, 70}
Requirements:
  1. Implement mergeSort() and merge() as separate functions.
  2. Display the array after each merge operation.
  3. Count and display the total number of merge operations.
  4. Do not use a built-in sorting function.

Q2. An online store stores product prices in an array. Sort the prices in ascending order using Merge Sort.
Input: {1299, 499, 2499, 799, 499, 1599, 999, 299}
Requirements:
  1. Display the left and right subarrays before each merge.
  2. Count comparisons between elements of the two subarrays during merging.
  3. Display the final sorted prices and total comparisons.
  4. Do not use a built-in sorting function.

Q3. A data-processing system receives n integers, where n is not known at compile time.
Sample input:
n = 6
Array = 35 12 90 12 48 7
Requirements:
  1. Read n and allocate the input array dynamically.
  2. Implement recursive Merge Sort.
  3. Allocate the temporary merge array dynamically rather than using a fixed-size array.
  4. Count recursive calls, merge operations, and element comparisons.
  5. Handle n &lt;= 0 with an error message.
  6. Release all dynamically allocated memory.

Q4. A university wants to sort student marks in ascending order using Quick Sort. Always select the last
element of the current subarray as the pivot.
Input: {40, 20, 70, 10, 60, 30, 50}
Requirements:
  1. Implement recursive quickSort() and a separate partition().
  2. Always choose the last element as pivot.
  3. Display the pivot and subarray boundaries for every partition call.
  4. Display the array after every partition completes.
  5. Count partition operations.

Q5. A warehouse stores product IDs and chooses the first element of each subarray as pivot.
Input: {55, 25, 75, 15, 65, 35, 45}
Requirements:
  1. Implement Quick Sort using the first element as pivot.
  2. Write a partition function that correctly supports this pivot strategy.
  3. Display the pivot and array after each partition.
  4. Count element comparisons.

Q6. An online shopping platform assigns a numeric order ID to every customer order. The system
needs to sort these order IDs in ascending order without using any comparison-based sorting
algorithm. Show the frequency count, cumulative count, and output array for each pass.
arr[] = {329, 457, 657, 839, 436, 720, 355}

Q7. A hospital maintains numeric patient record IDs and needs to arrange them in ascending order to
simplify record retrieval. Write a C++ program that implements Radix Sort for the given IDs. Your
solution must handle numbers with different numbers of digits and display the array after every pass.
arr[] = {91, 8, 1024, 56, 305, 7, 120}

Q8. A courier company records numeric tracking IDs for parcels received at its distribution center.
The company wants to sort the tracking IDs in ascending order using the Least Significant Digit
(LSD) Radix Sort algorithm. Write a complete C++ program to perform the sorting, display the array
after every digit pass, and determine the total number of passes required.
arr[] = {94, 802, 7, 1234, 56, 321, 405, 18}

Q9. A logistics company stores numeric tracking IDs for parcels arriving at its distribution center. Before
parcels are dispatched, the system must arrange the tracking IDs in ascending order using LSD Radix Sort.
Write a complete C++ implementation of Radix Sort using a stable Counting Sort as the subroutine. Display
the original array, the frequency count array, the cumulative count array, and the output array during every
pass. After each pass, show how the output array is copied back to the original array. Your solution must
handle duplicate tracking IDs correctly, determine the total number of digit passes dynamically using the
maximum value.
trackingIDs[] = {4721, 305, 472, 89, 3005, 721, 1000, 305, 9999, 42, 870, 100}

Q10. A digital library stores books using numeric accession numbers. During a database migration,
the accession numbers must be sorted in ascending order, and repeated numbers must remain in their
original relative order. The input sequence is {7314, 314, 731, 34, 3147, 147, 47, 7314, 4,
314}.Design a Radix Sort solution that sorts these accession numbers without using comparison-
based sorting algorithms. Determine the maximum number of digit passes required, show the array
after every pass,
