#include<stdio.h>
#define Max_length 100  //�Զ������������ֳ������ﲻ����Ϊ100 
struct Letter{
//������ĸ�ṹ 
		int Up;   //�±� 
		int Down;  //�ϱ�
		int if_empty;  //�ж��Ƿ�Ϊ����,1��ʾ�գ�0��ʾ���� 
		int ID;  //��ÿ����ĸһ����Ӧ�������±��ID��������� 

		void modify_down(int m){  //���������±� �������º������޶�m���ܵ�ȡֵΪ+-1  
			Down+=m;
		}
}; 
Letter Words[Max_length+1];  //�����洢�ṹ 
int real_length;  //��ʾʵ���ֳ� 
void init_Words(){
	//��ʼ��
	for(int i = 0;i < Max_length+1;i++){
		Words[i].if_empty = 1;
		Words[i].Up = 1;
		Words[i].ID = i; 
	}
}
void Swap(Letter A,Letter B){
	//����A��B�����е�˳�򣬵���������Ӧλ�õ�ID������A��BΪ�������� 
	int i = A.ID;
	int j = B.ID;
	Letter C = Words[j];
	Words[j].Down = Words[i].Down;
	Words[j].Up = Words[i].Up;
	Words[i].Down = C.Down;
	Words[i].Up = C.Up;
}
void Delete(Letter A){
	//������ɾ��A
	A.if_empty = 1;
	for(int i = A.ID;i < real_length ; i++){
		Words[i] = Words[i+1];
		Words[i].ID = i; 
	}
	real_length--;
}
void Rule(Letter A,Letter B){
//R1~R5
/*
		 ************�����£�************** 
	R1~R4������д����������ã��Һ�����i��=kʱ������8�����ԣ�������������������ĸ����
	���������������㣬 �۲췢��R1~R4��������֮�������ڴ������µķ�������������������
	���㣨��8���������ͳһΪһ������
	����������������ĸ��X_a^i * X_b^j��: 
		1��ǰ���±�Ϊa�������±�Ϊb����a>b������������ĸΪ��׼�򣬼�order = 1,
	��a<b�������򣬼� order = -1�� 
		����˵��ǰ���±��Ϊ��׼�򣬺����±��Ϊ���������order = -1�� 
		2��ѡ�±�С����X,�����ϱ���order���˷��������Ϊm����m����Ϊ+-1��
		3��������������ĸ˳�򣬼�д����X_b^j * X_a^i ������ѡ�����±�����X�������±�
	��m�������Ǽ�1���߼�1�����õ�X�����±ꡣ 

	 ����֤���ù�����Դ���R1~R4��д���������ã��Ҹ�������������ʹ�á� 
	 	 ************�����£�************** 
*/ 	int k = A.ID;
	int l = B.ID;
	int order = 1;
	int m;
	if(A.Down == B.Down){
		if(A.Up + B.Up == 0){
			Delete(B);
			Delete(A);	
		}//R5 
	}
	else {
		if(A.Down < B.Down){
			order = -1;
			m = order*A.Up;
			Words[l].modify_down(m);
		}//R3��R4��R1��R2������ 
		else{
			m = order*B.Up;
			Words[k].modify_down(m);
		} //R1��R2��R3��R4������ 
		Swap(A,B);
	}
}
int if_Rule(Letter A,Letter B){
	//�ж��Ƿ���Ҫ�����ڵ���ĸABʹ��Rule()
	if(A.Up == -1&&B.Up == 1)return 1; //ǰ���Ǹ���ĸ������Ϊ����ĸ����Ҫ 
	if(A.Up == 1&&B.Up == -1)return 0; //ǰ��������ĸ������Ϊ����ĸ������Ҫ
	if(A.Up == 1&&B.Up == 1&&A.Down <= B.Down)return 0; //��Ϊ���֣����ߴ�ʱ����Ҫ 
	if(A.Up == 1&&B.Up == 1&&A.Down > B.Down)return 1;
	if(A.Up == -1&&B.Up == -1&&A.Down >= B.Down)return 0; //��Ϊ���֣�ǰ�ߴ�ʱ����Ҫ 
	if(A.Up == -1&&B.Up == -1&&A.Down < B.Down) return 1;

}
void Rewrite1(){
	//��д����1������wתΪ�뷨ʽ
	//�ӵڶ�����ĸ��ʼ����ÿ����ĸ���뵽��ǰ�����У�ǰ�������Ѿ�����NF1���ĺ���λ�� 
	for(int i = 2;i <= real_length;i++){
		int j = i;
		int flag = if_Rule(Words[j-1],Words[j]);
		while(flag == 1&&j > 1){
			flag = if_Rule(Words[j-1],Words[j]);
			if(flag == 1){
				Rule(Words[j-1],Words[j]);
			}
			j--;
		}
	}
}
void Rewrite2(){
	//��д����2�����뷨ʽ��תΪ��ʽ 
	int if_end = 0; //������ֹѭ��Ѱ�����Υ���Ԫ�飬Ĭ�ϲ�ѭ����������һ�� 
	while(true){//����ҵ����Υ���Ԫ�飬�����ٴ�Ѱ�� 
		if_end = 0;
		int i = 1;
		int j = 2;
		int mid_p; 
		for(i;i < real_length;i++){//���������� 
			if(Words[i].Up == 1&&Words[j].Up == -1){//�ҵ�������ĸ���磬��û�����Ѿ��Ƿ�ʽ
				mid_p = i;
				while(Words[i].Down != Words[j].Down&&i > 0&&j <= real_length)
				{//�����Υ���Ԫ�飬��û�У����Ѿ��Ƿ�ʽ 
					if(Words[i].Down > Words[j].Down)i--;
					else j++; 
				} 
				if(i > 0&&j <= real_length){
					//�ҵ������Υ���Ԫ�飬���±�Ϊi,j 
					 while(i < mid_p){
					 	Rule(Words[i],Words[i+1]);
					 	i++;
					 }
					 while(j > mid_p){
					 	Rule(Words[j-1],Words[j]);
					 	j--;
					 }
					 if_end = 1; 
				}//��ȥ���Υ���Ԫ�� 
				break;//ֹͣ����������
			}
			j++;
		}
		if(if_end == 0)break;
	} 
}

