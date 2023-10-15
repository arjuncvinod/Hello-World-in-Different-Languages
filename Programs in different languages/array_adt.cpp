#include<iostream>
using namespace std;
struct array
{
    int *a;
    int size;
    int length=0;
};
void display(struct array *arr)
{
    int i;
    cout<<"\n elements are \n";
    for(i=0;i<arr->length;i++)
    cout<<arr->a[i]<<endl;
}
void append(struct array *arr,int x)
{
    if(arr->length<arr->size)
    arr->a[arr->length++]=x;
    display(arr);
}
int issorted(struct array *arr)
{
    for(int i=0;i<arr->length-1;i++)
    {
        if(arr->a[i]>arr->a[i+1])
        {
            return 0;
        }
    }
    return 1;
}
void insert(struct array *arr,int index,int x)
{
    if(issorted(arr))
    {
     int i=arr->length-1;
    while(x<=arr->a[i])
    {
        arr->a[i+1]=arr->a[i];
        i--;
    }
    arr->a[i+1]=x;   
    arr->length+=1;
    }
    else
    {
     int i;
    if(index>=0&&index<=arr->length)
    {
        for(i=arr->length;i>index;i--)
        arr->a[i]=arr->a[i-1];
            arr->a[index]=x;
            arr->length++;
    }
    }
}
int del(struct array *arr,int index)
{
    int i;
    int x=0;
    if(index>=0&&index<arr->length)
    {
        x=arr->a[index];
        for(i=index;i<arr->length;i++)
        arr->a[i]=arr->a[i+1];
        arr->length--;
        return x;
    }
    return 0;
}
void swap(int *x,int *y)
{
  int temp=*x;
 *x=*y;
 *y=temp;
}
int linearsearch(struct array *arr,int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(arr->a[i]==key)
        return i;
    }
    return -1;
}

int binarysearch(struct array arr,int x)
{
        int mid=0;
    int l=0;
    int h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr.a[mid]==x)
        {
            return mid;
        }
        else if(arr.a[mid]>x)
        {
            h=mid-1;  
        }
        else if(arr.a[mid]<x)
        {
            l=mid+1;
        }

    }
    return -1;

}
int rbinsearch(int a[],int l,int h,int x)
{
        int mid=0;
    mid=(l+h)/2;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(a[mid]==x)
        {
            return mid;
        }
        else if(a[mid]>x)
        {
            h=mid-1;
            return rbinsearch(a,l,h,x);   
        }
        else if(a[mid]<x)
        {
            l=mid+1;
            return rbinsearch(a,l,h,x);    
        }

    }
    return -1;
}
int get(struct array arr,int index)
{
    if(index>=0&&index<arr.length)
    return arr.a[index];

    return -1;
}
void set(struct array *arr,int index,int x)
{
    if(index>=0&&index<arr->length)
    arr->a[index]=x;
}
int max(struct array arr)
{
    int max=arr.a[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.a[i]>max)
        max=arr.a[i];
    }
    return max;
}
int min(struct array arr)
{
     int min=arr.a[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.a[i]<min)
        min=arr.a[i];
    }
    return min;
}
int sum(struct array arr)
{
    int sum=0;
    for(int i=0;i<arr.length;i++)
    sum=sum+arr.a[i];
    return sum;
}
float avg(struct array arr)
{
    int sum=0;
    for(int i=0;i<arr.length;i++)
    sum=sum+arr.a[i];
    return (sum/arr.length);
}
void reverse(struct array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(arr->a[i],arr->a[j]);
    }
}
void rearrange(struct array *arr)
{
    int i=0;
    int j=arr->length-1;
    while(i<j)
    {
        while(arr->a[i]<0)
        i++;
        while(arr->a[j]>0)
        j--;
        if(i<j)
        swap(arr->a[i],arr->a[j]);
    }
}
struct array* merge(struct array *arr1,struct array *arr2)
{
    int i=0,j=0,k=0;
    struct array *arr3= new struct array ;
    while(i<arr1->length&&j<arr2->length)
    {
        if(arr1->a[i]<arr2->a[j])
        arr3->a[k++]=arr1->a[i++];
        else
        arr3->a[k++]=arr2->a[j++];
    }
    for(;i<arr1->length;i++)
    arr3->a[k++]=arr1->a[i++];
    for(;j<arr2->length;j++)
    arr3->a[k++]=arr2->a[j];
    arr3->size=10;
    arr3->length=arr1->length+arr2->length;
    
