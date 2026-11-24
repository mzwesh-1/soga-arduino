// HC-SR04: ilinganisa ibanga ukuya entweni ngomsindo (ama-sentimitha).
// Ukuxhuma: VCC -> 5V, Trig -> 12, Echo -> 11, GND -> GND
#include <Sesotho.h>

e_sa_fetoheng palo ITRIG = 12;
e_sa_fetoheng palo IECHO = 11;

lefeela qala() {
    Seriale.qalo(9600);
    beha_phini(ITRIG, TSE_TSWANG);
    beha_phini(IECHO, TSE_KENANG);
}

desimale linganisa_ibanga() {
    ngola_dijithale(ITRIG, TLASE);
    ema_maekhro(2);
    ngola_dijithale(ITRIG, HODIMO);      // thumela umsindo isikhathi esingu-10 us
    ema_maekhro(10);
    ngola_dijithale(ITRIG, TLASE);
    e_se_nang_tshwayo telele isikhathi_sokubuya = lekanya_phalese(IECHO, HODIMO, 30000);
    kgutlisa isikhathi_sokubuya * 0.0343 / 2;         // umsindo uhamba 0.0343 cm nge-us, uya ubuye
}

lefeela pheta_pheta() {
    desimale ibanga = linganisa_ibanga();
    haeba (ibanga == 0) {
        Seriale.bontsha_mola("Ayikho into ebangeni");
    } ho_seng_jwalo {
        Seriale.bontsha("Ibanga: ");
        Seriale.bontsha(ibanga);
        Seriale.bontsha_mola(" cm");
    }
    ema(500);
}
