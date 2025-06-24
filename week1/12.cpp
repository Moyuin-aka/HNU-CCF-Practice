#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// 其实不用写类函数，但写类函数可以mem.erase(id)这种写法，就看起来很正规
class manager
{
private:
    struct block
    {
        int start;
        int size; // 内存块的起点位置和大小
    };
    int memory_size;                  // 内存总大小
    vector<int> memory;               // 内存状态,内存条，数值为块的所属id，空则为0
    unordered_map<int, block> blocks; // 内存块的映射，id->block
    int next_id;                      // 下一个内存块的id
public:
    manager(int size) : memory_size(size), next_id(1)
    {
        memory.resize(size, 0); // 初始化内存状态为0
    }
    void alloc(int n)
    {
        int start = -1; // 分配的起始位置
        for (int i = 0; i <= memory_size - n; i++)
        {
            bool isfree = true; // 是否找到连续的空闲内存块
            for (int j = 0; j < n; j++)
            {
                // 从每个起点开始找后面有没有连续n个空闲内存块，如果有就赋值了
                if (memory[i + j] != 0)
                {
                    isfree = false; // 如果有一个不为空，则不是连续空闲内存块
                    i = i + j;      // 跳过已经检查过的部分
                    break;
                }
            }
            if (isfree)
            {
                start = i;
                break; // 找到连续的空闲内存块，记录起始位置
            }
        }
        if (start != -1)
        {
            for (int i = start; i < start + n; i++)
            {
                memory[i] = next_id; // 分配内存块
            }
            blocks[next_id] = {start, n}; // 记录内存块信息
            next_id++;                    // 更新下一个内存块的id
            cout << next_id - 1 << endl;
        }
        else
            cout << "NULL" << endl;
    }
    void erase(int id)
    {
        if (blocks.find(id) == blocks.end())
        {
            cout << "ILLEGAL_ERASE_ARGUMENT" << endl; // 如果没有找到该内存块，输出NULL
            return;
        }
        for (int i = blocks[id].start; i < blocks[id].start + blocks[id].size; i++)
        {
            memory[i] = 0; // 将内存块对应的内存位置置为0
        }
        blocks.erase(id); // 删除内存块信息
    }
    void defragment()
    {
        // 就直接在原来的内存块清空改了，节约空间
        // 为了保证1-n的新内存块顺序，填充的时候要不要先排个序呢
        vector<pair<int, int>> sorted_blocks;
        for (const auto &pair : blocks)
        {
            int id = pair.first;
            int start_pos = pair.second.start;
            sorted_blocks.push_back({start_pos, id});
        }
        sort(sorted_blocks.begin(), sorted_blocks.end());
        //这个排序是必要的，无序哈希表虽然查找是O(1)，但遍历时顺序不定，可能会导致内存块填充不连续
        fill(memory.begin(), memory.end(), 0); // 清空内存
        int current_position = 0;              // 当前填充位置
        for (const auto &pair : sorted_blocks)
        {
            int id = pair.second;
            block &b = blocks[id];      // 获取内存块信息
            b.start = current_position; // 更新内存块的起始位置
            current_position += b.size; // 更新当前填充位置
        }
        for (const auto &pair : blocks)
        {
            int id = pair.first;
            const block &b = pair.second; // 获取内存块信息
            for (int i = 0; i < b.size; i++)
            {
                memory[b.start+ i] = id; // 填充内存块
            }
        }
    }
};
int main()
{
    int t, m;
    cin >> t >> m;
    manager mem(m);
    while (t--)
    {
        string command;
        cin >> command;
        if (command == "alloc")
        {
            int n;
            cin >> n;
            mem.alloc(n);
        }
        else if (command == "erase")
        {
            int id;
            cin >> id;
            mem.erase(id);
        }
        else if (command == "defragment")
        {
            mem.defragment();
        }
    }
    return 0;
}