#pragma once
#include <stdlib.h>
#include "Structures.h"
//���򷽷�ͷ�ļ�

Good* sortGoodBySales(Good* gFirst,int LEN_G,Order** o,int LEN_O) {
	if (gFirst == NULL) return NULL;
	Good** gList = (Good**)malloc(sizeof(Good*) * LEN_G);

	//����Ʒ����List
	int index = 0;
	Good* gNext = gFirst;
	while (gNext != NULL) {
		gList[index] = gNext;
		index++;
		gNext = gNext->nextGood;
	}

	//���򷽷�:ð��
	int i;
	for (i = 0; i < LEN_G; i++) {
		int j;
		for (j = i; j < LEN_G; j++) {
			//�ҵ���Ӧ��������
			int iVolume = 0;
			int jVolume = 0;
			int z = 0;
			for (; z < LEN_O; z++) {
				if (!strcmp(o[z]->orderIndex, gList[i]->index)) {
					iVolume += o[z]->salesVolume;
					continue;
				}
				if (!strcmp(o[z]->orderIndex, gList[j]->index)) {
					jVolume += o[z]->salesVolume;
					continue;
				}
			}

			//��ʼ�Ƚ�
			if (iVolume < jVolume) {
				//����ָ��
				Good* temp = gList[i];
				gList[i] = gList[j];
				gList[j] = temp;
			}
		}
	}
	//�ж���β
	gList[LEN_G-1]->nextGood = NULL;
	Good* g1 = NULL;
	//�������ӳ�����
	if (LEN_G >= 1)
		g1 = gList[0];
	i = 1;
	Good* last = g1;
	for (; i < LEN_G; i++) {
		last->nextGood = gList[i];
		last = last->nextGood;
	}
	return g1;
	free(gList);
}

//������Ʒ�ı������
Good* sortGoodByIndex(Good* gFirst, int gLen) {
	if (gFirst == NULL) return NULL;
	//��Ʒ�����Ը��õ�����
	Good** gList = (Good**)malloc(sizeof(Good*) * gLen);

	//����Ʒ����List
	int index = 0;
	Good* gNext = gFirst;
	while (gNext != NULL) {
		gList[index] = gNext;
		index++;
		gNext = gNext->nextGood;
	}

	//���򷽷�:ð��
	int i;
	for (i = 0; i < gLen; i++) {
		int j;
		for (j = i; j < gLen; j++) {
			if (strcmp(gList[i]->index, gList[j]->index) > 0) {
				//����ָ��
				Good* temp = gList[i];
				gList[i] = gList[j];
				gList[j] = temp;
			}
		}
	}

	//�ж���β
	gList[gLen-1]->nextGood = NULL;

	Good* g1 = NULL;
	//�������ӳ�����
	if (gLen >= 1)
		g1 = gList[0];
	i = 1;
	Good* last = g1;
	for (; i < gLen; i++) {
		last->nextGood = gList[i];
		last = last->nextGood;
	}
	free(gList);
	gFirst = g1;
}
