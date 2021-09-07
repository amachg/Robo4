// Αρχείο Score4_AI.ino με την τεχνητή ευφυΐα του παιχνιδιού Σκορ-4

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Επιτραπέζιο παιχνίδι Σκορ-4 για ρομποτικό βραχίονα Arduino Braccio
// Γλώσσα προγραμματισμού C++11 (χωρίς STL και streams)
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "Braxionas.h"      // Οι τοποθετήσεις των πουλιών από τον βραχίονα

constexpr int grammes{ 6 };
constexpr int stiles{ 7 };
constexpr int plithos_theseon{ grammes * stiles };
constexpr int plithos_nikis{ 4 };

constexpr int akrodekteses[stiles] = {14,15,16,17,18,19,20};

constexpr int katofliVathous{ //11  για release PC
                              // 9  για debug PC
                              5 // για Arduino Mega
                              //plithos_theseon για supercomputer
};
constexpr int katofliXronou(5000); //millisec
int ekarksiXronouAnazitisis;

constexpr int megistiAksia{ plithos_theseon / 2 };
constexpr int elaxistiAksia{ -plithos_theseon };

// Οι κεντρικότερες στήλες είναι πιθανότερα οι καλύτερες, λόγω περισσοτέρων δυνατών συνδυασμών.
constexpr int seiraEksetasisStilon[stiles]{ 4, 3, 5, 2, 6, 1, 7 };

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Τα χρώματα των πουλιών της πίστας

enum struct Xroma : char { // char για 8 bit μνήμης
  Keno    = ' ',
  Kokkino = 'R',
  Kitrino = 'Y'
};

