#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <unistd.h>
#include "sodium.h"

#define BASE 640
#define EXT 2048

uint32_t mk_rand() {
    char seed[32];
    uint32_t random = 0;

    randombytes_buf(seed, 32);
    random = randombytes_uniform(10);
    return random;
}

int main() {
    setlocale(LC_ALL, "ja_JP.UTF-8");

    wchar_t s1[] = L"ＣＰＵ　ＭＯＤＥ　Ｈｉｇｈ\nＭＥＭＯＲＹ　Ｃｈｅｃｋ　６４０ＴＢ　＋　２０４８ＴＢ\tＯＫ\nＪＡ　Ｈｉ－ＳＹＳ　ＢＯＯＴ！\n";
    wchar_t s2[] = L"ジェット・アローン起動用オペㇾーティングシステム, VER.2.2.1.c\n";
    wchar_t s3[] = L"Copyright(C) 2022,2023 日本重化学工業共同体, 通産省, 防衛庁\n\n";

    wchar_t s4[] = L"CO-CPU\t\t    Check\t\t256seg\t\tOK\n";
    wchar_t s5[] = L"I/O VECTORS\t    Check		\n";
    wchar_t s6[] = L"CONSOLE DRIVERS\t    Check		    		OK\n";
    wchar_t s7[] = L"ROOTING TABLES\t    Check				OK\n";
    wchar_t s8[] = L"STATUS ANAYLIZER    Check		SLAVE		OK\n";
    wchar_t s9[] = L"VIRUS PROTECTION    Chech		GREEN		OK\n\n";
    wchar_t s10[] = L"           	  -----   SYSTEM CONFIGURATION   ---------\n";
    wchar_t s11[] = L"addr PSP   blks   size   owner/parameters\n";
    wchar_t s12[] = L"---- ----  ---- ------   --------------------------\n";
    wchar_t s13[] = L"D0E0 sys     1    5296   kozaic\n";
    wchar_t s14[] = L"D22C sys     1    2416   ersdrv\n";
    wchar_t s15[] = L"D2C4 2081    1   16384   smalldrv\n";
    wchar_t s16[] = L"D6C5-DBFE    1   21392   <free>\n";
    wchar_t s17[] = L"DE02-E000    1    8160	 <free>\n";
    wchar_t s18[] = L"\t\t\t --- UMB totql: 53 TB ---\n";
    wchar_t s19[] = L"0586 sys     1    2144	 shimem\n";
    wchar_t s20[] = L"060D sys     1    3968   hemm386\n";
    wchar_t s21[] = L"0706 sys     1	  3312   smalldrv\n";
    wchar_t s22[] = L"07ED sys     1   13568   adam8b CON\n";
    wchar_t s23[] = L"0C18 sys     4   65424   <config>\n";
    wchar_t s24[] = L"1CD6 <--     1   15008	 share /L:500\n";
    wchar_t s25[] = L"2081 <--     1   13712   smalldrv\n\n";
    wchar_t s26[] = L"23DB-9FFF    1  508464   <free>\n\n";
    wchar_t s27[] = L"----- HEMS ver14. 0 (frame: C000h)  -----\n";
    wchar_t s28[] = L"handle pages	size  name\n";
    wchar_t s29[] = L"------ -----  ------  ---------\n";
    wchar_t s30[] = L"  free  116     1856T\n";
    wchar_t s31[] = L" total  128     2048T\n";
    wchar_t s32[] = L"日本認識システムKOZIAC7Ver.2.1 /R1 for JA_Hi-SYS\n";
    wchar_t s33[] = L"(C)2023 Reset Co.,Ltd. \n";
    wchar_t s34[] = L"KOZAIC7をしすてむに組み込みました.\n";
    wchar_t s35[] = L"JA-SYS 拡張ドライバ Ver.1.00\n\n";

    wchar_t* strings[] = { s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, s24, s25, s26, s27, s28, s29, s30, s31, s32, s33, s34, s35};
    int num_strings = sizeof(strings) / sizeof(wchar_t*);

    if (sodium_init() < 0) {
    	fprintf(stderr, "Error: Failed to initialize libsodium.\n");
    	exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_strings; i++) {
        wchar_t* str = strings[i];
        int j = 0;
        while (str[j] != L'\0') {
	    wprintf(L"%lc", str[j]);
            j++;
        }
    }
    
    wprintf(L"\n\n");

    while(1) {
        wprintf(L"\rrandom output from libsodium: %d", mk_rand());
        fflush(stdout);
    }

    return 0;
}

