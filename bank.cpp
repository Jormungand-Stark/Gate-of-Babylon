#include <iostream>
using namespace std;

int Allocation[11][101];//�����ѻ����Դ
int Max[11][101];//�������������Դ
int Available[11];//�ɷ�����Դ
int Need[11][101];//����������Դ
int Requesti[11];//��Դ����
int Work[11];//��������
int link[11];//��ȫ����
int x,y;//x���������y����Դ����

void init();//��ʼ��
void printSystemVariable();//�����Դ������
bool chesksafe();//��ȫ���㷨

int main(int argc, char const *argv[]) {
  init();
  printSystemVariable();
  if(!chesksafe()){
    return 0;
  }

  string an;//�洢�Ƿ����������û�ָ��
  bool flag = false;//������������ѭ���ı�־
  while(1){
    cout << "�Ƿ�������䣿��'y'or'Y'���ǣ�'n'or'N'��� " ;
    cin>>an;
    if(an[0]!='Y'&&an[0]!='y'){
        break;
    }
    int num;
    cout << "������������Դ�Ľ��̺ţ��磺P1������1���� " << endl;
    cin >> num;
    num -= 1;//���̴�1��ʼ���������������±��0��ʼ����
    cout << "��������������Դ��" << endl;
    for (int i = 0; i < y; i++) {
      cin >> Requesti[i];
    }
    for (int i = 0; i < y; i++) {
      if(Requesti[i]>Need[num][i]){
        cout << "����Ҫ����Դ���ѳ������������ֵMax" << endl;
        flag = true;
        break;
      }
      if(Requesti[i]>Available[i]){
        cout << "�����㹻��Դ" << endl;
        flag = true;
        break;
      }

      Available[i]-=Requesti[i];
      Allocation[num][i]+=Requesti[i];
      Need[num][i]-=Requesti[i];
    }

    if (flag){//��������Դ�����������ʱ����������ѭ��
      flag = false;//���±�־
      continue;//ִ����һ��ѭ��
    }

    int temp = 0;//����Maxֵ��Allocationֵ�ĸ���
    if(chesksafe()){//��ȫ,��ɱ��η���
      for (int i = 0; i < y; i++) {
        if(Allocation[num][i]>=Max[num][i]){
          temp++;
        }
      }
      if (temp == y) {/*���1�����̷�����Դ��ÿ����Դ�ѻ��ֵ�����ڵ�����
                        �����ֵ�����Available��Allocation��Need����*/
        for (int i = 0; i < y; i++) {
          Available[i]+=Allocation[num][i];//�ɷ�����Դ��øý����ѻ�õ���Դ��
          Allocation[num][i]=0;//��ոý����ѻ�õ���Դ��
          Need[num][i]=0;//��ոý�������ĸ�����Դ��
        }
      }
      cout << "����ɹ�" << endl;
      printSystemVariable();
    }else{//����ȫ,����֮ǰ�Ĳ���
      cout << "����ʧ��,�������β���" << endl;
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

void init(){//��ʼ��
  cout << "��������̸���:" << endl;
  cin >> x;
  cout << "��������Դ���ж�����:" << endl;
  cin >> y;
  cout << "������ÿ����������Ҫ�ĸ�����Դ�������Ŀ:" << endl;
  for (int i = 0; i < x; i++) {
    cout << "P" << i+1 << ":" ;
    for (int j = 0; j < y; j++) {
      cin >> Max[i][j];
    }
  }
  cout << "������ÿ�������ѷ������Դ������" << endl;
  for(int i=0; i<x; i++){
    cout << "P" << i+1 << ":" ;
    for(int j=0; j<y; j++){
      cin >> Allocation[i][j];
      if(Allocation[i][j]>Max[i][j]){
        cout << "�ѷ�����Դ�������ڽ����������Դ�����Ŀ������������" << endl;
        i--;
      }
    }
  }
  cout << "������ϵͳ�ɷ������Դ��:" << endl;
  for (int i = 0; i < y; i++) {
    cin >> Available[i];
  }

  for (int i = 0; i < x; i++) {//����ÿһ����������ĸ�����Դ����Need����
    for (int j = 0; j < y; j++) {
      Need[i][j] = Max[i][j] - Allocation[i][j];
    }
  }
}

void printSystemVariable(){//�����Դ������
  cout << "��ʱ��Դ���������£�" << endl;
  cout << "����  " << "   Max   " << "   Alloction " << "    Need  " << "    Available " << endl;
  for(int i=0;i<x;i++){//��i������
    cout << "P" << i+1 << "     " ;
    for(int j=0;j<y;j++){//��i�����̵�Max������Ϣ
      cout << Max[i][j] << "    " ;
    }
    cout << "|  " ;
    for(int j=0;j<y;j++){//��i�����̵�Allocation������Ϣ
      cout << Allocation[i][j] << "    " ;
    }
    cout << "|  " ;
    for(int j=0;j<y;j++){//��i�����̵�Need������Ϣ
      cout << Need[i][j] << "    " ;
    }
    cout << "|  " ;
    if(i==0){
      for(int j=0;j<y;j++){//��i�����̵�Available������Ϣ
        cout << Available[j] << "    " ;
      }
    }
    cout << endl ;
  }
}

bool chesksafe(){//��ȫ���㷨
  for (int i = 0; i < y; i++) {
    Work[i] = Available[i];
  }
  bool Finish[7];//��������
  int mark = x;//����ı�x��ֵ����ı���
  int temp = 0;//����������Դ����ʣ����Դ��һ��������Դ��
  int flag = 0;//������Դ����Ĵ���
  while (mark--) {//��ȫ���еĲ��������н�������
    for(int i=0;i<x;++i){//�ж���i������
      if(Finish[i]==true){
        continue;
      }
      for (int j = 0; j < y; j++) {
        if(Need[i][j]<=Work[j]){//����ý���������Դ����ʣ����Դ����Դ��
          temp++;
        }
      }
      if(temp==y){//ȫ����Դ������������Դ����ʣ����Դ
        for (int j = 0; j < y; j++) {//��÷��������Դ����Դ��
          Work[j]+=Allocation[i][j];
        }
        Finish[i]=true;
        flag++;//����һ����Դ����
        link[flag]=i+1;//��������Դ����Ľ������η������
      }
      temp=0;//�������������Դ��������Դ��
    }
  }
  if(flag==x){//���û�н��н���������Դ���䣬˵�����ǰ�ȫ����
    cout << "ϵͳ���ڰ�ȫ״̬����ȫ����Ϊ��" << endl;
    for (int i = 1; i <= x; i++) {
      cout << "P" << link[i] << " " ;
    }
    cout << endl;
    return true;
  }
  else{
    cout << "ϵͳ���ڲ���ȫ״̬" << endl;
    return false;
  }
}
