#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<map>
using namespace std ;
#include<iostream>

int main( int argc , char **argv )
{
  if(argc!=2)
  {
    printf("usage %s port " , argv[0]) ;

    exit(0) ;

  }

  int port =  atoi(argv[1] ) ;
  int sockfd ;

  struct sockaddr_in si_me ,  si_other ;

  char buffer[1024] ;

  socklen_t addr_size  ;
  sockfd =   socket(AF_INET  , SOCK_DGRAM ,  0 ) ;
  memset(&si_me , '\0' ,   sizeof(si_me)) ;
  si_me.sin_family =   AF_INET ;
  si_me.sin_port =   htons(port) ;
  si_me.sin_addr.s_addr = inet_addr("127.0.0.1") ;
  bind(sockfd  , (const struct sockaddr *)& si_me , sizeof(si_me)) ;
  addr_size =  sizeof(si_other) ;

map<string ,  string> data  ;

  while(1)
  {

    string oper , key ,  val ;



    recvfrom(sockfd , buffer , 1024 , 0 ,   (struct  sockaddr*)&si_other ,  &addr_size ) ;

int i= 1 ;
    // 0/1 -size1-size2
    if(buffer[0]=='1')
    {

      oper ="" ;
      for( ;i<1024 ;i++)
{
  if(buffer[i]=='-')
  break ;
  oper.push_back(buffer[i]) ;
}



int siz =  stoi( oper) ;
i++ ;

key="" ;
for( int j =0 ;j < siz ;j++)
{
  key.push_back(buffer[i+j])  ;

}
for(int j = i+siz ;j<1024 ;j++)
{
  if(buffer[j]=='\n' || buffer[j]=='\0')
  break ;
  val.push_back(buffer[j]) ;

}

data[key] =  val ;
cout<<key<< " " << val <<endl ;




    }else
    {


            oper ="" ;
            for( ;i<1024 ;i++)
      {
        if(buffer[i]=='-')
        break ;
        oper.push_back(buffer[i]) ;
      }



      int siz =  stoi(oper) ;
      i++ ;

      key="" ;
      for( int j =0 ;j < siz ;j++)
      {
        key.push_back(buffer[i+j])  ;

      }

      cout<<key<<" " <<data[key] <<endl ;

val = data[key] ;

memset(buffer,  '\0' , sizeof(buffer)) ;
for(int i = 0 ;i <val.size() ;i++)
{
  buffer[i] =  val[i] ;
}

sendto(sockfd ,   buffer ,  1024 ,   0 ,  (struct sockaddr * )&si_other , sizeof(si_other )   ) ;





    }







  }




 }
