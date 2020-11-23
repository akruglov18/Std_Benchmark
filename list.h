#include<list>
#include<chrono>
#include<thread>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

using namespace std;

void listInsert(int count) {
  list<int> l;
  l.resize(count);
  cout << "List insert " << count << ": ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    l.insert(l.begin(), i, i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count()<< "\n";

  ofstream fout("text.txt");
  fout << *(l.begin());
  fout.close();
}

void listPB(int count) {
  list<int> l;
  cout << "List push back " << count << " elements : ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    l.push_back(i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count() << "\n";

  ofstream fout("text.txt");
  fout << *(l.begin());
  fout.close();
}

void listPF(int count) {
  list<int> l;
  cout << "List push front " << count << " elements : ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    l.push_front(i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count() << "\n";

  ofstream fout("text.txt");
  fout << *(l.begin());
  fout.close();
}

void listFind(int count) {
  list<int> l;
  l.resize(count);
  for (int i = 0; i < l.size(); i++) {
    l.push_back(i);
  }
  cout << "Find into " << count << "-elements list: ";
  list<int>::iterator a;
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    a = find(l.begin(), l.end(), i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count() << "\n";

  ofstream fout("text.txt");
  fout << *a;
  fout.close();
}

void listTest() {
  cout << "LIST TEST\n";
  listInsert(100);
  listInsert(1000);
  listInsert(10000);
  cout << "\n";
  listPB(1000);
  listPB(10000);
  listPB(100000);
  listPB(1000000);
  listPB(10000000);
  listPB(100000000);
  cout << "\n";
  listPF(1000);
  listPF(10000);
  listPF(100000);
  listPF(1000000);
  listPF(10000000);
  listPF(100000000);
  cout << "\n";
}