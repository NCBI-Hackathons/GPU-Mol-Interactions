#include <bits/stdc++.h>
using namespace std;



//Here's the logic for the random function.
int randomDirection() {
  srand (time(NULL));
  return rand() % 8 +1;
}

void diffuseOneParticle(pair<double,double> particle) {
  int direction = randomDirection();

  if(direction == 1) {
    particle.left--;

  } else if(direction ==2) {
    particle.left--;
    particle.right++;
  } else if(direction == 3) {
    particle.right++;
  } else if(direction==4) {
    particle.left++;
    particle.right++;
  } else if(direction==5) {
    particle.left++;
  } else if(direction==6) {
    particle.left++;
    particle.right--;
  } else if(direction==7) {
    particle.right--;
  } else if(direction==8) {
    particle.left--;
    particle.right--;
  }
}

//implement the logic for diffusing quadrants. pass in more variables to generate the random function.
//I don't understand the randomness function to do it now.
void diffuseAQuadrant(set<pair<double,double>>> group) {
  for(pair<double,double> p:group) {
    diffuseOneParticle(p);
  }
}

