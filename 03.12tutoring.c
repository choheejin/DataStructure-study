// 구조체 실습

#include<stdio.h>
typedef struct _Person {
	int age;
	char gender;
}Person;

int main()
{
	Person p1;
	printf("%d %d %d %d", sizeof(p1.age), sizeof(p1.gender), sizeof(p1), sizeof(struct _Person));
}


// 구조체 구성 시 가장 큰 자료형에 맞춰서 구조체의 주소가 배정된다.

/*   1단계
	 이름과 나이, 학과 정보를 가진 Person구조체를 생성하고, 생성한 구조체를   
	 이용하여 만든 인스턴스에 이름 : 둘리, 나이 : 11, 주소 : 남극으로 입력.		  */

/*  2단계
	이제 setPerson이라는 메서드를 정의해보자. setPerson 메서드는 파라미터로 
	구조체 Person형식을 받는다. 그리고 setPerson 메서드는 파라미터로 들어온 
	구조체의 이름 항목을 "고길동"으로 바꾸고, 나이를 40으로 수정하고, 
	주소를 "서울시"로 변경한다.만든 setPerson함수를 메인함수에서 호출해보고
	호출한 후 처음에 만들었던 인스턴스의 이름, 나이, 주소 항목을 출력해보자.	 */

#include<stdio.h>
#include<string.h>
typedef struct _Person {
	char name[30];
	int age;
	char address[20];
}Person;

void setPerson(Person p1)
{
	printf("\n");
	strcpy(p1.name, "고길동");
	strcpy(p1.address, "서울시");
	p1.age = 40;
	
}

int main() 
{
	Person p1;
	p1.age = 11;
	strcpy(p1.name, "둘리");
	strcpy(p1.address, "남극");
	printf("이름: %s\n", p1.name);
	printf("나이: %d\n", p1.age);
	printf("주소: %s\n", p1.address);

	setPerson(p1);					 // 함수에 구조체 전달, 멤버 복사돼서 복사된 구조체가 바뀌는 것.
	printf("이름: %s\n", p1.name);   // 원본 p1에는 변화가 없어서 출력에 변화가 없음.
	printf("나이: %d\n", p1.age);
	printf("주소: %s\n", p1.address);

	return 0;
}

// (+ alpha)
//   .  ))  구조체 멤버 접근
//  ->  ))  구조체 주소 접근 -- 매개변수를 포인터로 할 경우, p1->name;
//  *   ))  내가 가리키고 싶은 것이 있을때

// 1주차 실습 과제 _ 2차원 숫자 배열 

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int row, col;
	int num = 0;
	int rowIndex, colIndex;
	int** array;

	printf("행을 입력하세요: ");
	scanf("%d", &row);
	printf("열을 입력하세요: ");
	scanf("%d", &col);
	
	array = (int**)malloc(sizeof(int*) * row); // 행row 메모리 할당
	for (rowIndex = 0; rowIndex < row; rowIndex++)  // 행에 대한 각 열의 메모리 할당
	{
		array[rowIndex] = (int*)malloc(sizeof(int) * col);
	}

	for (rowIndex = 0; rowIndex < row; rowIndex++) {
		for (colIndex = 0; colIndex < col; colIndex++) {
			array[rowIndex][colIndex] = num;
			printf("[%.2d] ", array[rowIndex][colIndex]);
			num++;
		}
		printf("\n");
	}

	for (rowIndex = 0; rowIndex < row; rowIndex++) {
		free(array[rowIndex]);
	}
	free(array);
	return 0;
}
