#include<bits/stdc++.h>
using namespace std;
 
// Returns the length and the LCIS of two
// arrays arr1[0..n-1] and arr2[0..m-1]
int LCIS(int arr1[], int n, int arr2[], int m)
{
    // table[j] is going to store length of LCIS
    // ending with arr2[j]. We initialize it as 0,
    int table[m];
    for (int j=0; j<m; j++)
        table[j] = 0;
 
    // Traverse all elements of arr1[]
    for (int i=0; i<n; i++)
    {
        // Initialize current length of LCIS
        int current = 0;
 
        // For each element of arr1[], traverse all
        // elements of arr2[].
        for (int j=0; j<m; j++)
        {
            // If both the array have same elements.
            // Note that we don't break the loop here.
            if (arr1[i] == arr2[j])
                if (current + 1 > table[j])
                    table[j] = current + 1;
 
            /* Now seek for previous smaller common
               element for current element of arr1 */
            if (arr1[i] > arr2[j])
                if (table[j] > current)
                    current = table[j];
        }
    }
 
    // The maximum value in table[] is out result
    int result = 0;
    for (int i=0; i<m; i++)
        if (table[i] > result)
           result = table[i];
 
    return result;
}
 
/* Driver program to test above function */
int main()
{
    int arr1[] = {3, 4, 9, 1};
    int arr2[] = {5, 3, 8, 9, 10, 2, 1};
 
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
 
    cout << "Length of LCIS is "
         << LCIS(arr1, n, arr2, m);
    return (0);
}
