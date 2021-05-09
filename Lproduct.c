#include "Lproduct.h"

int loadReserve(Reserve *p[],Hotel *h[],int linecount)
{
    int count = 0;
    FILE *fp;

    fp = fopen("reserve.txt", "r");

    for (int i = 0; i < linecount; i++)
    {
        fscanf(fp, "%d %d %s\n",&p[i]->room_number2,&p[i]->head_count2,p[i]->name2);
        count++;
    }
    fclose(fp);

    fp = fopen("hotel.txt", "r");

    for (int i = 0; i < 25; i++)
    {
        fscanf(fp,"%d %d %d %d\n", h[i]->room_number,h[i]->bed_count,h[i]->head_count,h[i]->check);
    }    
    fclose(fp);
    
    printf("\n=> 로딩 성공!\n");
    return count;
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

    for (int i = 0; i < count; i++)
    {   
        counter = 1;
        for (int j = 0; j < 25; j++)
        {
            if(p[i]->room_number2 == h[j]->room_number)
            {
                fprintf(fp,"%d %d %d %d\n", h[i]->room_number,h[i]->bed_count,h[i]->head_count,1);
                counter = 2;
            }
        }
        if (counter == 1)
        {
            fprintf(fp,"%d %d %d %d\n", h[i]->room_number,h[i]->bed_count,h[i]->head_count,0);
        }
    }
    fclose(fp);
    printf("=> 저장됨!");
}

void search_room_info(Hotel *p[], int count)
{
    int scnt = 0;
    int find = 0;
    printf("================================================\n");
    printf("|101~105호|201~205호|301~305호|401~405|501~505호|\n");
    printf("================================================\n\n");
    printf("예시. '104'");
    printf("검색할 방 번호는? : ");
    scanf("%d", find);

    printf("\n No Room# BedCount HeadCount Available \n");
    printf("=========================================\n");
    for (int i = 0; i < count; i++)
    {
        if(strstr(p[i]->room_number,find))
        {
            printf("%2d ", i+1);
            //readProduct(*p[i]);
            scnt++;
        }
        if(scnt == 0) printf("=> 방이 없습니다!");
        printf("\n");
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
    
    for (int i = 0; i < count; i++)
    {
        if(p[i]->bed_count == find)
        {
            printf("%2d ", i+1);
            //readProduct(*p[i]);
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
    
    for (int i = 0; i < count; i++)
    {
        if(p[i]->head_count == find)
        {
            printf("%2d ", i+1);
            //readProduct(*p[i]);
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
    
    for (int i = 0; i < count; i++)
    {
        if(p[i]->check == 0) //0 = empty, 1 = reserved
        {
            printf("%2d ", i+1);
            //readProduct(*p[i]);
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

    printf("\n No Room# BedCount HeadCount Available \n");
    printf("=========================================\n");
    for (int i = 0; i < count; i++)
    {
        if(strstr(p[i]->name2,search))
        {
            if (p[i]->head_count2 == -1) continue;
            printf("%2d ", i+1);
            //readProduct(*h[i]);
            scnt++;
        }
        if(scnt == 0) printf("=> 방이 없습니다!");
        printf("\n");
    }
}

