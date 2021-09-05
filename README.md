## Έργο

Το σχολείο μας συμμετέχει και φέτος στο διαγωνισμό της ΕΛΛΑΚ με το έργο **Ρομπο-4** που βασίζεται σε συνδυασμό ιδεών που μας προέκυψαν κατά τα προηγούμενα έργα μας.Αφορά την κατασκευή ενός ρομποτικού χεριού που θα μπορεί να παίζει εναντίον ενός (ανθρώπινου) αντιπάλου το επιτραπέζιο παιχνίδι **Σκορ-4** γνωστό και ως _Τέσσερα στη Σειρά_ (connect-4, four-in-a-row).
![IMG_20210601_130843](https://user-images.githubusercontent.com/38431707/132117284-0f5b367e-f942-4729-8027-c69f968e2a20.jpg)

### Ομάδα

Εφέτος, η ομάδα ρομποτικής **@robot7gymchai** του σχολείου μας, αποτελείται από τον μαθητή της πρώτης τάξης _Μουτζουρίδη Βασίλη_, τη μαθήτρια της δεύτερης τάξης _Λυμπερίου Θεοδώρα_ και τον καθηγητή πληροφορικής _Μαχαιρίδη Τάσο_.

### Περιγραφή παιχνιδιού

Το Σκορ-4 παίζεται σε μια πίστα με 42 θέσεις οργανωμένες σε 6 γραμμές και 7 στήλες και 21 κόκκινα και 21 κίτρινα πούλια που μοιράζονται στουςδύο παίκτες. Κάθε φορά, ο παίκτης που έχει τη σειρά να παίξει, ρίχνει ένα πούλι με το χρώμα του, στην κορυφή της στήλης που έχει επιλέξει, εφόσον υπάρχει κενό. Το πούλι στοιβάζεται πάνω σε τυχόν προηγούμενα πούλια της στήλης, καλύπτοντας τον κενό χώρο. Νικητής του αγώνα είναι ο πρώτος από τους δύο παίκτες που θα σχηματίσει τουλάχιστον μια τετράδα από συνεχόμενα πούλια του χρώματός του στην πίστα, με διεύθυνση είτε οριζόντια, είτε κάθετα, είτε διαγώνια. Αν δεν το κατορθώσει κανείς και γεμίσει η πίστα με τα πούλια και των δύο παικτών, τότε οι παίκτες θεωρούνται ισόπαλοι.

### Στόχος και σύνδεση με διαγωνισμό

Ο σκοπός του έργου είναι η διασκεδαστική κατασκευή ενόςψυχαγωγικού παιχνιδιού που συνδυάζει γνώσεις και δεξιότητες από τουςτομείς τηςμηχανικής, της πληροφορικής, τηςρομποτικής και των ηλεκτρονικών. Από τιςκατηγορίες του διαγωνισμό, ανήκει στην «Ψυχαγωγία». Και η σχέση με τον τομέα της τεχνητής νοημοσύνης είναι η προσπάθεια απόδοσης, στη μηχανή, ευφυΐας, που να μπορεί να προκαλέσει ισάξια έναν άνθρωπο να νικήσει ένα ρομπότ, σε ένα «ανθρώπινο» επιτραπέζιο παιχνίδι.

### Στόχοι

Οι κύριοι στόχοι μας είναι α) η εξοικείωση της ομάδας με τις κατασκευές και τον προγραμματισμό, β) η ομαλή εξέλιξη του παιχνιδιού, γ)η απόκτηση «εξυπνάδας» από το ρομπότ.

### Υλικά

Για την υλοποίηση του έργου, χρειάζονται:

- Ένα πλαστικό ταμπλό από επιτραπέζιο Σκορ-4 με πόδια και πούλια δύο χρωμάτων από κατάστημα παιχνιδιών (€15)
- Κατασκευαστικά υλικά (€20): A4 μακετόχαρτο, ένα μικρό ξύλο τύπου μπάλσα,μια ξύλινη βάση MDF πάχους ½ εκ., 10 εκ. σωλήνας από χοντρό χαρτόνι, θερμόκολλα σιλικόνης,αφρολέξ, μια άδεια πλαστική θήκη DVD/DVD για 50 δίσκους (disk cake)
- Ηλεκτρονικά εξαρτήματα: μικροελεγκτής Arduino mega (€25), ρομποτικός βραχίονας (€170) τουλάχιστον τεσσάρων βαθμών ελευθερίας, με αντίστοιχους σερβοκινητήρες και πλακέτα οδήγησης (shield), επτά αισθητήρες εγγύτητας (proximity) υπέρυθρων (€10), πλακέτα δοκιμών (breadboard) και καλώδια σύνδεσης (€5)

###### Εργαλεία:
πριόνι ξύλου, πιστόλι θερμόκολλας, λεπίδι, κατσαβίδια, πολύμετρο, χάρακας

### Υλοποίηση - Κατασκευή

