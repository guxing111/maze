
#include<stdio.h>

char a[50][50];

int n,m,time=0,min=1000,max=-1;//n�У�m�е��Թ� 

int main()

{

	while(scanf("%d%d%*c",&n,&m)!=EOF)

	{

		int i,ii,jj,j,sum=0;//ii��jjΪ��ڵ�ַ ��sumΪ�����ַ��� 

		for(i=0;i<n;i++)//�����Թ� 

	             gets(a[i]);

                for(i=0;i<n;i++) 

		    for(j=0;j<m;j++)

			if(a[i][j]=='*'){ii=i;jj=j;break;}	//�ҳ����ii��jj	

	        void sumserch (int ii,int jj,int *sum);//�������� 

		sumserch(ii,jj,&sum);

	    printf("�Թ�����%d�ֽⷨ����̾���Ϊ%d�������Ϊ%d\n",sum,min,max);

	}

}

void sumserch(int ii,int jj,int *sum)

{

	time++;   // ����·�� 

	if(a[ii][jj]=='+'||a[ii][jj]=='1'||ii>=n||ii<0||jj<0||jj>=m) //��������ʱ�����˺�·�̼�һ 

	    {time--;return;}     

	if(a[ii][jj]=='#') //�ҵ����� 

	{

	    (*sum)++;     

	   

            if(time>max)max=time;  //�Ƿ�·����� 

            if(time<min) min=time; //�Ƿ�·����С 

	    time--;    //����һ����������·�� 

	    return;

	}

	a[ii][jj]='+';   //�ѵ�ǰ����λ�ñ�Ϊ�����ߣ��Ѿ��߹� 

	sumserch(ii+1,jj,sum);  //���� 

	sumserch(ii-1,jj,sum);  //���� 

	sumserch(ii,jj+1,sum);  //���� 

	sumserch(ii,jj-1,sum);  //���� 

	a[ii][jj]='0';    //��ǰλ�����з����������ˣ����±�Ϊ���ߡ� 

	time--;     //����һ�� 

}

