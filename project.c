#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h> 
#define COUNT 10 
#define MAXLEN 9


/*
Information:
Arrays:
c contains the whole first day as chars
MixedArray,NewMixedArray,LastArray every single for breaking the file to timestamps and values
Timestamps=Contains the timestamps
Values=Contains the values
MergeArray and QucikArray for the sorts
ALl the above for the file with the temperatures

d contains the whole first day as chars
MixedArray2,NewMixedArray2,LastArray2 every single for breaking the file to timestamps and values
Timestamps2=Contains the timestamps
Values2=Contains the values
HeapifyArray,CountingArray for the sorts
ALl the above for the file with the huminity
*/
typedef struct datetime {
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
    } datetime;
//Function for merging
void merge(float arr[],char *arr2[], int left, int mid, int right){ 
    int i, j, k; 
    int n1 = mid - left + 1; 
    int n2 =  right - mid; 
  
    /* create temp arrays */
    int Left[n1], Right[n2];
    char *TempLeft[n1],*TempRight[n2];
  
    /* Copy data to temp arrays Left[] and Right[] */
    for (i = 0; i < n1; i++) 
    {
        Left[i] = arr[left + i]; 
        TempLeft[i]=arr2[left +i];
	}	
    for (j = 0; j < n2; j++) 
    {
        Right[j] = arr[mid + 1+ j]; 
        TempRight[j] = arr2[mid + 1+ j]; 
        
	}
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = left; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (Left[i] <= Right[j]) 
        { 
            arr[k] = Left[i];   
			arr2[k]= TempLeft[i];        
            i++; 
        } 
        else
        { 
            arr[k] = Right[j]; 
           	arr2[k]=TempRight[j];        
            j++; 
        }
        k++; 
    } 
  
    /* Copy the remaining elements of Left[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = Left[i];
		arr2[k]=TempLeft[i];   
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = Right[j]; 
        arr2[k]=TempRight[j];  
        j++; 
        k++; 
    } 
} 
  
// l is for left index and r is right index of the  sub-array of arr to be sorted 
// Function for mergeSort
void mergeSort(float arr[],char *arr2[], int left, int right) { 
    if (left < right) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int mid = left+(right-left)/2; 
  
        // Sort first and second halves 
        mergeSort(arr,arr2, left, mid); 
        mergeSort(arr,arr2, mid+1, right); 
  
        merge(arr,arr2, left, mid, right); 
    } 
} 

//Funtction for QuickSort
void QuickSort(float number[25],int first,int last){
   int i, j, pivot, temp;
   char *temp2[1];

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      
      QuickSort(number,first,j-1);
      QuickSort(number,j+1,last);

   }
}

// Function to swap the the position of two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Function to swap the the position of two elements
void swap2(char **a, char **b) {

    char *temp = *a;
    //printf("TEMP::%s \n",temp);
    *a = *b;
   // printf("AAA::%s \n",a);
    *b = temp;
	//printf("BBB::%s \n",b);
}

//Funtction for heapifying.
void heapify(int arr[],char *arr2[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      swap2(&arr2[i], &arr2[largest]);
      heapify(arr,arr2, n, largest);
    }
}
  
  // Main function to do heap sort
void heapSort(int arr[],char *arr2[], int n) {
    // Build max heap
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
      heapify(arr,arr2, n, i);
  
    // Heap sort
    for (i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      swap2(&arr2[0], &arr2[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr,arr2, i, 0);
    }
}


 // Main function to do countingSort
void countingSort(int array[], int size) {
  int output[size];

  // Find the largest element of the array
  int max = array[0];
  int i;
  for (i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }
  
  int p = max + 1;
  // The size of count must be at least (max+1) but
  int count[p];

  // Initialize count array with all zeros.
  for (i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

//Functions for TimeStamps Sorting
void TimeStampsSort(char *arr[],float arr2[],int n){
   char t[100];
   float temp;
   int i,j;
   for (i = 1; i < n; i++)
    {
      for (j = 1; j < n; j++)
      {                                              //if the previous string is greater than next
          if (strcmp(arr[j - 1], arr[j]) > 0)
          {                                         //swap their positions
              strcpy(t, arr[j - 1]);
              temp=arr2[j-1];
              strcpy(arr[j - 1], arr[j]);
              arr2[j-1]=arr2[j];
              strcpy(arr[j], t);
              arr2[j]=temp;
              
          }
      }
   }
}

void TimeStampsSort2(char *arr[],int arr2[],int n){
   char t[100];
   int temp;
   int i,j;
   for (i = 1; i < n; i++)
    {
      for (j = 1; j < n; j++)
      {                                              //if the previous string is greater than next
          if (strcmp(arr[j - 1], arr[j]) > 0)
          {                                         //swap their positions
              strcpy(t, arr[j - 1]);
              temp=arr2[j-1];
              strcpy(arr[j - 1], arr[j]);
              arr2[j-1]=arr2[j];
              strcpy(arr[j], t);
              arr2[j]=temp;
              
          }
      }
   }
}

// A recursive binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1 
/*  Binary searching begins */
void BinarySearch(char *arr[],int n,char word[],float arr2[],char *arr3[],int arr4[]){
    int lb, mid, ub;
    lb = 0;                             //lower bound to 0
    ub = n-1;                          //upper bound to n
    do
    {
        mid = (lb + ub) / 2;          //finding the mid of the array
        if ((strcmp(word,arr[mid]))<0) {     //compare the word with mid
            ub = mid - 1;                          //if small then decrement ub
        }
        else if ((strcmp(word,arr[mid]))>0){
      	        lb = mid + 1;                          //if greater then increment lb
            }
     /*repeat the process till lb doesn't becomes ub and string is found */   
    } while ((strcmp(word,arr[mid])!=0) && lb <= ub);
    if ((strcmp(word,arr[mid]))==0)              //if string is found
          {
		  printf("The temp you are looking is: %.2f \n",arr2[mid]);
	      }	
		  					
	 lb = 0;                             //lower bound to 0
   	 ub = n-1;                          //upper bound to n
     do
   	 {
	    mid = (lb + ub) / 2;          //finding the mid of the array
	    if ((strcmp(word,arr3[mid]))<0) {     //compare the word with mid
		      ub = mid - 1;                          //if small then decrement ub
	     }
       else if ((strcmp(word,arr3[mid]))>0){
		      lb = mid + 1;                          //if greater then increment lb
         }
		     /*repeat the process till lb doesn't becomes ub and string is found */   
	 } while ((strcmp(word,arr3[mid])!=0) && lb <= ub);             
	 
	  if ((strcmp(word,arr3[mid]))==0)              //if string is found
   	  {
		  printf("The hum you are looking is: %d \n",arr4[mid]);
	  }
	  else 
		  printf("SEARCH FAILED \n");
}
	
