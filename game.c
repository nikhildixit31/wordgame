#include <stdio.h>
#include <string.h>
#include "wordsEn.h"

int main(int argc, char **argv) {
  int dist[N];
  if(argc != 3) {
    printf("Usage: %s start_word end_word\n", argv[0]);
    return 1;
  }
  int i;
  int flag = 0;
  for(i = 0; i < N; ++i) {
    if(strcmp(argv[1], word[i]) == 0) {
      dist[i] = 0;
      flag += 2;
    } else {
      dist[i] = -1;
    }
    if(strcmp(argv[2], word[i]) == 0) {
      flag += 1;
    }
  }
  if(flag != 3) {
    if(flag <= 1) {
      printf("Illegal start_word: %s\n", argv[1]);
    }
    if(flag != 1) {
      printf("Illegal end_word: %s\n", argv[2]);
    }
    return 2;
  }
  if(strcmp(argv[1], argv[2]) == 0) {
    printf("0\n");
    return 0;
  }
  int d = 0;
  do {
    flag = 0;
    for(i = 0; i < N; ++i) {
      if(dist[i] == d) {
        int j;
        for(j = 0; j < N; ++j) {
          if(dist[j] == -1) {
            int len_i = strlen(word[i]);
            int len_j = strlen(word[j]);
            int flag2 = 0;
            int k;
            if(len_i == len_j) {
              for(k = 0; k < len_i; ++k) {
                if(word[i][k] != word[j][k]) {
                  break;
                }
              }
              if(k < len_i) {
                for(k = k+1; k < len_i; ++k) {
                  if(word[i][k] != word[j][k]) {
                    break;
                  }
                }
                flag2 = (k == len_i);
              }
            } else if(len_i == len_j-1) {
              for(k = 0; k < len_i; ++k) {
                if(word[i][k] != word[j][k]) {
                  break;
                }
              }
              if(k == len_i) {
                flag2 = 1;
              } else {
                for(; k < len_i; ++k) {
                  if(word[i][k] != word[j][k+1]) {
                    break;
                  }
                }
                flag2 = (k == len_i);
              }
            } else if(len_i == len_j+1) {
              for(k = 0; k < len_j; ++k) {
                if(word[i][k] != word[j][k]) {
                  break;
                }
              }
              if(k == len_j) {
                flag2 = 1;
              } else {
                for(; k < len_j; ++k) {
                  if(word[i][k+1] != word[j][k]) {
                    break;
                  }
                }
                flag2 = (k == len_j);
              }
            }
            if(flag2) {
              flag = 1;
              dist[j] = d + 1;
              if(strcmp(word[j], argv[2]) == 0) {
                printf("%d\n", dist[j]);
                return 0;
              }
            }
          }
        }
      }
    }
    d++;
  } while(flag);
  printf("Impossible\n");
  return 0;
}