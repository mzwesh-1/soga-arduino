// HC-SR04: ilinganisa ibanga ukuya entweni ngomsindo (ama-sentimitha).
// Ukuxhuma: VCC -> 5V, Trig -> 12, Echo -> 11, GND -> GND
#include <Sepedi.h>

sa_fetogego palo ITRIG = 12;
sa_fetogego palo IECHO = 11;

lefeela thoma() {
    Seriale.mathomo(9600);
    bea_phini(ITRIG, TSE_TSWAGO);
    bea_phini(IECHO, TSE_TSENAGO);
}

tesimale linganisa_ibanga() {
    ngwala_dijithale(ITRIG, FASE);
    leta_maekro(2);
    ngwala_dijithale(ITRIG, GODIMO);      // thumela umsindo isikhathi esingu-10 us
    leta_maekro(10);
    ngwala_dijithale(ITRIG, FASE);
    ntle_le_leswao telele isikhathi_sokubuya = lekanya_phalese(IECHO, GODIMO, 30000);
    busetsa isikhathi_sokubuya * 0.0343 / 2;         // umsindo uhamba 0.0343 cm nge-us, uya ubuye
}

lefeela boeletsa() {
    tesimale ibanga = linganisa_ibanga();
    ge (ibanga == 0) {
        Seriale.bontsha_mothaladi("Ayikho into ebangeni");
    } go_sego_bjalo {
        Seriale.bontsha("Ibanga: ");
        Seriale.bontsha(ibanga);
        Seriale.bontsha_mothaladi(" cm");
    }
    leta(500);
}
