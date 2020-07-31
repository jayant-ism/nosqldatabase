// import this file

/*

do connect(port_no ) for local server database

for the daabase out of the system  do  connect(ip address ,  port_no )

add for adding a variable
ask for getting  the value of a variable

 */





#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
using namespace std ;
#include<iostream>

#include<map>

class database{

    private :

    int sockfd ;

    struct sockaddr_in si_me ,  si_other ;

    char buffer[1024] ;

    socklen_t addr_size  ;

      int  port ;

    void set(int pt )
    {

      port = pt ;

          sockfd =  socket(AF_INET ,  SOCK_DGRAM  , 0) ;
          memset( &si_other , '\0' , sizeof(si_other ))  ;
          si_other.sin_family =AF_INET  ;
          si_other.sin_addr.s_addr  =  inet_addr("127.0.0.1" ) ;  // default
          si_other.sin_port = htons(port) ;
          addr_size = sizeof(si_other) ;


    }




    public :

    void connect(string ip_address ,  int pt)
    {

      port = pt ;

          sockfd =  socket(AF_INET ,  SOCK_DGRAM  , 0) ;
          memset( &si_other , '\0' , sizeof(si_other ))  ;
          si_other.sin_family =AF_INET  ;
          si_other.sin_addr.s_addr  =  inet_addr((char *)&ip_address ) ;  // default
          si_other.sin_port = htons(port) ;
          addr_size = sizeof(si_other) ;


    }




    void connect(int  port )
    {
      set(port) ;
    }

    void test()
    {
      strcpy(buffer ,"HELLO SERVER \n") ;

      sendto(sockfd ,   buffer ,  1024 ,   0 ,  (struct sockaddr * )&si_other , sizeof(si_other )   ) ;

      printf("DONE") ;


        recvfrom(sockfd , buffer , 1024 , 0 ,   (struct  sockaddr*)&si_other ,  &addr_size ) ;
    printf("%s "  , buffer ) ;


    }

    void add(string  key  , string val)
    {

      // send message query type
      string se ="1" ;
      se= se+ to_string(key.length()) +"-" +key+val ;
      memset(buffer ,'\0' , sizeof(buffer ))  ;
      for(int i = 0 ; i < se.length() ;i++)
      buffer[i] =  se[i] ;

      sendto(sockfd ,   buffer ,  1024 ,   0 ,  (struct sockaddr * )&si_other , sizeof(si_other )   ) ;














    }

    string ask(string  key )
    {


      string se ="0" ;
      se= se+ to_string(key.length()) +"-"+key ;
      memset(buffer ,'\0' , sizeof(buffer ))  ;
      for(int i = 0 ; i < se.length() ;i++)
      buffer[i] =  se[i] ;
      cout<<se<<endl ;


        sendto(sockfd ,   buffer ,  1024 ,   0 ,  (struct sockaddr * )&si_other , sizeof(si_other )   ) ;

        recvfrom(sockfd , buffer , 1024 , 0 ,   (struct  sockaddr*)&si_other ,  &addr_size ) ;
      string  va= "" ;
      for(auto i :  buffer )
      {
        if(i=='\n' || i=='\0' )
        break ;
        va.push_back(i)  ;
       }
    return  va ;



    }




};
