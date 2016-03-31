#include <iostream>

using namespace std;

//定义日期类
class Date
{
public:
    void setdate(int newy,int newm,int newd);
    void printdate();
    int judgeyear();
    void plusoneday();
private:
    int year,month,day;
};

void Date::setdate(int newy,int newm,int newd)//设定日期
{
    year=newy;
    month=newm;
    day=newd;
}

inline void Date::printdate()//打印日期
{
    cout<<year<<"/"<<month<<"/"<<day<<endl;
}

int Date::judgeyear()//判断是否为闰年，若是则返回1，否则返回0
{
    if(year%100==0)
    {
        if(year%400==0)
            return 1;
        else
            return 0;
    }
    else
    {
        if(year%4==0)
            return 1;
        else
            return 0;
    }
}

void Date::plusoneday()//实现加一天操作
{
    int i;

    switch(month)
    {
    case 1://有31天的月
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:


        {
            if(day==31)
            {
                day=1;
                month++;
            }
            else
                day++;
            break;
        }
    case 12:
        {
            if(day==31)//12/31,年份加一
            {
                day=1;
                month=1;
                year++;
            }
            break;
        }
    case 2://根据是否为闰年判断2月有几天
        {
            i=judgeyear();
            if(i==1)
            {
                if(day==29)
                {
                    day=1;
                    month++;
                }
                else
                {
                    day++;
                }

            }
            else
            {
                if(day==28)
                {
                    day=1;
                    month++;
                }
                else
                {
                    day++;
                }
            }
            break;
        }
    case 4://有30天的月
    case 6:
    case 9:
    case 11:
        {
            if(day==30)
            {
                day=1;
                month++;
            }
            else
            {
                day++;
            }
            break;
        }
    }

}

int main()
{
    Date d;
    int n,i,year,month,day;
    while(1)
    {
        cout<<"输入年月日"<<endl;
        cin>>year>>month>>day;
        if(month>12||day>31)//输入有误提醒
        {
            cout<<"输入错误请重输"<<endl;
            continue;
        }
        d.setdate(year,month,day);
        cout<<"输入1输出，2加一天输出，3判断是否闰年"<<endl;
        cin>>n;
        switch(n)
        {
        case 1:
            {
                d.printdate();
                break;
            }
        case 2:
            {
                d.plusoneday();
                d.printdate();
                break;
            }
        case 3:
            {
                i=d.judgeyear();
                d.printdate();

                if(i==0)
                {
                    cout<<"不是闰年"<<endl;
                }
                else
                {
                    cout<<"是闰年"<<endl;
                }
                break;
            }
        }
        cout<<"输入1退出,2继续"<<endl;
        cin>>n;
        if(n==1)
            return 0;
        else
            continue;
    }
}
