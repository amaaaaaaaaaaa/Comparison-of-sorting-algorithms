#include <stdio.h>
#include <stdlib.h>

void randomize_array(int randArray[], int sz)
{
    int i;
    for(i=0; i<sz; i++)
        randArray[i]=rand()%10000;
    for(i=0; i<sz; i++)
        printf("%d ",randArray[i]);
    printf("\n\n");
}

void print_array (int array[], int sz)
{
    printf("%s \n","The sorted array is:");
    int i;
    for ( i=0; i<sz; i++)
        printf("%d ", array[i]);
}

void BubbleSort(int array[], int sz)
{
    int i,j;
    for (i=0; i<sz-1; i++)
        for ( j=0; j<sz-i-1; j++)
            if (array[j]>array[j+1])
            {
                int aux=array[j];
                array[j]=array[j+1];
                array[j+1]=aux;
            }
}
void SelectionSort(int array[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (array[j] < array[min_idx])
                min_idx = j;
        if(min_idx != i)
        {
            int aux=array[min_idx];
            array[min_idx]=array[i];
            array[i]=aux;
        }
    }
}
void InsertionSort(int array[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void heapify(int array[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && array[left] > array[largest])
        largest = left;
    if (right < n && array[right] > array[largest])
        largest = right;
    if (largest != i)
    {
        int aux=array[i];
        array[i]=array[largest];
        array[largest]=aux;
        heapify(array, n, largest);
    }
}
void HeapSort(int array[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);
    for ( i = n - 1; i >= 0; i--)
    {
        int aux=array[0];
        array[0]=array[i];
        array[i]=aux;
        heapify(array, i, 0);
    }
}


int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i= low - 1,j;
    for ( j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            int aux=array[i];
            array[i]=array[j];
            array[j]=aux;
        }
    }
    int aux=array[i+1];
    array[i+1]=array[high];
    array[high]=aux;
    return i + 1;
}
void QuickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        QuickSort(array, low, pi - 1);
        QuickSort(array, pi + 1, high);
    }
}


void Merge(int array[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort(int array[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSort(array, l, m);
        MergeSort(array, m + 1, r);
        Merge(array, l, m, r);
    }
}


int getMax(int array[], int n)
{
    int max = array[0],i;
    for (i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}
void BucketSort(int array[], int n)
{
    int max = getMax(array, n);
    int bucket[max], i,j;
    for (i = 0; i <= max; i++)
        bucket[i] = 0;
    for ( i = 0; i < n; i++)
        bucket[array[i]]++;
    for ( i = 0, j = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            array[j++] = i;
            bucket[i]--;
        }
    }
}

void CountingSort(int array[], int size)
{
    int output[100000];
    int max = array[0],i;
    for ( i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    int count[100000]= {0};
    for ( i = 0; i < size; i++)
        count[array[i]]++;
    for ( i = 1; i <= max; i++)
        count[i] += count[i - 1];
    for (i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for ( i = 0; i < size; i++)
        array[i] = output[i];
}

void countingSort(int array[], int n, int place)
{
  int output[n + 1],i;
  int count[100000] = {0};
  for (i = 0; i < n; i++)
    count[(array[i] / place) % 10]++;
  for (i = 1; i < 100000; i++)
    count[i] += count[i - 1];
  for ( i = n - 1; i >= 0; i--)
    {
    output[count[(array[i] / place)%10]-1]=array[i];
    count[(array[i] / place) % 10]--;
  }

  for ( i = 0; i < n; i++)
    array[i] = output[i];
}

void RadixSort(int array[], int n)
{

    int max = getMax(array, n),place;
    for ( place = 1; max / place > 0; place *= 10)
        countingSort(array, n,place);
}
int main()
{
    int sz;
    printf("Enter the size of array:");
    scanf("%d",&sz);
    int randArray[sz], i;
    randomize_array(randArray,sz);
    HeapSort(randArray,sz);
    print_array(randArray,sz);
    return 0;
}
