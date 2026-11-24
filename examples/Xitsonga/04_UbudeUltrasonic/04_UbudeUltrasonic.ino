// HC-SR04: ilinganisa ibanga ukuya entweni ngomsindo (ama-sentimitha).
// Ukuxhuma: VCC -> 5V, Trig -> 12, Echo -> 11, GND -> GND
#include <Xitsonga.h>

lexi_nga_cinciki nomboro ITRIG = 12;
lexi_nga_cinciki nomboro IECHO = 11;

swi_hava sungula() {
    Siriyali.ku_sungula(9600);
    veka_phini(ITRIG, LESWI_HUMAKA);
    veka_phini(IECHO, LESWI_NGHENAKA);
}

desimali linganisa_ibanga() {
    tsala_dijitali(ITRIG, HANSI);
    rindza_maykhro(2);
    tsala_dijitali(ITRIG, HENHLA);      // thumela umsindo isikhathi esingu-10 us
    rindza_maykhro(10);
    tsala_dijitali(ITRIG, HANSI);
    handle_ka_mfungho leha isikhathi_sokubuya = pima_phalisi(IECHO, HENHLA, 30000);
    vuyisa isikhathi_sokubuya * 0.0343 / 2;         // umsindo uhamba 0.0343 cm nge-us, uya ubuye
}

swi_hava phindha_phindha() {
    desimali ibanga = linganisa_ibanga();
    loko (ibanga == 0) {
        Siriyali.kombisa_layini("Ayikho into ebangeni");
    } ku_nga_ri_tano {
        Siriyali.kombisa("Ibanga: ");
        Siriyali.kombisa(ibanga);
        Siriyali.kombisa_layini(" cm");
    }
    rindza(500);
}