//Function to break the given key to Numbers
long long int  SearchKey(char key[]){
	long long int NewResult;
    char stryear[10];
	char strmonth[10];
	char strday[10];
	char strhour[10];
	char strminute[10];
	char strsecond[10];
	char result[1024] ="";
	char zero = '0';
	char *tmp;

	datetime dt = {.year = atoi(key),
                   .month = atoi(key + 6),
                   .day = atoi(key + 8),
                   .hour = atoi(key + 11),
                   .minute = atoi(key + 14),
                   .second = atoi(key + 17)};       
	if (dt.year<10)
    {
      itoa(dt.year,stryear,10);
      tmp=strdup(stryear);
      strcpy(stryear, &zero);
	  strcat(stryear, tmp);
	  free(tmp);
	}	
    else
    	itoa(dt.year,stryear,10);
    	
    if (dt.month<10)
   {
    	itoa(dt.month,strmonth,10);
    	tmp=strdup(strmonth);
        strcpy(strmonth, &zero);
	    strcat(strmonth, tmp);
	    free(tmp);
  }
    else
    	itoa (dt.month,strmonth,10);
	
	if (dt.day<10)
    {
      itoa(dt.day,strday,10);
      tmp=strdup(strday);
      strcpy(strday, &zero);
	  strcat(strday, tmp);
	  free(tmp);  
	}	
    else
    	itoa(dt.day,strday,10);
    	
    	
	if (dt.hour<10)
    {
      itoa(dt.hour,strhour,10);
      tmp=strdup(strhour);
      strcpy(strhour, &zero);
	  strcat(strhour, tmp);
	  free(tmp);  
	}	
    else
    	itoa(dt.hour,strhour,10);
    
    if (dt.minute<10)
    {
      itoa(dt.minute,strminute,10);
      tmp=strdup(strminute);
      strcpy(strminute, &zero);
	  strcat(strminute, tmp);
	  free(tmp);  
	}	
    else
    	itoa(dt.minute,strminute,10);
    
    if (dt.second<10)
    {
      itoa(dt.second,strsecond,10);
      tmp=strdup(strsecond);
      strcpy(strsecond, &zero);
      strcat(strsecond, tmp);
	  free(tmp);   
	}	
    else
    	itoa(dt.second,strsecond,10);
                 

    strcpy(result, stryear);
    strcat(result, strmonth);
    strcat(result, strday);
    strcat(result, strhour);
    strcat(result, strminute);
	strcat(result, strsecond);
	
    NewResult=strtoll(result, &tmp, 10);
    
    strcpy(result, "");  
    strcpy(stryear, "");
    strcpy(strmonth, "");
    strcpy(strday, "");
    strcpy(strhour, "");
    strcpy(strminute, "");
    strcpy(strsecond, "");
    return NewResult;
   
}

