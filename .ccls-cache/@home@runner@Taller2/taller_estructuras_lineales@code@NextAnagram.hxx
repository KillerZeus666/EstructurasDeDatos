#ifndef __NEXTANAGRAM__HXX__
#define __NEXTANAGRAM__HXX__

#include <queue>
#include <stack>

// -------------------------------------------------------------------------
//Implementación de NextAnagram.h
template< class TList >

//Retorna una lista :D
TList NextAnagram( const TList& lst ){
    // Get contained type
    typedef typename TList::value_type TValue;
  
    // Used variables
    std::queue< TValue > q;
    std::stack< TValue > s;
    TList res;
    TValue pivot, v_aux, last_v;
    bool finished;
    typename TList::const_iterator lIt;
    typename TList::reverse_iterator rIt;
  
    // 1. Stack the input values
    /** TODO #1 **/ 
    //COMPLETADO
    for( lIt = lst.begin( ); lIt != lst.end( ); ++lIt ){
      s.push(*lIt);
    }
      
    // 2. Try to find a pivot
    finished = false;
    v_aux = s.top( );
    s.pop( );
    do{
      q.push( v_aux );
      last_v = v_aux;
      if( s.empty( ) ){
        finished = true;
        break;
      }
      else{
        // 2.1 Pop value from stack and store it into 'v_aux'
        /** TODO #2 **/ 
        //COMPLETADO
        for( lIt = lst.begin( ); lIt != lst.end( ); ++lIt ){
          v_aux = s.top(*lIt);
          s.pop();
        }
      } // fi
    }while( v_aux > last_v );
  
    // 2.5. if pivot has been found...
    if( !finished ){
      pivot = v_aux;

      // 3. Find a value just below pivot
      /** TODO #3 **/
      //COMPLETADO
      lIt = lst.begin( );
      do{
        
        if( q.empty( ) ){
          break;
        }
        //Se pone en auxiliar
        v_aux = q.front(*lIt);
        q.pop();
        // Ponerlo en la cola 
        q.push(v_aux);
        
        lIt++;

      //Se hace la confirmación de que se sigue cumpliendo           //con la condición
      //del enunciado
      }while (pivot > v_aux);


      // 5. Ahora el pivot4e esta al final de la cola
      q.push(pivot);

      // 6. Find the value just above pivot
      /** TODO #4 **/
      //COMPLETADO
      lIt = lst.begin( );
      do{
        
        if( q.empty( ) ){
          break;
        }
         v_aux = q.front(*lIt);
         q.push(v_aux);
         q.pop();
        
         lIt++;
      }while (v_aux < pivot);
      
      // 7. Put it into stack
      s.push(v_aux);
    } // fi
  
    // 8. Finish filling the stack by emptying the queue
    /** TODO #5 **/
    //COMPLETADO
    for( lIt = lst.begin( ); lIt != lst.end( ); ++lIt ){
      //Vaciar cola
      v_aux=q.front(*lIt);
      q.pop();
      //colocar en la pila
      s.push(v_aux);
    }
    // 9. Fill the final answer in reverse order by emptying the stack
    /** TODO #6 **/
    for(lIt = lst.begin( ); lIt != lst.end( ); ++lIt ){
    //Vaciar pila
    v_aux=s.top(*lIt);
    s.pop();
    //colocar en la lista de atras hacia adelante
    // aq
    res.push_front(v_aux);
    }
    
    // 10. Return
    return( res );
  }

  // -------------------------------------------------------------------------
  //Funcion que retorna un entero. Calcula la cantidad de anagramas 
  /** TODO #7 **/
  //COMPLETADO
  template< class TList >
  unsigned long ComputeNumberOfAnagrams( const TList& lst ){
    unsigned long nFactorial = lst.size();

    for (long i=nFactorial; i>0; i--){
      nFactorial = nFactorial * i;
    }
    return nFactorial;
    //Lógica aplicada 5!= 5 * 4 * 3* 2* 1
  }
  
  #endif // __NEXTANAGRAM__HXX__
  
  // eof - NextAnagram.hxx
  