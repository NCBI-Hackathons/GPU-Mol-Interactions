#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//get a random number, compare it to the probability.
bool random(double prob) {
  srand (time(NULL));
  double i = ((double) rand() / (RAND_MAX)) ;
  //cout << i <<" \n";
  if (i > prob) {
    return true;
  } else
    return false;
}

void dissociateParticle(vector<int>& particle2Cluster,vector<vector<int>>& cluster2Receptor, double dissociationProb) {

  //which one to disassociate
  for(int cluster=0; cluster < cluster2Receptor.size(); cluster++) {
    if(random(dissociationProb)) {
      for(int j =0; j< cluster2Receptor[cluster].size(); j++) {
        if(random(dissociationProb)) {
          //set the particle free and change it in the cluster2Receptor.
          int temp = cluster2Receptor[cluster][j];
          cluster2Receptor[cluster][j] = 0;
          particle2Cluster[temp] = temp;
          cout<<temp<<" \n";

          //Implement: if the cluster is empty or only has 1 element, don't remove it. ??
        }
      }
    }
  }
}

//add the particles to a 2d array of quadrants.
void partitioning(vector<vector<set<pair<double,double>>>>& quadrants, vector<pair<double, double>>& particles, int divisionLength, int areaLength) {
  //sort(particles.begin(), particles.end());
  //find out how many division horizontally and vertically. This assumes the area is square.
  double maxQuadrants = (double)ceil(areaLength/divisionLength);

  //decide what particle belongs to what box
  for(pair<double, double> p: particles) {
    int row =(int) ceil(p.first/maxQuadrants);
    int col= (int)ceil(p.second/maxQuadrants);
    quadrants[row][col].insert(p);
  }
}

//reassign the particles to a new quadrant. Call this after the particle's positions changed. This assumess the area is square. If it's not this can be changed later.
void reassign(vector<vector<set<pair<double,double>>>>& quadrants, int divisionLength, int areaLength) {
  //quadrants.size() should match this number.
  double maxQuadrants = (double)ceil(areaLength/divisionLength);

  //go through the quadrants, calculate the quadrant it belongs to now. Then add it. Remove it from the current quadrant.

  for(int i=0; i< quadrants.size(); i++) {
    for(int j=0; j < quadrants.size(); j++) {
      for(pair<double, double> p: quadrants[i][j]) {
        int row =(int) ceil(p.first/maxQuadrants);
        int col= (int)ceil(p.second/maxQuadrants);
        quadrants[row][col].insert(p);
        quadrants[i][j].erase(p);
      }
    }
  }
}



int main() {
  cout << "Hello world!" << endl;

  vector<vector<int>> cluster2Receptor{ { 1,2},{3,4}};
  vector<int> receptor2Cluster {1,1,3,3,5,6,7,8,9};
  dissociateParticle(receptor2Cluster,cluster2Receptor,0.5);

  for(int i : receptor2Cluster) {
    cout<< i<< " ";
  }
  cout<< "\n";
  for(int i=0; i<cluster2Receptor.size(); i++) {
    for(int j=0; j<cluster2Receptor[i].size(); j++) {
      cout<< cluster2Receptor[i][j]<< " ";
    }
  }

  return 0;
}