void SearchInterpolation(char *data[],float data2[],char *data3[],int data4[], int n, char searchKey[]){
	

    long long int ResultKey,ResultLow,ResultHigh;
    int position,low,high;
    low = 0;
    high = n-1;
    ResultLow = SearchKey(data[low]); // ResultLow = searchKey but integer
    ResultHigh =SearchKey(data[high]); // ResultHigh = searchKey but integer
    ResultKey = SearchKey(searchKey); // ResultKey = searchKey but integer
    if (ResultKey>=ResultLow && ResultKey<=ResultHigh){
    do{
    	
        ResultLow = SearchKey(data[low]); // ResultLow = searchKey but integer
        ResultHigh =SearchKey(data[high]); // ResultHigh = searchKey but integer
        position =low + (ResultKey - ResultLow) * (high-low) / (ResultHigh - ResultLow);
        if(strcmp(data[position], searchKey) > 0)
		 high = position - 1;
        else if(strcmp(data[position], searchKey) < 0)
		 low = position + 1;
		else
			low = position;
    } while ((strcmp(searchKey, data[position])>0) && (strcmp(searchKey, data[high]) < 0) && (strcmp(data[position], searchKey) != 0));
    }
    if ((strcmp(searchKey,data[position]))==0)              //if string is found
          {
		  printf("The temp you are looking is: %.2f \n",data2[position]);
	      }	
	low = 0;
    high = n-1;
    ResultLow = SearchKey(data3[low]); // ResultLow = searchKey but integer
    ResultHigh =SearchKey(data3[high]); // ResultHigh = searchKey but integer
    if (ResultKey>=ResultLow && ResultKey<=ResultHigh){
    do{
        ResultLow = SearchKey(data3[low]); // ResultLow = searchKey but integer
        ResultHigh =SearchKey(data3[high]); // ResultHigh = searchKey but integer
        position = (ResultKey - ResultLow) * (high-low) / (ResultHigh - ResultLow) + low;   
        if(strcmp(data3[position], searchKey) > 0)
		 high = position - 1;
        else if(strcmp(data3[position], searchKey) < 0)
		 low = position + 1;
		else
			low=position;
    } while ((strcmp(searchKey, data3[position])>0) && (strcmp(searchKey, data3[high]) < 0) && (strcmp(data3[position], searchKey)!=0));
    
    if ((strcmp(searchKey,data3[position]))==0)              //if string is found
          {
		  printf("The hum you are looking is: %d \n",data4[position]);
	      }	
   }
   else 
		  printf("SEARCH FAILED \n");
}


