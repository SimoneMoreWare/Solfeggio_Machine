//in tale stringa vi è selezionato il pin 
// in cui il cicalino è collegato dal filo rosso
const int buzzer = 2; 

//con tale stringa possiamo regolare la 
//velocità con cui viene riprodotto l'audio
const float velocitasuono = 1.5; 

//la libreria per utilizzare a pieno 
//le potenzialità del display
#include <LiquidCrystal.h> 

//in tale stringa vi sono 
//selezionati i pin in cui il display LCD è collegato
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 

// sono state definite le varia note, il valore 
//posto è la frequenza per cui si ottengono tali note. 
#define NOTE_DO4  262   
#define NOTE_RE4  294
#define NOTE_MI4  330
#define NOTE_FA4  349
#define NOTE_SOL4  392
#define NOTE_LA4  440
#define NOTE_SI4  494
#define NOTE_DO5  523
#define NOTE_RE5  587
#define NOTE_MI5  659
#define NOTE_FA5  698
#define NOTE_SOL5  784
#define NOTE_LA5  880
#define NOTE_SI5  988


//tramite l'ausilio del vettore noteusate, vi sarà 
//data la possibilità di far comparire sul display 
//le note riprodotte, nelle seguenti righe di codice 
//sarà più chiaro questo passaggio 
int noteusate[] = {       
   3, 5, 6, 6, 0, 
   6, 7, 1, 1, 0, 
   1, 2, 7, 7, 0,
   6, 5, 6, 0,
   
   3, 5, 6, 6, 0, 
   6, 7, 1, 1, 0, 
   1, 2, 7, 7, 0,
   6, 5, 6, 0,
   
   3, 5, 6, 6, 0, 
   6, 1, 2, 2, 0, 
   2, 3, 4, 4, 0,
   3, 2, 3, 6, 0,
   
   6, 7, 1, 1, 0, 
   2, 3, 6, 0, 
   6, 1, 7, 7, 0,
   1, 6, 7, 0,

   6, 6, 
   6, 7, 1, 1, 0, 
   1, 2, 7, 7, 0,
   6, 5, 6, 0,

   3, 5, 6, 6, 0, 
   6, 7, 1, 1, 0, 
   1, 2, 7, 7, 0,
   6, 5, 6, 0,
   
   3, 5, 6, 6, 0, 
   6, 1, 2, 2, 0, 
   2, 3, 4, 4, 0,
   3, 2, 3, 6, 0,
   
   6, 7, 1, 1, 0, 
   2, 3, 6, 0, 
   6, 1, 7, 7, 0,
   1, 6, 7, 0,

   3, 0, 0, 4, 0, 0,
   3, 3, 0, 5, 0, 3, 2, 0, 0,
   2, 0, 0, 1, 0, 0,
   7, 1, 0, 7, 0, 6,

   3, 0, 0, 4, 0, 0,
   3, 3, 0, 5, 0, 3, 2, 0, 0,
   2, 0, 0, 1, 0, 0,
   7, 1, 0, 7, 0, 6
};

