//Created by aboda243
//Modified by Justin H. for Pioneers in Engineering
//Used in Pioneer in Engineering's battery display on PDB
//https://create.arduino.cc/projecthub/aboda243/how-to-use-4-digit-7-segment-without-library-b8e014

void reset() { 
  digitalWrite(D1, !mode);
  digitalWrite(D2, !mode);
  digitalWrite(D3, !mode);
  if (digits == 4) {
    digitalWrite(D4, !mode);
  }
  for(byte i = 0 ; i < 8 ; i++){
  digitalWrite(seg[i], mode); //mode = 1; for each segment, 1 = off and 0 = on
  }
}

void printDigit(char Chara, int digitPort) { 
  reset(); 
  int character = -1;
  digitalWrite(digitPort, mode);
  for(int i = 0 ; i < charsInArray ; i++) {
    if (Chara == Char[i][8]) { //set character equal to the corresponding array index
     character = i;
    }
  }
  for (int i = 0; i < 8; i++) { //iterate through each segment for the digit, setting on or off as defined by array.h
    if (mode == common_anode) {
      digitalWrite(seg[i],!Char[character][i]); 
    }   
    else if (mode == common_cathode) {
      digitalWrite(seg[i], Char[character][i]);
      
    }
  }
}

char convert(char number) { //converts input char to another char
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  return alphabet.charAt(number);
}

void printDisplay(String Phrase, int Delay) { //no scrolling
  int stringLength = Phrase.length();
  int delay_factor = digits * 2;
  char char1 = ' ';
  char char2 = ' ';
  char char3 = ' ';
  int decimal_pos = -1;
  if (digits == 4) {
    char char4 = ' ';
  }

  for(int ti = 0 ; ti <= (Delay / delay_factor) ; ti++) { //continously flashes characters for DELAY duration
    for (int i = 0; i < digits; i++) {
      if (Phrase.charAt(i) == '.') {
        stringLength -= 1;
        decimal_pos = i + 1;
      }
    }

    if (1 <= stringLength && i != decimal_pos) {
      char1 = Phrase.charAt(0);
    } else if (1 <= stringLength) {
      char1 = convert(Phrase.charAt(0)) //!!!! MUST UPDATE ARRAY FILE
    }

    if (2 <= stringLength && i != decimal_pos) {
      char2 = Phrase.charAt(1);
    } else if (2 <= stringLength) {
      char2 = convert(Phrase.charAt(1)) //!!!! MUST UPDATE ARRAY FILE
    }
    
    if (3 <= stringLength && i != decimal_pos) {
      char3 = Phrase.charAt(2);
    } else if (3 <= stringLength) {
      char3 = convert(Phrase.charAt(2)) //!!!! MUST UPDATE ARRAY FILE
    }
    if (digits == 4) {
      if (4 <= stringLength && i != decimal_pos) {
      char4 = Phrase.charAt(3)
      } else if (4 <= stringLength) {
      char4 = convert(Phrase.charAt(3)) //!!!! MUST UPDATE ARRAY FILE
      }
    }
    printDigit(char1, D1);
    delay(2);
    printDigit(char2, D2);
    delay(2);
    printDigit(char3, D3);
    delay(2);
    if (digits == 4) {
      printDigit(char4, D4);
      delay(2);
    }
  }
} 


