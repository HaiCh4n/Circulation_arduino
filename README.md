# TrafficLightPedButton

Feu de signalisation pour voiture + bouton piéton (Arduino Mega/Uno).

- Cycle : Vert 8 s → Jaune 2 s → Rouge 10 s (répétition).

- Lorsque le bouton est appuyé (INPUT_PULLUP : pression = BAS), le système **enregistre**.
- Lorsque la phase rouge de la voiture est atteinte, le feu piéton **passe au vert** pendant 10 s.
- Fin de la phase rouge : le piéton repasse au **rouge**, suppression de la requête.

## Câblage
- carRed=2, carYellow=3, carGreen=4 → résistance 220–330 Ω → LED longue longueur ; Broche courte → GND
- Vert ped = 5, Rouge ped = 6 → idem
- Écrou = 7 : une broche écrou → broche 7, l’autre broche → GND (INPUT_PULLUP)

## Construction
- IDE Arduino : ouvrez le fichier « TrafficLightPedButton/TrafficLightPedButton.ino » et chargez-le.
