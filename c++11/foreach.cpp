#include <iostream>
#include <vector>
#include<map>

int main()
{
    std::vector<int> v(10);

    for(auto i:v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::map<char, int> m;
    m.insert(std::pair<char, int>('a', 1));
    m.insert(std::pair<char, int>('b', 2));
    m.insert(std::pair<char, int>('c', 3));

    for(auto entry: m)
    {
        std::cout << entry.first << std::endl;
    }

    std::map<char, std::vector<int> > m2;
    m2.insert(std::pair<char, std::vector<int> >('a', v));
    m2.insert(std::pair<char, std::vector<int> >('b', v));

    for(auto entry: m2)
    {
        std::cout << entry.first << std::endl;
        for(auto item: entry.second)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
