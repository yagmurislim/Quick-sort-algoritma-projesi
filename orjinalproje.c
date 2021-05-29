#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 10
struct nick
{
char a[10];
};
	 //function for quick sort
void quicksort(struct nick items[],int first,int last,int mid,int pivot,int pivot_temp)
{
    int j,i;
    char temp[10];
    pivot=pivot_temp;
    
    if(pivot==1){
    	pivot=first;
	}
	else if(pivot==2){
		pivot=last;
	}
	else if(pivot==3){
		pivot=mid;
	}
	
	if(first<last){
		
	    i=first;
	    j=last;
	    
	    while(i<j)
	    {
	        while((strcmp(items[i].a,items[pivot].a))<0)
	            i++;
	        while((strcmp(items[j].a,items[pivot].a))>0)
	            j--;
	
	        if(i<j)
	        {
	            strcpy(temp,items[i].a);          //swap the values at i and j'th index
	            strcpy(items[i].a,items[j].a);
	            strcpy(items[j].a,temp);
	        }
	    }
	    strcpy(temp,items[pivot].a);
	    strcpy(items[pivot].a,items[j].a);
	    strcpy(items[j].a,temp);
	    quicksort(items,first,j-1,mid/2,pivot,pivot_temp);                 //recursive call to quick sort
	    quicksort(items,j+1,last,j+1+mid/2,pivot,pivot_temp);
			
	}
}

void exFunc(){
	FILE *fp;
    int i=0,k=0,n;
    char fname[10],str[10],c;
    struct nick name[max];
    printf("\nKelime sayisini giriniz: ");
    scanf("%d",&n);
    printf("%d adet kelimeyi giriniz: \n",n);
    fp=fopen("dosya.txt","w");
    for(i=0;i<n;i++)
    {
        scanf("%s",name);
        fprintf(fp,"%s ",name);
    }
    fclose(fp);
    i=0;

    fp=fopen("dosya.txt","r");                   //open file in read mode
    while((c=getc(fp))!=EOF)
    {
        if(c==' ')
            {
                str[i]='\0';
                strcpy(name[k].a,str);          //copy string name to name
                i=0;
                k++;
            }
        else
        {
            str[i]=c;
            i++;
        }
    }
    fclose(fp);
    printf("\nGirdiginiz kelimeler: ");
    for(i=0; i<k; i++)
        printf("%s,", name[i].a);
    
    printf("\nLutfen pivotu seciniz (1-Pivot baslangic degeri  2-Pivot son deger  3-Pivot orta deger): ");
    int pivot,pivot_temp;
    scanf("%d",&pivot);
    pivot_temp = pivot;
    quicksort(name,0,k-1,(k-1)/2,pivot,pivot_temp);                              //calling quicksort
    printf("\n\nQuicksort isleminden sonra:\n");
    for(i=0; i<k; i++)
    {
        printf("%s,", name[i].a);                       //printing sorted
    }
}

int main()
{	
	for(;;){
		printf("\n---------------------------------------------------------\n");
		printf("\nQuickSort islemi icin 1'e, cikis yapmak icin 0'a basiniz.\n");
		printf("\n---------------------------------------------------------\n");
		
		int cd;
		
		scanf("%d",&cd);
		
		switch (cd) {
		    case 1 :
		       exFunc();
		       break;
		    case 0 :
		       return 0;
		    default :
		       printf("Istenen harflerden birini girmediniz!\n");
		}
	}
    
    return 0;
}
