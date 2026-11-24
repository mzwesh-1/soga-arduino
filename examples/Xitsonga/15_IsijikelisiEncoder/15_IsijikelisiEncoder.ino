// I-rotary encoder: jika ukwandisa/ukunciphisa inombolo; cindezela ukuyibuyisela ku-0.
// Ukuxhuma: CLK -> 2, DT -> 3, SW -> 4, + -> 5V, GND -> GND
#include <Xitsonga.h>

lexi_nga_cinciki nomboro I_CLK = 2;
lexi_nga_cinciki nomboro I_DT = 3;
lexi_nga_cinciki nomboro I_SW = 4;
lexi_cincaka_hi_ku_hatlisa nomboro isibali = 0;
nomboro isibali_esidala = 0;

swi_hava uma_kujikiwe() {
    loko (hlaya_dijitali(I_DT) != hlaya_dijitali(I_CLK)) isibali++;   // ngokwewashi
    ku_nga_ri_tano isibali--;                                               // ngokuphambene
}

swi_hava sungula() {
    veka_phini(I_CLK, LESWI_NGHENAKA);
    veka_phini(I_DT, LESWI_NGHENAKA);
    veka_phini(I_SW, LESWI_NGHENAKA_HI_KU_KOKA);
    Siriyali.ku_sungula(9600);
    khomanisa_ku_kavanyeta(phini_ku_kavanyeta(I_CLK), uma_kujikiwe, LOKO_YI_CINCA);
}

swi_hava phindha_phindha() {
    loko (hlaya_dijitali(I_SW) == HANSI) {
        isibali = 0;
        rindza(200);
    }
    loko (isibali != isibali_esidala) {
        isibali_esidala = isibali;
        Siriyali.kombisa("Isibali: ");
        Siriyali.kombisa_layini(isibali);
    }
}
