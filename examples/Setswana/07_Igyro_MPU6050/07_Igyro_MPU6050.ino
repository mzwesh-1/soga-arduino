// GY-521 MPU-6050: ifunda ukusheshisa (accelerometer) nokujika (gyroscope) ezinhlangothini ezi-3.
// Ukuxhuma ku-Mega: VCC -> 5V, GND -> GND, SDA -> 20, SCL -> 21
#include <Wire.h>
#include <Setswana.h>

e_sa_fetogeng palo IKHELI_LE_MPU = 0x68;

palo16 funda_amabhayithi_amabili() {
    palo16 phezulu = Terata.bala_baete();
    busa (phezulu << 8) | Terata.bala_baete();
}

lefela simolola() {
    Seriale.tshimologo(9600);
    Terata.tshimologo();
    Terata.simolola_go_romela(IKHELI_LE_MPU);
    Terata.kwala_baete(0x6B);          // irejista yamandla
    Terata.kwala_baete(0);             // vusa i-MPU-6050
    Terata.fetsa_go_romela(boammaaruri);
}

lefela boeletsa() {
    Terata.simolola_go_romela(IKHELI_LE_MPU);
    Terata.kwala_baete(0x3B);          // qala kurejista ye-accelerometer
    Terata.fetsa_go_romela(maaka);
    Terata.kopa_go(IKHELI_LE_MPU, 14, boammaaruri);
    palo16 ax = funda_amabhayithi_amabili(), ay = funda_amabhayithi_amabili(), az = funda_amabhayithi_amabili();
    palo16 ukushisa = funda_amabhayithi_amabili();
    palo16 gx = funda_amabhayithi_amabili(), gy = funda_amabhayithi_amabili(), gz = funda_amabhayithi_amabili();

    Seriale.bontsha("Ukusheshisa X/Y/Z: ");
    Seriale.bontsha(ax); Seriale.bontsha(" "); Seriale.bontsha(ay); Seriale.bontsha(" "); Seriale.bontsha(az);
    Seriale.bontsha("   Ukujika X/Y/Z: ");
    Seriale.bontsha(gx); Seriale.bontsha(" "); Seriale.bontsha(gy); Seriale.bontsha(" "); Seriale.bontsha(gz);
    Seriale.bontsha("   Ukushisa: ");
    Seriale.bontsha_mola(ukushisa / 340.0 + 36.53);
    ema(500);
}
