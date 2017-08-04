#include<iostream>
#if defined _WIN32
 #include<windows.h>
  #endif

using namespace std;
int main()
{
    #if defined _WIN32
// estas linhas serão executadas apenas quando o programa
// for compilado por alguma versão do Microsoft Visual C
  cout<<"Eh windows"<<endl;
  system("PAUSE");

#else
cout<<"OS not supported!";

#endif

return 0;
}
