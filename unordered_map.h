#include<unordered_map>
#include<chrono>
#include<thread>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

using namespace std;

void unordered_map_insert(int count) {
  unordered_map<int, int> d;
  cout << "Unordered map inserting " << count << " elements : ";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    d.insert({ i,i });
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count()<< "\n";

  ofstream fout("text.txt");
  fout << d[count - 1];
  fout.close();
}

void unordered_map_erase(int count) {
  unordered_map<int, int> d;
  for (int i = 0; i < count; i++) {
    d[i] = i;
  }
  cout << "Unordered map erase " << count << " elements : ";
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

void unordered_map_find(int count) {
  unordered_map<int, int> d;
  for (int i = 0; i < count; i++) {
    d[i] = i;
  }
  cout << "Find into " << count << "-elements unordered_map: ";
  unordered_map<int, int>::iterator a;
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < count; i++) {
    a = d.find(i);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  cout << fixed << setprecision(10) << elapsed.count() << "\n";

  ofstream fout("text.txt");
  fout << (*a).first;
  fout.close();
}

void unordered_map_test() {
  cout << "UNORDERED MAP TEST\n";
  unordered_map_insert(100);
  unordered_map_insert(1000);
  unordered_map_insert(10000);
  unordered_map_insert(100000);
  unordered_map_insert(1000000);
  unordered_map_insert(10000000);
  unordered_map_insert(100000000);
  cout << "\n";
  unordered_map_erase(1000);
  unordered_map_erase(10000);
  unordered_map_erase(100000);
  unordered_map_erase(1000000);
  unordered_map_erase(10000000);
  unordered_map_erase(100000000);
  cout << "\n";
  unordered_map_find(100);
  unordered_map_find(1000);
  unordered_map_find(10000);
  unordered_map_find(100000);
  unordered_map_find(1000000);
  unordered_map_find(10000000);
  cout << "\n";
}