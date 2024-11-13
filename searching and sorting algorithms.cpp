
#include<iostream>
#include<time.h>
using namespace std;

void swap(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

int partition(int arr[], int lb, int ub)
{
    int pivot=arr[ub];
    int i=lb-1;//ub
    for(int j=lb;j<ub-1;j++,i++)
    {
        if(arr[j]<pivot)
        {
            swap(arr[j],arr[i]);
        }
    }
	swap(arr[i+1],arr[ub]);
    return i+1;
}



void divide(int arr[], int lb, int ub)
{
    if(lb<ub)
    {
        int l=partition(arr,lb,ub);
        divide(arr, lb, l-1);
        divide(arr, l+1, ub);
    }
}
void merge(int arr1[], int lb, int c, int ub)
{
   int i=lb, j=c+1, k=0, b[1000];
   while(i<=c && j<=ub)
   {
       if(arr1[i]<=arr1[j])
       {
           b[k]=arr1[i];
           i++;
       }
       else
       {
           b[k]=arr1[j];
           j++;
       }
       k++;
   }
   while(j<=ub)
   {
       b[k]=arr1[j];
       j++;
       k++;
   }
   while(i<=c)
   {
       b[k]=arr1[i];
       i++;
       k++;
   }
   for(int i=0;i<k;i++)
   {
       arr1[i+lb]=b[i];
   }
}

void mergesort(int arr[], int lb, int ub)
{
	int c=(ub+lb)/2;
	mergesort(arr, lb, c);
	mergesort(arr, c+1, ub);
	merge(arr, lb, c,ub);
}


int IPS(int arr[], int n, int search)
{
    int lb=0, ub=n-1, c, gap;
    gap = (ub - lb) ? (arr[lb + 1] - arr[lb]) : 1; // Avoid division by zero
    while (lb <= ub)
    {
        c = lb + ((ub - lb) * (search - arr[lb])) / gap;
        if (arr[c] == search)
        {
            return c;
        }
        else if (arr[c] > search)
        {
            ub = c - 1;
        }
        else
        {
            lb = c + 1;
        }
    }
    return -1;
}

//binary ssearch
int BS(int arr[], int n, int search)
{
    int lb=0,ub=n-1,c;
    while(lb<=ub)
    {
        c=(ub+lb)/2;
        if(arr[c]==search)
        {
            return c;
        }
        else if(arr[c]>search)
        {
            
            ub=c-1;
        }
        else 
        {
            lb=c+1;
        }
    }
    return -1;
}

void display(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

void SelectionSort(int arr[], int n){
	int min_index;
	
	for (int i = 0; i < n; i++){
		min_index = i;
		for(int j = i + 1; j < n; j++){
			if(arr[j] < arr[min_index]){
				min_index = j;
			}		
		}
		swap(arr[i],arr[min_index]);
	}
}

void BubbleSort(int arr[], int n){
	bool swapped;
		
	for (int i = 0; i < n-1; i++){
		swapped = false;
		for(int j = 0; j < n-i-1; j++){
			if (arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		if (swapped == false){
			break;
		}
	}
}

void InsertionSort(int arr[], int n) 
{
	int j;
    for(int i=1; i<n; i++){
    	int key = arr[i];
    	for(j = i - 1; j>=0 && arr[j] > key; j--){
    		arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
}


int main()
{
	int arr1[10];
	again:
	srand(time(0));
	for(int i=0;i<10;i++)
	{
		arr1[i]=rand()%101;
	}
	char type;
    cout<<"\nEnter s for quick sort and merge sort, t for merge sorting, u for bubble sort, v for insertion sort, w for selection sort:";
	cin>>type;
	switch(type)
	{
    	 case 's':
        {
    	    cout<<"Quick sort:";
        	divide(arr1, 0,10);
        	display(arr1,10);
        	break;
        }
    	case 't':
    	{
        	cout<<"Merge sort:";
            mergesort(arr1,1,10);
        	display(arr1,10);
            break;
    	}
    	case 'w':
    	{
        	cout<<"Selection sort:";
            SelectionSort(arr1,10);
        	display(arr1,10);
            break;
    	}
    	case 'u':
    	{
        	cout<<"Bubble sort:";
            BubbleSort(arr1,10);
        	display(arr1,10);
            break;
    	}
    	case 'v':
    	{
        	cout<<"Insertion sort:";
            InsertionSort(arr1,10);
        	display(arr1,10);
            break;
    	}
	}
	goto again;
}