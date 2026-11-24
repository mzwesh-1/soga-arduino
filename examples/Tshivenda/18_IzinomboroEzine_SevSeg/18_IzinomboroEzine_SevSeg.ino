// Isibonisi sezinombolo ezi-4: isibali-sikhathi esibala imizuzwana eyishumi (0.0 - 999.9).
// Ukuxhuma: D1-D4 -> 2, 3, 4, 5; a-g, DP -> 6-13 (220 ohm)
// Dinga umtapo: "SevSeg" (Tools -> Manage Libraries)
#include <SevSeg.h>
#include <Tshivenda.h>

Tshisumbedzi_tsha_nomboro isibonisi;

a_huna thoma() {
    baithi amaphini_ezinombolo[] = {2, 3, 4, 5};
    baithi amaphini_ezingxenye[] = {6, 7, 8, 9, 10, 11, 12, 13};
    isibonisi.mathomo(COMMON_CATHODE, 4, amaphini_ezinombolo, amaphini_ezingxenye, mazwifhi);
    isibonisi.vhea_u_penya(90);
}

a_huna dovholola() {
    zwo_imaho hu_si_na_tshiga lapfu isikhathi_sokugcina = 0;
    zwo_imaho nomboro isibali = 0;
    arali (milisekhondo() - isikhathi_sokugcina >= 100) {
        isikhathi_sokugcina = milisekhondo();
        isibali = (isibali + 1) % 10000;
        isibonisi.vhea_nomboro(isibali, 1);   // ichashazi le-desimali endaweni yoku-1
    }
    isibonisi.vusuludza_tshisumbedzi();             // kumele kubizwe njalo
}