int linearSearch (char *Array[],char searchKey[], int n) {
	int i;
    for (i = 0; i < n; ++i) {
        if (strcmp(Array[i], searchKey) == 0)
            return i;
    }

    // We didn't find the searchKey in the Array
    return -1;
}

int BIS(char *arr[],int n, char searchKey[]){
    long long int ResultKey,ResultLeft,ResultRight,ResultNext;
    int i,next,left,right,newPos;
	double size;
    left = 0;
    right = n-1;
    size = right-left;
    ResultLeft = SearchKey(arr[left]); // ResultLow = searchKey but integer
    ResultRight =SearchKey(arr[right]); // ResultHigh = searchKey but integer
    ResultKey = SearchKey(searchKey); // ResultKey = searchKey but integer
    if (ResultKey>=ResultLeft && ResultKey<=ResultRight){
    next = left + (ResultKey - ResultLeft) * (right-left) / (ResultRight - ResultLeft);
    ResultNext=SearchKey(arr[next]);
    while (strcmp(searchKey, arr[next])!=0) {
        i = 0;
        size = right - left;
        if (size <= 3)
            return 2;
        if  (strcmp(searchKey,arr[right])>0) {
        	newPos = next + i*((int) sqrt(size)) - 1;
            while ((strcmp(searchKey,arr[newPos]) > 0)) {
                ++i;
            }
            right = next + (int) (i*sqrt(size));
            left  = next + (int) ((i-1)*sqrt(size));
        }
        else if (strcmp(searchKey, arr[right]) < 0) {
        	newPos = next -i* ((int) sqrt(size)) + 1;
            while ((strcmp(searchKey,arr[newPos]) < 0)) {
                ++i;
            }
            right = next - (int) ((i-1)*sqrt(size));
            left  = next - (int) (i*sqrt(size));
        }
        ResultLeft = SearchKey(arr[left]); // ResultLow = searchKey but integer
   	    ResultRight =SearchKey(arr[right]); // ResultHigh = searchKey but integer
        next = (int) (left + ((right - left +1)*(ResultKey - ResultLeft)/(ResultRight - ResultLeft))) - 1;
        ResultNext=SearchKey(arr[next]);
    }
    if ((strcmp(searchKey,arr[next]))==0)  
            return next;
    else 
		return -1;
	}
	else
		return -1;
}



