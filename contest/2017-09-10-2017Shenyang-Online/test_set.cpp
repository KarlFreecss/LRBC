#include<iostream> 
#include<set> 
using namespace std; 
//set����Ԫ�ز���  
int main() 
{ 
    //����һ��int�ͼ��϶���s,��ǰû���κ�Ԫ��  
    set<int> s; 
    s.insert(8);  //��һ�β���8�����Բ���  
    s.insert(1); 
    s.insert(12); 
    s.insert(6); 
    s.insert(8);   //�ڶ��β���8���ظ�Ԫ�أ��������  
    set<int>::iterator it; //����ǰ������� 
    //������������е�����Ԫ��  
    for(it=s.begin();it!=s.end();it++) 
    cout<<*it<<endl;    
    system("pause"); 
    return 0; 
} 
