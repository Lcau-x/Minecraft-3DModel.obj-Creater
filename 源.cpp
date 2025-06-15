#include <iostream>
using namespace std;
float h;//厚度
float l;//长度
int nf = 0;//方块数
void genefaceF()//输出f
{
	for (int g = 0; g < nf; g++)
	{
		int n = 8 * g;
		cout << "f " << n + 1 << "/1 " << n + 2 << "/2 " << n + 3 << "/3 " << n + 4 << "/4" << endl;
		cout << "f " << n + 1 << "/1 " << n + 4 << "/2 " << n + 8 << "/3 " << n + 5 << "/4" << endl;
		cout << "f " << n + 1 << "/1 " << n + 2 << "/2 " << n + 6 << "/3 " << n + 5 << "/4" << endl;
		cout << "f " << n + 6 << "/1 " << n + 2 << "/2 " << n + 3 << "/3 " << n + 7 << "/4" << endl;
		cout << "f " << n + 8 << "/1 " << n + 7 << "/2 " << n + 3 << "/3 " << n + 4 << "/4" << endl;
		cout << "f " << n + 5 << "/1 " << n + 6 << "/2 " << n + 7 << "/3 " << n + 8 << "/4" << endl;
	}
}
void creatcube()
{
	cout << "v -0.5 -0.5 -0.5" << endl << "v -0.5 0.5 -0.5" << endl << "v 0.5 0.5 -0.5" << endl << "v 0.5 -0.5 -0.5" << endl << "v -0.5 -0.5 0.5" << endl << "v -0.5 0.5 0.5" << endl << "v 0.5 0.5 0.5" << endl<<"v 0.5 -0.5 0.5" << endl;

	nf++;
}
class block
{
public:
	float coords0[3];
	float coords[3];
	float blockv[8][3];
	float blockf[6];

