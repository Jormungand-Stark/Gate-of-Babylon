#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
using namespace std;
typedef struct bg {
    char str[10000];
} BigInt;
int mp[200];
// name : a~z, 表示大整数的名称
void ReisterBigInt(char *bigIntString, char name, BigInt *pBigInt[]) {
    int i = name - 'a';
    pBigInt[i] = new BigInt;
    strcpy(pBigInt[i]->str, bigIntString);
    // transform bigIntString into the big int pBigInt[i];
    return;
}
char an[10000];
char ans[10000];
void strr(char *str) {
    if (!str || !*str) {
        return;
    }
    int len = strlen(str) - 1;
    int p1 = 0, p2 = len;
    while (p1 < p2) {
        char tmp = str[p1];
        str[p1] = str[p2];
        str[p2] = tmp;
        p1++;
        p2--;
    }
}
char *num_plus(char *a, char *b) {
    memset(ans, 0, sizeof ans);
    int len_a = strlen(a);
    int len_b = strlen(b);
    strr(a);
    strr(b);
    int yu = 0;
    for (int i = 0;; i++) {
        if (i < len_a && i < len_b) {
            ans[i] = (yu + a[i] - '0' + b[i] - '0') % 10 + '0';
            yu = (yu + a[i] - '0' + b[i] - '0') / 10;
        } else if (i < len_a) {
            ans[i] = (yu + a[i] - '0') % 10 + '0';
            yu = (yu + a[i] - '0') / 10;
        } else if (i < len_b) {
            ans[i] = (yu + b[i] - '0') % 10 + '0';
            yu = (yu + b[i] - '0') / 10;
        } else if (yu != 0) {
            ans[i] = yu % 10 + '0';
            yu = yu / 10;
        } else
            break;
    }
    strr(ans);
    strr(a);
    strr(b);
    strcpy(an, ans);
    return an;
}
int judge(char *a, char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    if (len_a > len_b)
        return 1;
    if (len_a < len_b)
        return -1;
    return strcmp(a, b);
}
char *num_sub(char *a, char *b) {
    char aa[10000], bb[10000];
    memset(aa, 0, sizeof aa);
    memset(bb, 0, sizeof bb);
    memset(ans, 0, sizeof ans);
    char *as = ans;
    int cnt = judge(a, b);
    bool bo = false;
    if (cnt > 0) {
        strcpy(aa, a);
        strcpy(bb, b);
        bo = false;
    } else if (cnt < 0) {
        strcpy(aa, b);
        strcpy(bb, a);
        bo = true;
    } else {
        ans[0] = '0';
        return as;
    }
    int len_a = strlen(aa);
    int len_b = strlen(bb);
    strr(aa);
    strr(bb);
    int i;
    for (i = 0;; i++) {
        if (i < len_a && i < len_b) {
            if (aa[i] >= bb[i]) {
                ans[i] = aa[i] - bb[i] + '0';
            } else {
                ans[i] = aa[i] - bb[i] + 10 + '0';
                for (int j = i + 1;; j++) {
                    if (aa[j] == '0')
                        aa[j] = '9';
                    else {
                        aa[j]--;
                        break;
                    }
                }
            }
        } else if (i < len_a) {
            ans[i] = aa[i];
        } else if (i < len_b) {
            ans[i] = bb[i];
        } else
            break;
    }
    while (i--) {
        ans[i + 1] = '\0';
        if (ans[i] - '0' > 0) {
            break;
        }
    }
    if (bo)
        ans[i + 1] = '-';
    strr(ans);
    strcpy(an, as);
    return an;
}
int ans3[10000];
char num[10000];
char *num_mul(char *a, char *b) {
    memset(ans3, 0, sizeof ans3);
    memset(num, 0, sizeof num);
    char *as = num;
    int nu = 0;
    int lena = strlen(a);
    int len_b = strlen(b);
    strr(a);
    strr(b);
    for (int i = 0; i < lena; i++) {
        for (int j = 0; j < len_b; j++) {
            ans3[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }
    int i;
    int yu = 0;
    int len = lena + len_b - 1;
    for (i = 0;; i++) {
        if (i < len || yu != 0) {
            yu = ans3[i] + yu;
            ans3[i] = yu % 10;
            yu = yu / 10;
        } else
            break;
    }
    while (i--) {
        num[nu++] = ans3[i] + '0';
    }
    return num;
}
char ans2[10000];
char *num_div(char *a, char *b) {
    memset(ans2, 0, sizeof ans2);
    int nu = 0;
    int lena = strlen(a);
    int len_b = strlen(b);
    for (int i = len_b; i < lena; i++) {
        b[i] = '0';
    }
    while (lena-- >= len_b) {
        int i = 0;
        while (judge(a, b) >= 0) {
            i++;
            strcpy(a, num_sub(a, b));
        }
        ans2[nu++] = i + '0';
        b[lena] = '\0';
    }
    if (ans2[0] == '\0') {
        ans2[0] = '0';
        return ans2;
    }
    if (ans2[0] == '0')
        return ans2 + 1;
    strcpy(an, ans2);
    return an;
}
char *final[1000];
char *solveBigInt(char *bigstring, BigInt *pBigInt[]) {
    int len = strlen(bigstring);
    char s1[10000];
    char s2[10000];
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < len; ++i) {
        if (bigstring[i] >= 'a' && bigstring[i] <= 'z') {
            s1[cnt1++] = bigstring[i];
        } else {
            if (bigstring[i] == '(') {
                s2[cnt2++] = '(';
                continue;
            }
            if (bigstring[i] == ')') {
                for (int j = cnt2 - 1; s2[j] != '('; --j) {
                    s1[cnt1++] = s2[j];
                    cnt2 = j;
                }
                cnt2--;
                continue;
            }
            for (int j = cnt2 - 1; j >= 0; --j) {
                if (mp[s2[j]] >= mp[bigstring[i]]) {
                    s1[cnt1++] = s2[j];
                    cnt2 = j;
                }
            }
            s2[cnt2++] = bigstring[i];
        }
    }
    for (int i = cnt2 - 1; i >= 0; --i) {
        s1[cnt1++] = s2[i];
    }
    int p = -1;
    for (int i = 0; i < cnt1; ++i) {
        if (s1[i] >= 'a' && s1[i] <= 'z') {
            final[++p] = pBigInt[s1[i] - 'a']->str;
        } else {
            if (s1[i] == '+') {
                final[p - 1] = num_plus(final[p - 1], final[p]);
                p--;
            } else if (s1[i] == '-') {
                final[p - 1] = num_sub(final[p - 1], final[p]);
                p--;
            } else if (s1[i] == '*') {
                final[p - 1] = num_mul(final[p - 1], final[p]);
                p--;
            } else if (s1[i] == '/') {
                final[p - 1] = num_div(final[p - 1], final[p]);
                p--;
            }
        }
    }
    return final[0];
}
void show(BigInt *d) {
    puts(d->str);
    return;
}
char problem[100];
int main() {
   clock_t start, finish;
   double  duration;
   start = clock();
    BigInt *bgInt[26], *p = NULL, *q = NULL;
    char *d;
    mp['+'] = mp['-'] = 1;
    mp['('] = mp[')'] = 0;
    mp['*'] = mp['/'] = 2;
    int n;
    cout << "输入数据总个数（不含运算符）：" << endl;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      printf("输入数据%c:",'a'+i);
    	scanf("%s", problem);
    	ReisterBigInt(problem, 'a' + i, bgInt);
    }
    cout << "输入表达式：" << endl;
    scanf("%s", problem);
    d = solveBigInt(problem, bgInt);
    puts(d);
    finish = clock();

   duration = (double)(finish - start) / CLOCKS_PER_SEC;

   printf( "%f seconds\n", duration );
    // show(d);
}
