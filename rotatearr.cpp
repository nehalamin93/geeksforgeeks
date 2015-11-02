/* function to print an array */
#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int size);

/*Fuction to get gcd of a and b*/
int gcd(int a,int b);

/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n)
{
    int i,j,temp,a,t;
    for(i=0;i<d;i++)
    {
        t = n-1-i;
        temp = arr[t];
        while(t>=0)
        {
            a = arr[(t-d+n)%n];
            cout<<a<<' ';
            arr[(t-d+n)%n] = temp;
            temp = a;
            t = t-d;
        }
    }
}

/*UTILITY FUNCTIONS*/
/* function to print an array */
void printArray(int arr[], int size)
{
int i;
for(i = 0; i < size; i++)
	printf("%d ", arr[i]);
}

/*Fuction to get gcd of a and b*/
int gcd(int a,int b)
{
if(b==0)
	return a;
else
	return gcd(b, a%b);
}

/* Driver program to test above functions */
int main()
{
int arr[] = {1, 2, 3, 4, 5, 6, 7};
leftRotate(arr, 2, 7);
printArray(arr, 7);
getchar();
return 0;
}
