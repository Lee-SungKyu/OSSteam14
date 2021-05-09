#include "Lproduct.h"

int selectMenu()
{
    printf("==================\n");
    printf("1.예약된 방 조회");
    printf("2. 방 예약");
    printf("3. 방 예약 수정");
    printf("4. 방 예약 취소");
    printf("5. 방 예약 저장");
    printf("6. 방 정보 검색");
    printf("7. 예약자 이름 검색");
    printf("0. 종료");
    printf("==================\n");
}
int selectMenu2()
{
    printf("==================\n");
    printf("1. 방 정보 검색");
    printf("2. 침대 갯수 검색");
    printf("3. 최대 인원수 검색");
    printf("4. 빈 방 검색");
    printf("0. 뒤로가기");
    printf("==================\n");

}

int main()
{
    Hotel Hlist[25];
    Reserve Rlist[100];
    int menu, menu2;
    int count = 0;
    int index = 0;
    int linecount = 0;
    char c;

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
        count = loadReservation(Rlist, Hlist, linecount);
        index = count;
        
        fclose(fp);
    }
    else
    {
        printf("\n => 파일없음\n");
        fp = fopen("reserve.txt", "wt");
        fclose(fp);
    }

    while(1)
    {
        menu = selectMenu(menu);
        if (menu == 0)
        {
            break;
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
