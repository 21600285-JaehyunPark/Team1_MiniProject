#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "register.h"

int selectMenu(){
int menu;
printf("\n*** 명부관리 ***\n");
printf("1. 조회\n");
printf("2. 추가\n");
printf("3. 수정\n");
printf("4. 삭제\n");
printf("0. 종료\n\n");
printf("=> 원하는 메뉴는? ");
scanf("%d", &menu);
return menu;
}

int writeStudent(Student *s){
 printf("이름은 ? ");
 scanf("%s", s->name);
 printf("나이는 ? ");
 scanf("%d", &s->age);
 printf("학부는 ? ");
 scanf("%s", s->major);
 getchar();
 printf("휴대폰 번호는? ex) 010-1234-1234 처럼 작성해주세요 ");
 scanf("%s", s->phoneNumber);
 printf("=> 추가됨!\n");
 return 1;
}
 
void readStudent(Student s){
 printf("%5s %5d %15s %15s",
   s.name, s.age, s.major, s.phoneNumber);
}

void listStudent(Student *s, int count){
 int i = 0;
 printf("\nNo Name    age   Major        Phone Number \n");
 printf("============================================\n");
 for(i= 0; i < count; i++){
   if(s[i].age == -1) continue;
   printf("%2d ", i+1);
   readStudent(s[i]);
 }
}

int updateStudent(Student *s){
 printf("이름은 ? ");
 scanf("%s", s->name);
 printf("나이는 ? ");
 scanf("%d", &s->age);
 printf("학부는 ? ");
 scanf("%s", s->major);
 getchar();
 printf("휴대폰 번호는? ex) 010-1234-1234 처럼 작성해주세요 ");
 scanf("%s", s->phoneNumber);
 printf("=> 수정완료!\n");
return 1;
}

int deleteStudent(Student *s){
s->age = -1;
printf("=> 삭제됨!\n");
return 1;
}

int selectStudentNo(Student *s, int count){
  int no;
    listStudent(s, count);
    printf("\n번호는? (취소:0)? ");
    scanf("%d", &no);
    return no;
}
