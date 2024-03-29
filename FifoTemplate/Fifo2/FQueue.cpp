// #include "FQueue.h"



//FQInfo::FQInfo( int key1, int tab1, int tab2 ) {
//	pTab = new int[2];
//	nKey = key1;
//	pTab[0] = tab1;
//	pTab[1] = tab2;
//}
//
//
//FQInfo::~FQInfo() {}
//
//
//ostream& operator << ( ostream& os, const FQInfo& info ) {
//	os << "nKey: " << info.nKey << endl;
//	os << "pTab[1]: " << info.pTab[0] << endl;
//	os << "pTab[2]: " << info.pTab[1] << endl;
//	return os;
//}
//
//
//template <class T>
//FQueue<T>::FQueue() {
//	m_pHead = NULL;
//	m_pTail = NULL;
//}
//
//
//
//template <class T>
//FQueue<T>::~FQueue() {}
//
//
//
//template <class T>
//bool FQueue<T>::FQEmpty() {
//	return ( !m_pHead );
//}
//
//
//
//template <class T>
//int FQueue<T>::FQEnqueue( T* pItem ) {
//	FifoItem<T>* pNew = new( nothrow ) FifoItem<T>( pItem );
//	if( !pNew ) {
//		throw fifoException( FIFO_ALLOCATION_ERROR );
//	}
//
//	if( FQEmpty() ) {
//		m_pHead = pNew;
//	}
//	else
//		m_pTail->m_pNext = pNew;
//
//	m_pTail = pNew;
//
//	return 0;
//}
//
//
//
//template <class T>
//void FQueue<T>::FQDel() {
//	if( m_pHead ) {
//		FifoItem<T>* temp = this->m_pHead;
//		m_pHead = m_pHead->m_pNext;
//		delete temp;
//	}
//	else
//		delete m_pTail;
//}
//
//
//
//template <class T>
//T* FQueue<T>::FQDequeue() {
//	if( FQEmpty() )
//		throw fifoException( FIFO_QUEUE_EMPTY );
//
//	T* temp = m_pHead->m_pItem;
//	FQDel();
//
//	return temp;
//}
//
//
//
//template <class T>
//void  FQueue<T>::FQClear() {
//	while( !FQEmpty() )
//		FQDel();
//}
//
//
//
//template <class T>
//void FQueue<T>::FQPrint() {
//	FifoItem<T>* pTmp = m_pHead;
//	while( pTmp ) {
//		cout << *( pTmp->m_pItem ) << endl;
//		pTmp = pTmp->m_pNext;
//	}
//}