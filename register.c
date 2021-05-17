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
printf("5. 찾기\n");
printf("6. 저장\n");
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
 printf("%5s %4d  %20s %14s\n",
   s.name, s.age, s.major, s.phoneNumber);
}

void listStudent(Student *s, int count){
 int i = 0;
 printf("\nNo Name     age   Major         Phone Number \n");
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

void searchName(Student *s, int count){
    int scnt = 0;
    char search[20];

    printf("검색할 이름? ");
    scanf("%s", search);

    printf("\nNo Name   age   Major        Phone Number \n");
    printf("============================================\n");
    for(int i=0;i<count;i++){
        if(s[i].age == -1) continue;
        if(strstr(s[i].name, search)){
        printf("%2d ", i+1);
        readStudent(s[i]);
        scnt++;
        }
    }
    if(scnt == 0) printf("=>검색된 데이터 없음!");
    printf("\n");
}

void saveData(Student *s, int count){
  FILE *fp;
  fp = fopen("register.txt", "wt");

  for(int i=0;i<count;i++){
    if(s[i].age == -1) continue;
      fprintf(fp, "%s %d %s %s\n", s[i].name, s[i].age, s[i].major, s[i].phoneNumber);
  }

  fclose(fp);
  printf("=> 저장됨! \n");
}

int loadData(Student *s){
  FILE *fp;
  if(access("register.txt", 00) == -1){
    printf("=> 파일 없음");
    return 0;
  }
  fp = fopen("register.txt", "rt");
  int i=0;
  for(;i<100;i++){
    fscanf(fp, "%s", s[i].name);
    if(feof(fp)) break;
    fscanf(fp, "%d", &s[i].age);
    fscanf(fp, "%s", s[i].major);
    fscanf(fp, "%s", s[i].phoneNumber);
  }
  fclose(fp);
  printf("=> 로딩 성공!\n");
  return i;
}

void descendingSort(Student *s, int count){

}

void ascendingSort(Student *s, int count){

}