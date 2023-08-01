#include <iostream>
#include <vector>

#define OFFSET 2

using namespace std;

enum {HELLO, FLOURINE, CHLORINE, BROMINE, IODINE, METHYL, ETHYL, PROPYL, BUTYL};

class Carbon {
  public:
		int Hnum;
		int substituent[4];
};

class Hydrocarbon {
  public:
		std::vector<Carbon> chain;
};

Hydrocarbon CreateHydrocarbon(){
  Hydrocarbon hydrocarbon;
	Carbon normCarbon;
	Carbon endCarbon;
	normCarbon.Hnum = 2;
	endCarbon.Hnum = 3;
	int a;
	cout << "How Many Carbons?\n>";
	cin >> a;
	a = a -2;
	hydrocarbon.chain.push_back(endCarbon);
	for (int i = 0; i < a; i++){
    hydrocarbon.chain.push_back(normCarbon);
	}
	hydrocarbon.chain.push_back(endCarbon);
	for (int i = 0; i < hydrocarbon.chain.size(); i++){
    hydrocarbon.chain[i].substituent[0] = 0;
		hydrocarbon.chain[i].substituent[2] = 0;
	}
	return hydrocarbon;
}

void printNameSubs(int subs[]){
  for (int i = 0; i < 10; i++){
    
	}
}

void printName(Hydrocarbon molecule){
	int subs[10];
  for (int i = 0; i < molecule.chain.size(); i++){
    if (molecule.chain[i].substituent[0] != 0){
      subs[molecule.chain[i].substituent[0]]++;
		}
		if (molecule.chain[i].substituent[2] != 0){
		  subs[molecule.chain[i].substituent[2]]++;
		}
	}
}

Hydrocarbon Halogenate(Hydrocarbon molecule, int reagent){
	bool found = false;
  for (int i = 0; i < molecule.chain.size(); i++){
    if (molecule.chain[i].substituent[0] == 0 && molecule.chain[i].Hnum != 3 && found != true){
      molecule.chain[i].substituent[0] = reagent;
			found = true;
		}
		if (molecule.chain[i].substituent[2] == 0 && molecule.chain[i].Hnum != 3 && found != true){
      molecule.chain[i].substituent[2] = reagent;
			found = true;
		}
	}
	return molecule;
}

Hydrocarbon Alkylate(Hydrocarbon molecule, int reagent){
	bool found = false;
  for (int i = 0; i < molecule.chain.size(); i ++){
	  if (molecule.chain[i].substituent[0] == 0 && molecule.chain[i].Hnum != 3 && found != true){
      molecule.chain[i].substituent[0] = reagent + 4;
			found = true;
		}
		if (molecule.chain[i].substituent[2] == 0 && molecule.chain[i].Hnum != 3 && found != true){
      molecule.chain[i].substituent[2] = reagent + 4;
			found = true;
		}
	}
	return molecule;
}

void printSub(int sub){
  switch (sub){
	  case FLOURINE:
			cout << "F    ";
			break;
		case CHLORINE:
			cout << "Cl   ";
			break;
		case BROMINE:
			cout << "Br   ";
			break;
		case IODINE:
			cout << "I    ";
			break;
		case METHYL:
			cout << "Me   ";
			break;
		case ETHYL:
			cout << "Et   ";
			break;
		case PROPYL:
			cout << "Pr   ";
			break;
		case BUTYL:
			cout << "Bu   ";
			break;
		case 0:
			cout << "H    ";
	}
}

void print(Hydrocarbon chem){
	int realNum = chem.chain.size() - 1;
  int topC = 0;

  for (int i = 0; i < realNum; i++){
    topC += 1;
	}
	topC += 1;

	cout << "     ";

  for (int i = 0; i < topC; i++){
    printSub(chem.chain[i].substituent[0]);
	}
	//cout << "H    ";
	cout << "\n     ";
	for (int i = 0; i < topC; i++){
    cout << "|    ";
	}
  cout << "\n";
	cout << "H----";
	for (int i = 0; i < realNum; i++){
    cout << "C----";
	}
	cout << "C";
	if (chem.chain[chem.chain.size() - 1].Hnum == 3)
		cout << "----H";
	cout << "\n     ";
	for (int i = 0; i < topC; i++){
	  cout << "|    ";
	}
	cout << "\n     ";
	for (int i = 0; i < topC; i++){
    printSub(chem.chain[i].substituent[2]);
	}
	cout << "\n";
}

int main(){
	int choice;
  cout << "Options\n";
	cout << "1: Creat Hydrocarbon";
  cin >> choice;
	if (choice == 1){
    Hydrocarbon molecule = CreateHydrocarbon();
		print(molecule);
		while (1){
		  cout << "Reactions:\n";
			cout << "1: Halogenation\n>";
			cout << "2: Alkylation\n";
			cin >> choice;
			switch (choice){
        case 1:
          cout << "Reagents:\n";
				  cout << "1: HF\n2: HCl\n3: HBr\n4: HI\n";
				  cout << ">";
				  cin >> choice;
				  molecule = Halogenate(molecule, choice);
					print(molecule);
					break;
				case 2:
          cout << "Reagents:\n";
					cout << "1: BrCH3\n2: BrC2H5\n3: BrC3H7\n4: BrC4H9\n>";
					cin >> choice;
					molecule = Alkylate(molecule, choice);
					print(molecule);
					break;
			}
		}
	}
}
