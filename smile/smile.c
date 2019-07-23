#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "emogis.h"
int main()
{
    setlocale(LC_ALL, "en_US.utf8");
    
    printf("Let's go drink some %lc\n", martini_emoji);

    return 0;
}