//nel vettore note vi è lo spartito della colonna sonora dei pirati dei caraibi, 
//lo 0 (0 Hz) indica che in quel preciso momento non deve essere prodotto nessun suono. 
int note[] = {       
   NOTE_MI4, NOTE_SOL4, NOTE_LA4, NOTE_LA4, 0, 
   NOTE_LA4, NOTE_SI4, NOTE_DO5, NOTE_DO5, 0, 
   NOTE_DO5, NOTE_RE5, NOTE_SI4, NOTE_SI4, 0,
   NOTE_LA4, NOTE_SOL4, NOTE_LA4, 0,
   
   NOTE_MI4, NOTE_SOL4, NOTE_LA4, NOTE_LA4, 0, 
   NOTE_LA4, NOTE_SI4, NOTE_DO5, NOTE_DO5, 0, 
   NOTE_DO5, NOTE_RE5, NOTE_SI4, NOTE_SI4, 0,
   NOTE_LA4, NOTE_SOL4, NOTE_LA4, 0,
   
   NOTE_MI4, NOTE_SOL4, NOTE_LA4, NOTE_LA4, 0, 
   NOTE_LA4, NOTE_DO5, NOTE_RE5, NOTE_RE5, 0, 
   NOTE_RE5, NOTE_MI5, NOTE_FA5, NOTE_FA5, 0,
   NOTE_MI5, NOTE_RE5, NOTE_MI5, NOTE_LA4, 0,
   
   NOTE_LA4, NOTE_SI4, NOTE_DO5, NOTE_DO5, 0, 
   NOTE_RE5, NOTE_MI5, NOTE_LA4, 0, 
   NOTE_LA4, NOTE_DO5, NOTE_SI4, NOTE_SI4, 0,
   NOTE_DO5, NOTE_LA4, NOTE_SI4, 0,

   NOTE_LA4, NOTE_LA4, 
   NOTE_LA4, NOTE_SI4, NOTE_DO5, NOTE_DO5, 0, 
   NOTE_DO5, NOTE_RE5, NOTE_SI4, NOTE_SI4, 0,
   NOTE_LA4, NOTE_SOL4, NOTE_LA4, 0,

   NOTE_MI4, NOTE_SOL4, NOTE_LA4, NOTE_LA4, 0, 
   NOTE_LA4, NOTE_SI4, NOTE_DO5, NOTE_DO5, 0, 
   NOTE_DO5, NOTE_RE5, NOTE_SI4, NOTE_SI4, 0,
   NOTE_LA4, NOTE_SOL4, NOTE_LA4, 0,
   
   NOTE_MI4, NOTE_SOL4, NOTE_LA4, NOTE_LA4, 0, 
   NOTE_LA4, NOTE_DO5, NOTE_RE5, NOTE_RE5, 0, 
   NOTE_RE5, NOTE_MI5, NOTE_FA5, NOTE_FA5, 0,
   NOTE_MI5, NOTE_RE5, NOTE_MI5, NOTE_LA4, 0,
   
   NOTE_LA4, NOTE_SI4, NOTE_DO5, NOTE_DO5, 0, 
   NOTE_RE5, NOTE_MI5, NOTE_LA4, 0, 
   NOTE_LA4, NOTE_DO5, NOTE_SI4, NOTE_SI4, 0,
   NOTE_DO5, NOTE_LA4, NOTE_SI4, 0,

   NOTE_MI5, 0, 0, NOTE_FA5, 0, 0,
   NOTE_MI5, NOTE_MI5, 0, NOTE_SOL5, 0, NOTE_MI5, NOTE_RE5, 0, 0,
   NOTE_RE5, 0, 0, NOTE_DO5, 0, 0,
   NOTE_SI4, NOTE_DO5, 0, NOTE_SI4, 0, NOTE_LA4,

   NOTE_MI5, 0, 0, NOTE_FA5, 0, 0,
   NOTE_MI5, NOTE_MI5, 0, NOTE_SOL5, 0, NOTE_MI5, NOTE_RE5, 0, 0,
   NOTE_RE5, 0, 0, NOTE_DO5, 0, 0,
   NOTE_SI4, NOTE_DO5, 0, NOTE_SI4, 0, NOTE_LA4
};

//in tale vettore vi è l'intervallo di tempo per 
//cui ciascuna nota del vettore note[i] sarà prodotta.
int durata[] = {         
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125, 
  250, 125, 250, 125, 
  125, 125, 250, 125, 125,
  125, 125, 375, 375,

  250, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125, 
  250, 125, 250, 125, 
  125, 125, 250, 125, 125,
  125, 125, 375, 375,
  
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500,

  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500
};



void setup() {
              
//con lcd.begin si inizializzano le 
//righe e colonne di cui è composto il display          
  lcd.begin(16,2);


//con lcd.print si fa comparire il messaggio sulla 
//prima riga del display "Nota Usata : "
  lcd.print("Nota Usata : ");



}



void loop() {
int i; 
String n;
  
 for (int i=0;i<203;i++){ 
//con il comando switch si attua una conversione dei valori interi (da 0 a 7) 
//posti all'interno del vettore, in stringhe (Che corrisponderanno alle note /
/utilizzate)
  switch (noteusate[i]){
    case 0:
    n = "   ";
    break;
    case 1:
    n = "DO ";
    break;
    case 2:
    n = "RE ";
    break;
    case 3:
    n = "MI ";
    break;
    case 4:
    n = "FA ";
    break;
    case 5:
    n = "SOL";
    break;
    case 6:
    n = "LA ";
    break;
    case 7:
    n = "SI ";
    break;
  
    
  }              
  int attesa = durata[i] * velocitasuono;


//tone è la funzione che permette di generare il suono
 //tramite il cicalino, vi sono tre parametri formali,
 //il primo parametro costituisce il pin in cui è collegato il cicalino,
 //il secondo parametro è costituito dal vettore note (lo spartito) 
//e dalle relative frequenze //il terzo parametro è costituito dal periodo durante
 //il quale verrà prodotto ciascun suono.
  tone(buzzer,note[i],attesa); 
  

//l'intervallo di tempo in cui vengono prodotte due 
//note (la nota posta a indice i, e poi la nota posta a indice i+1)      
  delay(attesa); 


//tale funzione imposta la posizione del cursore, perciò dove il prossimo testo apparirà (nel 
// nostro caso colonna 0 e riga 1). Colonne e righe iniziano la numerazione da 0 e non 
// da 1. in questo caso è stata è stata selezionata la seconda riga
  lcd.setCursor(0, 1); 


//fa comparire sulla seconda riga dello schermo la nota riprodotta
 //in quel preciso istante di tempo t 
  lcd.print(n);   
  }


 // delay(2000) costituisce l'intervallo di tempo per cui
 //una volta terminato il brano lo ricomincerà da capo
  delay (2000);

  }
