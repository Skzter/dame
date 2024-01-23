# Abschlussprüfung Grundlagen der Programmierung 
## HTWK Leipzig, Medieninformatik, 1. Semester
**Aufgabenstellung**

Ein Damebrettspiel für diese Aufgabe besteht aus einem Brett mit 10×10 Feldern. Die Felder sind
in beide Richtungen abwechselnd schwarz und weiß markiert. Die Startposition ist, dass jeder
Spieler auf sich gegenüberliegenden Brettseiten jeweils 15 Spielsteine auf den schwarzen Feldern der
ersten 3 Reihen hat. Gespielt wird abwechselnd, jeder Spieler darf nur seine eigenen Steine bewegen.
Ein normaler Zug ist das Bewegen eines Spielsteins ein Feld vorwärts in Diagonalrichtung auf ein
benachbartes leeres Feld. Das Schlagen des gegnerischen Steines erfolgt durch das ¨Uberspringen
in Diagonalrichtung. Der geschlagene Stein wird dann vom Brett genommen. Bei der Ausgabe
des Spielfeldes auf dem Bildschirm sollen die Anzahl der geschlagenen Steine angezeigt werden.
Alle weiteren üblichen Regeln finden für diese Aufgabe keine Anwendung.
Benennen Sie die Spielzüge über Buchstaben und Zahlen wie beim Schachspiel: A1 B2 würde
einen Spielstein aus dem linken unteren Eck um ein Feld nach rechts oben bewegen. A3 C1
hingegen wäre ein Sprung, der nur gültig ist, wenn auf B2 ein gegnerischer Stein läge und das
Feld C1 selbst nicht belegt ist.
Schreiben Sie ein Programm, das
- das Damebrett mit den Spielsteinen beider Spieler als Objekt definiert;
- das den aktuellen Spielstand im Sinne der Belegung des Brettes ausgeben kann (intern
realisiert über Operatoren);
- das ausgibt, welcher Spieler gerade am Zug ist;
- das eine Eingabe eines Zuges vom jeweiligen Spieler nach den oben definierten Regeln
unterstützt;
- das dem Spieler ausgibt, ob der Zug gültig und diesen dann durchführt;
- das bei einem ungültigen Zug den Spieler warnt, den Zug nicht durchführt, und um eine
erneute Eingabe bittet;
- das alle bisherigen Brettbelegungen sowie der aktuelle Spieler, der am Zug ist vollständig
im Speicher (RAM) zwischenspeichert, sodass der Spielstand jederzeit durch Eingabe von
’-’ auf den vorherigen Spielstand zurückgesetzt werden kann!
