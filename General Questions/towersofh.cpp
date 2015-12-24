#include <iostream>
using namespace std;


void tower(int n, char frompeg, char auxpeg, char destpeg){
  if (n==1){
    cout << "move the last disk from auxilary peg to destpeg" << endl;
    cout << "nice! you solved the puzzle"<< endl;
    return;
  }

  tower(n-1, frompeg, auxpeg, destpeg);
  cout << "move from frompeg to auxpeg"<< endl;

  tower(n-1, auxpeg, destpeg, frompeg);
  cout << "move from auxpeg to destpeg" << endl;
}




int main()
{
  int n =0;
  char frompeg, auxpeg, destpeg;
  cout << "enter n" << endl;
  cin >> n ;
  cout << "tower func being called" << endl;
  tower(n, frompeg, auxpeg, destpeg);
  return 0;
}
