# Solfeggio_Machine
Arduino: comporre “canzoni” con buzzer e un display
Nel mondo di Arduino vi è data la possibilità di realizzare una miriade di progetti. In questo articolo vi sarà un tutorial su come comporre la colonna sonora dei “Pirati dei Caraibi” tramite l’ausilio di un buzzer passivo e inoltre sarà anche utilizzato un display LCD, sul quale saranno riportate le note riprodotte durante la composizione. Per capire e scoprire le potenzialità di un cicalino passivo e di un display LCD sono presenti rispettivamente tutorial che illustrano ciò (clicca qui per il tutorial per il display e clicca qui per il tutorial sul buzzer passivo).

Per la riuscita di questo progetto occorre utilizzare :

1x board di Arduino o schede compatibili
1x buzzer passivo
1x Un display LCD (In questo caso il display LCD1602)
1x Potenziometro (10k)
Breadboard (in questo caso è stata utilizzata la breadboard con 830 fori)
19x connettori M-M (connettori Maschio-Maschio)

Nella immagine sottostante è riportata il diagramma di collegamento:

![alt text](https://i0.wp.com/www.moreware.org/wp/wp-content/uploads/2019/12/Untitled-Sketch_bb.jpg.png?resize=1024%2C963&ssl=1)

In seguito è riportato lo sketch per l’utilizzo del display LCD su Arduino:
https://github.com/SimoneMoreWare/Solfeggio_Machine/blob/main/solfeggio_machine.ino

video
https://www.youtube.com/watch?v=AwRgN7O34ug


Una piccola nota riguardo il programma: per far comparire le note riprodotte in quel preciso istante di tempo bastava creare un vettore di tipo “string” e inserire all’interno di questo vettore il nome delle note utilizzate. Il ragionamento è giustissimo ma vi sono degli inghippi a livello “pratico”. La memoria massima che può essere utilizzata per la creazione di un programma in Arduino è 2048 byte. Chi programma in C/C++ o qualsiasi altro tipo di linguaggio non ha problemi di questo tipo, poiché almeno in C++ la memoria massima utilizzabile (quella stack) è di 4 MB, nel caso si utilizzassero variabili, vettori e matrici “statiche” e non dinamiche. Ma coloro i quali programmano con Arduino.ide devono possedere l’accortezza di creare programmi “snelli” e poco “pesanti” a livello di memoria. Le stringhe “consumano” molta memoria, e per ovviare a questo ostacolo si può utilizzare il comando di “Swicth case statement”.
