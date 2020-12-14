#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int exit_flag = 0;
	FILE *fp;
	
	char name[200];
	char place[100], typeName[100];	
	size_t size;
	int month;
	int day;
	int type;
	void *list;
	void *ndPtr;
	void *schedInfo;
	int option;
	int cnt;
	
	//1. FILE pointer open & error handling
	//fill code here ----
	fp = fopen("schedule.dat", "r"); //스케줄 파일을 열고 읽기모드로
	
	if(fp == NULL) //파일을 찾지 못한 경우 
	{
		printf("invalid path\n");
		return -1;
	}
	
	//initializing the list
	printf("Reading the data files... \n");
	list = (void*)list_genList();
	
	
	 

	//2. read from the file
	char line[100];
	
	while (!feof(fp)/* fill code here -- read from the file*/ ) //파일의 끝이 아니라면 
	{	
		fgets(line,100,fp); //파일에서 문자열 데이터를 읽어옴 
		//fill code here -- generate genSchedInfo structure by genSchedInfo function
		sched_genSchedInfo(name, place, type, month, day);
		//put the scheduling info instance generated by genSchedInfo function
		list_addTail(schedInfo, list);
	}
	
	
	//fill code here ---- close the file pointer
	fclose(fp); 
	printf("Read done! %i schedules are read\n", list_len(list));
	
	
	//program starts
	while(exit_flag == 0) 
	{
		//3. menu printing
		//fill code here ---- 
		printf("1. print all the schedules\n");
		printf("2. search for schedules in the month\n");
		printf("3. search for schedules in the place\n");
		printf("4. search for specific type schedule\n");
		printf("5. exit\n\n");
		//4. get option from keyboard
		//fill code here ----
		printf("select an option : "); //옵션 입력
		scanf("%d", &option);
		
		switch(option)
		{
			case 1: //print all the schedules(모든 스케줄)
				printf("printing all the schedules in the scheduler.....\n\n\n");
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) == 0)
				{
					//file code here -- print count and each scheduling info element
					ndPtr = list_getNextNd(ndPtr); //get the next node from the list
					schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
					
					printf("----------------------------------------\n");
					sched_print(ndPtr); //스케줄 출력 
					
					//fill code this part - end
					if(ndPtr = NULL) //스케줄 더 없으면 끝내기 
						break;
				}
				
				break;
				
			case 2: //해당 달에 포함되는 스케줄 
				printf("which month ? : ");
				scanf("%i", &month);
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) == 0)
				{
					//file code here -- print scheduling info elements matching to the month
					ndPtr = list_getNextNd(ndPtr); //get the next node from the list
					schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
					
					printf("----------------------------------------\n");
					sched_getMonth(&month);
					sched_print(ndPtr); //스케줄 출력
					
					//fill code this part - end
					if(ndPtr = NULL) //스케줄 더 없으면 끝내기 
						break;
				}
				
				break;
				
			case 3: //해당 장소에 포함되는 스케줄 
				printf("which place ? : ");
				scanf("%s", place);
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) == 0)
				{
					//file code here -- print scheduling info elements matching to the place
					ndPtr = list_getNextNd(ndPtr); //get the next node from the list
					schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
					
					printf("----------------------------------------\n");
					sched_getPlace(place);
					sched_print(ndPtr); //스케줄 출력
					
					//fill code this part - end
					if(ndPtr = NULL) //스케줄 더 없으면 끝내기 
						break;
				}
				
				break;
				
			case 4: //해당 유형에 포함되는 스케줄 
				printf("which type ?\n");
				sched_printTypes();
				printf("your choice : ");
				scanf("%s", typeName);
				
				if (sched_convertType(typeName)>=0 && sched_convertType(typeName)<7/* fill code here -- convert the type and check if the type is valid */)
				{
					ndPtr = list;
					while (list_isEndNode(ndPtr) == 0)
					{
						//file code here -- print scheduling info elements matching to the place
						ndPtr = list_getNextNd(ndPtr); //get the next node from the list
						schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
						
						printf("----------------------------------------\n");
						sched_getType(typeName);
						sched_print(ndPtr); //스케줄 출력
					
						//fill code this part - end
						if(ndPtr = NULL) //스케줄 더 없으면 끝내기 
							break;
					}
				}
				else
				{
					printf("wrong type name!\n");
				}
				break;
				
			case 5:
				printf("Bye!\n\n");
				exit_flag = 1;
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
		
		
	}
	
	return 0;
}
