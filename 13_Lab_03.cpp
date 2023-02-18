#include <iostream>  
#include <map>  
#include <conio.h>
#include "Time.h"
#include <algorithm> 
using  namespace  std;


typedef  map<int, Time>TMap; //определяем тип для работы со словарем  
typedef  TMap::iterator it; //итератор  

//функция для формирования словаря  
TMap make_map(int n)
{
    TMap m;//пустой словарь 
    Time a;
    for (int i = 0; i < n; i++)
    {
        cout << "?";
        cin >> a;
        //создаем пару и добавляем е е в словарь 
        m.insert(make_pair(i, a));
    }
    return m;//возвращаем словарь как результат работы функции  
}

////функция для печати словаря  
void print_map(TMap m)
{
    //cout << endl;
    for (int i = 0; i < m.size(); i++)
        cout << i << " : " << m[i] << " " << endl;
    //cout << endl;
}

//вычислен ие среднего арифметического  
Time srednee(TMap v)
{
    Time s(0, 0);
    //перебор  словаря  
    for (int i = 0; i < v.size(); i++)
        s = s + v[i];
    int n = v.size();//количество элементов в словаре  
    return s / n;
}

Time s;

struct Greater_s //больше, чем s 
{
    bool operator()(Time t)
    {
        if (t > s) return true; else return false;
    }
};

struct Comp_less // для сортировки по убыванию 
{
public:
    bool operator()(Time t1, Time t2)
    {

        if (t1 > t2)return true;
        else return false;
    }
};
struct Equal_s
{
    bool operator()(Time t)
    {
        return t == s;
    }
};

void del(Time& t)
{
    t = t + s;
}


//основная функция 
void main()
{
    int n;
    Time t;
    cout << "kolvo elementov: "; 
    cin >> n;//количество элементов  
    TMap v = make_map(n);//создать словарь 
    print_map(v);//напечатать словарь  

    
    TMap::iterator i;
    i = max_element(v.begin(), v.end());

    s = srednee(v);//нашли среднее арифметическое вектора
    cout << "sred=" << s << endl;
}