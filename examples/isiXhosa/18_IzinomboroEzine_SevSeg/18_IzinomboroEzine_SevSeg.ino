// Isibonisi sezinombolo ezi-4: isibali-sikhathi esibala imizuzwana eyishumi (0.0 - 999.9).
// Ukuxhuma: D1-D4 -> 2, 3, 4, 5; a-g, DP -> 6-13 (220 ohm)
// Dinga umtapo: "SevSeg" (Tools -> Manage Libraries)
#include <SevSeg.h>
#include <isiXhosa.h>

Isiboniso_samanani isibonisi;

ize qalisa() {
    ibhayithi amaphini_ezinombolo[] = {2, 3, 4, 5};
    ibhayithi amaphini_ezingxenye[] = {6, 7, 8, 9, 10, 11, 12, 13};
    isibonisi.ukuqala(COMMON_CATHODE, 4, amaphini_ezinombolo, amaphini_ezingxenye, ubuxoki);
    isibonisi.misela_ukuqaqamba(90);
}

ize phinda_phinda() {
    emileyo engenaphawu ende isikhathi_sokugcina = 0;
    emileyo inani isibali = 0;
    ukuba (iimilisekondi() - isikhathi_sokugcina >= 100) {
        isikhathi_sokugcina = iimilisekondi();
        isibali = (isibali + 1) % 10000;
        isibonisi.misela_inani(isibali, 1);   // ichashazi le-desimali endaweni yoku-1
    }
    isibonisi.hlaziya_isiboniso();             // kumele kubizwe njalo
}
