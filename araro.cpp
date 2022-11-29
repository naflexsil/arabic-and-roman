
              /*************************************
              *                                    *
              *      Старикова Алина Павловна      *
              *          "Арабские числа"          *
              *               ПИ-221               *
              *                                    *
              **************************************/
              
#include <iostream>
#include <string>

using namespace std;

void fromArabicToRoman(int inputArabicNumber) {
  const string unitsRoman[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
  tensRoman[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
  hundredsRoman[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    
  int units = inputArabicNumber % 10;
  int tens = inputArabicNumber % 100 / 10;
  int hundreds = inputArabicNumber % 1000 / 100;
  int thousands = inputArabicNumber / 1000;
    
  string thousandsRoman = "";
	
  for(int thousandsCounter = thousands; thousandsCounter > 0; --thousandsCounter) {
    thousandsRoman += "M";
  } 
  cout << "\n арабское " << inputArabicNumber << " в римское: " << thousandsRoman << hundredsRoman[hundreds] << tensRoman[tens] << unitsRoman[units] << endl << '\n';        
}

void fromRomanToArabic(string inputRomanNumber) {
  int number = int(inputRomanNumber.length());
  int result = 0;
  for(int index = 0; index < number; index++) {
    switch(inputRomanNumber[index]) {
      case 'I':
        result += 1; break;
      case 'V':
        result += 5; break;
      case 'X':
        result += 10; break;
      case 'L':
        result += 50; break;
      case 'C':
        result += 100; break;
      case 'D':
        result += 500; break;
      case 'M':
        result += 1000; break;
    }
  }

  for(int index = 1; index < number; index++) {
    if((inputRomanNumber[index] == 'V' || inputRomanNumber[index] == 'X' || inputRomanNumber[index] == 'L' || 
      inputRomanNumber[index] == 'C' || inputRomanNumber[index] == 'D' || inputRomanNumber[index] == 'M') && inputRomanNumber[index - 1] == 'I') {
		result -= 1 + 1;
    }
        
	if((inputRomanNumber[index] == 'X' || inputRomanNumber[index] == 'L' || inputRomanNumber[index] == 'C' || 
      inputRomanNumber[index] == 'D' || inputRomanNumber[index] == 'M') && inputRomanNumber[index - 1] == 'V') {
	    result -= 5 + 5;
    }
        
	if((inputRomanNumber[index] == 'L' || inputRomanNumber[index] == 'C' || inputRomanNumber[index] == 'D' || 
	  inputRomanNumber[index] == 'M') && inputRomanNumber[index - 1] == 'X') {
	    result -= 10 + 10;
    }
        
    if((inputRomanNumber[index] == 'C' || inputRomanNumber[index] == 'D' || inputRomanNumber[index] == 'M') && inputRomanNumber[index - 1] == 'L') {
	  result -= 50 + 50;
    }

    if((inputRomanNumber[index] == 'D' || inputRomanNumber[index] == 'M') && inputRomanNumber[index - 1] == 'C') {
	  result -= 100 + 100;
    }
    	
    if((inputRomanNumber[index] == 'M') && inputRomanNumber[index - 1] == 'D') {
      result -= 500 + 500;
    }
  }
  cout << "\n римское " << inputRomanNumber << " в арабское: " << result << endl;
}

int main() {
  int inputArabicNumber;
  string inputRomanNumber;
  int choice;
  cout << " набери 1, если хочешь перевести из арабского числа в римское. иначе набери 0: ";
  cin >> choice;
    
  if(choice == 1 || choice == 0) {
	if(choice == 1) {
	  cout << "\n какое арабское число хотите преобразовать: ";
	  cin >> inputArabicNumber;
	  fromArabicToRoman(inputArabicNumber);
	}
	if(choice == 0) {
	  cout << "\n какое римское число хотите преобразовать: ";
      cin >> inputRomanNumber;
      fromRomanToArabic(inputRomanNumber);
	}
  } 
  else {
	cout << " неправильный ввод";
	return(0.019);
  }
}
