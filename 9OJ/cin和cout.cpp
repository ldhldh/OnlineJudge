#include<iostream>
using namespace std; 
int main()
{
int x=30, y=300, z=1024;
cout<<x<<' '<<y<<' '<<z<<endl; //��ʮ�������
cout.unsetf(ios::dec ); //ȡ��ʮ�����������
cout.setf(ios::showbase | ios::uppercase); //���û�ָʾ���������ֵ�е���ĸ��д���
cout<<x<<' '<<y<<' '<<z<<endl;
cout.unsetf(ios::showbase | ios::uppercase); //ȡ����ָʾ���������ֵ�е���ĸ��д���
cout.setf(ios::oct); //����Ϊ�˽������,�����ò�ȡ��һֱ��Ч
cout<<x<<' '<<y<<' '<<z<<endl; //���˽������
cout.setf(ios::showbase | ios::uppercase); //���û�ָʾ���������ֵ�е���ĸ��д���
cout<<x<<' '<<y<<' '<<z<<endl;
cout.unsetf(ios::showbase | ios::uppercase); //ȡ����ָʾ���������ֵ�е���ĸ��д���
cout.unsetf(ios::oct); //ȡ���˽���������ã��ָ���ʮ�������
cout.setf(ios::hex); //����Ϊʮ���������
cout<<x<<' '<<y<<' '<<z<<endl;
cout.setf(ios::showbase | ios::uppercase); //���û�ָʾ���������ֵ�е���ĸ��д���
cout<<x<<' '<<y<<' '<<z<<endl;
cout.unsetf(ios::showbase | ios::uppercase); //ȡ����ָʾ���������ֵ�е���ĸ��д���
cout.unsetf(ios::hex); //ȡ��ʮ������������ã��ָ���ʮ�������
cout<<x<<' '<<y<<' '<<z<<endl;
return 0; 
}