	void calcblockv()
	{
		blockv[0][0] = coords0[0];
		blockv[0][1] = coords0[1];
		blockv[0][2] = coords0[2];
		blockv[1][0] = coords0[0];
		blockv[1][1] = coords0[1] + coords[1];
		blockv[1][2] = coords0[2];
		blockv[2][0] = coords0[0] + coords[0];
		blockv[2][1] = coords0[1] + coords[1];
		blockv[2][2] = coords0[2];
		blockv[3][0] = coords0[0] + coords[0];
		blockv[3][1] = coords0[1];
		blockv[3][2] = coords0[2];
		blockv[4][0] = coords0[0];
		blockv[4][1] = coords0[1];
		blockv[4][2] = coords0[2] + coords[2];
		blockv[5][0] = coords0[0];
		blockv[5][1] = coords0[1] + coords[1];
		blockv[5][2] = coords0[2] + coords[2];
		blockv[6][0] = coords0[0] + coords[0];
		blockv[6][1] = coords0[1] + coords[1];
		blockv[6][2] = coords0[2] + coords[2];
		blockv[7][0] = coords0[0] + coords[0];
		blockv[7][1] = coords0[1];
		blockv[7][2] = coords0[2] + coords[2];
		nf++;
	}
};
class creatface
{
	public:
	int way;
	int pixel[8][8];
	block face[8][8];
	void put()
	{
		cin >> pixel[0][0] >> pixel[1][0] >> pixel[2][0] >> pixel[3][0] >> pixel[4][0] >> pixel[5][0] >> pixel[6][0] >> pixel[7][0]
			>> pixel[0][1] >> pixel[1][1] >> pixel[2][1] >> pixel[3][1] >> pixel[4][1] >> pixel[5][1] >> pixel[6][1] >> pixel[7][1]
			>> pixel[0][2] >> pixel[1][2] >> pixel[2][2] >> pixel[3][2] >> pixel[4][2] >> pixel[5][2] >> pixel[6][2] >> pixel[7][2]
			>> pixel[0][3] >> pixel[1][3] >> pixel[2][3] >> pixel[3][3] >> pixel[4][3] >> pixel[5][3] >> pixel[6][3] >> pixel[7][3]
			>> pixel[0][4] >> pixel[1][4] >> pixel[2][4] >> pixel[3][4] >> pixel[4][4] >> pixel[5][4] >> pixel[6][4] >> pixel[7][4]
			>> pixel[0][5] >> pixel[1][5] >> pixel[2][5] >> pixel[3][5] >> pixel[4][5] >> pixel[5][5] >> pixel[6][5] >> pixel[7][5]
			>> pixel[0][6] >> pixel[1][6] >> pixel[2][6] >> pixel[3][6] >> pixel[4][6] >> pixel[5][6] >> pixel[6][6] >> pixel[7][6]
			>> pixel[0][7] >> pixel[1][7] >> pixel[2][7] >> pixel[3][7] >> pixel[4][7] >> pixel[5][7] >> pixel[6][7] >> pixel[7][7];
	}
	void genefaceV()
	{
		if (way == 0)
		{
			for (int i = 0; i <= 7; i++)
			{
				for (int j = 0; j <= 7; j++)
				{
					if (pixel[i][j] == 1)
					{
						face[i][j].coords0[0] = 0.5;
						face[i][j].coords0[1] = l * (i - 4);
						face[i][j].coords0[2] = l * (j - 4);
						face[i][j].coords[0] = h;
						face[i][j].coords[1] = l;
						face[i][j].coords[2] = l;face[i][j].calcblockv();
						for (int k = 0; k <= 7; k++)
						{
							cout << "v " << face[i][j].blockv[k][1] << " " << face[i][j].blockv[k][2] << " " << face[i][j].blockv[k][0] << endl;
						}
					}
				}
			}
		}//正面
		if (way == 1)
		{
			for (int i = 0; i <= 7; i++)
			{
				for (int j = 0; j <= 7; j++)
				{
					if (pixel[i][j] == 1)
					{
						face[i][j].coords0[0] = l*(i-4);
						face[i][j].coords0[1] = -0.5-h;
						face[i][j].coords0[2] = l * (j-4);
						face[i][j].coords[0] = l;
						face[i][j].coords[1] = h;
						face[i][j].coords[2] = l;face[i][j].calcblockv();
						for (int k = 0; k <= 7; k++)
						{
							cout << "v " << face[i][j].blockv[k][1] << " " << face[i][j].blockv[k][2] << " " << face[i][j].blockv[k][0] << endl;
						}
					}
				}
			}
		}//左面
		if (way == 2)
		{
			for (int i = 0; i <= 7; i++)
			{
				for (int j = 0; j <= 7; j++)
				{
					if (pixel[i][j] == 1)
					{
						face[i][j].coords0[0] = l*(3-i);
						face[i][j].coords0[1] = 0.5;
						face[i][j].coords0[2] = l * (j - 4);
						face[i][j].coords[0] = l;
						face[i][j].coords[1] = h;
						face[i][j].coords[2] = l;face[i][j].calcblockv();
					for (int k = 0; k <= 7; k++)
					{
						cout << "v " << face[i][j].blockv[k][1] << " " << face[i][j].blockv[k][2] << " " << face[i][j].blockv[k][0] << endl;
					}


					}
				}
			}
		}//右面
		if (way == 3)
		{
			for (int i = 0; i <= 7; i++)
			{
				for (int j = 0; j <= 7; j++)
				{
					if (pixel[i][j] == 1)
					{
						face[i][j].coords0[0] = -0.5-h;
						face[i][j].coords0[1] = l * (3-i);
						face[i][j].coords0[2] = l * (j - 4);
						face[i][j].coords[0] = h;
						face[i][j].coords[1] = l;
						face[i][j].coords[2] = l;face[i][j].calcblockv();
					for (int k = 0; k <= 7; k++)
					{
						cout << "v " << face[i][j].blockv[k][1] << " " << face[i][j].blockv[k][2] << " " << face[i][j].blockv[k][0] << endl;
					}

					}
				}
			}
		}//后面
		if (way == 4)
		{
			for (int i = 0; i <= 7; i++)
			{
				for (int j = 0; j <= 7; j++)
				{
					if (pixel[i][j] == 1)
					{
						face[i][j].coords0[0] = l*(3-j);
						face[i][j].coords0[1] = l * (i - 4);
						face[i][j].coords0[2] = 0.5;
						face[i][j].coords[0] = l;
						face[i][j].coords[1] = l;
						face[i][j].coords[2] = h;face[i][j].calcblockv();
					for (int k = 0; k <= 7; k++)
					{
						cout << "v " << face[i][j].blockv[k][1] << " " << face[i][j].blockv[k][2] << " " << face[i][j].blockv[k][0] << endl;
					}

					}
				}
			}
		}//上面
		if (way == 5)
		{
			for (int i = 0; i <= 7; i++)
			{
				for (int j = 0; j <= 7; j++)
				{
					if (pixel[i][j] == 1)
					{
						face[i][j].coords0[0] = l*(4-i);
						face[i][j].coords0[1] = l * (j-4);
						face[i][j].coords0[2] = -0.5-h;
						face[i][j].coords[0] = l;
						face[i][j].coords[1] = l;
						face[i][j].coords[2] = h;face[i][j].calcblockv();
					for (int k = 0; k <= 7; k++)
					{
						cout << "v " << face[i][j].blockv[k][0] << " " << face[i][j].blockv[k][1] << " " << face[i][j].blockv[k][2] << endl;
					}
					}					
				}
			}
		}//下面	
	}
};


int main()
{
	h=0.06;
	l = (2 * h + 1) / 8;
	creatface front_;
	creatface left_;
	creatface right_;
	creatface behind_;
	creatface up_;
	creatface down_;
	front_.way = 0;
	left_.way = 1;
	right_.way = 2;
	behind_.way = 3;
	up_.way = 4;
	down_.way = 5;//创建6个面并初始化
	cout << "请输入正面" << endl;
	front_.put();
	
	cout << "请输入左面" << endl;
	left_.put();
	
	cout << "请输入右面" << endl;
	right_.put();
	cout << "请输入后面" << endl;
	behind_.put();
	cout << "请输入上面" << endl;
	up_.put();
	cout << "请输入下面" << endl;
	down_.put();
	creatcube();
	front_.genefaceV();
	left_.genefaceV();
	right_.genefaceV();
	behind_.genefaceV();
	up_.genefaceV();
	down_.genefaceV();
	cout << "vt 0 0" << endl << "vt 0 1" << endl << "vt 1 1" << endl << "vt 1 0" << endl;
	genefaceF();



	system("pause");
	return 0;
}