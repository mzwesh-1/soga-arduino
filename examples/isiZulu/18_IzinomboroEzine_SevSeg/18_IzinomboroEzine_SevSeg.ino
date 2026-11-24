// Isibonisi sezinombolo ezi-4: isibali-sikhathi esibala imizuzwana eyishumi (0.0 - 999.9).
// Ukuxhuma: D1-D4 -> 2, 3, 4, 5; a-g, DP -> 6-13 (220 ohm)
// Dinga umtapo: "SevSeg" (Tools -> Manage Libraries)
#include <SevSeg.h>
#include <isiZulu.h>

Isibonisi_sezinombolo isibonisi;

ize qala() {
    ibhayithi amaphini_ezinombolo[] = {2, 3, 4, 5};
    ibhayithi amaphini_ezingxenye[] = {6, 7, 8, 9, 10, 11, 12, 13};
    isibonisi.ukuqala(COMMON_CATHODE, 4, amaphini_ezinombolo, amaphini_ezingxenye, amanga);
    isibonisi.setha_ukucwebezela(90);
}

ize phindaphinda() {
    okumile ongenaphawu ende isikhathi_sokugcina = 0;
    okumile inombolo isibali = 0;
    uma (amamilisekhondi() - isikhathi_sokugcina >= 100) {
        isikhathi_sokugcina = amamilisekhondi();
        isibali = (isibali + 1) % 10000;
        isibonisi.setha_inombolo(isibali, 1);   // ichashazi le-desimali endaweni yoku-1
    }
    isibonisi.vuselela_isibonisi();             // kumele kubizwe njalo
}
