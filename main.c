#include "Lproduct.h"

int selectMenu()
{
    int menu;
    printf("==================\n");
    printf("1.예약된 방 조회\n");
    printf("2. 방 예약\n");
    printf("3. 방 예약 수정\n");
    printf("4. 방 예약 취소\n");
    printf("5. 방 예약 저장\n");
    printf("6. 방 정보 검색\n");
    printf("7. 예약자 이름 검색\n");
    printf("0. 종료\n");
    printf("==================\n");
    scanf("%d", &menu);
    return menu;
}
int selectMenu2()
{
    int menu2;
    printf("==================\n");
    printf("1. 방 정보 검색\n");
    printf("2. 침대 갯수 검색\n");
    printf("3. 최대 인원수 검색\n");
    printf("4. 빈 방 검색\n");
    printf("0. 뒤로가기\n");
    printf("==================\n");
    scanf("%d", &menu2);
    return menu2;

}

int main()
{
    Hotel *Hlist[25];
    Reserve *Rlist[100];
    int menu, menu2;
    int count = 0;
    int index = 0;
    int linecount = 0;
    char c;
    
    for (int i = 0; i < 25; i++)
    {
        Hlist[i] = (Hotel *) malloc(sizeof(Hotel));
    }

    FILE *fp;
    
    if ((fp = fopen("reserve.txt", "r")))
    {
        
        for (c = getc(fp); c != EOF; c = getc(fp))
        {
           
            if (c == '\n')
            {   
                
                linecount++;
            }
        }
        for(int i = 0; i < linecount; i++)
        {
            Rlist[i] = (Reserve *) malloc(sizeof(Reserve));
        }

        count = loadReservation(Rlist, linecount);
        index = count;
        
        fclose(fp);
    }
    else
    {
        printf("\n => 파일없음\n");
        fp = fopen("reserve.txt", "wt");
        fclose(fp);
    }

    loadHotel(Hlist);
  

 
    while(1)
    {
        menu = selectMenu(menu);

        if (menu == 0)
        {
            break;
        }
        else if (menu == 1)
        {
            listReservation(Rlist, &count);
        }
        else if (menu == 2)
        {
            Rlist[index] = (Reserve *)malloc(sizeof(Reserve));
            count += createReservation(Rlist[index++]);
            saveReservation(Rlist, Hlist, count);
        }
        else if (menu == 3)
        {
            updateReservation(Rlist, &count);
            saveReservation(Rlist, Hlist, count);
        }
        else if (menu == 4)
        {
            deleteReservation(Rlist, &count);
            saveReservation(Rlist, Hlist, count);
        }
        else if (menu == 5)
        {
            saveReservation(Rlist, Hlist, count);
        }
        else if (menu == 6)
        {
            while(1)
            {
                menu2 = selectMenu2(menu2);
                
                if (menu2 == 1)
                {
                    search_room_info(Hlist, count);

                }
                else if (menu2 == 2)
                {
                    search_bed_count(Hlist, count);

                }
                else if (menu2 == 3)
                {
                    search_head_count(Hlist, count);

                }
                else if (menu2 == 4)
                {
                    search_empty_room(Hlist, count);

                }
                else if (menu2 == 0)
                {
                    break;
                }
            }
        }
        else if (menu == 7)
        {
            search_name(Rlist, Hlist, count);
        }
    }
}
