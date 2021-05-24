#pragma once
#include <stdio.h>
#include "Structures.h"


//�˵���ʾ
void displayMenu() {
	printf("******��Ʒ����ϵͳ�˵�*******\n");
	printf("1. ����Ʒ�������\n");//�����
	printf("2. ������Ʒ\n");//�����
	printf("3. ɾ��ָ������\n");//�����
	printf("4. ����������Ʒ������ϸ\n");//�����
	printf("5. ������Ʒ�������ͳ��\n");//�����
	printf("6. ����Ʒ����������\n");//�����
	printf("7. ���ָ����Ʒ��Ϣ\n");//�����
	printf("8. �޸�����\n");//�����
	printf("0. �˳�ϵͳ\n");//�����
	printf("*****************************\n");
}

//���û���ѡ�����Ʒ��ʾҳ
void dispAllGoodToUsers(Good* firstGood) {
	printf("��Ʒ����\t��Ʒ����\t��Ʒ�۸�\n");
	printf("=============================================\n");
	Good* next = firstGood;
	while (next != NULL) {
		printf("%d\t\t%s\t\t%.2f\n", next->type, next->name, next->value);
		next = next->nextGood;
	}
	printf("=============================================\n");
}

//��ʾһ��������Ϣ 
void dispOrder(Order* o,Good* first) {
	char goodName[20];
	//������Ʒ��Ϣ
	Good* next = first;
	while (next != NULL) {
		if (!strcmp(o->orderIndex, next->index))
			strcpy(goodName, next->name);
		next = next->nextGood;
	}
	printf("%04d\t\t%s\t%s\t\t%d\t%.2f\t%.2f\n", o->index, o->orderIndex,goodName, o->salesVolume, o->unitPrice, o->totalSales);
}

void dispUserOrder(Good* link,int orderIndex) {
	printf("��%04d�Ŷ�����������:\n", orderIndex);
	printf("���\t����\t����\t����\t�ܼ�\n");
	printf("===============================================\n");
	int countGood = 0;
	float countValue = 0;
	int index = 1;
	Good* next = link;
	while (next != NULL) {
		printf("%d:\t%s\t%.2f\t%d\t%.2f\n", index, next->name, next->value, next->count, next->value * next->count);
		countGood++;
		countValue += next->value * next->count;
		next = next->nextGood;
		index++;
	}
	printf("===============================================\n");
	printf("�ܹ�%d����Ʒ,�ܹ�%.2fԪ\n", countGood, countValue);
	printf("===============================================\n");
	
}


//�������ʾһ����Ʒ
void dispGoodByCategory(int categoryIndex,Good* firstGood,Order** oList,int LEN_ORDER) {
	printf("���۵���\t������Ʒid\t������\t����\t�ܶ�\n");
	printf("======================================================\n");
	//������Ʒ����
	Good* next = firstGood;
	while (next != NULL) {
		if (next->type == categoryIndex) {
			//�ҵ���Ӧ�Ķ�����,��Ʒ���,��Ʒ����,��������,����,�ܽ��

			int i;
			for (i = 0; i < LEN_ORDER; i++) {
				if (!strcmp(next->index, oList[i]->orderIndex)) {
					dispOrder(oList[i],firstGood);
				}
			}
		}
		next = next->nextGood;
	}
	printf("======================================================\n");
}

//��ʾһ����Ʒ
void dispGood(Good* g) {
	printf("%8s\t%d\t%8s\t%d\t%.2f\n",g->index,g->type,g->name,g->count,g->value);
}

//������ʾ�򵥵���Ʒid����Ʒ����
void dispGoodSimple(Good* g) {
	printf("%s\t%s\t\n", g->index, g->name);
}

//��ʾ��Ʒ�����ֲ��һ���ʾ�����۶�
void dispAllGoodUseSalesVolume(Good* firstGood, Order** oList,int O_LEN) {
	printf("%10s\t%10s%10s%8s\t%6s\n", "��Ʒid", "��Ʒ����", "��������", "����", "�ܽ��");
	printf("==================================================================\n");
	//��������
	Good* gNext = firstGood;
	while (gNext != NULL) {
		int salesVolume = 0;
		float unitPrice = 0;
		float total = 0;
		int i = 0;
		for (; i < O_LEN; i++) {
			if (!strcmp(oList[i]->orderIndex, gNext->index)) {
				salesVolume += oList[i]->salesVolume;
				unitPrice = oList[i]->unitPrice;
			}
		}
		total = unitPrice * salesVolume;
		printf("%10s\t%10s\t%d\t%.2f\t%.2f\n", gNext->index, gNext->name, salesVolume, unitPrice,total);
		gNext = gNext->nextGood;
	}
	printf("==================================================================\n");
}

