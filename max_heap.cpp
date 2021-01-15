#include<iostream>
#include<climits>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class maxheap
{
    int *arr;
    int capacity;
    int heap_size;

public: 
    maxheap(int capacity);

    void maxheapify(int i);

    int parent(int i)
    {
        return (i-1)/2;
    }

    int left(int i)
    {
        return (2*i+1);
    }

    int right(int i)
    {
        return (2*i+2);
    }

    int extractmax();

    void increasekey(int i, int new_value);

    void deletekey(int i);

    void insertkey(int k);

    int getmax()
    {
        return arr[0];
    }
};

maxheap::maxheap(int cap)
{
    heap_size = 0;
    capacity = cap;
    arr = new int[cap];
}



void maxheap::maxheapify(int  i)
{
    int l = left(i);
    int r = right(i);
    int greatest = i;
    if (l<heap_size && arr[l]>arr[i])
        greatest = l;
    if (l<heap_size && arr[r]>arr[greatest])
        greatest = r;
    if (greatest != i)
    {
        swap(&arr[i], &arr[greatest]);
        maxheapify(greatest);
    }  
}

int maxheap::extractmax()
{
    if (heap_size<=0)
        return INT_MIN;
    if (heap_size == 1)
    {
        heap_size--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    maxheapify(0);

    return root;
}

void maxheap::increasekey(int i, int new_value)
{
    arr[i] = new_value;
    while(i!=0 && arr[parent(i)]<arr[i])
    {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

void maxheap::deletekey(int i)
{
    increasekey(i, INT_MAX);
    extractmax();
}

void maxheap::insertkey(int value)
{
    if (heap_size == capacity)
    {
        cout<<"\nOverflow";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    arr[i] = value;

    while(i!=0 && arr[parent(i)]<arr[i])
    {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

void heapsort(maxheap h)
{
    int val;
    while(true)
    {
        val = h.extractmax();
        if (val == INT_MIN)
            break;
        cout<<val<<" ";
    }
    cout<<endl;
}

int main()
{
    cout<<"Your Choice:";
    cout<<"\n(1) for inserting key\n(2) for extracting maximum value\n(3) for incresing key\n(4) for gettig maximum key\n(5) for sorting\n(6) exit";
    int choice = 1, temp, pos;
    maxheap h(20);
    while (choice != 6)
    {
    switch (choice)
    {
    case 1:
        cout<<"\nEnter key: ";
        cin>>temp;
        h.insertkey(temp);
        break;

    case 2:
        cout<<"\nMaximum: "<<h.extractmax();
        break;
    
    case 3:
        cout<<"\nEnter position and new value: ";
        cin>>pos>>temp;
        h.increasekey(pos, temp);
        break;

    case 4:
        cout<<"\nMaximum key: "<<h.getmax();
        break;
    
    case 5:
        cout<<"\nSorted array is:\n";
        heapsort(h);
        break;
    case 6:

    default:
        break;
    }
    cout<<"\nYour Choice:";
    cin>>choice;
    }
}