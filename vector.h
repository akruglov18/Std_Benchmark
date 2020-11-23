#include<vector>
#include<chrono>
#include<thread>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

using namespace std;

void vecInsert(int count) {
  vector<int> d;
  d.resize(count);
  for (int i = 0; i < count; i++) {
    d[i] = i;
  }
  cout << "Inserting into " << count << "-element vector: ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    d.insert(d.begin(), i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count()<< "\n";

  ofstream fout("text.txt");
  fout << d[count - 1];
  fout.close();
}

void vectorPB(int count) {
  vector<int> d;
  cout << "Vector push back " << count << " elements : ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    d.push_back(i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count() << "\n";

  ofstream fout("text.txt");
  fout << d[count - 1];
  fout.close();
}

void vectorPBwithReserve(int count) {
  vector<int> d;
  d.reserve(count);
  cout << "Vector push back " << count << " elements with reserve : ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    d.push_back(i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count() << "\n";

  ofstream fout("text.txt");
  fout << d[count - 1];
  fout.close();
}

void vecFind(int count) {
  vector<int> d;
  d.resize(count);
  for (int i = 0; i < count; i++) {
    d[i] = i;
  }
  for (int i = 0; i < d.size(); i++) {
    d[i] = i;
  }
  cout << "Find into " << count << "-elements vector: ";
  vector<int>::iterator a;
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    a = find(d.begin(), d.end(), i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count() << "\n";

  ofstream fout("text.txt");
  fout << *a;
  fout.close();
}

void vectorTest() {
  cout << "VECTOR TEST\n";
  vecInsert(100);
  vecInsert(1000);
  vecInsert(10000);
  vecInsert(100000);
  cout << "\n";
  vectorPB(1000);
  vectorPB(10000);
  vectorPB(100000);
  vectorPB(1000000);
  vectorPB(10000000);
  vectorPB(100000000);
  vectorPB(1000000000);
  cout << "\n";
  vectorPBwithReserve(1000);
  vectorPBwithReserve(10000);
  vectorPBwithReserve(100000);
  vectorPBwithReserve(1000000);
  vectorPBwithReserve(10000000);
  vectorPBwithReserve(100000000);
  vectorPBwithReserve(1000000000);
  cout << "\n";
  vecFind(100);
  vecFind(1000);
  vecFind(10000);
  vecFind(100000);
  cout << "\n";
}