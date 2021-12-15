#include <array>
#include <format>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
array<vector<string>, 4> arr;
default_random_engine g_e;
unique_ptr<uniform_int_distribution<int>> u[4];

auto split(string in, const char &split = ',') -> vector<string> 
{
    vector<string> out;
    in += split;
    string temp;
    for (const auto &i : in) 
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
                    "皮实,复盘,赋能,加持,沉淀,倒逼,落地,串联,协同,反哺,兼容,包装,重组,履约,响应,量化,发力,布局,联动,细分,梳理,输出,加速,共建,共创,支撑,融合,解耦,聚合,集成,对标,对齐,聚焦,抓手,拆解,拉通,抽象,摸索,提炼,打通,吃透,迁移,分发,分层,封装,辐射,围绕,复用,渗透,扩展,开拓,给到,死磕,破圈",
                    "漏斗,中台,闭环,打法,纽带,矩阵,刺激,规模,场景,维度,格局,形态,生态,话术,体系,认知,玩法,体感,感知,调性,心智,战役,合力,赛道,基因,因子,模型,载体,横向,通道,补位,链路,试点",
                    "新生态,感知度,颗粒度,方法论,组合拳,引爆点,点线面,精细化,差异化,平台化,结构化,影响力,耦合性,易用性,便捷性,一致性,端到端,短平快,护城河",
                    "底层逻辑,顶层设计,交付价值,生命周期,价值转化,强化认知,资源倾斜,完善逻辑,抽离透传,复用打法,商业模式,快速响应,定性定量,关键路径,去中心化,结果导向,垂直领域,归因分析,体验度量,信息屏障"
            };

    for (auto &&i = 0; i < 4; ++i) 
    {
        arr[i] = split(a[i]);
        u[i] = std::make_unique<uniform_int_distribution<int>>(0, arr[i].size() - 1);
    }
}

auto allInsert(vector<vector<int>> &randomNum) -> void 
{
    int num[4] = {5, 7, 7, 12};
    for (auto &&i = 0; i < 4; ++i) 
    {
        for (auto &&j = 0; j < num[i]; ++j) 
        {
            bool flag = false;
            int k = (*u[i])(g_e);
            for (const auto &l : randomNum[i]) 
            {
                do {
                    k = (*u[i])(g_e);
                } while (k == l);
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
            "{}是{}{}，{}行业{}。{}是{}{}{}，通过{}和{}达到{}。{}是在{}采用{}打法达成{}。{}{}作为{}为产品赋能，{}作为{}的评判标准。亮点是{}，优势是{}。{}整个{}，{}{}{}{}。{}是{}达到{}标准。",
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
