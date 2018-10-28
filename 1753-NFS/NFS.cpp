#include <cstdio>

using namespace std;

int main(){

  double eps = 1e-06;

  int n,t;
  int ret = scanf("%d %d", &n, &t);

  while (ret!=-1){

    int d_i[n];
    int s_i[n];

    int min_s = 0;

    for (int k=0; k<n; k++){
      int d, s;
      scanf("%d %d", &d, &s);

      if (!k){
        min_s = s;
      }else{
        if (s<min_s){
          min_s = s;
        }
      }

      d_i[k] = d;
      s_i[k] = s;
    }

    double max_c = 1e09;
    double min_c = - min_s+1e-09;
    double c = 0;
    double t_approx = 0;

    while (max_c-min_c >= eps){
      c = min_c + (max_c-min_c)/2;
      t_approx = 0;

      for (int k=0; k<n; k++){
        t_approx += d_i[k]/(s_i[k]+c);
      }

      if (t_approx < t){
        max_c = c-1e-09;
      }else{
        min_c = c+1e-09;
      }
    }

    printf("%.7f\n", min_c);

    ret = scanf("%d %d", &n, &t);

  }
  return 0;
}
