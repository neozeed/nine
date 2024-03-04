/*
 * Copyright (c) 2015, Louis P. Santillan <lpsantil@gmail.com>
 * All rights reserved.
 * See LICENSE for licensing details.
 */
#include <rt0/syscall.h>

int write( int f, const char* d, int l )
{
   int ret = syscall3( SYS_write, f, ( long )( d ), l );

   return( ret );
}

int str_len( const char *string )
{
   int length = 0;
   while( *string ) { string++; length++; }
   return( length );
}

void print( const char* string )
{
   write( 1, string, str_len( string ) );
}

int main( int argc, char** argv, char** envp )
{
   int i, j,
       ret = syscall0( SYS_fork );
   char *c = "CCCCCCCCCCCCCCCCCCCCC\n";
   char *p = "PPPPPPPPPPPPPPPPPPPPP\n";

   if( 0 == ret )
   {
      for( i = 0; i < 10; i++ )
      {
         write( 1, c + 20 - i, i + 2 );
      }
      print( "Bye from the child\n" );
   }
   else
   {
      for( j = 0; j < 20; j++ )
      {
         write( 1, p + 20 - j, j + 2 );
      }
      print( "Bye from the parent\n" );
   }

   return( 0 );
}
