//Created by aboda243
//Modified by Justin H. for Pioneers in Engineering
//Used in Pioneer in Engineering's battery display on PDB
//https://create.arduino.cc/projecthub/aboda243/how-to-use-4-digit-7-segment-without-library-b8e014


char convert(char number) { //converts input char to another char
  if (isdigit(number)) {
    String alphabet = "abcdefghijklmnopqrstuvwxyz";
    return alphabet.charAt((int) (number - '0'));
  } else {
    return number;
  }
}

String removeChar(String phrase, char remove) {
  String newPhrase = "    ";
  int k = 0;
  for (int i = 0; i < phrase.length(); i++) {
    if (phrase.charAt(i) != remove) {
      newPhrase[k] = phrase[i];
      k += 1;
    }
    if (k == 4) {
      break;
    }
  }
  return newPhrase;
}

String DisplayChars(String Phrase) { //no scrolling
  int stringLength = Phrase.length();
  int delay_factor = 4 * 2;
  int decimal_pos = -1;
  String toPrint = "    ";

  for (int i = 0; i < 4 + 1; i++) {
    if (Phrase.charAt(i) == '.') { //only supports 1 decimal point
      stringLength -= 1;
      decimal_pos = i;
      break;
    }
  }
  Phrase = removeChar(Phrase, '.');

  for(int i = 0; i < 4; i++) {
    if (i+1 <= stringLength && decimal_pos == i+1) {
      toPrint[i] = convert(Phrase[i]);
    } else if (i+1 <= stringLength) {
      toPrint[i] = Phrase[i];
    }
  }
  return toPrint;
}
