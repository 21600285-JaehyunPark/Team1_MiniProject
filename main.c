#include "register.h"

int main() {
    Student s[100];
    int count=0, menu, index = 0;

// 1. 조회 2. 추가 3. 수정 4. 삭제
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
    }
    printf("종료됨!\n");
    return 0;
}