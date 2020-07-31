
#include"clint.h"


int main( )
{




database ds ;
ds.connect(9898) ;



ds.add( "key" , "val" ) ;
cout<<ds.ask("key") <<endl   ;





  }
