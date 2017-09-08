
/** Arquitetura de Computadores III - Lesandro Ponciano
  * Trabalho Pratico 1 - Flicker Database
  * Integrantes: Igor Machado Seixas
  *              Joao Castro
  *              Paulo Junio
  * Linguagem utilizada: C++
  * Recursos: <string> substr (int inicio, int quantidade) - Substring
  *           <string> find (String padrao) - "contains" retorna posicao do padrao se achar, se nao achar returna -1
  *           <string> at (int posicao) - "charAt" retorna o char da posicao passada por parametro
  *           <string> stod (string str) - "parseDouble" retorna o valor double da string em parametro
  */

  // Imports
  #include <iostream>
  #include <list>
  #include <algorithm>
  //#include <string> // Not Used
  using namespace std;

  #define ARRAY_SIZE 200  // Define the length of the study group

  class graph {
   public:
   // Atributes
   int nivelZero;
   int nivelPrimeiro;
   int nivelSegundo;
   int nivelTerceiro;
   int nivelQuarto;

   list<double>* usergraph; // Vertex which will cotain user id
   list<double>::iterator it;
   int n;

   /**
     * Graph Construtctor
     * @param double V - Number of Vertex of the graph
     */
     graph ( ) {
      usergraph = new list<double> [ARRAY_SIZE];
      n = 0;
      nivelZero = 0;
      nivelQuarto = 0;
      nivelSegundo = 0;
      nivelTerceiro = 0;
      nivelPrimeiro = 0;
     }

   /**
     * Add Edge to Graph
     * @param u1 - Vertex User
     * @param u1 - User to be added
     */
     void addEdge ( double u1, double u2 ) {
       int pos1, pos2;

       // Verificating if there is User u1
       pos1 = sequencialSearch(u1);
       if ( pos1 == -1 ) {   // Find and check position of first user
         pos1 = n;  // Update pos1 situation
         addVertex(u1);
       }
       // Verificating if there is User u2
       pos2 = sequencialSearch(u2);
       if ( pos2 == -1 ) { // Find and check position of second user
         pos2 = n; // Update pos2 situation
         addVertex(u2);
       }
       // Create Edge between User u1 and User u2
       usergraph[pos1].push_back(u2);
       usergraph[pos2].push_back(u1);

       //it = find(usergraph[0].begin( ), usergraph[0].end( ), 2 );
     }

   /**
     * Add Vertex to Graph
     * @param v - Vertex to be added
     */
     void addVertex (double v) {
      int pos;
      pos = sequencialSearch(v);
      
      if (pos == -1){
       usergraph[n].push_front(v);
       n++;
      }
     }


   /**
     * Binary Find
     * @param u - User which will be search
     */
     int binaryFind ( double u ) {
       int left = 0, right = n -1, middle;
       int ans = -1;

       while (left <= right) {
         middle = (left+right) /2;

         if ( u == *usergraph[middle].begin( ) ) {
           ans = middle;
           left = ARRAY_SIZE;
         } else {
           if ( u > *usergraph[middle].begin( ) ) {
             left = middle+1;
           } else {
             right = middle-1;
           }
         }
       } // end while

       return ans;
     }

    /**
      * Sequencial Search
      * @param u - user which will be search
      */

     int sequencialSearch(double u){
      int answer = -1;
      for(int i = 0; i < n; i++){
        if( u == *usergraph[i].begin()){
          answer = i;
          i = n;
        }
      }
      return answer;
     }


   /**
     * Print Graph
     */
     void printGraph ( ) {
       for ( int i = 0; i < n; i++) {
         for ( list<double>::iterator j = usergraph[i].begin( ); j != usergraph[i].end( ); j++ ) {
           cout << *j << ' ';
         }

         cout << '\n';
       } // end for
     }


     void largeSearch(double idOwner , double idFriend) {

       int n0 = sequencialSearch(idOwner);
       if(n0 != -1 ) {
         for ( list<double>::iterator i = next(usergraph[n0].begin( ),1); i != usergraph[n0].end( ); i++ ) {
            if(*i == idFriend) {
           cout << "LALA i" << " " <<idFriend << '\n';

              nivelZero++;

            }else{
              int n1 = sequencialSearch(*i);
              if( n1 != -1) {

                for( list<double>::iterator j = next(usergraph[n1].begin( ),1); j != usergraph[n1].end( ); j++ ) {
                  if(*j == idFriend) {
                  cout << "LALA j" << *j << " " << idFriend << '\n';

                    nivelPrimeiro++;

                  }else{
                    int n2 = sequencialSearch(*j);
                    if( n2 != -1){

                      for( list<double>::iterator k = next(usergraph[n2].begin( ),1); k != usergraph[n2].end( ); k++ ) {
                        if(*k == idFriend) {
                        cout << "LALA k" << *k << " " << idFriend << '\n';

                          nivelSegundo++;

                        }else{
                          int n3 = sequencialSearch(*k);

                          if( n3 != -1 ){

                            for( list<double>::iterator l = next(usergraph[n3].begin( ),1); l != usergraph[n3].end( ); l++ ) {
                              if(*l == idFriend) {
                              cout << "LALA l" << *l << " " << idFriend << '\n';

                                nivelTerceiro++;

                              }else{
                                int n4 = sequencialSearch(*l);

                                  for( list<double>::iterator m = next(usergraph[n4].begin( ),1); m != usergraph[n4].end( ); m++ ) {
                                    if(*m == idFriend) {
                                    cout << "LALA m" << *m << " " <<  idFriend << '\n';

                                      nivelQuarto++;

                                    }
                                  }
                                } // for of
                              } // for else
                          } // for if
                        } // third of
                      } //  trird else
                    } // third if
                  } // second of
                } // second else
              } // second if
           } // end first of
         } //end else
       } // end first if
     }// end method
  }; // end class graph

//   //////////////////////// TESTING AREA \\\\\\\\\\\\\\\\\\\\\\
// int main ()
// {

//   graph g;

//   g.addEdge(1,2);
//   g.addEdge(1,123.312);
//   g.addEdge(1,4);
//   g.addEdge(33.33,212);
//   g.addEdge(32,2);
//   g.addEdge(32,1);
//   g.addEdge(32,123123);
//   g.addEdge(1,20);

//   g.printGraph( );

//   return 0;
// }

// github.com/castrob/ac3_filcker/TODO.txt to task list
