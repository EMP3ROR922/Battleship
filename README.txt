#Torpedójáték


A játéktér 11x11es, mindegyik játékos 6 hajóval kezd, ezeket a preparation phase alatt el kell helyezniuk a térképen,
ügyelve arra, hogy a hajók közt ne legyen átfedés, mivel a program ezt sajnos nem tudja jól kezelni.
A játék a prep phase-el indul, ha egy játékos lerakta az összes hajóját, akkor az "Enter" lenyomásával következhet a másik.
Miután a kettes játékos is végzett, az action phase következik, melyet szintén az egyes játékos kezd. Egy szektor kijelölése után
azonnali visszajelzést kap a találatról(talált - > vörös, nem talált -> zöld, süllyedt -> pontok száma nő). A játékot az nyeri, aki előbb 
megtalálja az összes olyan szektort, ahol hajók vannak. Ekkor a pálya eltűnik és a győztes játékos sorszáma jelenik meg a képernyőn.

A hajókat térképen kívülre tenni nem lehet, csak a pálya határain belül mozgathatók. A hajók közti átfedés programhibát okoz sajnos. :( 
A hajókat BAL klikkel lehet felvenni, és JOBB klikkel lehet letenni. A már letett hajókat újból felvenni nem lehet.