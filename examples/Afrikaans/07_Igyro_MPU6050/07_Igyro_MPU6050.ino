// GY-521 MPU-6050: ifunda ukusheshisa (accelerometer) nokujika (gyroscope) ezinhlangothini ezi-3.
// Ukuxhuma ku-Mega: VCC -> 5V, GND -> GND, SDA -> 20, SCL -> 21
#include <Wire.h>
#include <Afrikaans.h>

konstant heelgetal IKHELI_LE_MPU = 0x68;

heelgetal16 funda_amabhayithi_amabili() {
    heelgetal16 phezulu = Kabel.leesgreep();
    terug (phezulu << 8) | Kabel.leesgreep();
}

leeg opstel() {
    Seriaal.begin(9600);
    Kabel.begin();
    Kabel.begin_stuur(IKHELI_LE_MPU);
    Kabel.skryfgreep(0x6B);          // irejista yamandla
    Kabel.skryfgreep(0);             // vusa i-MPU-6050
    Kabel.klaar_stuur(waar);
}

leeg lus() {
    Kabel.begin_stuur(IKHELI_LE_MPU);
    Kabel.skryfgreep(0x3B);          // qala kurejista ye-accelerometer
    Kabel.klaar_stuur(vals);
    Kabel.vra_van(IKHELI_LE_MPU, 14, waar);
    heelgetal16 ax = funda_amabhayithi_amabili(), ay = funda_amabhayithi_amabili(), az = funda_amabhayithi_amabili();
    heelgetal16 ukushisa = funda_amabhayithi_amabili();
    heelgetal16 gx = funda_amabhayithi_amabili(), gy = funda_amabhayithi_amabili(), gz = funda_amabhayithi_amabili();

    Seriaal.druk("Ukusheshisa X/Y/Z: ");
    Seriaal.druk(ax); Seriaal.druk(" "); Seriaal.druk(ay); Seriaal.druk(" "); Seriaal.druk(az);
    Seriaal.druk("   Ukujika X/Y/Z: ");
    Seriaal.druk(gx); Seriaal.druk(" "); Seriaal.druk(gy); Seriaal.druk(" "); Seriaal.druk(gz);
    Seriaal.druk("   Ukushisa: ");
    Seriaal.drukreel(ukushisa / 340.0 + 36.53);
    wag(500);
}
