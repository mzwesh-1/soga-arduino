// I-tilt switch: uma ubhodi lutshekile, i-LED iyakhanya.
// Ukuxhuma: i-tilt switch -> 2 no-GND; i-LED -> 13
#include <Xitsonga.h>

lexi_nga_cinciki nomboro ITILT = 2;
lexi_nga_cinciki nomboro ILED = 13;

swi_hava sungula() {
    veka_phini(ITILT, LESWI_NGHENAKA_HI_KU_KOKA);
    veka_phini(ILED, LESWI_HUMAKA);
    Siriyali.ku_sungula(9600);
}

swi_hava phindha_phindha() {
    loko (hlaya_dijitali(ITILT) == HANSI) {
        tsala_dijitali(ILED, HANSI);
    } ku_nga_ri_tano {
        tsala_dijitali(ILED, HENHLA);
        Siriyali.kombisa_layini("Kutshekile!");
    }
    rindza(100);
}
