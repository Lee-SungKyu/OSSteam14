#include "Lproduct.h"
#include <string.h>

int createReservation(Reserve *p) {
    
        printf("\n예약할 방 번호는? : ");
	    scanf("%d", &p->room_number2);
        
	    printf("묶을 인원은? : ");
	    scanf("%d", &p->head_count2);

	    printf("당신의 이름은? : ");
	    scanf("%s", p->name2);
	
    return 1;

}

void updateReservation(Reserve *p[], int *count) {
    int editRoom = 0;
    int editCount = 0;

    int check = 0;

    listReservation(p,count);
    
    printf("변경할 예약 번호는? : ");
    scanf("%d", &editRoom);

    for(int i = 1; i <= *count; i ++) {
        if (i == editRoom) {
            editCount = i;
            check = 1;
            break;
        }
    }

    if (check == 0) {
        printf("해당 방 번호는 예약되지 않았습니다!\n");
    }

	else {
        printf("\n예약할 방 번호는? : ");
	    scanf("%d", &p[editCount-1]->room_number2);
    	
    	printf("인원수는? : ");
    	scanf("%d", &p[editCount-1]->head_count2);

    	printf("이름은? : ");
    	scanf("%s", p[editCount-1]->name2);
	
    	printf("변경이 완료되었습니다!\n");
	}
}

void deleteReservation(Reserve *p[], int *count) {
    int deleteNum = 0;
    int check = 0;

    listReservation(p,count);
    
    printf("삭제할 예약 번호는? : ");
    scanf("%d", &deleteNum);

    for(int i = 1; i <= *count; i ++) {
        if (i == deleteNum) {
            check = 1;
            p[i-1]->head_count2 = -1;
            p[i-1]->room_number2 = -1;
			printf("삭제가 완료되었습니다!\n");
			break;
        }
    }
    if (check == 0) {
        printf("해당 방 번호는 예약되지 않았습니다!\n");
    }
}

void listReservation(Reserve *p[], int *count) {
    printf("\nNo Room# HeadCount Name\n");
    printf("==========================\n");
    for(int i = 0; i < *count; i ++) {
        if (p[i]->head_count2 != -1) {
            printf("%d  %d      %d      %s\n", i+1, p[i]->room_number2, p[i]->head_count2, p[i]->name2);
        }
    }
}
void listHotel(Hotel *p[])
{
    for (int i = 0; i < 25; i++)
    {
        printf("%d %d %d %d\n", p[i]->room_number,p[i]->bed_count,p[i]->head_count,p[i]->check);
    }
}

int loadReservation(Reserve *p[],int linecount)
{
    int count = 0;
    FILE *fp;
    fp = fopen("reserve.txt", "r");
    for (int i = 0; i < linecount; i++)
    {
        
        fscanf(fp,"%d %d %s\n",&p[i]->room_number2,&p[i]->head_count2,p[i]->name2);
        count++;
    }
    fclose(fp);
    
    printf("\n=> 로딩 성공!\n");
    
    return count;
}

void loadHotel(Hotel *p[])
{
    FILE *fp;

    fp = fopen("hotel.txt", "r");
    for (int i = 0; i < 25; i ++)
    {
        fscanf(fp,"%d %d %d %d",&p[i]->room_number,&p[i]->bed_count,&p[i]->head_count,&p[i]->check);
    }
    fclose(fp);
}

void saveReservation(Reserve *p[], Hotel *h[], int count)
{
    FILE *fp;
    fp = fopen("reserve.txt", "wt");

    for (int i = 0; i < count; i++)
    {
        if(p[i]->head_count2 == -1) continue;
        fprintf(fp, "%d %d %s\n",p[i]->room_number2,p[i]->head_count2,p[i]->name2);
    }
    fclose(fp);
    
    int counter = 1;

    fp = fopen("hotel.txt", "wt");

    for (int i = 0; i < 25; i++)
    {   
        counter = 1;
        for (int j = 0; j < count; j++)
        {
            if(h[i]->room_number == p[j]->room_number2)
            {
                fprintf(fp,"%d %d %d %d\n", h[i]->room_number,h[i]->bed_count,h[i]->head_count,1);
                counter++;
            }    
        }
        if(counter == 1)
            {
                fprintf(fp,"%d %d %d %d\n", h[i]->room_number,h[i]->bed_count,h[i]->head_count,0);
            }  
        
    }
    fclose(fp);
    printf("=> 저장됨!");
}
void readHotel(Hotel p)
{
    printf("%d        %d        %d      %d\n",p.room_number,p.bed_count,p.head_count,p.check);
}
void readReserve(Reserve p)
{
    printf("%d       %d       %s\n\n", p.room_number2,p.head_count2,p.name2);
}
void search_room_info(Hotel *p[], int count)
{
    int scnt = 0;
    int find = 0;
    printf("================================================\n");
    printf("|101~105호|201~205호|301~305호|401~405|501~505호|\n");
    printf("================================================\n\n");
    printf("예시. '104'\n");
    printf("검색할 방 번호는? : ");
    scanf("%d", &find);
    printf("\n No Room# BedCount HeadCount Available \n");
    printf("=========================================\n");
    
    for (int i = 0; i < 25; i++)
    {
        if((p[i]->room_number == find))
        {
            printf("%2d   ", i+1);
            readHotel(*p[i]);
            scnt++;
        }
    }
    if(scnt == 0)
    {
        printf("=> 방이 없습니다!\n");
    }
}

void search_bed_count(Hotel *p[], int count)
{
    int scnt = 0;
    int find = 0;

    printf("검색할 방 최대 침대 수 는? : ");
    scanf("%d", &find);

    printf("\n No Room# BedCount HeadCount Available \n");
    printf("=========================================\n");
    
    for (int i = 0; i < 25; i++)
    {
        if(p[i]->bed_count == find)
        {
            printf("%2d   ", i+1);
            readHotel(*p[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 방이 없습니다!");
    printf("\n");
}
void search_head_count(Hotel *p[], int count)
{
    int scnt = 0;
    int find = 0;

    printf("검색할 방 최대 침대 수 는? : ");
    scanf("%d", &find);

    printf("\n No Room# BedCount HeadCount Available \n");
    printf("=========================================\n");
    
    for (int i = 0; i < 25; i++)
    {
        if(p[i]->head_count == find)
        {
            printf("%2d   ", i+1);
            readHotel(*p[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 방이 없습니다!");
    printf("\n");
}
void search_empty_room(Hotel *p[], int count)
{
    int scnt = 0;
    
    printf("\n No Room# BedCount HeadCount Available \n");
    printf("=========================================\n");
    
    for (int i = 0; i < 25; i++)
    {
        if(p[i]->check == 0) //0 = empty, 1 = reserved
        {
            printf("%2d   ", i+1);
            readHotel(*p[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 방이 없습니다!");
    printf("\n");
}

void search_name(Reserve *p[],Hotel *h[], int count)
{
    int scnt = 0;
    char search[20];
    printf("검색할 예약자 이름은? : ");
    scanf("%s", search);
    printf("\n No Room# HeadCount Name \n");
    printf("==============================\n");
    for (int i = 0; i < count; i++)
    {
        if(strcmp(p[i]->name2,search) == 0)
        {
            printf("%2d   ", i+1);
            readReserve(*p[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 방이 없습니다!");
    printf("\n");
}

