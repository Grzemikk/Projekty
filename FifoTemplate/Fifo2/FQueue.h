#pragma once
#include<iostream>
#include "global.h"
using namespace std;
#define FIFO_ALLOCATION_ERROR  0x01
#define FIFO_QUEUE_EMPTY 0x04
#define OTHER_ERROR      0x10


//- dodac klase wyjatku FifoException tez w tym pliku naglowkowym
//class FifoException

//	konstr FifoException( int errCode = OTHER_ERROR );
//metoda getReason();  implementacja inline

//Klsa zawiera tylko konstruktor( inline ) na bazie kodu bledu i metode inline
//getReason() zwrajaca( switch( ) ) odpowiedni string( const char* ) opisujacy rodzaj bledu


#define FQINFO FQInfo

//w global.h  zdef klase( strukt ) FQInfo z polami
//- int nKey,
//-tablica dynamiczna p int - ów( dwuelementowa ),
//-konstr z param int
//- wirt destr,
//-operat <<
//zdef stala preprocesora FQINFO jako struktura FQInfo


struct FQInfo {
public:
	FQInfo( int key, int tab1, int tab2 );
	virtual ~FQInfo();

	friend ostream& operator << ( ostream& os, const FQInfo& info );

private:
	int nKey;
	int* pTab;
};


FQInfo::FQInfo( int key1, int tab1, int tab2 ) {
	pTab = new int[ 2 ];
	nKey = key1;
	pTab[ 0 ] = tab1;
	pTab[ 1 ] = tab2;
}


FQInfo::~FQInfo() {}


ostream& operator << ( ostream& os, const FQInfo& info ) {
	os << "nKey: " << info.nKey << endl;
	os << "pTab[1]: " << info.pTab[ 0 ] << endl;
	os << "pTab[2]: " << info.pTab[ 1 ] << endl;
	return os;
}


class fifoException {
		public:
	fifoException( int errCode = OTHER_ERROR );
	const char* getReason();

	private:
	int m_errCode;
};


inline fifoException::fifoException( int errCode ) : m_errCode( errCode ) {}

inline const char* fifoException::getReason() {
	switch( m_errCode ) {
		case FIFO_ALLOCATION_ERROR:
			return "FIFO_ALLOCATION_ERROR";
		case FIFO_QUEUE_EMPTY:
			return "FIFO_QUEUE_EMPTY";
		case OTHER_ERROR:
			return "OTHER_ERROR";
		default:
			return "UNKNOWN_ERROR";
	}
}



//skladowe( FifoItem )
//- wsk m_pItem( wsk na FQINFO ),
//-wsk m_pNext( wsk na nastepny w kolejce )
//tylko w metodach klasy FQueue mozna wykreowac obiekt FifoItem
//konstr i destr inline
//konstr z parametrem domyslnym( NULL ) - wsk na FQINFO( uzywamy stalej preprocesora WSZEDZIE )


template <class T>
class FifoItem 
{
	public:
	FifoItem( T* pItem = NULL );
	virtual ~FifoItem();

	template<class T> friend class FQueue;

	T* getItem() const;

	private:
	T* m_pItem;
	FifoItem* m_pNext;
};


template <class T>
T* FifoItem<T>::getItem() const {
	return m_pItem;
}


template <class T>
inline FifoItem<T>::FifoItem( T* pItem ) 
{
	m_pItem = pItem;
	m_pNext = NULL;
}

template <class T>
inline FifoItem<T>::~FifoItem() {}



//Fifo( class FQueue ) realizowany jako lista prosta( z glowa ) z dwoma
//wskaznikami( m_pHead, m_pTail )

//Fifo( class FQueue ) realizowany jako lista prosta( z glowa ) z dwoma
//wskaznikami( m_pHead, m_pTail )
//
//- konstruktor bez param
//- wirt destr
//- bool FQEmpty(), int FQEnqueue( FQINFO* ); FQINFO* FQDequeue();
//void  FQClear();
//-prywatna void  FQDel();


template <class T>
class FQueue {
public:
	FQueue();
	virtual ~FQueue();

	bool FQEmpty();
	int FQEnqueue( T* pItem );
	FifoItem<T>* FQDequeue();
	void  FQClear();
	void FQPrint();

private:
	void  FQDel();

private:
	FifoItem<T>* m_pHead;
	FifoItem<T>* m_pTail;
};


template <class T>
inline FQueue<T>::FQueue()
{
	m_pHead = m_pTail = new FifoItem<T>();
}


template <class T>
FQueue<T>::~FQueue() {}


template <class T>
bool FQueue<T>::FQEmpty() {
	return  !m_pHead || !( m_pHead->m_pNext );
}


template <class T>
int FQueue<T>::FQEnqueue( T* pItem ) {
	FifoItem<T>* pNew = new( nothrow ) FifoItem<T>( pItem );
	if( !pNew ) {
		throw fifoException( FIFO_ALLOCATION_ERROR );
	}

		m_pTail->m_pNext = pNew;
		m_pTail = pNew;;

	return 0;
}


template <class T>
void FQueue<T>::FQDel() {
	if( m_pHead ) {
		FifoItem<T>* temp = this->m_pHead;
		m_pHead = m_pHead->m_pNext;
		delete temp;
	}
	if( FQEmpty() )
	{
		m_pTail = m_pHead;
	}
}


template <class T>
FifoItem<T>* FQueue<T>::FQDequeue() {
	if( FQEmpty() )
		throw fifoException( FIFO_QUEUE_EMPTY );

	FifoItem<T>* temp = m_pHead->m_pNext;
	FQDel();

	return temp;
}


template <class T>
void  FQueue<T>::FQClear() {
	while( !FQEmpty() )
		FQDel();
}


template <class T>
void FQueue<T>::FQPrint() {
	FifoItem<T>* pTmp = m_pHead->m_pNext;
	while( pTmp ) {
		cout << *( pTmp->m_pItem ) << endl;
		pTmp = pTmp->m_pNext;
	}
}
