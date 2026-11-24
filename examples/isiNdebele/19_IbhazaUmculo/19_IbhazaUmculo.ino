// Ibhaza elingasebenzi ngokwalo (passive): lidlala iculo elifushane.
// Ukuxhuma: + -> 8, - -> GND
#include <isiNdebele.h>

okungatjhugulukiko inomboro IBHAZA = 8;
// Amanothi: C D E F G A B C (Hz)
inomboro amanothi[] = {262, 294, 330, 349, 392, 440, 494, 523};
inomboro isikhathi_senothi[] = {250, 250, 250, 250, 250, 250, 250, 500};

ilize thoma() {
    jikeleza (inomboro i = 0; i < 8; i++) {
        ithoni(IBHAZA, amanothi[i], isikhathi_senothi[i]);
        lindela(isikhathi_senothi[i] * 1.3);
    }
    misa_ithoni(IBHAZA);
}

ilize phinda_phinda() {
    // Iculo lidlala kanye kuphela. Cindezela u-RESET ukuze uphinde ulizwe.
}
