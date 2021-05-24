#pragma once
#include "Structures.h"

//����Ʒ����д�뵽�ļ���
void writeGoods(FILE *f,Good* first) {
	fprintf(f, "#��ͷΪע�͡�#�����������£�\n");
	fprintf(f, "#��Ʒ���,���������,��Ʒ����,�����,����\n");
	Good* next = first;
	while (next != NULL) {
		fprintf(f, "%s %d %s %d %f\n", next->index, next->type, next->name, next->count, next->value);
		next = next->nextGood;
	}
}

//����������д�뵽�ļ���
void writeOrder(FILE* f, Order* first) {
	fprintf(f, "#��ͷΪע�͡�#�����������£�\n");
	fprintf(f, "#�������,��Ʒ���,������,����,�ܽ��\n");
	Order* next = first;
	while (next != NULL) {
		fprintf(f, "%04d %s %d %.2f %.2f\n",next->index,next->orderIndex,next->salesVolume,next->unitPrice,next->totalSales);
		next = next->nextOrder;
	}
}

//����������д�뵽�ļ���
void writeCategory(FILE* f, Category* first) {
	fprintf(f,"#��ͷΪע�͡�#�����������£�\n");
	fprintf(f,"#�����,�����\n");
	Category* next = first;
	while (next != NULL) {
		fprintf(f, "%d %s\n",next->index,next->name);
		next = next->nextCategory;
	}
}