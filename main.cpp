#include <iostream>
#include<vector>
#include<map>

using namespace std;


template <typename first, typename second>
pair<first, second> operator* (const pair<first, second>& lhs, const pair<first, second>& rhs);
template<typename T>
vector<T> operator* (const vector<T>& lhs, const vector<T>& rhs);
template<typename first, typename second>
map<first, second> operator* (const map<first, second>& lhs, const map<first, second>& rhs);

template <typename Collection>
Collection Sqr(Collection coll){
    return coll * coll;
}

template<typename first, typename second>
map<first, second> operator* (const map<first, second>& lhs, const map<first, second>& rhs){
    map<first, second> rezult;
    for(auto& element : lhs){
        rezult[element.first] = element.second * element.second;
    }
    return rezult;
}

template <typename first, typename second>
pair<first, second> operator* (const pair<first, second>& lhs, const pair<first, second>& rhs){
    pair<first, second> rezult;
    rezult.first = lhs.first * lhs.first;
    rezult.second = lhs.second * lhs.second;

    return rezult;
}

template<typename T>
vector<T> operator* (const vector<T>& lhs, const vector<T>& rhs){
    vector<T> rezult;
    for(const auto& element : lhs){
        rezult.push_back(element * element);
    }

    return rezult;
}

int main()
{
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
}