int main(){
	//��������wת��Ϊ�䷨ʽ 
while(1){
 
	init_Words(); //��ʼ�� 
	
	printf("�������������������ĸ���ϱ���±꣬�����س����ϱ겻Ϊ+-1��ʾ���������\n");
	for(int i = 1;i <= Max_length;i ++) {
		scanf("%d",&Words[i].Up);
	//	printf("%d %d\n",Words[i].Up,Words[i].Down);
		if(Words[i].Up != 1 && Words[i].Up != -1){
			real_length = i-1;
			break; 
		}
		else {
			scanf("%d",&Words[i].Down);
			Words[i].if_empty = 0;
		}
	}//�õ���w
	 
	Rewrite1();//��д�õ��뷨ʽ 
	Rewrite2();//��д�õ���ʽ 
	
	if(real_length != 0){	//��� 
		//������ֲ��֣�������������ֿա� 
		int i =1;
		if(Words[1].Up == -1)printf("���ֿ�\n");
		else printf("�����±������������Ϊ��\n");
	
		while(i <= real_length&&Words[i].Up == 1){
	 		printf("%d ",Words[i].Down);
	 		i++;
		}
		printf("\n");
		if(i > real_length)	printf("���ֿ�\n");  //������ֲ��֣�������������ֿա� 
		else printf("�����±������������Ϊ��\n");
		
		while(i <= real_length&&Words[i].Up == -1){
	 		printf("%d ",Words[i].Down);
	 		i++;
		}
		printf("\n\n");
	}
}
	return 0;
}
 
