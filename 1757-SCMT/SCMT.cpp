#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

int main(){

  int m;
  int n;

  while (scanf("%d %d\n", &m, &n)!=-1){

    unordered_map<char,set<char>> dict;

    string alphabet ("abcdefghijklmnopqrstuvwxyz");
    for (auto it = alphabet.begin(); it<alphabet.end(); it++)
      dict[*it].insert(*it);

    for (int idx_m = 0; idx_m < m; idx_m++){
      char p1;
      char p2;

      scanf("%c %c\n", &p1, &p2);

      for (auto element : dict[p2])
        dict[p1].insert(element);

      for (auto it = alphabet.begin(); it<alphabet.end(); it++){
        if (dict[*it].find(p1)!=dict[*it].end()){
          for (auto element : dict[p1])
            dict[*it].insert(element);
        }
      }
    }

    for (int idx_n = 0; idx_n < n; idx_n++){
      bool b = true;

      char w1[50];
      char w2[50];

      scanf("%s %s", w1, w2);

      string str1 (w1);
      string str2 (w2);
      if (str1.length()!=str2.length()){
        printf("no\n");
        continue;
      }

      auto it = str1.begin();
      auto it2 = str2.begin();
      while (b && (it<str1.end())){
        if (dict[*it].find(*it2)==dict[*it].end()){
          b = false;
          break;
        }
        it++;
        it2++;
      }

      if (b) printf("yes\n");
      else printf("no\n");
    }
  }

  return 0;
}
