#include <stdio.h>
#include <cstdlib>

/*Data:
    1. Array space
    2. Size
    3. Length (No. of elements)
  Operations:
    1. Display()
    2. Add(x)/Append(x)
    3. Insert(index x)
    4. Delete(index)
    5. Search(x)
    6. Get(index)
    7. Set(index, x)
    8. Max(), Min()
    9. Reverse()
    10. Shift()/Rotate()
*/

struct Array{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("Elements are\n");
    for(i=0;i<arr.length;i++){
        printf("%d ", arr.A[i]);
    }
}

void Append(struct Array *arr, int x){
    if(arr->length<arr->size){
        arr->A[arr->length++]=x;
    }
}

void Insert(struct Array *arr, int index, int x){
    int i;
    if(index>=0 &&index <= arr->length){
        for(i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}

int Delete(struct Array*arr, int index){
    int x=0;

    if(index>=0 && index<=arr->length-1){
        x=arr->A[index];
        for(int i=index;i<arr->length-1;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }

    return 0;
}

int LinearSearch(struct Array arr, int key){
    int i;
    for(i=0;i<arr.length;i++){
        if(key==arr.A[i]){
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key){
    int l,mid,h;
    l=0;
    h=arr.length-1;

    while(l<=h){
        mid=(l+h)/2;
        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            h=mid-1;
        }
        else {
            l=mid+1;
        }
    }
    return -1;
}

int RBinSearch(int a[], int l, int h, int key){
    int mid;

    if(l<=h){
        mid=(l+h)/2;
        if(key==a[mid]){
            return mid;
        }
        else if (key<a[mid]){
            return RBinSearch(a,l,mid-1,key);
        }
        else {
            return RBinSearch(a,mid+1,h,key);
        }
    }
    return -1;
}

int Get(struct Array arr,int index){
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }
    return -1;
}
void Set(struct Array *arr,int index,int x){
    if(index>=0 && index<arr->length){
        arr->A[index]=x;
    }
}

int Max(struct Array arr){
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        if(arr.A[i]>max){
            max=arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr){
    int min=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        if(arr.A[i]<min){
            min=arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr){
    int s=0;
    int i;
    for(i=0;i<arr.length;i++){
        s+=arr.A[i];
    }
    return s;
}

float Avg(struct Array arr){
    return (float)Sum(arr)/arr.length;
}






void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Reverse(struct Array *arr){
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}

int isSorted(struct Array arr){
    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}

int main()
{
    struct Array *arr1;
    int ch,sz;
    int x,index;

    cout<<"Enter Size of Array";
    scanf("%d",&sz);
    arr1=new Array(sz);

    do {
        cout<<"\n\nMenu\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Search\n";
        cout<<"4. Sum\n";
        cout<<"5. Display\n";
        cout<<"6.Exit\n";

        cout<<"enter you choice ";
        cin>>ch;
        switch(ch) {
            case 1: cout<<"Enter an element and index ";
            cin>>x>>index;
            arr1->Insert(index,x);
            break;

            case 2: cout<<"Enter index ";
            cin>>index;
            x=arr1->Delete(index);
            cout<<"Deleted Element is"<<x;
            break;

            case 3:cout<<"Enter element to search";
            cin>>x;
            index=arr1->LinearSearch(x);
            cout<<"Element index "<<index;
            break;

            case 4:cout<<"Sum is "<<arr1->Sum();
            break;
            case 5:arr1->Display();
        }
    }
    while(ch<6);
        return 0;
}