Στο Σκορ-4, οι δύο παίκτες παίζουν ο ένας μετά τον άλλον, στη σειρά. Πάντα θα ξεκινάει το παιχνίδι ο ανθρώπινος παίκτης με τα _κόκκινα_ πούλια, που όταν έχει σειρά, θα χρειαστεί να ανιχνεύεται η στήλη στην οποία έριξε το πούλι του. Γι&#39; αυτό το σκοπό, χρησιμοποιούμε επτά ηλεκτρονικούς αισθητήρες στερεωμένους στην κορυφή κάθε στήλης, σε τρύπες μέσα σε μια _υπερκατασκευή_.

Ο κάθε αισθητήρας μετράει συνέχεια την αντανάκλαση των εκπεμπόμενων υπέρυθρων ακτινών, σε κοντινή απόσταση δίπλα του και αν αισθανθεί κοντά του πούλι, στέλνειένα ηλεκτρικό σήμα μέσω ξεχωριστού καλωδίουσε αποκλειστική ακίδα (pin) ψηφιακής εισόδουτου μικροελεγκτή.

Αντίστοιχα, στη δική του σειρά, ο μικροελεγκτής θα πρέπει, αφού διαλέξει τη κάθετη στήλη, να δώσει εντολή στο ρομποτικό χέρι να πάρει ένα _κίτρινο_ πούλι και να το ρίξει στη σωστή σχισμή. Το χέρι σκύβει για να πάρει το πούλι από το σημείο που βρίσκεται, λυγίζοντας τις αρθρώσεις του, ώστε τα δύο δάκτυλά του να καταλήξουν γύρω από το πούλι. Αμέσως μετά, κλείνει τα δάκτυλα για να το πιάσει, το ανασηκώσει και περιστρέφεται ολόκληρο, μέχρι την κατεύθυνση της πίστας. Εκεί ξανασκύβει μέχρι να αφήσει το πούλι στην είσοδο της στήλης. Για να κάνει αυτή την κίνηση, το συγκεκριμένο ρομποτικό που χρησιμοποιούμε, πρέπει να είναι τοποθετημένο σε ψηλή θέση ώστε να φτάνει σε όλες τις εισόδους. Γι&#39; αυτό το στερεώνουμε με βίδες πάνω σε μια πλαστική θήκη από DVD που περίσσεψε.

<img src="https://user-images.githubusercontent.com/38431707/132117251-d50f0870-c1a5-47e3-ab1d-49ec3d507707.jpg" width="460" /> <img src="https://user-images.githubusercontent.com/38431707/132117216-1c6acad4-46ff-47d5-bd0e-8493e0dfaf85.jpg" width="460" />

