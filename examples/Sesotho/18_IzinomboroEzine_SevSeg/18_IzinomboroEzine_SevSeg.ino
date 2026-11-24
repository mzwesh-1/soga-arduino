// Isibonisi sezinombolo ezi-4: isibali-sikhathi esibala imizuzwana eyishumi (0.0 - 999.9).
// Ukuxhuma: D1-D4 -> 2, 3, 4, 5; a-g, DP -> 6-13 (220 ohm)
// Dinga umtapo: "SevSeg" (Tools -> Manage Libraries)
#include <SevSeg.h>
#include <Sesotho.h>

Pontsho_ya_dinomoro isibonisi;

lefeela qala() {
    baete amaphini_ezinombolo[] = {2, 3, 4, 5};
    baete amaphini_ezingxenye[] = {6, 7, 8, 9, 10, 11, 12, 13};
    isibonisi.qalo(COMMON_CATHODE, 4, amaphini_ezinombolo, amaphini_ezingxenye, leshano);
    isibonisi.beha_kgantsho(90);
}

lefeela pheta_pheta() {
    e_emeng e_se_nang_tshwayo telele isikhathi_sokugcina = 0;
    e_emeng palo isibali = 0;
    haeba (dimilisekonde() - isikhathi_sokugcina >= 100) {
        isikhathi_sokugcina = dimilisekonde();
        isibali = (isibali + 1) % 10000;
        isibonisi.beha_nomoro(isibali, 1);   // ichashazi le-desimali endaweni yoku-1
    }
    isibonisi.ntjhafatsa_pontsho();             // kumele kubizwe njalo
}
