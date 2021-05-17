#include "register.h"

int main() {
    Student s[100];
    int count=0, menu, index = 0;

    count = loadData(s);
    index = count;

// 1. 조회 2. 추가 3. 수정 4. 삭제 5. 이름으로 찾기 6. 파일 저장
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
          if(count != 0)
            listStudent(s, index);
        }
        else if (menu == 2){
          count += writeStudent(&s[index++]);
        }
        else if (menu == 3){
            int no = selectStudentNo(s, index);
            if(no > 0){
                updateStudent(&s[no-1]);
            }
        }
        else if (menu == 4){
          int no = selectStudentNo(s, index);
            if( no > 0){
                int deleteok ;
                printf("정말로 삭제하시겠습니까? (삭제:1)");
                scanf("%d", &deleteok);
                if(deleteok == 1){
                    deleteStudent(&s[no-1]);
                    count--;
                }
            }
        }
        else if (menu == 5){
            searchName(s, count);
        }
        else if (menu == 6){
            saveData(s, index);
        }
        else if (menu == 7){
            int a;
            printf("오름차순은 1, 내림차순은 2를 입력해 주세요");
            scanf("%d", &a);
            if(a == 1){
                ascendingSort(s, count);
            }
            else if (a == 2){
                descendingSort(s, count);
            }
            else{
                printf("=>잘못 누르셨습니다\n\n");
            }
        }
    }
    printf("종료됨!\n");
    return 0;
}