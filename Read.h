#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"

#define FLASHBACK_OFFSET 1//�ۻ�ʱҪ����\n

//��ȡ��һ����Ʒ
Good* readNextGood(FILE *f_goods) {
	char nextStr[50];
	fgets(nextStr, 50, f_goods);
	if (nextStr[0] == '#') {
		return NULL;
	}
	//ָ���ۻ�
	fseek(f_goods, -(long)(strlen(nextStr)+FLASHBACK_OFFSET), SEEK_CUR);
	Good* g = (Good*)calloc(1, sizeof(Good));
	fscanf(f_goods, "%s", g->index); //��ȡ��Ʒ���
	fscanf(f_goods, "%d", &(g->type)); //��ȡ��Ʒ����
	fscanf(f_goods, "%s", g->name); //��ȡ��Ʒ����
	fscanf(f_goods, "%d", &(g->count)); //��ȡ��Ʒ�������
	fscanf(f_goods, "%f", &(g->value)); //��ȡ��Ʒ����
	return g;
}

//��ȡ��һ��������Ϣ
Order* readNextOrder(FILE* f_orders) {
	char nextStr[50];
	fgets(nextStr, 50, f_orders);
	if (nextStr[0] == '#') {
		return NULL;
	}
	//ָ���ۻ�
	fseek(f_orders, -(long)(strlen(nextStr) + FLASHBACK_OFFSET), SEEK_CUR);
	Order* o = (Order*)calloc(1, sizeof(Order));
	fscanf(f_orders, "%d", &(o->index));  //��ȡ���۵���
	fscanf(f_orders, "%s", o->orderIndex);       //��ȡ������Ʒ���
	fscanf(f_orders, "%d", &(o->salesVolume)); //��ȡ���۶�
	fscanf(f_orders, "%f", &(o->unitPrice));   //��ȡ����
	fscanf(f_orders, "%f", &(o->totalSales));  //�ܶ�
	return o;
}

//��ȡ��һ������
Category* readNextCategory(FILE* f_category) {
	char nextStr[50];
	fgets(nextStr, 50, f_category);
	if (nextStr[0] == '#') {
		return NULL;
	}
	fseek(f_category, -(long)(strlen(nextStr) + FLASHBACK_OFFSET), SEEK_CUR);
	Category* c = (Category*)calloc(1, sizeof(Category));
	fscanf(f_category, "%d", &(c->index)); //��ȡ���ͱ��
	fscanf(f_category, "%s", c->name);  //��ȡ��������
	return c;
}

//��ȡ���е���Ʒ��Ϣ,���ҷ��ص�������ͷ
Good* readAllGood(FILE *f_good,int *LEN) {
	if (feof(f_good)) return NULL;
	//����ͷ
	Good* firstGood=NULL;
	while (!feof(f_good)) {
		firstGood = readNextGood(f_good);
		if (firstGood == NULL) continue;
		else break;
	}
	if (!strcmp(firstGood->index,""))
	{
		free(firstGood);
		return NULL;
	}
	(*LEN)++;
	Good* lastGood = NULL;
	while (!feof(f_good)) {
		Good* nextGood = readNextGood(f_good);
		if (nextGood == NULL) continue;
		if (strcmp(nextGood->index, "") == 0) {
			break;
		}
		//�������Ӳ���
		if (lastGood != NULL)
			lastGood->nextGood = nextGood;
		else
			firstGood->nextGood = nextGood;
		//����+1
		(*LEN)++;
		lastGood = nextGood;
	}
	return firstGood;
}

//��ȡ���е�������Ϣ,���ҷ��ص�������ͷ
Category* readAllCategory(FILE* f_category,int *LEN) {
	if (feof(f_category)) return NULL;
	Category* firstCategory=NULL;
	while (!feof(f_category)) {
		firstCategory = readNextCategory(f_category);
		if (firstCategory == NULL) continue;
		else break;
	}
	if (firstCategory->index == 0) {
		free(firstCategory);
		return NULL;
	}
	(*LEN)++;
	Category* lastCategory = NULL;
	while (!feof(f_category)) {
		Category* nextCategory = readNextCategory(f_category);
		if (nextCategory == NULL) continue;
		if (nextCategory->index == 0) {
			break;
		}
		//�������Ӳ���
		if (lastCategory != NULL)
			lastCategory->nextCategory = nextCategory;
		else
			firstCategory->nextCategory = nextCategory;
		//����+1
		(*LEN)++;
		lastCategory = nextCategory;
	}
	return firstCategory;
}

//���ļ��ж�ȡȫ����������Ϣ
Order* readAllOrder(FILE* f_order,int *LEN,int *maxIndex) {
	if (feof(f_order))
		return NULL;
	Order* firstOrder = NULL;
	while (!feof(f_order)) {
		firstOrder = readNextOrder(f_order);
		if (firstOrder == NULL) continue;
		else break;
	}
	
	if (firstOrder->index == 0)
	{
		free(firstOrder);
		return NULL;
	}
	(*LEN)++;
	Order* lastOrder = NULL;
	while (!feof(f_order)) {
		Order* nextOrder = readNextOrder(f_order);
		if (nextOrder == NULL) continue;
		if (nextOrder->index == 0) {
			break;
		}
		//�������Ӳ���
		if (lastOrder != NULL)
			lastOrder->nextOrder = nextOrder;
		else
			firstOrder->nextOrder = nextOrder;
		//����+1
		(*LEN)++;
		//������󶩵���,�����������������
		if (*maxIndex < nextOrder->index)
			(*maxIndex) = nextOrder->index;
		lastOrder = nextOrder;
	}
	return firstOrder;
}