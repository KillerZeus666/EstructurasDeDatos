#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <string>

#include "NextAnagram.h"

#define MAX_ANAGRAMS 1000

// -------------------------------------------------------------------------
// Lists used in this code, vector caracteres y vector de strings globales
typedef std::vector< char >        TCharacterList;  
typedef std::vector< std::string > TStringList;  

// -------------------------------------------------------------------------
//Funciones que leen los vectores
TCharacterList ReadAsCharacterList( std::istream& input ); 
TStringList ReadAsStringList( std::istream& input );

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  // Get a valid input stream
  /*Se revisa que la entrada de datos sea valida, verificando que se haya 
  //ingresado más de un argumento, ya que por defecto siempre está el nombre del archivo*/
  std::istream* input = &std::cin;
  if( argc > 1 )
    input = new std::ifstream( argv[ 1 ] );

  /*Si no se ingresó el argumento que indica el nombre del archivo de input
  //manda error de que no se pudo abrir el archivo*/
  if( !( *input ) ){
    std::cerr << "Error opening input stream." << std::endl;
    return( -1 );
  }//fi

  //Loop over input
  unsigned int line_type;

  //Se hace el while sobre la entrada recibida en consola
  do
  {
    // Get complete text line
    
    /*Se obtiene toda la línea de texto ingresada como argumento y se pone
    //en line*/
    std::string line;
    std::getline( *input, line );

    // Prepare a simple tokenizer
    /*Con esta función con la linea anteriormente declarada
    //se obtiene la capacidad de manipular el string como de salida 
    //como de entrada con >> <<*/
    std::stringstream line_stream( line );

    // Get type of data

    /*Se inserta como argumento el stream de la línea de texto en el line_type
    //en caso de que esta sea 0, signfica que es un string, en caso de que sea 1
    //es char, y se realiza este ciclo mientras sea diferente de 2, que significa
    //que no es ninguno de los dos anteriores*/
    line_stream >> line_type;

    //Caso de que sea string
    if( line_type == 0 )
    {
      // String list
      TStringList stringList = ReadAsStringList( line_stream );

      // Compute number of anagrams
      unsigned long nAnagrams = ComputeNumberOfAnagrams( stringList );
      if( nAnagrams >= MAX_ANAGRAMS )
        nAnagrams = MAX_ANAGRAMS;

      // Print all (or at least MAX_ANAGRAMS) anagrams
      for( unsigned long i = 0; i < nAnagrams; ++i )
      {
        std::copy(
          stringList.begin( ), stringList.end( ),
          std::ostream_iterator< std::string >( std::cout, " : " )
          );
        std::cout << std::endl;
        stringList = NextAnagram( stringList );

      } // rof
    }
    else if( line_type == 1 )
    {
      // Char list
      TCharacterList charList = ReadAsCharacterList( line_stream );

      // Compute number of anagrams
      unsigned long nAnagrams = ComputeNumberOfAnagrams( charList );
      if( nAnagrams >= MAX_ANAGRAMS )
        nAnagrams = MAX_ANAGRAMS;

      // Print all (or at least MAX_ANAGRAMS) anagrams
      for( unsigned long i = 0; i < nAnagrams; ++i )
      {
        std::copy(
          charList.begin( ), charList.end( ),
          std::ostream_iterator< char >( std::cout, "" )
          );
        std::cout << std::endl;
        charList = NextAnagram( charList );

      } // rof

    } // fi

  } while( line_type != 2 );

  // Close input stream, if needed (ie. it wasn't taken from std::cin)
  if( input != &std::cin )
  {
    dynamic_cast< std::ifstream* >( input )->close( );
    delete input;

  } // fi
  
  return( 0 );
}

// -------------------------------------------------------------------------
//Funcion que lee lista de caracteres
TCharacterList ReadAsCharacterList( std::istream& input )
{
  // Prepare output
  TCharacterList lst;

  // Loop over a space separated stream (tokenizer)
  while( !input.eof( ) )
  {
    std::string str;
    input >> str;

    for(
      std::string::const_iterator sIt = str.begin( );
      sIt != str.end( );
      ++sIt
      )
      lst.push_back( *sIt );

  } // elihw

  return( lst );
}

// -------------------------------------------------------------------------
//Funcion que lee lista de strings
TStringList ReadAsStringList( std::istream& input )
{
  // Prepare output
  TStringList lst;

  // Loop over a space separated stream (tokenizer)
  while( !input.eof( ) )
  {
    std::string str;
    input >> str;
    lst.push_back( str );

  } // elihw

  return( lst );
}

// eof - solve_anagram.cxx
