#include<set>
#include<chrono>
#include<thread>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

using namespace std;

void setInsert(int count) {
  set<int> d;
  cout << "Set inserting " << count << " elements : ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    d.insert(i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count()<< "\n";

  ofstream fout("text.txt");
  fout << *(--d.end());
  fout.close();
}

void setErase(int count) {
  set<int> d;
  for (int i = 0; i < count; i++) {
    d.insert(i);
  }
  cout << "Set erase " << count << " elements : ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    d.erase(i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count() << "\n";

  ofstream fout("text.txt");
  fout << *(--d.end());
  fout.close();
}

void setFind(int count) {
  set<int> d;
  for (int i = 0; i < count; i++) {
    d.insert(i);
  }
  cout << "Find into " << count << "-elements set: ";
  set<int, int>::iterator a;
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    a = d.find(i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count() << "\n";

  ofstream fout("text.txt");
  fout << *a;
  fout.close();
}

void setTest() {
  cout << "SET TEST\n";
  setInsert(100);
  setInsert(1000);
  setInsert(10000);
  setInsert(100000);
  setInsert(1000000);
  setInsert(10000000);
  setInsert(100000000);
  cout << "\n";
  setErase(1000);
  setErase(10000);
  setErase(100000);
  setErase(1000000);
  setErase(10000000);
  setErase(100000000);
  cout << "\n";
  setFind(100);
  setFind(1000);
  setFind(10000);
  setFind(100000);
  setFind(1000000);
  setFind(10000000);
  cout << "\n";
}