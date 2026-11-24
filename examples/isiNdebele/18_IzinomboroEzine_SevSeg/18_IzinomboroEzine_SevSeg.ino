// Isibonisi sezinombolo ezi-4: isibali-sikhathi esibala imizuzwana eyishumi (0.0 - 999.9).
// Ukuxhuma: D1-D4 -> 2, 3, 4, 5; a-g, DP -> 6-13 (220 ohm)
// Dinga umtapo: "SevSeg" (Tools -> Manage Libraries)
#include <SevSeg.h>
#include <isiNdebele.h>

Isitjengisi_seenomboro isibonisi;

ilize thoma() {
    ibhayithi amaphini_ezinombolo[] = {2, 3, 4, 5};
    ibhayithi amaphini_ezingxenye[] = {6, 7, 8, 9, 10, 11, 12, 13};
    isibonisi.ukuthoma(COMMON_CATHODE, 4, amaphini_ezinombolo, amaphini_ezingxenye, amala);
    isibonisi.setha_ukukhazimula(90);
}

ilize phinda_phinda() {
    okumileko okungenatshwayo okude isikhathi_sokugcina = 0;
    okumileko inomboro isibali = 0;
    nangabe (amamilisekhondi() - isikhathi_sokugcina >= 100) {
        isikhathi_sokugcina = amamilisekhondi();
        isibali = (isibali + 1) % 10000;
        isibonisi.setha_inomboro(isibali, 1);   // ichashazi le-desimali endaweni yoku-1
    }
    isibonisi.vuselela_isitjengisi();             // kumele kubizwe njalo
}