    display(arr3);
    return 0;
}
array uni(array *arr1,array *arr2)
{
    array arr3;
    arr3.length=0;
    arr3.size=arr1->size+arr2->size;
    int i=0,j=0,k=0;
    while(i<arr1->length&&j<arr2->length)
    {
        if(arr1->a[i]<arr2->a[j])
        {
                    arr3.a[k++]=arr1->a[i++];
                arr3.length++;
        }
        else if(arr1->a[i]>arr2->a[j])
        {
            arr3.a[k++]=arr2->a[j++];
        arr3.length++;
        }
        else
        {
            arr3.a[k++]=arr2->a[j++];
            i++;
            arr3.length++;
        }
 
    }
    for(;i<arr1->length;i++)
    {
        arr3.a[k++]=arr1->a[i];
        arr3.length++;
    }
    for(;j<arr2->length;j++)
    {
        arr3.a[k++]=arr2->a[j];
        arr3.length++;
    }

    return arr3;
}
array intersection(array *arr1,array *arr2)
{
    array arr3;
    arr3.length=0;
    arr3.size=arr1->size+arr2->size;
    int i=0,j=0,k=0;
    while(i<arr1->length&&j<arr2->length)
    {
        if(arr1->a[i]<arr2->a[j])
        {
            i++;
        }
        else if(arr1->a[i]>arr2->a[j])
        {
            j++;
        }
        else
        {
            arr3.a[k++]=arr2->a[j++];
            i++;
            arr3.length++;
        }
 
    }

    return arr3;
}
array set_diffrence(array *arr1,array *arr2)
{
    array arr3;
    arr3.length=0;
    arr3.size=arr1->size+arr2->size;
    int i=0,j=0,k=0;
    while(i<arr1->length&&j<arr2->length)
    {
        if(arr1->a[i]<arr2->a[j])
        {
            arr3.a[k++]=arr1->a[i++];
            arr3.length++;
        }
        else if(arr1->a[i]>arr2->a[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
 
    }
    for(;i<arr1->length;i++)
    {
        arr3.a[k++]=arr1->a[i];
        arr3.length++;
    }

    return arr3;

}
int set_membership(array *arr,int key)
{
    int l=0;
    int h=arr->length-1;
    while(l<=h)
    {
        int mid=(h+l)/2;
        if(key==arr->a[mid])
        {
            cout<<"its a member\n";
            return 0;
        }
        else if(key<arr->a[mid])
        {
            h=mid-1;
            mid=(l+h)/2;
        }
        else if(key>arr->a[mid])
        {
            l=mid+1;
            mid=(l+h)/2;
        }

    }
    return -1;
}
int main()
{
    struct array arr1;
    int ub,ch;
    int x,index;
    cout<<"enter size and length of array respectively: ";
    cin>>arr1.size>>arr1.length;
    arr1.a=new int[arr1.size];
    cout<<"enter element of  array one by one:\n";
    for(int i=0;i<arr1.length;i++)
    cin>>arr1.a[i];
    do
    {
    cout<<"wht type of operations u want to perform unary 1:(insert,search)\n or \n2:binary(merge)\n or \n 0: for exit enter your choice:  ";
    cin>>ub;
    if(ub==1)
    {
        do
        {
            cout<<"here is menu of unary operations\n press \n (1) for: display \n (2) for: append/add a value \n (3) for: insert \n (4) for: delete \n (5) for linear search \n (6) for binary search \n (7) for recursivebinary search \n (8) for Getting index of value \n (9) to set a value at an index \n (10) to find maximum value in array \n (11) to find minimum value \n (12) to get sum of all value of array \n (13) to find average of all value \n (14) to reverse the array \n (15) to rarrange -ve on left side and +ve on right side \n press ( 0 ) to go back... ";
            cin>>ch;
            switch (ch)
            {
                case 1:
                display(&arr1);
                break;
                case 2:
                cout<<"enter the value to add in array: ";
                cin>>x;
                append(&arr1,x);
                break;
                case 3:
                cout<<"enter the index and value respectively :";
                cin>>index>>x;
                insert(&arr1,index,x);
                break;
                case 4:
                cout<<"enter the index to be deleted: ";
                cin>>index;
                del(&arr1,index);
                break;
                case 5:
                cout<<"enter the value to be linear search: ";
                cin>>x;
                cout<<linearsearch(&arr1,x)<<endl;
                break;
                case 6:
                cout<<"enter the value to be binary search: ";
                cin>>x;
                cout<<binarysearch(arr1,x)<<endl;
                break;
                case 7:
                cout<<"enter the value to be rbinary search: ";
                cin>>x;
                cout<<rbinsearch(arr1.a,0,arr1.length-1,x)<<endl;
                break;
                case 8:
                cout<<"enter the index to find value: ";
                cin>>index;
               cout<<get(arr1,index);
               break;
               case 9:
               cout<<"enter index and value respectively: ";
               cin>>index>>x;
               set(&arr1,index,x);
               break;
               case 10:
               cout<<max(arr1)<<endl;
               break;
               case 11:
               cout<<min(arr1)<<endl;
               break;
               case 12:
               cout<<sum(arr1)<<endl;
               break;
               case 13:
               cout<<avg(arr1)<<endl;
               break;
               case 14:
               reverse(&arr1);
               break;
               case 15:
               rearrange(&arr1);
               break;
               default:
            
               break;
            }

        } while (ch);
    }
    else if(ub==2)
    {
            struct array arr2;
            cout<<"enter size and length of  2nd array respectively: ";
            cin>>arr2.size>>arr2.length;
            arr2.a=new int[arr2.size];
            cout<<"enter element of 2nd array one by one:\n";
            for(int i=0;i<arr2.length;i++)
            cin>>arr2.a[i];
            
        do
        {
            cout<<" here is binary operations menu of array:\n press...  \n (1) for merging array \n (2) for finding union \n (3) to find intersection \n (4) to find difference A-B \n press ( 0 ) to go back to main menu....\n";
            cin>>ch;
            switch (ch)
            {
            case 1:
            merge(&arr1,&arr2);
            break;
            case 2:
            uni(&arr1,&arr2);
            break;
            case 3:
            intersection(&arr1,&arr2);
            break;
            case 4:
            set_diffrence(&arr1,&arr2);
            break;
            default:
            break;
            }

        } while (ch);
        
    }
    } while (ub);
    
    return 0;
}