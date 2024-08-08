#ifndef __NEXTANAGRAM__H__
#define __NEXTANAGRAM__H__

// -------------------------------------------------------------------------
//Recibe listas de caracteres o string
template< class TList >
TList NextAnagram( const TList& lst );

// -------------------------------------------------------------------------
template< class TList >
unsigned long ComputeNumberOfAnagrams( const TList& lst );

// -------------------------------------------------------------------------
#include "NextAnagram.hxx"

#endif // __NEXTANAGRAM__H__

// eof - NextAnagram.h
