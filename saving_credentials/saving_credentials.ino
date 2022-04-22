/*
   Date de création: 2022-02-20
   Auteur: Nicolas R. et Richard M.
   Dans le cadre du développement d'une station météo dans un des projet mener par le
   Gripcal et superviser par David Beaulieux un professeur en technique du génie physique
   au Cégep André-Laurendeau

   But du code: Le but de se code est de premetre de venir bruler les données du credential dans
   la mémoire flash du microcontroleur. Pour quelle puisse être réutilisé n'importe quand si l'on
   compile un autre programme. Tant que se code si n'a pas été recompiler les valeur reste enregistrées
   dasn la mémoire du microcontrôleur. C'est se code si qui réinitialise toute la mémoire.
*/


#include <Preferences.h>
#include <nvs_flash.h>

Preferences preferences;

const char* WIFI_SSID = "Dista";
const char* WIFI_PASSWD = "dista-wifi";
//const char* WIFI_SSID = "CAL-Techno";
//const char* WIFI_PASSWD = "technophys123";
const char* PRIVATE_URL = "http://technophys.herokuapp.com/api/datas/736AE4FE1E";

void setup() {
  Serial.begin(115200);
  Serial.println();
  // on efface toute la mémoire flash puis on la réinitialise
  nvs_flash_erase();
  nvs_flash_init();

  // on store les donnée dans le classeur credential
  preferences.begin("credentials", false);
  // on store l'étiquette de la donnée suivi de sa valeur
  preferences.putString("WIFI_SSID", WIFI_SSID);
  preferences.putString("WIFI_PASSWD", WIFI_PASSWD);
  preferences.putString("PRIVATE_URL", PRIVATE_URL);

  Serial.println("Network Credentials Saved using Preferences");

  preferences.end();
}

void loop() {

}
