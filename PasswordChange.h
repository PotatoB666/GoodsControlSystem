#pragma once
#include <stdio.h>
#include <string.h>

void crypt(char* s);
void decode(char* s);
//�����޸�
void changePwd() {
	while (1)
	{
		char newPwd[20];
		char againCheck[20];
		printf("�������µ�����:");
		for (int i = 0; i < 20; i++) {
			char ch = getch();
			if (ch == 13) {
				newPwd[i] = '\0';
				break;
			}
			newPwd[i] = ch;
			printf("*");
		}
		printf("\n");
		printf("���ٴ�ȷ����������:");
		for (int i = 0; i < 20; i++) {
			char ch = getch();
			if (ch == 13) {
				againCheck[i] = '\0';
				break;
			}
			againCheck[i] = ch;
			printf("*");
		}
		printf("\n\n");
		if (strcmp(newPwd, againCheck) == 0) {
			//����������ȷ
			FILE* f = fopen("data\\pwd.txt", "w");
			crypt(newPwd);
			fprintf(f, "%s", newPwd);
			printf("�����޸ĳɹ�,���μ���������.\n");
			fclose(f);
			return;
		}
		else {
			//�ڶ��������������
			printf("�ڶ����������,�������޸�����...\n");
		}
	}
}

//���ܺ���(�򵥼���)
void crypt(char* s) {
	int i = 0;
	while (s[i] != '\0') {
		s[i] += 10;
		i++;
	}
}
//���ܺ���
void decode(char* s) {
	int i = 0;
	while (s[i] != '\0') {
		s[i] -= 10;
		i++;
	}
}