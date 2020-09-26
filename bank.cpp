#include <iostream>
using namespace std;

int Allocation[11][101];//进程已获得资源
int Max[11][101];//进程所需最大资源
int Available[11];//可分配资源
int Need[11][101];//进程所需资源
int Requesti[11];//资源请求
int Work[11];//工作向量
int link[11];//安全序列
int x,y;//x表进程数，y表资源种类

void init();//初始化
void printSystemVariable();//输出资源分配量
bool chesksafe();//安全性算法

int main(int argc, char const *argv[]) {
  init();
  printSystemVariable();
  if(!chesksafe()){
    return 0;
  }

  string an;//存储是否请求分配的用户指令
  bool flag = false;//用于跳出两层循环的标志
  while(1){
    cout << "是否请求分配？（'y'or'Y'表是，'n'or'N'表否） " ;
    cin>>an;
    if(an[0]!='Y'&&an[0]!='y'){
        break;
    }
    int num;
    cout << "请输入请求资源的进程号（如：P1则输入1）： " << endl;
    cin >> num;
    num -= 1;//进程从1开始计数但各个数组下标从0开始计数
    cout << "输入进程请求的资源数" << endl;
    for (int i = 0; i < y; i++) {
      cin >> Requesti[i];
    }
    for (int i = 0; i < y; i++) {
      if(Requesti[i]>Need[num][i]){
        cout << "所需要的资源数已超过所宣布最大值Max" << endl;
        flag = true;
        break;
      }
      if(Requesti[i]>Available[i]){
        cout << "尚无足够资源" << endl;
        flag = true;
        break;
      }

      Available[i]-=Requesti[i];
      Allocation[num][i]+=Requesti[i];
      Need[num][i]-=Requesti[i];
    }

    if (flag){//当任意资源请求出现问题时，跳出两层循环
      flag = false;//更新标志
      continue;//执行下一次循环
    }

    int temp = 0;//满足Max值的Allocation值的个数
    if(chesksafe()){//安全,完成本次分配
      for (int i = 0; i < y; i++) {
        if(Allocation[num][i]>=Max[num][i]){
          temp++;
        }
      }
      if (temp == y) {/*如果1个进程分配资源后，每个资源已获得值都大于等于所
                        需最大值则更新Available、Allocation和Need矩阵*/
        for (int i = 0; i < y; i++) {
          Available[i]+=Allocation[num][i];//可分配资源获得该进程已获得的资源数
          Allocation[num][i]=0;//清空该进程已获得的资源数
          Need[num][i]=0;//清空该进程尚需的各类资源数
        }
      }
      cout << "分配成功" << endl;
      printSystemVariable();
    }else{//不安全,撤销之前的操作
      cout << "分配失败,撤销本次操作" << endl;
      for (int i = 0; i < y; i++) {
        Available[i]+=Requesti[i];
        Need[num][i]+=Requesti[i];
        Allocation[num][i]-=Requesti[i];
      }
      printSystemVariable();
    }

  }

  return 0;
}

void init(){//初始化
  cout << "请输入进程个数:" << endl;
  cin >> x;
  cout << "请输入资源共有多少类:" << endl;
  cin >> y;
  cout << "请输入每个进程所需要的各种资源的最大数目:" << endl;
  for (int i = 0; i < x; i++) {
    cout << "P" << i+1 << ":" ;
    for (int j = 0; j < y; j++) {
      cin >> Max[i][j];
    }
  }
  cout << "请输入每个进程已分配的资源数量：" << endl;
  for(int i=0; i<x; i++){
    cout << "P" << i+1 << ":" ;
    for(int j=0; j<y; j++){
      cin >> Allocation[i][j];
      if(Allocation[i][j]>Max[i][j]){
        cout << "已分配资源数量大于进程所需的资源最大数目，请重新输入" << endl;
        i--;
      }
    }
  }
  cout << "请输入系统可分配的资源数:" << endl;
  for (int i = 0; i < y; i++) {
    cin >> Available[i];
  }

  for (int i = 0; i < x; i++) {//计算每一个进程尚需的各类资源数，Need矩阵
    for (int j = 0; j < y; j++) {
      Need[i][j] = Max[i][j] - Allocation[i][j];
    }
  }
}

void printSystemVariable(){//输出资源分配量
  cout << "此时资源分配量如下：" << endl;
  cout << "进程  " << "   Max   " << "   Alloction " << "    Need  " << "    Available " << endl;
  for(int i=0;i<x;i++){//第i个进程
    cout << "P" << i+1 << "     " ;
    for(int j=0;j<y;j++){//第i个进程的Max矩阵信息
      cout << Max[i][j] << "    " ;
    }
    cout << "|  " ;
    for(int j=0;j<y;j++){//第i个进程的Allocation矩阵信息
      cout << Allocation[i][j] << "    " ;
    }
    cout << "|  " ;
    for(int j=0;j<y;j++){//第i个进程的Need矩阵信息
      cout << Need[i][j] << "    " ;
    }
    cout << "|  " ;
    if(i==0){
      for(int j=0;j<y;j++){//第i个进程的Available矩阵信息
        cout << Available[j] << "    " ;
      }
    }
    cout << endl ;
  }
}

bool chesksafe(){//安全性算法
  for (int i = 0; i < y; i++) {
    Work[i] = Available[i];
  }
  bool Finish[7];//工作向量
  int mark = x;//避免改变x的值所设的变量
  int temp = 0;//满足需求资源少于剩余资源这一条件的资源数
  int flag = 0;//进行资源分配的次数
  while (mark--) {//求安全序列的操作最多进行进程数次
    for(int i=0;i<x;++i){//判定第i个进程
      if(Finish[i]==true){
        continue;
      }
      for (int j = 0; j < y; j++) {
        if(Need[i][j]<=Work[j]){//计算该进程需求资源少于剩余资源的资源数
          temp++;
        }
      }
      if(temp==y){//全部资源都满足需求资源少于剩余资源
        for (int j = 0; j < y; j++) {//获得分配给该资源的资源数
          Work[j]+=Allocation[i][j];
        }
        Finish[i]=true;
        flag++;//进行一次资源分配
        link[flag]=i+1;//将进行资源分配的进程依次放入队列
      }
      temp=0;//更新满足分配资源条件的资源数
    }
  }
  if(flag==x){//如果没有进行进程数次资源分配，说明不是安全序列
    cout << "系统处于安全状态，安全序列为：" << endl;
    for (int i = 1; i <= x; i++) {
      cout << "P" << link[i] << " " ;
    }
    cout << endl;
    return true;
  }
  else{
    cout << "系统处于不安全状态" << endl;
    return false;
  }
}
