#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> umap;

    umap.insert({"test1", 1});
    umap.emplace("test2", 2);
    umap["test1"] = 4;

    for(auto element: umap) {
        cout << element.first << "::" << element.second << "\n";
    }

    auto search = umap.find("test4");
    if (search != umap.end()) {
        cout << "found: " << search -> first << " " << (*search).second << "\n";
    } else{
        cout << "not found.." << '\n';
    }

    umap["test1"]++;
    cout << umap["test1"] << "\n";
    cout <<umap.size() <<"\n";
    umap.erase("test1");
    cout <<umap.size() <<"\n";
}