typedef struct TreeNode{
	char Timestamp;
    float val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* build(float *array, int size) {
    if(size == 0)
        return NULL;
    else {
        TreeNode *root = malloc(sizeof(TreeNode));//in the case of return NULL there is before if-block, cause of memory leak
        int i, j, mid;
        int swap = 1;

        j = size-1;
        while(swap){//To deter a repeat of the sort
            swap = 0;
            for(i = 0; i < j; ++i) {
                if(array[i] > array[i+1]) {
                    float temp = array[i];
                    array[i] = array[i+1];
                    array[i+1] = temp;
                    swap = 1;
                }
            }
            --j;
        }
        root->val = array[mid = size / 2];
        root->left  = build(array, mid);
        root->right = build(array + mid + 1, size - mid -1);
        return root;
    }
}


// Function to print binary tree in 2D 
// It does reverse inorder traversal 
void print2DUtil(struct TreeNode *p, int space) { 
	int i;
    // Base case 
    if (p == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(p->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%.2f\n", p->val); 
  
    // Process left child 
    print2DUtil(p->left, space); 
} 
  
// Wrapper over print2DUtil() 
void print2D(TreeNode *p){ 
   // Pass initial space count as 0 
   print2DUtil(p, 0); 
} 


struct node {
    char *Timestamp;            // all void* types replaced by char*
    struct node *p_left;
    struct node *p_right;
};

typedef int (*Compare)(const char *, const char *);


//inserts elements into the tree
void insert(char* key, struct node** leaf, Compare cmp){
    int res;
    if( *leaf == NULL ) {
        *leaf = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->Timestamp = malloc( strlen (key) +1 );     // memory for key
        strcpy ((*leaf)->Timestamp, key);                   // copy the key
        (*leaf)->p_left = NULL;
        (*leaf)->p_right = NULL;
    } else {
        res = cmp (key, (*leaf)->Timestamp);
        if( res < 0)
            insert( key, &(*leaf)->p_left, cmp);
        else if( res > 0)
            insert( key, &(*leaf)->p_right, cmp);
        else                                            // key already exists
            printf ("Key '%s' already in tree\n", key);
    }
}

//compares value of the new node against the previous node
int CmpStr(const char *a, const char *b){
    return (strcmp (a, b));     // string comparison instead of pointer comparison
}

//recursive function to print out the tree inorder
void in_order(struct node *root){
    if( root != NULL ) {
        in_order(root->p_left);
        printf("   %s\n", root->Timestamp);     // string type
        in_order(root->p_right);
    }
}


int main () {
   char c[100000];
   int j=0;
   FILE *fptr;
    if ((fptr = fopen("tempm.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

     //reads text until newline is encountered
    fscanf(fptr, "%[^\n]", c);
    fclose(fptr);
    int i=0;
    char *MixedArray[10000];
    char *token = strtok(c, ",");
    while( token != NULL ) {
      MixedArray[i]=token;                  //First break of the file.
      token = strtok(NULL, ",");
      i++;
   }
    i=0;
    char *NewMixedArray[256];
    char *token2 = strtok(MixedArray[j], " ");
	while (MixedArray[j]!=NULL){
	    if( token2 != NULL ) {
	      NewMixedArray[i]=token2;
	      token2 = strtok(0, " ");
	      i++;
		 } 
   else{
	   	  j++;
	   	  token2 = strtok(MixedArray[j], " ");
	      NewMixedArray[i]=token2;
	      token2 = strtok(0, " ");
	      i++;
 	  }
	}
   
   i=0;
   char   item[100]; 
   char  *LastArray[1000];
   
   while (NewMixedArray[i] != NULL)
   {
    sscanf (NewMixedArray[i],"\"%99[^\"]", item);  //Remove of Symbols
	LastArray[i] = strdup(item);
    i++;
   }


   char *NA[69];
   float Values[69];
   char *Timestamps[69];
   
   i=0;
   j=0;
    while(i<140){
    	Timestamps[j]=LastArray[i]; //New array with the timestamps
        NA[j]=LastArray[i+1];
        Values[j] = atof(NA[j]);
        i=i+2;
        j++;
    }
    
    int n=70;
    float MergeArray[69];
    float QuickArray[69];

    for(i=0; i<70; i++)
    {
        MergeArray[i] = Values[i];
        QuickArray[i] = Values[i];
    }
    
     //MergeSort and QuickSort
    mergeSort(MergeArray,Timestamps,0,n-1);        
   	printf("Sorts for the file with the temperatures\n ");
	printf("Sorted (mergesort) array is :\n ");
	for(i=0;i<n;i++)
		printf("%s and %.2f \n ",Timestamps[i],MergeArray[i]);
	
	
    QuickSort(QuickArray,0,n-1);  
    printf("\nSorted (quicksort) array is :\n");
    for(i=0;i<n;i++)
        printf("%s and  %.2f \n",Timestamps[i],QuickArray[i]);
        

  
  
  
  char d[100000];
  j=0;
    FILE *fptr2;
    if ((fptr2 = fopen("hum.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }
     //reads text until newline is encountered
    fscanf(fptr2, "%[^\n]", d);
    fclose(fptr2);
    i=0;
    char *MixedArray2[10000];
    char *token3 = strtok(d, ",");
    while( token3 != NULL ) {
      MixedArray2[i]=token3;                  //First break of the file.
      token3 = strtok(NULL, ",");
      i++;
   }
    i=0;
    char *NewMixedArray2[256];
    char *token4 = strtok(MixedArray2[j], " ");
	while (MixedArray2[j]!=NULL){
	    if( token4 != NULL ) {
	      NewMixedArray2[i]=token4;
	      token4 = strtok(0, " ");
	      i++;
		 } 
   else{
	   	  j++;
	   	  token4 = strtok(MixedArray2[j], " ");
	      NewMixedArray2[i]=token4;
	      token4 = strtok(0, " ");
	      i++;
 	  }
	}
   
   i=0;
   char  item2[100]; 
   char  *LastArray2[1000];
   
   while (NewMixedArray2[i] != NULL)
   {
    sscanf (NewMixedArray2[i],"\"%99[^\"]", item2);  //Remove of Symbols
	LastArray2[i] = strdup(item2);
    i++;
   }

   char *NA2[69];
   int Values2[69];
   char *Timestamps2[69];
   
   i=0;
   j=0;
    while(i<140){
    	Timestamps2[j]=LastArray2[i]; //New array with the timestamps
        NA2[j]=LastArray2[i+1];
        Values2[j] = atoi(NA2[j]);
        i=i+2;
        j++;
    }
    
    n=70;
    int HeapifyArray[69];
    int CountingArray[69];

    for(i=0; i<70; i++)
    {
        HeapifyArray[i] = Values2[i];
        CountingArray[i] = Values2[i];
    }
    int last,temp;
 	
    heapSort(HeapifyArray,Timestamps2, n);
    
    
    printf("\nSorts for the file with the humidity\n");
    
    printf("Sorted (heapify) array is :\n");
    for(i = 0; i < n ;i++)-
        printf("%d : %s and  %d \n",i,Timestamps2[i],HeapifyArray[i]);
     	

    countingSort(CountingArray, n);
    printf("\nSorted (counting) array is :\n");
   for(i = 0; i < n ;i++)
        printf("%d : %s and  %d \n",i,Timestamps2[i],CountingArray[i]);
   
   char word[100];      //variable      
   TimeStampsSort(Timestamps,Values,n);
   TimeStampsSort2(Timestamps2,Values2,n);         
   
   printf("Enter the timestamp to be searched with binary search: \n");
   gets(word);  
   printf("The word is: %s \n",word);                   //entering the word to be searched
   BinarySearch(Timestamps,n,word,Values,Timestamps2,Values2);     //calling search function
   
   char key[100];
   printf("Enter the timestamp to be searched with interpolation search: \n");
   gets(key);
   printf("The key is: %s \n",key); 
   SearchInterpolation(Timestamps,Values,Timestamps2,Values2, n, key);
   
   char BISkey[100];
   printf("Enter the timestamp to be searched with binary interpolation search: \n");
   gets(BISkey);
   printf("The key is: %s \n",BISkey); 
    int hit;
    int linearpos;
    hit = BIS(Timestamps,n,BISkey);
    if (hit != -1) 
    {
        printf("The temp you are looking is: %.2f \n",Values[hit]);
    }
    if (hit == 2)
    {
      linearpos = linearSearch (Timestamps,BISkey,n);
      printf("The temp you are looking is: %.2f \n",Values[linearpos]);
	}
	
	hit = BIS(Timestamps2,n, BISkey);
    if (hit != -1) 
    {
        printf("The hum you are looking is: %d \n",Values2[hit]);
    }
    
    else if (hit == 2)
    {
      linearpos = linearSearch (Timestamps,BISkey,n);
       printf("The hum you are looking is: %d \n",Values2[linearpos]);
	}
	else
		  printf("SEARCH FAILED \n");
		  
    n=70;
    TreeNode *root = build(Values, n);
    printf(" \n");
    printf(" \n");
	printf ("BST by Temperatures: \n");  
    print2D(root);
    
    struct node *p_root = NULL;
    char *Timestamp;
    printf(" \n");
    printf(" \n");
    printf ("BST by Day: \n");
    for (i=0; i<n; i++){
    		Timestamp = Timestamps[i];
            printf ("%s\n", Timestamp);
            insert(Timestamp,  &p_root, (Compare)CmpStr);
	}	
    
 return 0;
}

