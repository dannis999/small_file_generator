#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genfile(const char *fn)
{
	FILE *f;
	f=fopen(fn,"w");
	if (!f)
	{
		puts("打开文件失败");
		system("pause");
		return;
	}
	fprintf(f," ");
	fclose(f);
}

int main()
{
	char s[200],cmd[200];
	int n;
	puts("请输入盘符：");
	gets(s);
	puts("请输入文件个数：");
	scanf("%d",&n);
	puts("正在创建目录");
	srand(time(0));
	sprintf(s,"%c:\\%d",s[0],rand());
	sprintf(cmd,"md %s",s);
	system(cmd);
	puts("正在生成文件");
	for (int i=1;i<=n;i++)
	{
		sprintf(cmd,"%s\\%d",s,i);
		genfile(cmd);
		if (i%10000==0) printf("已生成%d个\n",i);
	}
	puts("正在删除文件");
	sprintf(cmd,"rd /s /q %s",s);
	system(cmd);
	puts("清理成功");
	system("pause");
	return 0;
}
