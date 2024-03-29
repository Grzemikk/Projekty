#include <iostream>
#include "FQueue.h"



using namespace std;

int main() {
  try {

    // Tworzenie 5 elementowej kolejki z
    FQueue<FQINFO> q;

    FQINFO* pFQInfo = NULL;
    for( int i = 0; i < 5; i++ ) {
      int tab1 = rand() % 50;
      int tab2 = rand() % 50;
      pFQInfo = new FQINFO( i, tab1, tab2 );
      q.FQEnqueue( pFQInfo );
    }


    // Wyswietlenie kolejki
    cout << "Kolejka FIFO 5-cio elementowa:" << endl << endl;
    q.FQPrint();
    cout << endl << "==============================" << endl << endl;


    //// Usuniecie 3 elementow z kolejki
    //for( int i = 0; i < 3; i++ ) {
    //  FifoItem<FQINFO>* Deq = q.FQDequeue();
    //  cout << i + 1 << " Dequeued: " << endl << *Deq << endl;
    //}
    //cout << endl << "==============================" << endl << endl;


    // Usuniecie 3 elementow z kolejki
    for( int i = 0; i < 3; i++ ) {
      FifoItem<FQINFO>* DeqItem = q.FQDequeue();
        cout << i + 1 << " Dequeued: " << endl << *( DeqItem->getItem() ) << endl;
    
    }

    cout << endl << "==============================" << endl << endl;


    // Wyswietlenie kolejki
    cout << "Kolejka FIFO po usunieciu 3 elementow:" << endl << endl;
    q.FQPrint();
    cout << endl << "==============================" << endl << endl;

    // Usuniecie kolejki
    q.FQClear();
    cout << "Drukowanie kolejki FIFO po wyczyszczeniu:" << endl << endl;
    q.FQPrint();
    cout << endl << "==============================" << endl << endl;

  }
  catch( fifoException& err ) {
    cout << "Wychwycono FifoException: " << err.getReason() << endl;
  }

  return 0;
}


