// Ibhaza elingasebenzi ngokwalo (passive): lidlala iculo elifushane.
// Ukuxhuma: + -> 8, - -> GND
#include <Setswana.h>

e_sa_fetogeng palo IBHAZA = 8;
// Amanothi: C D E F G A B C (Hz)
palo amanothi[] = {262, 294, 330, 349, 392, 440, 494, 523};
palo isikhathi_senothi[] = {250, 250, 250, 250, 250, 250, 250, 500};

lefela simolola() {
    dikologa (palo i = 0; i < 8; i++) {
        modumo(IBHAZA, amanothi[i], isikhathi_senothi[i]);
        ema(isikhathi_senothi[i] * 1.3);
    }
    emisa_modumo(IBHAZA);
}

lefela boeletsa() {
    // Iculo lidlala kanye kuphela. Cindezela u-RESET ukuze uphinde ulizwe.
}
