#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int point;
int fault ,hit;
void print(int framesize,int frame[])
{
	int i;
	for(i=0;i<framesize;i++)
	{
		if(frame[i]==-1)
			printf("- ");
		else
			printf("%d ",frame[i]);
	}

	printf("\n");
}

void addref(int fsize,int frame[], int ref)
{
	int i;
	bool alloted = false;
	for(i=0;i<fsize;i++)
	{
		if(frame[i]==ref)
		{
			alloted = true;
			printf("  Hit for %d | ", ref);
			hit++;
			break;
		}
		else if(frame[i]==-1)
		{
			alloted = true;
			frame[i] = ref;
			printf("Fault for %d | ", ref);
			fault++;
			break;
		}
	}
	if(alloted == false)
	{
		fault++;
		printf("Fault for %d | ", ref);
		frame[point] = ref;
		point = (point+1)%fsize;
	}
	print(fsize, frame);
}

int main()
{
	int fsize,i,num;
	printf("Enter frame size: ");
	scanf("%d",&fsize);
	int frame[fsize];
	for(i=0;i<fsize;i++)
	{
		frame[i] = -1;
	}

	print(fsize,frame);
	
	printf("Enter the number of references: ");
	scanf("%d",&num);
	int ref[num];
	
	printf("\nEnter the pages : ");
	for(i=0;i<num;i++)
	{
		scanf("%d",&ref[i]);
		addref(fsize,frame,ref[i]);
	}
	printf("\nNumber of faults: %d \nNumber of hits: %d\n",fault,hit );
}
