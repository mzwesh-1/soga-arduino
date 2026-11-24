// Ibhaza elingasebenzi ngokwalo (passive): lidlala iculo elifushane.
// Ukuxhuma: + -> 8, - -> GND
#include <Afrikaans.h>

konstant heelgetal IBHAZA = 8;
// Amanothi: C D E F G A B C (Hz)
heelgetal amanothi[] = {262, 294, 330, 349, 392, 440, 494, 523};
heelgetal isikhathi_senothi[] = {250, 250, 250, 250, 250, 250, 250, 500};

leeg opstel() {
    vir (heelgetal i = 0; i < 8; i++) {
        toon(IBHAZA, amanothi[i], isikhathi_senothi[i]);
        wag(isikhathi_senothi[i] * 1.3);
    }
    geentoon(IBHAZA);
}

leeg lus() {
    // Iculo lidlala kanye kuphela. Cindezela u-RESET ukuze uphinde ulizwe.
}
