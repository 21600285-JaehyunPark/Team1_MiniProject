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
 scanf("%[^\n]", s->name);
 getchar();
 printf("나이는 ? ");
 scanf("%d", &s->age);
 printf("전공은 ? ");
 scanf("%[^\n]", s->major);
 getchar();
 printf("휴대폰 번호는 ? ");
 scanf("%d", &s->phoneNumber);
 printf("=> 추가됨!\n");
 return 1;
}
 
void readStudent(Student s){
 printf("%5s %5d %15s %4d-%4d-%4d",
   s.name, s.age, s.major, s.phoneNumber[0],s.phoneNumber[1],s.phoneNumber[2]);
}

void listStudent(Student *s, int count){
 int i = 0;
 printf("\nNo Name  age           Major    Phone Number \n");
 printf("============================================\n");
 for(i= 0; i < count; i++){
   if(s[i].age == -1) continue;
   printf("%2d ", i+1);
   readProduct(s[i]);
 }
}

int updateStudent(Student *s){
 getchar();
 printf("이름은 ? ");
 scanf("%[^\n]", s->name);
 getchar();
 printf("나이는 ? ");
 scanf("%d", &s->age);
 printf("전공은 ? ");
 scanf("%[^\n]", s->major);
 getchar();
 printf("휴대폰 번호는 ? ");
 scanf("%d", &s->phoneNumber);
 printf("=> 수정완료!\n");
return 1;
}

int deleteStudent(Student *s){
s->age = -1;
printf("=> 삭제됨!\n");
return 1;
}
