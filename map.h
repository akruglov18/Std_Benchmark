#include<map>
#include<chrono>
#include<thread>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

using namespace std;

void mapInsert(int count) {
  map<int,int> d;
  cout << "Map inserting " << count << " elements : ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    d.insert({ i,i });
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count() << "\n";

  ofstream fout("text.txt");
  fout << d[count - 1];
  fout.close();
}

void mapErase(int count) {
  map<int, int> d;
  for (int i = 0; i < count; i++) {
    d[i] = i;
  }
  cout << "Map erase " << count << " elements : ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    d.erase(i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count() << "\n";

  ofstream fout("text.txt");
  fout << d[count - 1];
  fout.close();
}

void mapFind(int count) {
  map<int, int> d;
  for (int i = 0; i < count; i++) {
    d[i] = i;
  }
  cout << "Find into " << count << "-elements map: ";
  map<int, int>::iterator a;
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    a=d.find(i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count()<< "\n";

  ofstream fout("text.txt");
  fout << (*a).first;
  fout.close();
}

void mapTest() {
  cout << "MAP TEST\n";
  mapInsert(100);
  mapInsert(1000);
  mapInsert(10000);
  mapInsert(100000);
  mapInsert(1000000);
  mapInsert(10000000);
  mapInsert(100000000);
  cout << "\n";
  mapErase(1000);
  mapErase(10000);
  mapErase(100000);
  mapErase(1000000);
  mapErase(10000000);
  mapErase(100000000);
  cout << "\n";
  mapFind(100);
  mapFind(1000);
  mapFind(10000);
  mapFind(100000);
  mapFind(1000000);
  mapFind(10000000);
  cout << "\n";
}