//��ʾ��Ʒ����Ϣ���һ���ʾ����Ʒ��������
void dispAllGoodUseTypeName(Good* firstGood,Category** cList) {
	printf("%10s\t%10s\t%10s\t%6s%6s\n", "��Ʒid", "��Ʒ��������", "��Ʒ����", "�����", "�۸�");
	printf("==================================================================\n");
	//��������
	Good* gNext = firstGood;
	while (gNext != NULL) {
		printf("%10s\t%10s\t%10s\t%d\t%.2f\n", gNext->index, cList[gNext->type - 1]->name, gNext->name, gNext->count, gNext->value);
		gNext = gNext->nextGood;
	}
	printf("==================================================================\n");
}

//��ʾһ������
void dispCategory(Category* c) {
	printf("%d\t%s\n",c->index,c->name);
}


//��һ������Ʒ������ʾ����
void dispAllGood(Good* g) {
	printf("��Ʒid\t��Ʒ����\t��Ʒ����\t�����\t�۸�\n");
	printf("==================================================\n");
	Good* gNext = g;
	while (gNext != NULL) {
		dispGood(gNext);
		gNext = gNext->nextGood;
	}
}

//��һ������Ʒ��������Ʒ��ź���Ʒ������ʾ����
void dispAllGoodSimple(Good* g) {
	printf("��Ʒid\t\t��Ʒ����\n");
	printf("=======================\n");
	Good* gNext = g;
	while (gNext != NULL) {
		dispGoodSimple(gNext);
		gNext = gNext->nextGood;
	}
	printf("=======================\n");
}

//��һ��������������ʾ����
void dispAllCategory(Category* c) {
	printf("����id\t��������\n");
	printf("============================\n");
	Category* cNext = c;
	while (cNext != NULL) {
		dispCategory(cNext);
		cNext = cNext->nextCategory;
	}
	printf("============================\n");
}

//��һ��������������ʾ����
void dispAllOrder(Good* firstGood,Order* o,int *MAX_INDEX) {
	*MAX_INDEX = 1;
	printf("���۵���\t������Ʒid\t��Ʒ����\t������\t����\t�ܶ�\n");
	printf("================================================================================\n");
	Order* oNext = o;
	while (oNext != NULL) {
		if (oNext->index > * MAX_INDEX)
			*MAX_INDEX = oNext->index;
		dispOrder(oNext, firstGood);
		oNext = oNext->nextOrder;
	}
	printf("================================================================================\n");
}

//��ʾһ����Ʒ����Ϣ,������Ϣ���ж�Ӧ�����۶�
void dispGoodWithSalesV(Good* g,int v) {
	printf("%8s%8s\t%d\t%d\t\t%.2f\n", g->index, g->name, g->count,v, g->value);
}


//��ʾ�ض���Ʒ��������Ϣ
void dispSpecifiGood(Good* first,Order** oList,int oLen) {
	//����ʾȫ����Ʒ�ı�ź���Ʒ����
	dispAllGoodSimple(first);
	//���û�������Ʒ��Ż���Ʒ����
	printf("��������Ҫ���ҵ���Ʒ�ı�Ż�����:");
	char searchStr[20];
	scanf("%s", searchStr);

	

	printf("��Ʒid\t��Ʒ����\t�����\t��������\t����\n");
	printf("=======================================================================\n");
	//�����������
	Good* g1 = first;
	while (g1 != NULL) {
		if (strcmp(g1->index, searchStr) == 0 || strcmp(g1->name, searchStr) == 0) {
			//�����۶��������ҵ���Ӧ�����۶�
			int v = 0;
			int i;
			for (i = 0; i < oLen; i++) {
				if (strcmp(g1->index, oList[i]->orderIndex) == 0) {
					v += oList[i]->salesVolume;
				}
			}
			dispGoodWithSalesV(g1,v);
		}
		g1 = g1->nextGood;
	}
	printf("=======================================================================\n");
	return;
}