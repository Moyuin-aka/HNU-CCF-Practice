#include<iostream>
#include<iomanip> // 用于设置输出精度
#include<cmath>
using namespace std;
//用鞋带公式坐标求三角形面积，本质就是向量叉乘求四边形面积，然后/2……，S=|x1(y2-y3)+x2(y3-y1)+x3(y1-y2)|/2
double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
}
int main(){
    //用浮点数输入
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0) {
        break; // 如果输入全为0，则结束程序
    }
    double S = area(x1, y1, x2, y2, x3, y3);
    //输出保留6位小数
    cout << fixed<< setprecision(6) << S << endl;
}
    return 0;
}