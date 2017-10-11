#include<iostream> 
#include<set> 
using namespace std; 
//set插入元素操作  
int main() 
{ 
    //定义一个int型集合对象s,当前没有任何元素  
    set<int> s; 
    s.insert(8);  //第一次插入8，可以插入  
    s.insert(1); 
    s.insert(12); 
    s.insert(6); 
    s.insert(8);   //第二次插入8，重复元素，不会插入  
    set<int>::iterator it; //定义前向迭代器 
    //中序遍历集合中的所有元素  
    for(it=s.begin();it!=s.end();it++) 
    cout<<*it<<endl;    
    system("pause"); 
    return 0; 
} 
