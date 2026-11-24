// Isibonisi sezinombolo ezi-4: isibali-sikhathi esibala imizuzwana eyishumi (0.0 - 999.9).
// Ukuxhuma: D1-D4 -> 2, 3, 4, 5; a-g, DP -> 6-13 (220 ohm)
// Dinga umtapo: "SevSeg" (Tools -> Manage Libraries)
#include <SevSeg.h>
#include <Xitsonga.h>

Xikombisi_xa_tinomboro isibonisi;

swi_hava sungula() {
    bayiti amaphini_ezinombolo[] = {2, 3, 4, 5};
    bayiti amaphini_ezingxenye[] = {6, 7, 8, 9, 10, 11, 12, 13};
    isibonisi.ku_sungula(COMMON_CATHODE, 4, amaphini_ezinombolo, amaphini_ezingxenye, mavunwa);
    isibonisi.veka_ku_phatima(90);
}

swi_hava phindha_phindha() {
    lexi_yimeke handle_ka_mfungho leha isikhathi_sokugcina = 0;
    lexi_yimeke nomboro isibali = 0;
    loko (timilisekoni() - isikhathi_sokugcina >= 100) {
        isikhathi_sokugcina = timilisekoni();
        isibali = (isibali + 1) % 10000;
        isibonisi.veka_nomboro(isibali, 1);   // ichashazi le-desimali endaweni yoku-1
    }
    isibonisi.pfuxeta_xikombisi();             // kumele kubizwe njalo
}
