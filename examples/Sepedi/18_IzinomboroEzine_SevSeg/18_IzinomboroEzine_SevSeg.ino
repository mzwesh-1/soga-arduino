// Isibonisi sezinombolo ezi-4: isibali-sikhathi esibala imizuzwana eyishumi (0.0 - 999.9).
// Ukuxhuma: D1-D4 -> 2, 3, 4, 5; a-g, DP -> 6-13 (220 ohm)
// Dinga umtapo: "SevSeg" (Tools -> Manage Libraries)
#include <SevSeg.h>
#include <Sepedi.h>

Pontsho_ya_dinomoro isibonisi;

lefeela thoma() {
    paete amaphini_ezinombolo[] = {2, 3, 4, 5};
    paete amaphini_ezingxenye[] = {6, 7, 8, 9, 10, 11, 12, 13};
    isibonisi.mathomo(COMMON_CATHODE, 4, amaphini_ezinombolo, amaphini_ezingxenye, maaka);
    isibonisi.bea_phadimo(90);
}

lefeela boeletsa() {
    emego ntle_le_leswao telele isikhathi_sokugcina = 0;
    emego palo isibali = 0;
    ge (dimilisekhontse() - isikhathi_sokugcina >= 100) {
        isikhathi_sokugcina = dimilisekhontse();
        isibali = (isibali + 1) % 10000;
        isibonisi.bea_nomoro(isibali, 1);   // ichashazi le-desimali endaweni yoku-1
    }
    isibonisi.mpshafatsa_pontsho();             // kumele kubizwe njalo
}
