#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    ps();
    printf(1, "Uptime (ticks): %d\n", uptime());
    exit();
}