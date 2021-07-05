#include <array>
#include <format>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
array<vector<string>, 4> arr;
default_random_engine g_e;
unique_ptr<uniform_int_distribution<int>> u[4];

auto split( string in, const char& split = ',' ) -> vector<string>
{
	vector<string> out;
	in += split;
	string temp;
	for (const auto& i : in)
	{
		if (i != split)
		{
			temp += i;
		}
		else
		{
			out.emplace_back(temp);
			temp = "";
		}
	}
	return out;
}

auto initial() -> void
{
	g_e.seed(time(nullptr));
	string a[4] =
	{
		"Ƥʵ,����,����,�ӳ�,����,����,���,����,Эͬ,����,����,��װ,����,��Լ,��Ӧ,����,����,����,����,ϸ��,����,���,����,����,����,֧��,�ں�,����,�ۺ�,����,�Ա�,����,�۽�,ץ��,���,��ͨ,����,����,����,��ͨ,��͸,Ǩ��,�ַ�,�ֲ�,��װ,����,Χ��,����,��͸,��չ,����,����,����,��Ȧ",
		"©��,��̨,�ջ�,��,Ŧ��,����,�̼�,��ģ,����,ά��,���,��̬,��̬,����,��ϵ,��֪,�淨,���,��֪,����,����,ս��,����,����,����,����,ģ��,����,����,ͨ��,��λ,��·,�Ե�",
		"����̬,��֪��,������,������,���ȭ,������,������,��ϸ��,���컯,ƽ̨��,�ṹ��,Ӱ����,�����,������,�����,һ����,�˵���,��ƽ��,���Ǻ�",
		"�ײ��߼�,�������,������ֵ,��������,��ֵת��,ǿ����֪,��Դ��б,�����߼�,����͸��,���ô�,��ҵģʽ,������Ӧ,���Զ���,�ؼ�·��,ȥ���Ļ�,�������,��ֱ����,�������,�������,��Ϣ����"
	};

	for (auto&& i = 0; i < 4; ++i)
	{
		arr[i] = split(a[i]);
		u[i] = std::make_unique<uniform_int_distribution<int>>(0, arr[i].size() - 1);
	}
}

auto allInsert( vector<vector<int>>& randomNum ) -> void
{
	int num[4] = {5, 7, 7, 12};
	for (auto&& i = 0; i < 4; ++i)
	{
		for (auto&& j = 0; j < num[i]; ++j)
		{
			bool flag = false;
			int k = (*u[i])(g_e);
			for (const auto& l : randomNum[i])
			{
				do
				{
					k = (*u[i])(g_e);
				}
				while (k == l);
			}
			randomNum[i].emplace_back(k);
		}
	}
}

auto main() -> int
{
	initial();
	vector<vector<int>> randomNum(4);
	allInsert(randomNum);

	cout << format(
		"{}��{}{}��{}��ҵ{}��{}��{}{}{}��ͨ��{}��{}�ﵽ{}��{}����{}����{}�򷨴��{}��{}{}��Ϊ{}Ϊ��Ʒ���ܣ�{}��Ϊ{}�����б�׼��������{}��������{}��{}����{}��{}{}{}{}��{}��{}�ﵽ{}��׼��",
		arr[3][randomNum[3][0]], arr[0][randomNum[0][0]], arr[3][randomNum[3][1]], arr[0][randomNum[0][1]],
		arr[2][randomNum[2][0]],
		arr[3][randomNum[3][2]], arr[0][randomNum[0][2]], arr[1][randomNum[1][0]], arr[3][randomNum[3][3]],
		arr[2][randomNum[2][1]], arr[2][randomNum[2][2]],
		arr[2][randomNum[2][3]],
		arr[3][randomNum[3][4]], arr[3][randomNum[3][5]], arr[1][randomNum[1][1]], arr[3][randomNum[3][6]],
		arr[3][randomNum[3][7]], arr[3][randomNum[3][8]],
		arr[1][randomNum[1][2]], arr[3][randomNum[3][9]], arr[1][randomNum[1][3]],
		arr[1][randomNum[1][4]], arr[1][randomNum[1][5]], arr[0][randomNum[0][3]], arr[3][randomNum[3][10]],
		arr[0][randomNum[0][4]], arr[1][randomNum[1][6]],
		arr[0][randomNum[0][5]], arr[3][randomNum[3][11]], arr[2][randomNum[2][4]], arr[2][randomNum[2][5]],
		arr[2][randomNum[2][6]]);

	return 0;
}
