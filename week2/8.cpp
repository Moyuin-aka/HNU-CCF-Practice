#include <iostream>
#include <vector>
// 数圈问题，开二维数组，有一个方向变量插入值
using namespace std;
// 走 1 步，右转，走 1 步，右转，走 2 步，右转，走 2 步，右转，走 3 步，右转，走 3 步，右转，走 3 步，右转
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    int x = n % 2 == 0 ? n / 2 - 1 : n / 2, y = n % 2 == 0 ? n / 2 - 1 : n / 2;
    int num = 1;
    // 我们每次都是走两步右转
    // 方向数组：0-右, 1-下, 2-左, 3-上,这样凭借着索引就可以一次性规定方向
    int dx[] = {0, 1, 0, -1}; // 右，下，左，上
    int dy[] = {1, 0, -1, 0}; // 右，下，左，上
    int dir = 0;              // 初始方向为右,但是为了进入下一步，我们先暂定方向为上，这样右转就是第一步直接右转
    int step = 1;             // 当前步数
    int turn_count = 0;
    arr[x][y] = num++; // 右转计数,每到2就增加一次总步数
    while (num <= n * n)
    {
        for(int i=0;i<step;i++)
        {
            // 走一步
            x += dx[dir];
            y += dy[dir];
            if (x < 0 || x >= n || y < 0 || y >= n || arr[x][y] != 0) // 理论上不会越界
            {
                // 如果越界或者已经填充，回退
                x -= dx[dir];
                y -= dy[dir];
                break;
            }
            arr[x][y] = num++;
            if (num > n * n) break;
        }
        if (num > n * n) break;
        dir= (dir + 1) % 4; // 右转
        turn_count++;
        if(turn_count==2) {
            step++;
            turn_count = 0;
        }
    }
    for (const auto &row : arr)
    {
        for (const auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
起点 (arr[x][y] = num++;)
你站在地板的中心，放下数字1。游戏正式开始。

进入主循环 (while)
你准备开始走路了，拿起了指令卡 step（现在上面写着1）。

走一小段路 (for 循环)

for(int i=0; i<step; i++) 这段代码的意思就是：“严格按照指令卡 step 上写的步数，一步一步地走”。

你现在面朝东(dir=0)，指令卡上写着走1步。于是你向东走了一步，在脚下写上数字2。

for循环结束，因为你已经走完了指令卡上要求的1步。

走完一段路，必须转弯 (dir = (dir + 1) % 4;)

你走完了指令要求的一段路，规则要求你必须立刻向右转90度。

你本来朝东(0)，右转后现在朝南(1)了。

向计数器报告 (turn_count++)

你对你的小本本（turn_count）说：“我转了一次弯。” 现在 turn_count 变成了 1。

决定下次要走多远 (if(turn_count==2))

你检查小本本，发现turn_count是1，不等于2。所以什么也不做。

你再次进入主循环的下一次迭代。

再次执行第3步（走一小段路）

你现在朝南(dir=1)，指令卡step上写的仍然是走1步。于是你向南走了一步，在脚下写上数字3。

for循环结束。

再次执行第4步（转弯）

你再次右转，从朝南(1)变成朝西(2)。

再次执行第5步（报告）

你对小本本说：“我又转了一次弯。” 现在turn_count变成了2。

再次执行第6步（做决定！）

你检查小本本，发现turn_count等于2了！

if(turn_count==2) 条件成立！这是一个关键时刻。

这意味着你已经走了“向东1步”和“向南1步”，完成了螺旋的一个“拐角”。

规则告诉你：“每完成两个拐角，下次走路的距离就该变长了！”

于是你拿出指令卡 step，把上面的数字1擦掉，写上2 (step++)。

同时，你把小本本上的turn_count擦掉，重置为0，准备开始新一轮的两次转向计数。

循环往复

接下来，你会朝西走2步（4, 5），然后转弯，turn_count变1。

再朝北走2步（6, 7），然后转弯，turn_count变2。

turn_count又等于2了！于是你再次更新指令卡，把step从2改成3。


*/

// 下面的方法填外旋可以，就是1开头的，但是不能写此题内旋（1在中心）的情况，会有覆盖冲突
/*int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    int x = n/2, y = n/2; // 起始位置
    int dx = 0, dy = 1; // 初始方向向右
    int num = 1; // 当前填充的数字
    int total = n * n; // 总数
    while(num<=total){
        arr[x][y]=num;
        num++;
        // 检查下一个位置是否越界或已填充
        int next_x = x + dx;
        int next_y = y + dy;
        if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || arr[next_x][next_y] != 0){
            // 改变方向
            if(dx == 0 && dy == 1){ // 向右
                dx = 1; dy = 0; // 改为向下
            } else if(dx == 1 && dy == 0){ // 向下
                dx = 0; dy = -1; // 改为向左
            } else if(dx == 0 && dy == -1){ // 向左
                dx = -1; dy = 0; // 改为向上
            } else if(dx == -1 && dy == 0){ // 向上
                dx = 0; dy = 1; // 改为向右
            }
        x += dx;
        y += dy;
        } else {
            x = next_x;
            y = next_y;
        }
    }
    for(const auto& row : arr){
        for(const auto& val : row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;

}*/