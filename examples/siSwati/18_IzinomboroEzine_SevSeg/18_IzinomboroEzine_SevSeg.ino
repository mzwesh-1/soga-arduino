// Isibonisi sezinombolo ezi-4: isibali-sikhathi esibala imizuzwana eyishumi (0.0 - 999.9).
// Ukuxhuma: D1-D4 -> 2, 3, 4, 5; a-g, DP -> 6-13 (220 ohm)
// Dinga umtapo: "SevSeg" (Tools -> Manage Libraries)
#include <SevSeg.h>
#include <siSwati.h>

Sibonisi_setinombolo isibonisi;

lite cala() {
    libhayithi amaphini_ezinombolo[] = {2, 3, 4, 5};
    libhayithi amaphini_ezingxenye[] = {6, 7, 8, 9, 10, 11, 12, 13};
    isibonisi.kucala(COMMON_CATHODE, 4, amaphini_ezinombolo, amaphini_ezingxenye, emanga);
    isibonisi.setha_kucwebezela(90);
}

lite phindza_phindza() {
    lokumile lokungenasibonakaliso lokudze isikhathi_sokugcina = 0;
    lokumile inombolo isibali = 0;
    nangabe (emamilisekhondi() - isikhathi_sokugcina >= 100) {
        isikhathi_sokugcina = emamilisekhondi();
        isibali = (isibali + 1) % 10000;
        isibonisi.setha_inombolo(isibali, 1);   // ichashazi le-desimali endaweni yoku-1
    }
    isibonisi.vuselela_sibonisi();             // kumele kubizwe njalo
}
