#include <stdio.h>
#include <stdlib.h>
void readArr(int *arr,int n)
{
    printf("\nEnter the array elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",arr+i);
}
void displayEle(int *arr,int n)
{
    if(n==0)
    {
        printf("\nEmpty array,nothing to diaplay.\n\n");
        return;
    }
    printf("\n\n*************************************\n\n");
    printf("\nArray elements are:\n");
    for(int i=0;i<n;i++)
        printf("%d\t",*(arr+i));
    printf("\n\n\n*************************************\n\n");
}
void insertEle(int *arr,int *n)
{
    int ind,ele;
    printf("\nEnter the position to insert an element:\t");
    scanf("%d",&ind);
    ind--;
    if(ind>*n)
    {
        printf("\nInvalid position for insertion.\n");
        return;
    }
    printf("\nEnter the element to be inserted at position %d:\t",ind+1);
    scanf("%d",&ele);
    if(ind==*n)
    {
        *(arr+(*n))=ele;
        (*n)++;
        return;
    }
    else
    {
        int i=*n;
        for(;i>=ind;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[ind]=ele;
        (*n)++;
        return;
    }

}
void deleteEle(int *arr,int *N)
{
    if(*N==0)
    {
        printf("\nEmpty array,nothing to delete.\n\n");
        return;
    }
    int ind,n=*N;
    printf("\nEnter the position to delete an element:\t");
    scanf("%d",&ind);
    ind--;
    if(ind>=0 && ind<=n-1)
    {
        printf("\n%d is deleted from the array.\n",*(arr+ind));
        int i=ind;
        for(;i<=n-1;i++)
        {
            arr[i]=arr[i+1];
        }
        (*N)--;
    }
    else
    {
        printf("\nInvalid position for insertion.\n");
        return;
    }
}
void searchEle(int *arr,int n)
{
    if(n==0)
    {
        printf("\nEmpty array,nothing to search.\n\n");
        return;
    }
    int key,i=0;
    printf("\nEnter the key element to be searched:\t");
    scanf("%d",&key);
    for(;i<n;i++)
    {
        if(*(arr+i)==key)
        {
            printf("\nSuccessful search!Key is found at position %d.\n",i+1);
            return;
        }
    }
    printf("\nUnsuccessful search!Key not found.\n");
}
void reverseArray(int *arr,int n)
{
    if(n==0)
    {
        printf("\nEmpty array,nothing to reverse.\n\n");
        return;
    }
    int i=n-1,count=0,revArr[n];
    for(;i>=0;i--)
    {
        revArr[count++]=arr[i];
    }
    for(i=0;i<n;i++)
    {
        arr[i]=revArr[i];
    }
    
}
int main(void)
{
    int n=0,ch;
    printf("Enter the number of array elements:\t");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    readArr(arr,n);
    for(;;)
    {
        printf("\n1-INSERT AN ELEMENT\n2-DELETE AN ELEMENT\n3-SEARCH AN ELEMENT\n4-REVERSE THE ARRAY\n5-DISPLAY THE ARRAY ELEMENTS\n6-EXIT\nEnter the choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    insertEle(arr,&n);
                    break;
            case 2:
                    deleteEle(arr,&n);
                    break;
            case 3:
                    searchEle(arr,n);
                    break;
            case 5:
                    displayEle(arr,n);
                    break;
            case 6:
                    printf("\n\n\nThank you.\n\n");
                    exit(0);
            default:
                    printf("\nEnter a valid choice from menu!\n");
                    break;
            case 4:
                    reverseArray(arr,n);
                    break;
        }
    }
    return 0;
}
