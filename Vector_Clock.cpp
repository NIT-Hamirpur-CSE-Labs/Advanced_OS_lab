#include<bits/stdc++.h>

using namespace std;

int max1(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int main() {
  int i, j, k, p1[20], p2[20], e1, e2, dep[20][20];

  printf("enter the events : ");
  scanf("%d %d", & e1, & e2);

  int vector1[e1][2], vector2[e2][2];

  for (i = 0; i < e1; i++) {
    vector1[i][0] = i + 1;
    vector1[i][1] = 0;
  }
  for (i = 0; i < e2; i++) {
    vector2[i][1] = i + 1;
    vector2[i][0] = 0;
  }

  printf("enter the dependency matrix:\n");
  printf("\t enter 1 if e1->e2 \n\t enter -1, if e2->e1 \n\t else enter 0 \n\n");
  for (i = 0; i < e2; i++)
    printf("\te2%d", i + 1);

  for (i = 0; i < e1; i++) {
    printf("\n e1%d \t", i + 1);
    for (j = 0; j < e2; j++)
      scanf("%d", & dep[i][j]);
  }

  for (i = 0; i < e1; i++) {
    for (j = 0; j < e2; j++) {
      if (dep[i][j] == 1) {
        vector2[j][0] = vector1[i][0];
        for (k = j; k < e2; k++)
          vector2[k + 1][0] = vector2[j][0];
      }
      if (dep[i][j] == -1) {
        vector1[i][1] = vector2[j][1];
        for (k = i; k < e1; k++)
          vector1[k + 1][1] = vector1[i][1];
      }
    }
  }
  printf("\nProcess 1 : ");
  for (i = 0; i < e1; i++)
    printf("%d %d --> ", vector1[i][0], vector1[i][1]);
  printf("\nProcess 2 : ");
  for (j = 0; j < e2; j++)
    printf("%d %d --> ", vector2[j][0], vector2[j][1]);
  cout << endl;
  return 0;
}
