// HC-SR04: ilinganisa ibanga ukuya entweni ngomsindo (ama-sentimitha).
// Ukuxhuma: VCC -> 5V, Trig -> 12, Echo -> 11, GND -> GND
#include <Setswana.h>

e_sa_fetogeng palo ITRIG = 12;
e_sa_fetogeng palo IECHO = 11;

lefela simolola() {
    Seriale.tshimologo(9600);
    baya_phini(ITRIG, TSE_DI_TSWANG);
    baya_phini(IECHO, TSE_DI_TSENANG);
}

tesimale linganisa_ibanga() {
    kwala_dijithale(ITRIG, TLASE);
    ema_maekero(2);
    kwala_dijithale(ITRIG, GODIMO);      // thumela umsindo isikhathi esingu-10 us
    ema_maekero(10);
    kwala_dijithale(ITRIG, TLASE);
    e_se_na_tshwao leele isikhathi_sokubuya = lekanya_phalese(IECHO, GODIMO, 30000);
    busa isikhathi_sokubuya * 0.0343 / 2;         // umsindo uhamba 0.0343 cm nge-us, uya ubuye
}

lefela boeletsa() {
    tesimale ibanga = linganisa_ibanga();
    fa (ibanga == 0) {
        Seriale.bontsha_mola("Ayikho into ebangeni");
    } go_seng_jalo {
        Seriale.bontsha("Ibanga: ");
        Seriale.bontsha(ibanga);
        Seriale.bontsha_mola(" cm");
    }
    ema(500);
}