Η υπερκατασκευή που αναφέρθηκε νωρίτερα, είναι μια κατασκευή με παραπέτα και χωρίσματα κολλημένηστην κορυφή της πίστας, φτιαγμένηαπό μακετόχαρτο, με σκοπό την οδήγηση της ρίψης ώστε να μη ξεφεύγουν τα πούλια κατά την πορεία τουςστησχισμή της σωστής στήλης.
![IMG_20210628_105944](https://user-images.githubusercontent.com/38431707/132117455-b3572ec6-7024-4e37-b09c-4e17e10d6dd1.jpg)

Μια δεύτερη κατασκευή από ξύλο μπάλσα και μακετόχαρτο, αφορά μια _γλύστρα_ για τα πούλια. Λειτουργεί σαν τροφοδότης του ρομποτικού χεριού, με πούλια. Πρόκειται για έναν λεπτό διάδρομο που χωράει 12 πούλια, όρθια τοποθετημένα, σε σειρά και στερεώνεται σε αρκετή κλίση με κατάλληλη κολώνα από χαρτόνι. Όταν το χαμηλότερο πούλιαφαιρείται, τότε τα υπόλοιπα κυλάνε μια θέση παρακάτω στον διάδρομο και το επόμενο παίρνει τη θέση του. Μάλιστα, στο τέλος της διαδρομής κολλάμε ένα μικρό κομμάτι αφρώδες υλικό (π.χ. αφρολέξ) για να φρενάρει το πούλι που κυλάει και να μην αναπηδάει στο σκληρό ξύλο.

<img src="https://user-images.githubusercontent.com/38431707/132117368-f8e1f7e0-6e76-4ffb-a594-30de644c01ee.jpg" width="600" /> <img src="https://user-images.githubusercontent.com/38431707/132117366-d9d6494c-0077-4ed4-8944-8f0b2a01b7ed.jpg" height="300" /> <img src="https://user-images.githubusercontent.com/38431707/132117359-070567c5-cbf1-4b8a-842e-dc734e353091.jpg" height="300" />

![IMG_20210601_130843](https://user-images.githubusercontent.com/38431707/132117375-ce98966e-c7b4-4f18-92b8-d4b0885dab0a.jpg)

https://user-images.githubusercontent.com/38431707/132118566-641e8604-30ad-4622-bd40-0fe1cfc8a071.mp4

https://user-images.githubusercontent.com/38431707/132118706-056b3a62-8f25-444f-9053-7c033b0fbc38.mp4

### Κώδικας – Εργαλεία - Γλώσσα

Ο προγραμματισμός του μικροελεγκτή γίνεται στο περιβάλλον &quot;[Arduino Web Editor](https://create.arduino.cc/editor)&quot; στον ιστότοπο της εταιρείας. Μέσα από το chrome, αφού συνδεθούμε με τον λογαριασμό μας, πληκτρολογούμε τον πηγαίο κώδικα, τον μεταφράζουμε και ανεβάζουμε το εκτελέσιμο αρχείο στον μικροελεγκτή, μέσω της σειριακής του θύρας και της USB του υπολογιστή.Η γλώσσα προγραμματισμού είναι μια παραλλαγή της C++11 (χωρίς στη βασική βιβλιοθήκη STL), όμως μπορεί να χρησιμοποιηθεί και η Python.

### Μοντελοποίηση

Η κατάσταση του παιχνιδιού κρατιέται σε έναν πίνακα δύο διαστάσεων με 6 γραμμές και 7 στήλες, που σε κάθε θέση μπορεί να έχει μία από τις δυνατές τιμές «_Κόκκινο_», «_Κίτρινο_», ή «_Κενό_». Φυσικά, αρχικά όλες οι θέσεις έχουν την τιμή _Κενό_.

### Αλγόριθμοι και τεχνητή ευφυΐα (ΑΙ)

Επειδή πρώτος παίζει ο άνθρωπος, ο κώδικας επαναλαμβάνει ένα βρόχο (loop) που ελέγχει, διαδοχικά και γρήγορα, τα σήματα από τους αισθητήρες, μέχρι να συλλάβει ένα θετικό σήμα ρίψης. Στο συγκεκριμένο αισθητήρα αντιστοιχεί ένας αριθμός στήλης. Από αυτόν υπολογίζουμε την χαμηλότερη κενή γραμμή που θα καταλάβει το πούλι πέφτοντας, άρα και τη θέση στην πίστα, η οποία αλλάζει από _Κενό_ σε _Κόκκινο_.

Αλλάζει η σειρά και τώρα πρέπει να παίξει το ρομπότ. Η απόφαση για τη στήλη που θα ρίξει το πούλι του, λαμβάνεται από τον αλγόριθμο εξερεύνησης _negamax_, μια συντομότερη παραλλαγή του αλγόριθμου _minimax_, ενισχυμένο με τη δυνατότητα κλαδέματος των κόμβων του δέντρου της εξέλιξης του παιχνιδιού (alpha-beta). Επιπρόσθετα, η εξερεύνηση ξεκινάει από τις κεντρικότερες στήλες και καταλήγει στις ακραίες στήλες της πίστας, διότι οι τα πούλια στις πρώτες είναι πιθανότερο να σχηματίσουν νικητήριες τετράδες .

Αυτός ο αλγόριθμος παίζει όλες τις δυνατές κινήσεις και αμέσως μετά, για κάθε μια από αυτές, παίζει όλες τις δυνατές απαντήσεις του αντίπαλου. Το μοτίβο συνεχίζεται αναδρομικά, μέχρι να τερματιστεί ο αγώνας με κάποιο από τα αποτελέσματα: νίκη-ήττα-ισοπαλία, το κάθε ένα από τα οποία παίρνει να από μια ξεχωριστή αριθμητική τιμή που ονομάζεται _αξία_. Μετά, ο αλγόριθμοςεπιστρέφει από τις υποτιθέμενες μελλοντικές κινήσεις με τις αντίστοιχες αξίες και επιλέγει την μέγιστη από αυτές, αν πρόκειται για τον τρέχοντα παίκτη, ή την ελάχιστη από αυτές αν πρόκειται για τον αντίπαλο παίκτη. Τελικά, όταν επιστρέψει από τη αναδρομή στην τρέχουσα κατάσταση του αγώνα, επιλέγει να τοποθετήσει το πούλι του στη θέση που οδηγεί στην καλύτερη εξέλιξη του αγώνα, ακόμα και αν αντίπαλος παίξει τέλεια.
![IMG_20210617_153818](https://user-images.githubusercontent.com/38431707/132117355-f97dc011-f400-47ce-8527-144f1b3446d2.jpg)

Αξιοσημείωτο είναι ότι το συγκεκριμένο παιχνίδι έχει πρόσφατα επιλυθεί οριστικά, με την βοήθεια υπερυπολογιστών. Βρέθηκε ότι ο παίκτης που παίζει πρώτος, αν παίξει τέλεια, σίγουραθα νικήσει. Όμως, σε έναν μικροελεγκτή, αλλά και σε έναν απλό υπολογιστή, είναι αδύνατο να προϋπολογιστούν οι τρισεκατομμύρια δυνατές εξελίξεις ενός αγώνα, σε διάστημα δευτερολέπτου. Γι&#39; αυτό, στον κώδικα μπαίνει ένας χρονικός«κόφτης»στηναναζήτηση της επόμενης θέσης του ρομπότ. Όταν ξεπεραστεί τοδιάστημα του ενόςδευτερολέπτου, τότε σταματάει η διαδικασία και επιλέγεται η καλύτερη μέχρι στιγμής θέση, χωρίς να είναι βέβαιο ότι είναι και γενικάη καλύτερη.

