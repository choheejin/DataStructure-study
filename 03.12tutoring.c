// ����ü �ǽ�

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


// ����ü ���� �� ���� ū �ڷ����� ���缭 ����ü�� �ּҰ� �����ȴ�.

/*   1�ܰ�
	 �̸��� ����, �а� ������ ���� Person����ü�� �����ϰ�, ������ ����ü��   
	 �̿��Ͽ� ���� �ν��Ͻ��� �̸� : �Ѹ�, ���� : 11, �ּ� : �������� �Է�.		  */

/*  2�ܰ�
	���� setPerson�̶�� �޼��带 �����غ���. setPerson �޼���� �Ķ���ͷ� 
	����ü Person������ �޴´�. �׸��� setPerson �޼���� �Ķ���ͷ� ���� 
	����ü�� �̸� �׸��� "��浿"���� �ٲٰ�, ���̸� 40���� �����ϰ�, 
	�ּҸ� "�����"�� �����Ѵ�.���� setPerson�Լ��� �����Լ����� ȣ���غ���
	ȣ���� �� ó���� ������� �ν��Ͻ��� �̸�, ����, �ּ� �׸��� ����غ���.	 */

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
	strcpy(p1.name, "��浿");
	strcpy(p1.address, "�����");
	p1.age = 40;
	
}

int main() 
{
	Person p1;
	p1.age = 11;
	strcpy(p1.name, "�Ѹ�");
	strcpy(p1.address, "����");
	printf("�̸�: %s\n", p1.name);
	printf("����: %d\n", p1.age);
	printf("�ּ�: %s\n", p1.address);

	setPerson(p1);					 // �Լ��� ����ü ����, ��� ����ż� ����� ����ü�� �ٲ�� ��.
	printf("�̸�: %s\n", p1.name);   // ���� p1���� ��ȭ�� ��� ��¿� ��ȭ�� ����.
	printf("����: %d\n", p1.age);
	printf("�ּ�: %s\n", p1.address);

	return 0;
}

// (+ alpha)
//   .  ))  ����ü ��� ����
//  ->  ))  ����ü �ּ� ���� -- �Ű������� �����ͷ� �� ���, p1->name;
//  *   ))  ���� ����Ű�� ���� ���� ������

// 1���� �ǽ� ���� _ 2���� ���� �迭 

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int row, col;
	int num = 0;
	int rowIndex, colIndex;
	int** array;

	printf("���� �Է��ϼ���: ");
	scanf("%d", &row);
	printf("���� �Է��ϼ���: ");
	scanf("%d", &col);
	
	array = (int**)malloc(sizeof(int*) * row); // ��row �޸� �Ҵ�
	for (rowIndex = 0; rowIndex < row; rowIndex++)  // �࿡ ���� �� ���� �޸� �Ҵ�
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
