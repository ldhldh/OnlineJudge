#include<stdio.h>
#define Max_length 100  //自定义允许的最大字长，这里不妨设为100 
struct Letter{
//定义字母结构 
		int Up;   //下标 
		int Down;  //上标
		int if_empty;  //判断是否为空字,1表示空，0表示不空 
		int ID;  //给每个字母一个对应于数组下标的ID，方便操作 

		void modify_down(int m){  //用来调整下标 ，在重新函数中限定m可能的取值为+-1  
			Down+=m;
		}
}; 
Letter Words[Max_length+1];  //给出存储结构 
int real_length;  //表示实际字长 
void init_Words(){
	//初始化
	for(int i = 0;i < Max_length+1;i++){
		Words[i].if_empty = 1;
		Words[i].Up = 1;
		Words[i].ID = i; 
	}
}
void Swap(Letter A,Letter B){
	//交换A、B在字中的顺序，但不交换对应位置的ID，其中A、B为相邻两项 
	int i = A.ID;
	int j = B.ID;
	Letter C = Words[j];
	Words[j].Down = Words[i].Down;
	Words[j].Up = Words[i].Up;
	Words[i].Down = C.Down;
	Words[i].Up = C.Up;
}
void Delete(Letter A){
	//在字中删除A
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
		 ************（创新）************** 
	R1~R4四条重写规则均可逆用，且涵盖了i！=k时的所有8中数对，所以任意两个相邻字母均可
	按规则做交换运算， 观察发现R1~R4具有相似之处，我在此引入新的方法将这四条规则及其逆
	运算（共8种运算规则）统一为一条规则：
	对任意两个相邻字母（X_a^i * X_b^j）: 
		1：前者下标为a，后者下标为b，若a>b，称这两个字母为标准序，记order = 1,
	若a<b，称逆序，记 order = -1； 
		（简单说，前者下标大为标准序，后者下标大为逆序，逆序记order = -1） 
		2：选下标小的数X,用其上标与order做乘法，结果记为m，则m可能为+-1；
		3：交换这两个字母顺序，即写作（X_b^j * X_a^i ），并选其中下标大的数X，将其下标
	加m（可能是加1或者减1），得到X的新下标。 

	 经验证，该规则可以代替R1~R4重写规则及其逆用，且更方便计算机和人使用。 
	 	 ************（创新）************** 
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
		}//R3、R4及R1、R2的逆用 
		else{
			m = order*B.Up;
			Words[k].modify_down(m);
		} //R1、R2及R3、R4的逆用 
		Swap(A,B);
	}
}
int if_Rule(Letter A,Letter B){
	//判断是否需要对相邻的字母AB使用Rule()
	if(A.Up == -1&&B.Up == 1)return 1; //前者是负字母，后者为正字母，需要 
	if(A.Up == 1&&B.Up == -1)return 0; //前者是正字母，后者为负字母，不需要
	if(A.Up == 1&&B.Up == 1&&A.Down <= B.Down)return 0; //均为正字，后者大时不需要 
	if(A.Up == 1&&B.Up == 1&&A.Down > B.Down)return 1;
	if(A.Up == -1&&B.Up == -1&&A.Down >= B.Down)return 0; //均为负字，前者大时不需要 
	if(A.Up == -1&&B.Up == -1&&A.Down < B.Down) return 1;

}
void Rewrite1(){
	//重写函数1，将字w转为半法式
	//从第二个字母开始，将每个字母插入到它前边序列（前边序列已经满足NF1）的合适位置 
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
	//重写函数2，将半法式字转为法式 
	int if_end = 0; //用于终止循环寻找最大违规二元组，默认不循环，即遍历一次 
	while(true){//如果找到最大违规二元组，则需再次寻找 
		if_end = 0;
		int i = 1;
		int j = 2;
		int mid_p; 
		for(i;i < real_length;i++){//找正负交界 
			if(Words[i].Up == 1&&Words[j].Up == -1){//找到正负字母交界，若没有则已经是法式
				mid_p = i;
				while(Words[i].Down != Words[j].Down&&i > 0&&j <= real_length)
				{//找最大违规二元组，若没有，则已经是法式 
					if(Words[i].Down > Words[j].Down)i--;
					else j++; 
				} 
				if(i > 0&&j <= real_length){
					//找到了最大违规二元组，且下标为i,j 
					 while(i < mid_p){
					 	Rule(Words[i],Words[i+1]);
					 	i++;
					 }
					 while(j > mid_p){
					 	Rule(Words[j-1],Words[j]);
					 	j--;
					 }
					 if_end = 1; 
				}//消去最大违规二元组 
				break;//停止找正负交界
			}
			j++;
		}
		if(if_end == 0)break;
	} 
}

int main(){
	//将任意字w转化为其法式 
while(1){
 
	init_Words(); //初始化 
	
	printf("请从左至右依次输入字母的上标和下标，并按回车，上标不为+-1表示输入结束：\n");
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
	}//得到字w
	 
	Rewrite1();//重写得到半法式 
	Rewrite2();//重写得到法式 
	
	if(real_length != 0){	//输出 
		//输出正字部分，或者输出“正字空” 
		int i =1;
		if(Words[1].Up == -1)printf("正字空\n");
		else printf("正字下标从左至右依次为：\n");
	
		while(i <= real_length&&Words[i].Up == 1){
	 		printf("%d ",Words[i].Down);
	 		i++;
		}
		printf("\n");
		if(i > real_length)	printf("负字空\n");  //输出负字部分，或者输出“负字空” 
		else printf("负字下标从左至右依次为：\n");
		
		while(i <= real_length&&Words[i].Up == -1){
	 		printf("%d ",Words[i].Down);
	 		i++;
		}
		printf("\n\n");
	}
}
	return 0;
}
 