Xroma xromaAntipalou(const Xroma xroma) {  // προϋπόθεση το xroma να μην είναι Κενό.
  return xroma == Xroma::Kokkino ? Xroma::Kitrino : Xroma::Kokkino;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Η εξωτερικές συντεταγμένες μιας θέσης πουλιού στην πίστα

struct Thesi {
  Thesi() : grammi{ 0 }, stili{ 0 } {}
  Thesi(const int g, const int s) : grammi{ g }, stili{ s } {}
  bool operator!=(const Thesi& th) const {return grammi != th.grammi || stili != th.stili;}
  
  int grammi, stili;   // Οι εξωτερικοί αριθμοί γραμμής/στήλης, δηλαδή 1 έως 6 και 1 έως 7.
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class Pista {
public:
	enum /*struct*/ Tetrada {
		Kammia = 0,	// Σημαίνει ότι δεν υπάρχει τετράδα, αλλά γέμισε η πίστα.
		Orizontia,
		Katheta,
		Diagonia,
		Antidiagonia,
		KammiaAllaGemise
	};

  void theseXroma(const Thesi& thesi, const Xroma xroma);	// βάλε το παίξιμο

  void adeiaseTin(const Thesi& thesi);    // ακύρωσε το παίξιμο
  
  bool einaiKeniThesi(const Thesi& thesi) const {return exeiXroma(thesi, Xroma::Keno);}

  Thesi xamiloteroKeno(const int stili) const;

  bool miposGemise() const {return ypoloipaKena == 0;}
  
	int posesKenes() const { return ypoloipaKena; }

  // Αποφάσισε αν έχει ήδη γίνει τετράδα και πού.
  Tetrada kaneiTetrada(const Thesi& elegxomeniThesi, const Xroma xroma) const;

	Thesi psakseGiaTetrada(const Xroma xroma) const;  // Δοκίμασε μήπως γίνεται τετράδα

  int vresTyxaiaStiliMeKeno() const;            // Διάλεξε τυχαία μια από τις κενές θέσεις.

  // Φέρε το παιγμένο πούλι στη σχισμή στη στήλη της πίστας.
  void vraxionasPaizeiPouli(const int stili) const;

  void sxediaseStiSeiriaki() const;
  
  Pista();
  Pista(const String& arxikiKatastasi);

	// Ευκαιρίες για τετράδα ενός χρώματος, ανά πλήθος των χρωματιστών θέσεων
	mutable int efkairies[plithos_nikis]{};
	// Στατική εκτίμηση των ευκαιριών νίκης συμβόλου. 
	int ektimiseEfkairiesTetradas(const Xroma xroma) const;

private:
  // Η πίστα σε γραμμές και στήλες με εσωτερικούς αριθμούς θέσης, δηλαδή 0 έως 5 & 0 έως 6.
  // Σε κάθε πρόσβαση αφαιρείται μια μονάδα από τους πραγματικούς αριθμούς θέσης.
  Xroma koutakia[grammes][stiles];
  int ypoloipaKena{ plithos_theseon };

  Xroma pareXroma(const Thesi& thesi) const {return koutakia[thesi.grammi - 1][thesi.stili - 1];}

  bool exeiXroma(const Thesi& thesi, const Xroma xroma) const {return pareXroma(thesi) == xroma;}

	// Έλεγχος στις ευθείες της πίστας.
	inline void efkairiesGrammon(const Xroma xroma) const;
	inline void efkairiesStilon(const Xroma xroma) const;
	inline void efkairiesDiagon(const Xroma xroma) const;
	inline void efkairiesAntiDiag(const Xroma xroma) const;

  // Συνάρτηση ανάκλησης (callback) με την οποία ο βραχίονας φέρνει το πούλι στην ανάλογη στήλη.
  typedef void (*ValePouli)();
  ValePouli valePouli[stiles] = {valePouli1, valePouli2, valePouli3, valePouli4, valePouli5, valePouli6, valePouli7};
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Pista::Pista() {
  for (int grammi{ 1 }; grammi <= grammes; ++grammi)
    for (int stili{ 1 }; stili <= stiles; ++stili)
      koutakia[grammi - 1][stili - 1] = Xroma::Keno;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Pista::Pista(const String& arxikesRipseis) : Pista() {
	// Το κόκκινο ξεκινά πάντα πρώτο, το κίτρινο δεύτερο και εναλλάξ.
	auto xroma{ Xroma::Kokkino };
	for (auto xaraktirasStilis : arxikesRipseis) {
		const int stili = xaraktirasStilis - '0';
		theseXroma( xamiloteroKeno(stili), xroma );
		xroma = xromaAntipalou(xroma);
	}
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Pista::theseXroma(const Thesi& thesi, const Xroma xroma) {
  // Βάλε το παιγμένο σύμβολο στο ανάλογο κουτάκι. Προϋπόθεση είναι να είναι η θέση κενή.
  koutakia[thesi.grammi - 1][thesi.stili - 1] = xroma ;
  --ypoloipaKena;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Pista::adeiaseTin(const Thesi& thesi) {
  // Προϋπόθεση είναι να είναι η θέση γεμάτη.
  koutakia[thesi.grammi - 1][thesi.stili - 1] = Xroma::Keno;
  ++ypoloipaKena;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Thesi Pista::xamiloteroKeno(const int stili) const {  
  // Προϋπόθεση είναι η ύπαρξη κενής θέσης στη στήλη.
     
    for (auto grammi{ grammes }; 1 <= grammi; --grammi) {
        const Thesi thesi{ grammi, stili };
        if (einaiKeniThesi(thesi))
            return thesi;
    }

    return {0,0};  
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Αποφάσισε αν γίνεται τετράδα με την (υποτιθέμενη;) τοποθέτηση πουλιού χρώματος στη θέση.
// Επιστρέφει τον κωδικό της τετράδας (αληθής) ή το 0 (ψευδής).
// Η ελεγχόμενη_θέση και το χρώμα χρειάζονται για λιγότερους ελέγχους (μόνο γύρω από τη θέση).

Pista::Tetrada Pista::kaneiTetrada(const Thesi& elegxomeniThesi, const Xroma xroma) const {
	const int elGr{elegxomeniThesi.grammi};
	const int elSt{elegxomeniThesi.stili};

	int metritisPoulion{ 1 };		// Περιλαμβάνει το (υποτιθέμενο;) πούλι της θέσης.
  
	// έλεγξε τη elGr του παιξίματος για διαδοχικά όμοια σύμβολα, προς τα αριστερά & δεξιά
	metritisPoulion = 1;
	for (auto j{ elSt - 1 }; 1 <= j && exeiXroma( { elGr, j }, xroma); --j)
		++metritisPoulion;
	for (auto j{ elSt + 1 }; j <= stiles && exeiXroma( { elGr, j }, xroma); ++j)
		++metritisPoulion;
	if (metritisPoulion >= plithos_nikis)
		return Orizontia;  // τετράδα στη elGr 
	
	// έλεγξε τη elSt του παιξίματος διαδοχικά όμοια σύμβολα, προς τα πάνω & προς τα κάτω
	metritisPoulion = 1;
	for (auto i{ elGr - 1 }; 1 <= i && exeiXroma( { i, elSt }, xroma); --i)
		++metritisPoulion;
	for (auto i{ elGr + 1 }; i <= grammes && exeiXroma( { i, elSt }, xroma); ++i)
		++metritisPoulion;
	if (metritisPoulion >= plithos_nikis)
		return Katheta;  // τετράδα στη elSt
	
	// έλεγξε τη διαγώνιο του συμβόλου προς τα πάνω-αριστερά & προς τα κάτω-δεξιά
	metritisPoulion = 1;
	for (auto j{ elSt - 1 }, i{ elGr - 1 };
		1 <= j && 1 <= i && exeiXroma( { i, j }, xroma); --j, --i)
		++metritisPoulion;
	for (auto j{ elSt + 1 }, i{ elGr + 1 };
		j <= stiles && i <= grammes && exeiXroma( { i, j }, xroma); ++j, ++i)
		++metritisPoulion;
	if (metritisPoulion >= plithos_nikis)
		return Diagonia;  // τετράδα στη διαγώνιο
  
	// έλεγξε τη αντιδιαγώνιο του συμβόλου προς τα κάτω-αριστερά & προς τα πάνω-δεξιά
	metritisPoulion = 1;
	for (auto j{ elSt - 1 }, i{ elGr + 1 };
		1 <= j && i <= grammes && exeiXroma( { i, j }, xroma); --j, ++i)
		++metritisPoulion;
	for (auto j{ elSt + 1 }, i{ elGr - 1 };
		j <= stiles && 1 <= i && exeiXroma( { i, j }, xroma); ++j, --i)
		++metritisPoulion;
	if (metritisPoulion >= plithos_nikis)
		return Antidiagonia;   // τετράδα στην αντιδιαγώνιο

	return Kammia;    // δεν έχει γίνει τετράδα
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Thesi Pista::psakseGiaTetrada(const Xroma xroma) const {
  // Σε κάθε στήλη με κενό, δοκίμασε αν γίνεται τετράδα συμπληρώνοντας το κατώτερο κενό
  // της στήλης. Αν ναι επίστρεψε το τετραδάτο παίξιμο, αλλιώς το άκυρο παίξιμο.
  
  for (int stili{ 1 }; stili <= stiles; ++stili) {
      if (einaiKeniThesi({ 1, stili })) { //αν υπάρχει κενό στη στήλη
          const Thesi thesi{ xamiloteroKeno(stili) };
          if (kaneiTetrada( thesi, xroma ))
              return thesi;         // επιστρέφει την θέση που κάνει τετράδα
      }
  }

  return { 0, 0 }; // Το σύμβολο δεν κάνει τετράδα σε κανένα κενό κουτάκι, επίστρεψε άκυρη θέση.
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Pista::vraxionasPaizeiPouli(const int stili) const {
  pareApoGlystra();
  valePouli[ stili - 1 ]();
  orthiosBraxionas(); 
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Pista::sxediaseStiSeiriaki() const {
  for (auto j = 1; j <= stiles; ++j)
    Serial.print(String("   ") + j);
  Serial.println();

  Serial.print(" |");
  for (auto j = 1; j <= stiles; ++j)
    Serial.print("---+");
  Serial.println();

  for (auto i = 1; i <= grammes; ++i) {
    Serial.print(i);
    for (auto j = 1; j <= stiles; ++j)
      Serial.print(String("| ") + static_cast<char>(pareXroma({ i,j })) + " ");
    Serial.println("|");
    Serial.print(" |");
    for (auto j = 1; j <= stiles; ++j)
      Serial.print("---+");
    Serial.println("");
  }
  Serial.println();
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Pista::efkairiesGrammon(const Xroma xromaAnaforas) const {
	for (int grammi{ 1 }; grammi <= grammes; ++grammi) { // Γίνεται και με διπλή std::find_if
		for (int stiliArxisSeiras{ 1 }; stiliArxisSeiras <= stiles - 3; ++stiliArxisSeiras) {
			int metritisXromatos{}, metritisSeiras{};
			int apostApoArxi{ 0 };
			for (; apostApoArxi <= 3; ++apostApoArxi) {
				const auto xroma{ pareXroma({ grammi, stiliArxisSeiras + apostApoArxi }) };
				if (xroma == xromaAntipalou(xromaAnaforas)) break;
				if (xroma == xromaAnaforas) ++metritisXromatos;
				++metritisSeiras;
			}
			if (metritisSeiras >= 4) ++efkairies[metritisXromatos];
		}
	}
}
void Pista::efkairiesStilon(const Xroma xromaAnaforas) const {
	for (int stili{ 1 }; stili <= stiles; ++stili) {
		for (int grammiArxisSeiras{ 1 }; grammiArxisSeiras <= grammes - 3; ++grammiArxisSeiras) {
			int metritisXromatos{}, metritisSeiras{};
			int apostApoArxi{ 1 };
			for (; apostApoArxi <= 4; ++apostApoArxi) {
				const auto xroma{ pareXroma({ grammiArxisSeiras + apostApoArxi - 1, stili }) };
				if (xroma == xromaAntipalou(xromaAnaforas)) break;
				if (xroma == xromaAnaforas) ++metritisXromatos;
				++metritisSeiras;
			}
			if (metritisSeiras >= 4) ++efkairies[metritisXromatos];
		}
	}
}
void Pista::efkairiesDiagon(const Xroma xromaAnaforas) const {
	// Άνω δευτερεύουσες διαγώνιοι με αρχή, από το 2ο στοιχείο της πρώτης grammiς έως και το 7ο.
	for (int stiliEnarksisDiag{ 2 }; stiliEnarksisDiag <= stiles - 3; ++stiliEnarksisDiag) {
		const auto mikosDiagoniou{ 6 - stiliEnarksisDiag + 2 };
		for (int apostArxisSeiras{ 0 }; apostArxisSeiras <= mikosDiagoniou - 4; ++apostArxisSeiras) {
			int metritisXromatos{}, metritisSeiras{};
			int apostApoArxi{ 0 };
			for (; apostApoArxi <= 3; ++apostApoArxi) {
				const auto xroma{ pareXroma({   1 + apostArxisSeiras + apostApoArxi,
								stiliEnarksisDiag + apostArxisSeiras + apostApoArxi }) };
				if (xroma == xromaAntipalou(xromaAnaforas)) break;
				if (xroma == xromaAnaforas) ++metritisXromatos;
				++metritisSeiras;
			}
			if (metritisSeiras >= 4) ++efkairies[metritisXromatos];
		}
	}	
	// Κύρια διαγώνιος. Και κάτω δευτερεύουσες διαγώνιοι με αρχή, από 2ο στοιχείο της πρώτης stiliς έως και το 6ο.
	for (int grammiEnarksis{ 1 }; grammiEnarksis <= grammes - 3; ++grammiEnarksis) {
		const auto mikosDiagoniou{ 6 - grammiEnarksis + 1 };
		for (int apostArxisSeiras{ 0 }; apostArxisSeiras <= mikosDiagoniou - 4; ++apostArxisSeiras) {
			int metritisXromatos{}, metritisSeiras{};
			int apostApoArxi{ 0 };
			for (; apostApoArxi <= 3; ++apostApoArxi) {
				const auto xroma{ pareXroma({ grammiEnarksis + apostArxisSeiras + apostApoArxi,
															1 + apostArxisSeiras + apostApoArxi }) };
				if (xroma == xromaAntipalou(xromaAnaforas)) break;
				if (xroma == xromaAnaforas) ++metritisXromatos;
				++metritisSeiras;
			}
			if (metritisSeiras >= 4) ++efkairies[metritisXromatos];
		}
	}
}
void Pista::efkairiesAntiDiag(const Xroma xromaAnaforas) const {
	// Άνω δευτερεύουσες αντιδιαγώνιοι με αρχή, από 4ο & 5ο στοιχείο της πρώτης stiliς. Και κύρια αντιδιαγώνιος στο 6ο.
	for (int grammiEnarksis{ 4 }; grammiEnarksis <= grammes; ++grammiEnarksis) {
		const auto mikosDiagoniou{ grammiEnarksis };
		for (int apostArxisSeiras{ 0 }; apostArxisSeiras <= mikosDiagoniou - 4; ++apostArxisSeiras) {
			int metritisXromatos{}, metritisSeiras{};
			int apostApoArxi{ 0 };
			for (; apostApoArxi <= 3; ++apostApoArxi) {
				const auto xroma{ pareXroma({ grammiEnarksis - apostArxisSeiras - apostApoArxi,
															1 + apostArxisSeiras + apostApoArxi }) };
				if (xroma == xromaAntipalou(xromaAnaforas)) break;
				if (xroma == xromaAnaforas) ++metritisXromatos;
				++metritisSeiras;
			}
			if (metritisSeiras >= 4) ++efkairies[metritisXromatos];
		}
	}
	// Κάτω δευτερεύουσες αντιδιαγώνιοι με αρχή, από το 2ο στοιχείο της τελευταίας grammiς έως και το 4ο.
	for (int stiliEnarksisDiag{ 2 }; stiliEnarksisDiag <= stiles - 3; ++stiliEnarksisDiag) {
		const auto mikosDiagoniou{ 6 - stiliEnarksisDiag + 2 };
		for (int apostArxisSeiras{ 0 }; apostArxisSeiras <= mikosDiagoniou - 4; ++apostArxisSeiras) {
			int metritisXromatos{}, metritisSeiras{};
			int apostApoArxi{ 0 };
			for (; apostApoArxi <= 3; ++apostApoArxi) {
				const auto xroma{ pareXroma({	 6 - apostArxisSeiras - apostApoArxi,
								stiliEnarksisDiag + apostArxisSeiras + apostApoArxi }) };
				if (xroma == xromaAntipalou(xromaAnaforas)) break;
				if (xroma == xromaAnaforas) ++metritisXromatos;
				++metritisSeiras;
			}
			if (metritisSeiras >= 4) ++efkairies[metritisXromatos];
		}
	}
}
int Pista::ektimiseEfkairiesTetradas(const Xroma xromaAnaforas) const {
// Η εκτίμηση του πλήθους των ευκαιριών μελλοντικής νίκης του χρώματος αναφοράς.
// Δηλαδή, σε γραμμές, στήλες και διαγώνιους, αρίθμησε το πλήθος των χώρων που ο καθένας τους
// περιλαμβάνει ικανά σύμβολα & κενά ώστε να μπορεί να προκύψει σ' αυτόν μια τετράδα.
// Ο δείκτης '0' αντιστοιχεί σε εντελώς κενούς χώρους.
	for(auto& e : efkairies) e=0;
	// Έλεγχος στην ευθεία της κάθε γραμμής.
	efkairiesGrammon(xromaAnaforas);
	// Έλεγχος στην ευθεία της κάθε στήλης.
	efkairiesStilon(xromaAnaforas);
	// Έλεγχος στην ευθεία της κάθε διαγώνιου
	efkairiesDiagon(xromaAnaforas);
	// Έλεγχος στην ευθεία της κάθε αντιδιαγώνιου
	efkairiesAntiDiag(xromaAnaforas);
	// Άθροισε τις ευκαιρίες ανά πλήθος συμβόλων με ανάλογα βάρη.
	double stathmismenes{ 0 };
	// Εκτίμηση(κατάστασης πίστας) = 10*X3 + .5*X2 + .2*X1 + .1*X0
	stathmismenes += 0.1 * efkairies[0];
	stathmismenes += 0.2 * efkairies[1];
	stathmismenes += 0.5 * efkairies[2];
	stathmismenes +=  10 * efkairies[3];
	//std::cout << " Ευκ(" ;
	//for (int plithosXromatonSeiras{ 0 }; plithosXromatonSeiras <= plithos_nikis - 1; ++plithosXromatonSeiras) {
	//	std::cout << xromaAnaforas << plithosXromatonSeiras << ':' << efkairies[plithosXromatonSeiras] << " ";
	//}
	//std::cout << "\b)=" << stathmismenes << '\n';

	return static_cast<int>(stathmismenes);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
class Agonas {
public:
	int ripseonAA{};
	void paikseMexriTelous();
  Agonas(const String& arxikesRipseis);
	Agonas() : Agonas("") {}
private:
	Pista::Tetrada paikseGyro();
	void typoseApotelesma(const Pista::Tetrada apotelesma, const Thesi thesi) const;

	Thesi pareThesisApoPliktrologio() const;  
	int vresStiliApoAisthitires() const;
	// επίπεδα: 1. τύχη / 2. επόμενη τετράδα / 3. Negamax Άλφα-Βήτα
	Thesi vresTyxaiaKeni() const;
	Thesi vresEyretika();
	Thesi vresMeNegamaxAB();  
  
	Pista pista;
	Xroma trexonXroma{};
	Thesi trexousaThesi{};
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Agonas::Agonas(const String& arxikesRipseis) : pista(arxikesRipseis) {
  // Ο τυχαίος θόρυβος του ασύνδετου αναλογικού πιν 1 παράγει διαφορετικούς τροφοδότες αριθμούς.
  randomSeed(analogRead(1));
  //srand(static_cast<unsigned>(time(NULL)));

	ripseonAA = arxikesRipseis/*.size*/.length()+ 1;

	// Το χρώμα του πουλιού που έπαιξε τελευταίο.
	trexonXroma = (arxikesRipseis/*.size*/.length() % 2 == 0) ? Xroma::Kokkino : Xroma::Kitrino;
	//trexonXroma = Xroma::Kokkino;// Το χρώμα που ξεκινάει ΠΑΝΤΑ πρώτο είναι το ΚΟΚΚΙΝΟ.
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Agonas::paikseMexriTelous() {
  Serial.println(F("NEO PAIXNHDI! PROTOS PAIZEI O XRHSTHS ME TA KOKKINA...") );
    pista.sxediaseStiSeiriaki();

	auto apotelesma{ Pista::Kammia };
	while (true) {		// Παίξε μέχρι να τελειώσει ο αγώνας με ένα αποτέλεσμα.
		if (apotelesma = paikseGyro())	// Δεν τελείωσε (false), αποτελέσμα (true).
			break;
		// Αλλιώς συνέχισε με τον επόμενο παίκτη με αλλαγή σειράς.
		trexonXroma = (trexonXroma == Xroma::Kitrino) ? Xroma::Kokkino : Xroma::Kitrino;
	}
	typoseApotelesma(apotelesma, trexousaThesi);	// Έχει τελειώσει ο αγώνας.
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Pista::Tetrada Agonas::paikseGyro() {
// Άν έχει σειρά να παίξει ο άνθρωπος (με τα κόκκινα πούλια), ανίχνευσε τη θέση που έριξε το πούλι.
// Αλλιώς, αν έχει σειρά να παίξει ο υπολογιστής (με τα κίτρινα πούλια), ζήτα τη θέση από το ΑΙ.
	if (trexonXroma == Xroma::Kokkino) {
		trexousaThesi = 
			pista.xamiloteroKeno(vresStiliApoAisthitires());
			//pareThesisApoPliktrologio();
			//vresTyxaiaKeni();
			//vresEyretika();
			//vresMeNegamaxAB();
	}
	else { // Xroma::Kitrino
		trexousaThesi = vresMeNegamaxAB();
		pista.vraxionasPaizeiPouli(trexousaThesi.stili);
	}
	
	const auto posesKenes{ pista.posesKenes() };
	const auto posaMouMeneoun{ (posesKenes % 2 == 0) ? posesKenes / 2 : (posesKenes + 1) / 2 };
	Serial.println("\nRipsi #" + String(ripseonAA) + " (kena:"  + String(posesKenes) + ") PAIZEI TO: " 
	 + String(static_cast<char>(trexonXroma)) + " (menoun:"  + String(posaMouMeneoun) + ") STH STHLH: "
	 + String(trexousaThesi.stili) + '\n');
	  
  //Serial.println(String(static_cast<char>(trexonXroma)) + ": RIXNEI STH STHLH: " + trexousaThesi.stili);
  
	// Η επόμενηΘέση έχει ήδη ελεγχθεί ότι είναι ελεύθερη!
	pista.theseXroma(trexousaThesi, trexonXroma);
	++ripseonAA;
	pista.sxediaseStiSeiriaki();

	if (const auto apotelesma = pista.kaneiTetrada(trexousaThesi, trexonXroma))
		return apotelesma;					// Τέλος αγώνα, υπάρχει νικητής
	if (pista.miposGemise())
		return Pista::KammiaAllaGemise;		// Τέλος αγώνα, κωδικός ισοπαλίας

	return Pista::Kammia;					// ο αγώνας συνεχίζεται.
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Agonas::typoseApotelesma(const Pista::Tetrada apotelesma, const Thesi thesi) const {
	switch (apotelesma) {
		case Pista::Orizontia :
      Serial.println("NIKH GIA TA " + String(static_cast<char>(trexonXroma)) + " me tetrada stin " + String(thesi.grammi) + "h grammh!\n");
      return;
		case Pista::Katheta :
      Serial.println("NIKH GIA TA " + String(static_cast<char>(trexonXroma)) + " me tetrada stin " + String(thesi.stili) + "h stili!\n");
      return;
		case Pista::Diagonia :
      Serial.println("NIKH GIA TA " + String(static_cast<char>(trexonXroma)) + " me tetrada sti diagonio!\n");
      return;
		case Pista::Antidiagonia :
      Serial.println("NIKH GIA TA " + String(static_cast<char>(trexonXroma)) + " me tetrada stin antidiagonio!\n");
      return;
		case Pista::KammiaAllaGemise :
      Serial.println(F("OI PAIKTES HR8AN ISOPALOI!\n"));
  }
	Serial.println(".");
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Thesi Agonas::pareThesisApoPliktrologio() const {
  Serial.println("Arithmo Stilis pou tha riksete to pouli sas: ");
  do {
    if (Serial.available()) {
      String eiserxomeno {Serial.readStringUntil('\n')};
      eiserxomeno.trim();
      eiserxomeno.toLowerCase();
      const char c {eiserxomeno.charAt(0)};
      if (eiserxomeno.length() == 1
      && (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7')
      && pista.einaiKeniThesi( pista.xamiloteroKeno( c - '0') )
      ) {
        return pista.xamiloteroKeno( c - '0');
      }
      else
        Serial.println(F("Lathos thesi! Ksanaprospathiste..."));
    }
  } while (true);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int Agonas::vresStiliApoAisthitires() const {
  while (true) {
    //Σάρωνε τους αισθητήρες προσέγγισης μέχρι κάποιος από αυτούς να ανιχνεύσει ρίψη.
    for (int stili{ 1 }; stili <= stiles; ++stili) {
      if (digitalRead(akrodekteses[stili-1]) == LOW) {
        Serial.println("TO BLEPO STIN STHLH: " + String(stili));
        delay(10);
        while (true) {
          if(digitalRead(akrodekteses[stili-1]) == HIGH) {
            Serial.println("EPESE STIN STHLH: " + String(stili) + "\n");
            return stili;
          }
        }
      }
      delay(10);
    }
  }
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Thesi Agonas::vresTyxaiaKeni() const {
	int stilesMeKena[stiles]{ 0 };    // Λίστα των κενών στηλών της πίστας
	int plithosKenonStilon{ 0 };

	// Αποθήκευσε τις στήλες με κενά.
	for (int stili{ 1 }; stili <= stiles; ++stili) {
		if (pista.einaiKeniThesi( {1, stili} )) //αν υπάρχει κενό στη στήλη
			stilesMeKena[plithosKenonStilon++] = stili;
	}
	const auto stiliTyxaia = (plithosKenonStilon > 0) ?
		// Υπάρχουν κενές στήλες διάλεξε μια, τυχαία από 0 έως plithosKenonStilon-1.
		stilesMeKena[/*rand*/random() % plithosKenonStilon]
		: 0;     // Δε βρέθηκε κενή στήλη, επίστρεψε άκυρη.

	return pista.xamiloteroKeno(stiliTyxaia);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Thesi Agonas::vresEyretika() {
// Η ύπαρξη κενού είναι εγγυημένη προϋπόθεση.
	
	// Πρώτα προσπάθησε να κάνεις τετράδα.
	const Thesi thesiTetradasMou{ pista.psakseGiaTetrada(trexonXroma) };
	if (thesiTetradasMou != Thesi{ 0, 0 })
		return thesiTetradasMou;
	
	// Αλλιώς, προσπάθησε να εμποδίσεις τετράδα του αντίπαλου σου.
	// Βέβαια αν προσφέρω στον αντίπαλο πάτημα για τετράδα, θα χάσω στο επόμενό του.
	const Xroma antipalos{ xromaAntipalou(trexonXroma) };
	const Thesi thesiTetradasTou{ pista.psakseGiaTetrada(antipalos) };
	if (thesiTetradasTou != Thesi{ 0, 0 })
		return thesiTetradasTou;
	
	// Αλλιώς, διάλεξε τυχούσες διαθέσιμες θέσεις κατά την προκαθορισμένη αποστ_από_αρχή_σειράς εξέτασης.
	Thesi keniThesi{};
	for (const auto stili : seiraEksetasisStilon) {
		if (pista.einaiKeniThesi({ 1, stili })) {		// αν υπάρχει κενό κάπου στη στήλη
			keniThesi = pista.xamiloteroKeno(stili);

			// Αν προσφέρει στον αντίπαλο πάτημα για τετράδα, απόφυγέ την.
			if (1 < keniThesi.grammi) {
				pista.theseXroma(keniThesi, trexonXroma);		// παίξε προσωρινά
				const Thesi thesiAkrivosApoPano{ keniThesi.grammi - 1, stili };
				if (pista.kaneiTetrada(thesiAkrivosApoPano, antipalos)) {
					pista.adeiaseTin(keniThesi);      // ακύρωσε παίξιμο,
					continue;	// συνέχισε ο ψάξιμο για τυχούσα καλύτερη θέση.
				}
				pista.adeiaseTin(keniThesi);      // ακύρωσε παίξιμο
			}
			return keniThesi;
		}
	}
	return keniThesi; // Γύρισε την τελευταία κενή θέση ακόμα και είναι πάτημα για τον αντίπαλο!
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int aksiaNegamaxAB(Pista& pista, const Thesi& paigmeniThesi, const Xroma trexonXroma, 
int vathos, int a=0, int b=0) {
  const auto diarkeiaAnazitisis{ millis() - ekarksiXronouAnazitisis };

  // Αντίπαλος αντιπάλου είναι ο προηγούμενος παίκτης
  const auto antipalos{ xromaAntipalou(trexonXroma) };

  if (pista.kaneiTetrada( paigmeniThesi, antipalos )) {
      // Serial.println(F("Tetrada!"));
      // Πριμοδοτώ τις ταχύτερες νίκες, όπου η αξία της νίκης ισούται με υπόλοιπα πούλια 
      // του χρώματος μου, συν αυτό που έκανε την τετράδα.
		return -(static_cast<int>(pista.posesKenes() / 2 + 1));
  }
  if (pista.miposGemise()) {
      // Serial.println(F("Isopalia!"));
      return -0;
  }
  // Αν φθάνει το όριο του βάθους αναζήτησης ή ξεπερνά τη μέγιστη χρονική διάρκεια
	if (vathos >= katofliVathous || diarkeiaAnazitisis > katofliXronou) {
		// Αντίπαλος αντιπάλου είναι ο προηγούμενος παίκτης
		const int efkairiesMou{ pista.ektimiseEfkairiesTetradas(antipalos) };
		const int efkairiesTou{ pista.ektimiseEfkairiesTetradas(trexonXroma) };
		auto aksiaPaiksimatos{ (efkairiesMou - 3* efkairiesTou) /2 };
		// 3* διότι το επόμενο χρώμα πλεονεκτεί. /2 διότι αλλιώς είναι μεγάλο και αποκόπτει τις καλύτερες.
		if (vathos < katofliVathous)
		  Serial.println( " Αποκοπή σε βάθος:" + String(vathos) + ", ευκ.μου:" + efkairiesMou 
			+ " -3*ευκ.του:" + efkairiesTou  + " /2 " + aksiaPaiksimatos + '\n');
		const auto aksiaNikis{ static_cast<int>(pista.posesKenes() / 2 + 1) };
		aksiaPaiksimatos = max(-aksiaNikis+1, aksiaPaiksimatos);
		aksiaPaiksimatos = min( aksiaNikis-1, aksiaPaiksimatos);
		return -aksiaPaiksimatos;
  }

  // Αν υπάρχει κενό στη στήλη, παίξε προσωρινά, υπολόγισε την αξία και το ακύρωσε παίξιμο.
  for (const int stili : seiraEksetasisStilon) {
      if (pista.einaiKeniThesi({ 1, stili })) { // αν υπάρχει κενό στη στήλη
        const Thesi thesi{ pista.xamiloteroKeno(stili) };

        pista.theseXroma( thesi, trexonXroma );    // παίξε προσωρινά
        // Serial.println("Paizo: " + String(static_cast<char>(trexonXroma)) + "[" 
        //   + thesi.grammi + ", " + thesi.stili + "], vathos:" 
        //   + (vathos + 1) + ", [a,b]:" + a + ", " + b );

			  const auto aksiaPaiksimatos{-aksiaNegamaxAB(pista, thesi, antipalos, vathos+1, -b, -a)};

        // Serial.println("Score: " + String(static_cast<char>(trexonXroma)) + "[" 
        //   + thesi.grammi + ", " + thesi.stili + "] = " + aksiaPaiksimatos
        //   + ", plithosAksiologiseon:" + plithosAksiologiseon );
        pista.adeiaseTin(thesi);      // ακύρωσε παίξιμο

        // κλάδεμα α-β (alpha-beta pruning)
        a = max(a, aksiaPaiksimatos);
        if (a >= b)
            break;
      }
  }
  
  return a;
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 struct ThesiKaiAksia {
     Thesi thesi;
     int aksia;
 };

Thesi Agonas::vresMeNegamaxAB() {
  auto a{ elaxistiAksia };
  auto b{ megistiAksia };
  const Xroma antipalos{ xromaAntipalou(trexonXroma) }; 

  static ThesiKaiAksia theseisKaiAksies[stiles];
  int plithosAksiologimenonTheseon{ 0 };
  
  auto trexoysaMegistiAksia{ elaxistiAksia };
  ekarksiXronouAnazitisis = millis();
  
  // Αν υπάρχει κενό στη στήλη, παίξε προσωρινά, υπολόγισε την αξία και το ακύρωσε παίξιμο.
  for (int stili{ 1 }; stili <= stiles; ++stili) {
    if (pista.einaiKeniThesi({ 1, stili })) {
      const Thesi& thesi{ pista.xamiloteroKeno(stili) };
      
      pista.theseXroma( thesi, trexonXroma );
      Serial.println("PPaizo: " + String(static_cast<char>(trexonXroma)) + "[" 
        + thesi.grammi + ", " + thesi.stili + "], vathos:1, [a,b]:" 
        + a + ", " + b );

      const auto aksiaPaiksimatos{-aksiaNegamaxAB(pista, thesi, antipalos, 1, -b, -a)};

      Serial.println("SScore: " + String(static_cast<char>(trexonXroma)) + "[" 
        + thesi.grammi + ", " + thesi.stili + "] = " + aksiaPaiksimatos);
      pista.adeiaseTin(thesi);
      
      theseisKaiAksies[plithosAksiologimenonTheseon++] = {thesi, aksiaPaiksimatos};

      trexoysaMegistiAksia = max(aksiaPaiksimatos, trexoysaMegistiAksia);
    }
  }

  // φιλτράρισμα μόνο των καλύτερων θέσεων
  static Thesi kalyteresThesis[stiles];
  int plithosKalyteron{ 0 };
	for (const auto& thesiAksia : theseisKaiAksies)
		if (thesiAksia.aksia == trexoysaMegistiAksia)
			kalyteresThesis[plithosKalyteron++] = thesiAksia.thesi;
  
	//return kalyteresThesis[rand() % plithosKalyteron];	// τυχαία επιλογή από τις καλύτερες
	return kalyteresThesis[0];								// επιλογή πρώτης από τις καλύτερες
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void setup() {
  // Αρχικοποίηση της σειριακής θύρας για επικοινωνία με τον χρήστη μέσω monitor.
  Serial.begin(9600);
  delay(500);
  Serial.println();
  Serial.println(F("### ANOIKSE H SEIRIAKH THYRA ###"));
  //---------------------------------------------------------------------------
  
  // Αρχικοποίηση των ακροδεκτών των 7 Αισθητήρων Προσέγγισης
  for (int akida : akrodekteses) {
    pinMode(akida, INPUT);
  }
  //--------------------------------------------------------------------------- 
  
  // Αρχικοποίηση της Braccio.
  pinMode(SOFT_START_CONTROL_PIN, OUTPUT);
  digitalWrite(SOFT_START_CONTROL_PIN, LOW);
  
  // Πριν τις attach, για να αποφύγουμε την απότομη αλλαγή θέσης των κινητήρων
  orthiosBraxionas(); 
  
  // Αρχικοποίηση των ακροδεκτών των σερβοκινητήρων
  base.attach(11);
  shoulder.attach(10);
  elbow.attach(9);
  wrist_rot.attach(6);
  wrist_ver.attach(5);
  gripper.attach(3);
  
  // Αφήνει το PIN12 σε υψηλή τάση, αν το άφηνε σε χαμηλή τότε τα σερβό δεν θα ανταποκρίνονταν.
  digitalWrite(SOFT_START_CONTROL_PIN, HIGH);
  //--------------------------------------------------------------------------- 
  
  //Agonas agonas("2252576253462244111563365343671351441"); //Σκορ: -1
  //Agonas agonas("22525762534622441115633");
  //Agonas agonas("745673372421446145467"); //Σκορ: 2
  //Agonas agonas("23663444331752227747"); //Σκορ: -1	
  Agonas agonas("554");
  //Agonas agonas;
  agonas.paikseMexriTelous();
}

void loop() {
}
