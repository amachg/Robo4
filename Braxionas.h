#include <Braccio.h>

Servo base, shoulder, elbow, wrist_rot, wrist_ver, gripper;
int kath = 30, kath_metaksi = 300;
int glystra = 140, pista = 103;
int krata = 60, rixni = 30, anoix = 10;

//---------------------------------------------------------------------------  

void orthiosBraxionas() {// Όρθια θέση βραχίονα (ξεκούρασης!)
  delay(500);
  //Τιμές:             ελάχιστη - μέση - μέγιστη
  //Καθυστέρηση:            010 - 020 - 030 χιλιοστά δευτερόλεπτου
  //Βάση (M1):              000 - 090 - 180 μοίρες στροφής άξονα σερβοκινητήρα
  //Ώμος (M2):              015 - 090 - 165             <<
  //Αγκώνας (M3):           000 - 090 - 180             <<
  //Καρπός Ανύψωση(M4):     000 - 090 - 180             <<
  //Καρπός Περιστροφή(M5):  000 - 090 - 180             <<
  //Δαγκάνα (M6): (κλειστό) 073 - 055 - 010 (ανοιχτό)
  //           Καθυστέρηση,  Βασ,     Ώμος, Αγγ, ΚαρΑ, ΚαρΠ, Δαγκ;
  Braccio.ServoMovement(20,  pista,   90,  90,   90,   90,  55);
}

void pareApoGlystra() {
  Braccio.ServoMovement(kath, glystra,   90,  90,   90,   90, krata);  delay(kath_metaksi);
  Braccio.ServoMovement(kath, glystra,   62,   0,   10,   90, anoix);  delay(kath_metaksi);
  Braccio.ServoMovement(kath, glystra,   62,   0,   10,   90, krata);  delay(kath_metaksi);
  Braccio.ServoMovement(kath, glystra,  165,   0,    5,   90, krata);  delay(kath_metaksi);
  orthiosBraxionas(); 
}

// 1η στήλη πίστας(μακρύτερη)
void valePouli1() {
  Braccio.ServoMovement(kath, pista,   55,  58,   60,   90, krata);  delay(kath_metaksi);
  Braccio.ServoMovement(kath, pista,   55,  58,   60,   90, rixni);  delay(kath_metaksi);
}
// 2η στήλη πίστας
void valePouli2() {
  Braccio.ServoMovement(kath, pista,   65,  60,   43,   90, krata);  delay(kath_metaksi);
  Braccio.ServoMovement(kath, pista,   65,  60,   43,   90, rixni);  delay(kath_metaksi);
}
// 3η στήλη πίστας
void valePouli3() {
  Braccio.ServoMovement(kath, pista,   73,  65,   26,   90, krata);  delay(kath_metaksi);
  Braccio.ServoMovement(kath, pista,   73,  65,   26,   90, rixni);  delay(kath_metaksi);
}
// 4η στήλη πίστας
void valePouli4() {
  Braccio.ServoMovement(kath, pista,   81,  58,   18,   90, krata);  delay(kath_metaksi);
  Braccio.ServoMovement(kath, pista,   81,  58,   18,   90, rixni);  delay(kath_metaksi);
}
// 5η στήλη πίστας
void valePouli5() {
  Braccio.ServoMovement(kath, pista,   88,  58,    7,   90, krata);  delay(kath_metaksi);
  Braccio.ServoMovement(kath, pista,   88,  58,    7,   90, rixni);  delay(kath_metaksi);
}
// 6η στήλη πίστας
void valePouli6() {
  Braccio.ServoMovement(kath, pista,  100,  52,    2,   90, krata);  delay(kath_metaksi);
  Braccio.ServoMovement(kath, pista,  100,  52,    2,   90, rixni);  delay(kath_metaksi);
}
// 7η στήλη πίστας (κοντότερη)
void valePouli7() {
  Braccio.ServoMovement(kath, pista,  117,  40,    0,   90, krata);  delay(kath_metaksi);
  Braccio.ServoMovement(kath, pista,  117,  40,    0,   90, rixni);  delay(kath_metaksi);
}
