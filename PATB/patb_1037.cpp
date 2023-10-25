#include <math.h>
#include <stdio.h>
int main() {
    int pg, ps, pk;
    int ag, as, ak;
    int galleon = 17 * 29;
    int sickle = 29;
    scanf("%d.%d.%d %d.%d.%d", &pg, &ps, &pk, &ag, &as, &ak);
    int sum = (ag - pg) * galleon + (as - ps) * sickle + ak - pk;
    if (sum < 0) {
        printf("-");
        sum = -sum;
    }
    printf("%d.%d.%d", sum / galleon, sum % galleon / sickle, sum % galleon % sickle);
    return 0;
}