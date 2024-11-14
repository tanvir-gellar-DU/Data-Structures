#include<stdio.h>
int a[]={20,30,40,50,55,67,78,80,90};
int binarysearch(int size,int element)
{
    int low,mid,high;
    low=0;
    high=size-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==element)
        return mid;
        else if(a[mid]>element)
          high=mid-1;
        else
           low=mid+1;  
    }
    return -1;
}
int main()
{
    int size=sizeof(a)/sizeof(int);
    int b=binarysearch(size,50);
    if(b==-1)
    printf("not found");
    else
    printf("%d is founded at %d index",a[b],b);
    return 0;

}