#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct {
 char name[20];
 int age;
 char major [30];
 int phoneNumber[3]; // p[0]: 010, p[1]: 1234, p[2]: 1234 => 010-1234-1234
} Student;

int selectMenu();

int writeStudent(Student *s); // 학생 추가

void readStudent(Student s); // 명부 읽기

void listStudent(Student *s, int count); // 전체 등록된 명부 출력

int selectStudentNo(Student *s, int count); // 선택된 학생 가져오기

int updateStudent(Student *s); // 명부 수정

void searchName(Student *s, int count); // 학생 이름 검색

int deleteStudent(Student *s); // 명부에 있는 학생 삭제

void saveData(Student *s, int count); // 명부를 File에 저장

int loadData(Student *s); // 파일에서 명부 불러오기

void descendingSort(Student *s, int count); // 명부 내림차순 정렬 

void ascendingSort(Student *s, int count); // 명부 오름차순 정렬
