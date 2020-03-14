
#include<stdio.h>

char a[50][50];

int n,m,time=0,min=1000,max=-1;//n行，m列的迷宫 

int main()

{

	while(scanf("%d%d%*c",&n,&m)!=EOF)

	{

		int i,ii,jj,j,sum=0;//ii，jj为入口地址 ，sum为多少种方法 

		for(i=0;i<n;i++)//给出迷宫 

	             gets(a[i]);

                for(i=0;i<n;i++) 

		    for(j=0;j<m;j++)

			if(a[i][j]=='*'){ii=i;jj=j;break;}	//找出入口ii，jj	

	        void sumserch (int ii,int jj,int *sum);//函数申明 

		sumserch(ii,jj,&sum);

	    printf("迷宫共有%d种解法，最短距离为%d，最长距离为%d\n",sum,min,max);

	}

}

void sumserch(int ii,int jj,int *sum)

{

	time++;   // 经过路程 

	if(a[ii][jj]=='+'||a[ii][jj]=='1'||ii>=n||ii<0||jj<0||jj>=m) //当不可走时，就退后，路程减一 

	    {time--;return;}     

	if(a[ii][jj]=='#') //找到出口 

	{

	    (*sum)++;     

	   

            if(time>max)max=time;  //是否路程最大 

            if(time<min) min=time; //是否路程最小 

	    time--;    //回退一步，找其他路线 

	    return;

	}

	a[ii][jj]='+';   //把当前所处位置变为不可走，已经走过 

	sumserch(ii+1,jj,sum);  //向上 

	sumserch(ii-1,jj,sum);  //向下 

	sumserch(ii,jj+1,sum);  //向右 

	sumserch(ii,jj-1,sum);  //向左 

	a[ii][jj]='0';    //当前位置所有方向都搜索过了，重新变为可走。 

	time--;     //回退一步 

}

