/*
   Date de création: 2022-02-20
   Auteur: Nicolas R. et Richard M.
   Dans le cadre du développement d'une station météo dans un des projet mener par le
   Gripcal et superviser par David Beaulieux un professeur en technique du génie physique
   au Cégep André-Laurendeau

   But du code: Le but de se code est de premetre de venir bruler des données dans la
   mémoire Flash du ESP 32. Comme ça peut importe le code que nous instalons les données
   enregistrer reste enregistrer et peuvent être appeler quand nous le désirons. Les bibliothèques
   Preference.h et nvs_flash.h sont importante pour que le code fonctionne bien. Ne pas oublier
   que le code flash credential doit impérativement avoir été fait pour permettre l'effacement de
   ces fameuses données.
*/

#include <Preferences.h>
#include <nvs_flash.h>

Preferences preferences;

float valeur;

/********************************************************/
// Fonction qui permet de venir bruler les donnée dans la mémoire flash
// nom : le nom du dossier dans lequel la donnée va être enregistrer
// tag : l'étiquette de la valeur
// value : la valeur de la donnée

void storeFlashDataFloat(String nom, String tag, float value) {
  char classeur[12];
  char Buffer[12];
  nom.toCharArray(classeur, 12);
  tag.toCharArray(Buffer, 12);
  preferences.begin(classeur, false);
  preferences.putFloat(Buffer, value);
  Serial.println("Données sauvegarder dans la mémoire flash");
  preferences.end();
}
/********************************************************/
// Fonction permettant de lire se que nous avons enregistrer dans la mémoire flash
// nom : nom du classeur ou la donnée est enregistré
// tag : L'étiquet de la donnée
// La fonction renvois dans la varriable "valeur" la valeur de la donnée rechercher. 

void recallFlashDataFloat(String nom, String tag) {
  char classeur[12];
  char Buffer[12];
  nom.toCharArray(classeur, 12);
  tag.toCharArray(Buffer, 12);
  preferences.begin(classeur, false);
  valeur = preferences.getFloat(Buffer);
  preferences.end();
}
/*******************************************************/

void setup() {
  Serial.begin(115200);
  Serial.println();

  // initalise la mémoire flash
  nvs_flash_init();

  // Exemple pour écrire les valeurs

  float valeurT = 20.1;
  String capteur = "etalonage";
  String capteur2 = "capteur";
  String tagSensor = "temp";
  storeFlashDataFloat(capteur, tagSensor, valeurT);

  float valeurP = 101.3;
  String tagSensor2 = "Pres";
  storeFlashDataFloat(capteur2, tagSensor2, valeurP);

  // Exemple pour aller lire les valeurs

  recallFlashDataFloat(capteur, tagSensor);
  Serial.print("La température est de ");
  Serial.println(valeur);

  recallFlashDataFloat(capteur2, tagSensor2);
  Serial.print("La Pression est de ");
  Serial.println(valeur);


}

void loop() {
  // put your main code here, to run repeatedly:

}
