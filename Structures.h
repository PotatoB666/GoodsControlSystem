#pragma once
//���ͽṹ
typedef struct category {
	int index; //����id
	char name[20];  //��������
	struct category* nextCategory;
}Category;

//���۽ṹ
typedef struct order {
	int index;//���۵���
	char orderIndex[20];//���۵���Ʒid
	int salesVolume;//���۶�
	float unitPrice;//����
	float totalSales;//�ܶ�
	struct order* nextOrder;
}Order;

//��Ʒ�ṹ
typedef struct good {
	char index[20];//��Ʒid
	int type;//��Ʒ����
	char name[20];//��Ʒ����
	int count;//�����
	float value;//�۸�
	struct good* nextGood;
}Good;
